#!/bin/bash

# Path to your repository
repo_path="/Users/ahtavarasmus/cp"
cd "$repo_path"

# Ensure we're on the master branch
master_branch="master"
git checkout "$master_branch"

# Function to create commits
create_commit() {
    branch_name=$1
    file_name=$2
    content=$3
    timestamp=$4

    # Create or update a file
    echo "$content" > "$file_name"
    # Add file to staging and commit the change
    GIT_AUTHOR_DATE="$timestamp" GIT_COMMITTER_DATE="$timestamp" git commit -a -m "Update $file_name on $branch_name"
}

# Function to safely create branches
safe_create_branch() {
    branch_name=$1
    base_branch=$2

    # Delete the branch if it exists
    if git show-ref --verify --quiet "refs/heads/$branch_name"; then
        git checkout "$base_branch"
        git branch -D "$branch_name"
    fi

    # Create a new branch from the base branch
    git checkout "$base_branch"
    git checkout -b "$branch_name"
}

# Function to create branches and commits with unique timestamps
create_branches_and_commits() {
    branch_name=$1
    num_commits=$2
    parent_branch=$3
    second_count=$4
    merge=$5
    last_timestamp=""

    safe_create_branch "$branch_name" "$parent_branch"
    
    # Create a number of commits on the branch
    for ((i=0; i<num_commits; i++)); do
        file_name="${branch_name}_file_${i}.txt"
        
        # Generate a new timestamp and ensure it is unique by comparing with the last one
        new_timestamp=$(date -v+"$second_count"S +"%FT%T")
        if [[ "$new_timestamp" == "$last_timestamp" ]]; then
            # Increment the second count if the timestamp is not unique
            ((second_count++))
            new_timestamp=$(date -v+"$second_count"S +"%FT%T")
        fi
        last_timestamp=$new_timestamp
        
        create_commit "$branch_name" "$file_name" "Content for $branch_name commit $i" "$new_timestamp"
        ((second_count+=10))
    done

    # Merge this branch back into the parent if specified
    if [ "$merge" = "true" ]; then
        git checkout "$parent_branch"
        
        # Generate a new timestamp for the merge and ensure it is unique
        merge_timestamp=$(date -v+"$second_count"S +"%FT%T")
        if [[ "$merge_timestamp" == "$last_timestamp" ]]; then
            # Increment the second count if the timestamp is not unique
            ((second_count++))
            merge_timestamp=$(date -v+"$second_count"S +"%FT%T")
        fi
        last_timestamp=$merge_timestamp
        
        GIT_AUTHOR_DATE="$merge_timestamp" GIT_COMMITTER_DATE="$merge_timestamp" git merge --no-ff -m "Merge $branch_name into $parent_branch" "$branch_name"
    fi

    echo $((second_count+1)) # Increment to ensure unique timestamp for next operation
}



# Reset second_count to current time in seconds since 1970-01-01 00:00:00 UTC
second_count=$(date +%s)

# Use the functions to create branches and commits as before...

# Create a complex tree structure
second_count=$(create_branches_and_commits 'feature1' 3 "$master_branch" "$second_count" "true")
second_count=$(create_branches_and_commits 'feature2' 2 "$master_branch" "$second_count" "false")
second_count=$(create_branches_and_commits 'subfeature2.1' 1 'feature2' "$second_count" "true")
second_count=$(create_branches_and_commits 'subfeature2.2' 1 'feature2' "$second_count" "false")

git checkout 'feature2'
second_count=$(date -v+"$second_count"S +"%FT%T")
GIT_AUTHOR_DATE="$second_count" GIT_COMMITTER_DATE="$second_count" git merge --no-ff -m "Merge subfeature2.2 into feature2" 'subfeature2.2'

second_count=$(create_branches_and_commits 'feature3' 4 "$master_branch" "$second_count" "true")

# Now let's create some parallel work on feature1 and feature3
second_count=$(create_branches_and_commits 'parallel1' 2 'feature1' "$second_count" "false")
second_count=$(create_branches_and_commits 'parallel2' 2 'feature3' "$second_count" "false")

# Merge everything back into master
git checkout "$master_branch"
second_count=$(date -v+"$second_count"S +"%FT%T")
GIT_AUTHOR_DATE="$second_count" GIT_COMMITTER_DATE="$second_count" git merge --no-ff -m "Merge feature1 into master" 'feature1'
second_count=$(date -v+"$second_count"S +"%FT%T")
GIT_AUTHOR_DATE="$second_count" GIT_COMMITTER_DATE="$second_count" git merge --no-ff -m "Merge feature2 into master" 'feature2'
second_count=$(date -v+"$second_count"S +"%FT%T")
GIT_AUTHOR_DATE="$second_count" GIT_COMMITTER_DATE="$second_count" git merge --no-ff -m "Merge feature3 into master" 'feature3'

