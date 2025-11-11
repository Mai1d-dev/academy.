# Submission Instructions

Use this generic workflow for all lectures/assignments. Replace placeholders with your own details.

## Fork the Repository

- Navigate to the repository on [GitHub](https://github.com/funky-bois/academy).
- Click the "Fork" button in the top-right corner of the page.
- Select your GitHub account as the destination for the fork.
- Wait for GitHub to create your fork (this takes a few seconds).
- Clone your forked repository to your local machine:

```bash
git clone https://github.com/your-username/academy.git
cd repository-name
```

## Branch Naming

- Create a new branch for each lecture.
- Format: name-surname/lectureN
  - Examples:
    - john-doe/lecture1
    - jane-smith/lecture3

```bash
git checkout -b name-surname/lectureN
```

## Directory Structure

- Inside the repository root, create a folder for the lecture:
  - lectureN/
- Inside lectureN/, create a directory with your name to avoid conflicts:
  - lectureN/name-surname/
- Put all your files for that lecture inside your personal directory.

Example:
- lecture1/john-doe/mario.c
- lecture1/john-doe/README.md

```bash
mkdir -p lectureN/name-surname
# move or create your files inside lectureN/name-surname
git add lectureN/name-surname
git commit -m "Add lectureN submission for name-surname"
```

## Push Your Branch

```bash
git push -u origin name-surname/lectureN
```

## Open a Pull Request (PR)

- Base: main (or the repository’s default branch)
- Compare: name-surname/lectureN
- Title: lectureN: name-surname
- Description: Briefly list what you added and any notes for reviewers

## Assign Reviewers

- Assign Meho and Selmir to the PR.

## Updates After Review

- Address feedback by committing to the same branch:
```bash
# make changes
git add .
git commit -m "Address review feedback"
git push
```

## Notes

- Replace all occurrences of name-surname and lectureN with your actual name and lecture number.
- Keep unrelated files out of your lectureN/name-surname directory.
- If the lecture includes multiple tasks, create subfolders under lectureN/name-surname as needed.
