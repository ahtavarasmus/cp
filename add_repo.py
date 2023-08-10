def track_repo_for_user(user: User, repo_name: str, repo_github_id: str):
    """
    Sets up a webhook for the repository or retrieves the existing one.
    """

    webhook_url = f'{config.get("APP_URL")}/webhook'
    access_token = user.github_token_decrypted
    headers = {'Authorization': f'token {access_token}'}
    
    # Fetch the existing webhooks for the repository
    response = requests.get(f'https://api.github.com/repos/{user.github_login}/{repo_name}/hooks', headers=headers)
    if response.status_code != 200:
        print(f"Failed to retrieve webhooks for {repo_name}: {response.content}")
        return None

    existing_hooks = response.json()
    hook_id = next((hook['id'] for hook in existing_hooks if hook['config']['url'] == webhook_url), None)

    # If the webhook does not exist, create a new one
    if not hook_id:
        data = {
            'name': 'web',
            'active': True,
            'events': ['push'],
            'config': {
                'url': webhook_url,
                'content_type': 'json',
            }
        }
        response = requests.post(f'https://api.github.com/repos/{user.github_login}/{repo_name}/hooks', json=data, headers=headers)
        if response.status_code != 201:
            print(f"Failed to set up webhook for {repo_name}: {response.content}")
            return None
        hook_id = response.json()['id']

    # Check if repo exists
    repo = Repo.query.filter_by(github_id=repo_github_id).first()
    if not repo:
        # Create a new repo if it doesn't exist
        repo = Repo(name=repo_name, owner_github_login=user.github_login, github_id=repo_github_id, webhook_id=hook_id)
        db.session.add(repo)
    else:
        # if the repo exists, update the webhook id
        repo.webhook_id = hook_id

    user.tracked_repos.append(repo)
    db.session.commit()

    return hook_id 

