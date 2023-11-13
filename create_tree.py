import os,time
from datetime import datetime, timedelta
from git import Repo, GitCommandError

# Path to your repository (adjust to your actual repo path)
repo_path = '/Users/ahtavarasmus/cp'

# Initialize the repo object
repo = Repo(repo_path)

# Make sure we are on the master branch
master_branch = 'master'
repo.git.checkout(master_branch)

second_count = 0

# Function to create commits
def create_commit(branch_name, file_name, content,timestamp):
    # Create or update a file
    full_path = os.path.join(repo_path, file_name)
    with open(full_path, 'w') as file:
        file.write(content + '\n')
    # Add file to staging and commit the change
    repo.index.add([full_path])
    repo.index.commit(f'Update {file_name} on {branch_name}', author_date=timestamp, commit_date=timestamp)

def safe_create_branch(branch_name, base_branch='master'):
    try:
        if branch_name in (head.name for head in repo.heads):
            # Checkout a different branch before deleting the current one
            repo.git.checkout(base_branch)
            repo.git.branch('-D', branch_name)
        # Create a new branch from the base branch
        repo.git.checkout(base_branch)
        repo.git.checkout('-b', branch_name)
    except GitCommandError as e:
        print(f"Git command error: {e}")

# Function to create branches and commits
def create_branches_and_commits(branch_name, num_commits, parent_branch, second_count, merge=False):
    safe_create_branch(branch_name, parent_branch)
    
    # Create a number of commits on the branch
    for i in range(num_commits):
        file_name = f'{branch_name}_file_{i}.txt'
        timestamp = (datetime.now() + timedelta(seconds=int(second_count))).replace(microsecond=0).isoformat()
        print(f'Creating commit {i} on {branch_name} at {timestamp}')
        second_count += 10 
        print(f"adding 10 seconds to second_count: {second_count}")
        create_commit(branch_name, file_name, f'Content for {branch_name} commit {i}', timestamp)
    
    second_count += 20
    # Merge this branch back into the parent if specified
    if merge:
        repo.git.checkout(parent_branch)
        repo.git.merge(branch_name, '--no-ff', '-m', f'Merge {branch_name} into {parent_branch}')
    return second_count+12

second_count = 0
# Create a complex tree structure
second_count = create_branches_and_commits('feature1', 3, master_branch, second_count=second_count, merge=True)
print(f"second_count: {second_count}")
second_count += 12
second_count = create_branches_and_commits('feature2', 2, master_branch, second_count=second_count)
print(f"second_count: {second_count}")
second_count += 12
second_count = create_branches_and_commits('subfeature2.1', 1, 'feature2',second_count=second_count, merge=True)
print(f"second_count: {second_count}")
second_count += 12
second_count = create_branches_and_commits('subfeature2.2', 1, 'feature2', second_count=second_count)
print(f"second_count: {second_count}")
second_count += 12
repo.git.checkout('feature2')
repo.git.merge('subfeature2.2', '--no-ff', '-m', 'Merge subfeature2.2 into feature2')
print(f"second_count: {second_count}")
second_count += 12

second_count = create_branches_and_commits('feature3', 4, master_branch, second_count=second_count, merge=True)
print(f"second_count: {second_count}")
second_count += 12

# Now let's create some parallel work on feature1 and feature3
second_count = create_branches_and_commits('parallel1', 2, 'feature1', second_count=second_count)
print(f"second_count: {second_count}")
second_count += 12
second_count = create_branches_and_commits('parallel2', 2, 'feature3', second_count=second_count)
print(f"second_count: {second_count}")

# Merge everything back into master
repo.git.checkout(master_branch)
second_count += 12
repo.git.merge('feature1', '--no-ff', '-m', 'Merge feature1 into master')
print(f"second_count: {second_count}")
second_count += 12
repo.git.merge('feature2', '--no-ff', '-m', 'Merge feature2 into master')
print(f"second_count: {second_count}")
second_count += 12
repo.git.merge('feature3', '--no-ff', '-m', 'Merge feature3 into master')
print(f"second_count: {second_count}")
second_count += 12


