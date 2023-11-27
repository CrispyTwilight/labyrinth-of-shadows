# Naming Conventions
These are the GitHub naming conventions used within the project.

## For Branches
Always edit in a branch. DO NOT try to commit to the main branch. The settings of the repo will not allow it.<br>
A branch name should start with a category

- feature is for adding/removing/changing a feature
- bugfix is for fixing a bug
- test is for experimenting
- docs is for adding/removing/changing documentation

Most often, we will use feature branches. Follow with a backlash, then write a short hyphen separated description.

Example:
```
feature/add-validateInt-function
```

## For Commits
A commit message should start with the category of change
- feat is for adding a new feature
- fix is for fixing a bug
- refactor is for changing code for performance or convenience purpose
- chore is for everything else (writing documentation, formatting, adding tests, cleaning useless code etc.)

Then add a colon (:) and a short imperative, present tense, ie "change" not "changed" nor "changes", then a brief message. You can also add a longer description as needed.

Example:

```
feat: add new integer validation function.
```
