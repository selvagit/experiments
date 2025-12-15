# Git Commit Rules

This project uses **Husky** for git hooks and **commitlint** to enforce conventional commit messages. These tools help maintain code quality and consistency across the project.

## Setup

The git commit rules are automatically configured. When you install dependencies with `npm install`, Husky will set up the git hooks.

## Commit Message Format

All commits must follow the **Conventional Commits** specification:

```
<type>(<scope>): <subject>

<body>

<footer>
```

### Type

Must be one of the following:

- **feat**: A new feature
- **fix**: A bug fix
- **docs**: Documentation only changes
- **style**: Changes that do not affect the meaning of the code (formatting, missing semicolons, etc.)
- **refactor**: A code change that neither fixes a bug nor adds a feature
- **perf**: A code change that improves performance
- **test**: Adding missing tests or correcting existing tests
- **chore**: Changes to the build process, dependencies, or other tooling
- **ci**: Changes to CI/CD configuration
- **revert**: Reverts a previous commit

### Scope (Optional)

A scope may be provided to specify the section of the codebase that the commit addresses. Examples:
- `components`
- `api`
- `styles`
- `types`

### Subject

- Use the imperative mood ("add" not "added" or "adds")
- Do not capitalize the first letter
- Do not use a period (.) at the end
- Maximum 100 characters
- Examples:
  - `feat(components): add dark mode toggle`
  - `fix(api): resolve authentication issue`
  - `docs: update installation instructions`

### Body (Optional)

- Wrap at 100 characters
- Explain what and why, not how
- Be specific about what changed and why

### Footer (Optional)

- Reference issue tickets: `Closes #123`, `Fixes #456`
- Breaking changes: `BREAKING CHANGE: description`

## Examples

### Simple Feature
```
feat(button): add loading state animation
```

### Bug Fix with Scope
```
fix(auth): resolve token expiration handling
```

### Documentation Update
```
docs: update contributing guidelines
```

### Complex Commit with Body
```
feat(modal): add form validation in dialog

Implement client-side validation for form fields within
the modal component. This prevents unnecessary API calls
for invalid data and improves user feedback.

Closes #123
```

### Breaking Change
```
feat(api): redesign authentication endpoints

BREAKING CHANGE: Authentication endpoint paths have changed
from /api/auth/* to /api/v2/auth/*
```

## Hooks Enabled

### pre-commit
- Runs **eslint** and **prettier** on staged files
- Only TypeScript, JavaScript, JSON, and Markdown files are processed
- Fixes auto-fixable issues automatically

### commit-msg
- Validates commit message format using **commitlint**
- Rejects commits with invalid messages
- Provides helpful error messages

## Bypassing Hooks (Not Recommended)

If you need to bypass the hooks for a specific commit:

```bash
git commit --no-verify
```

**Note**: This should only be used in exceptional circumstances.

## Troubleshooting

### Commit is rejected for invalid message format

Ensure your commit message follows the format:
```
<type>(<scope>): <subject>
```

Valid types: `feat`, `fix`, `docs`, `style`, `refactor`, `perf`, `test`, `chore`, `ci`, `revert`

### Pre-commit hook fails

The linting checks may have found issues. You can:

1. **Auto-fix issues**: 
   ```bash
   npm run lint -- --fix
   npx prettier --write .
   ```

2. **Stage the fixed files** and commit again:
   ```bash
   git add .
   git commit -m "your message"
   ```

### Husky not working after clone

Make sure to install dependencies:
```bash
npm install
```

The `prepare` script in package.json will automatically set up Husky.

## Configuration Files

- **commitlint.config.js**: Rules for commit message validation
- **.prettierrc**: Code formatting rules
- **.husky/commit-msg**: Git hook for commit message validation
- **.husky/pre-commit**: Git hook for linting and formatting
- **package.json**: Contains `lint-staged` configuration

## References

- [Conventional Commits](https://www.conventionalcommits.org/)
- [Husky Documentation](https://typicode.github.io/husky/)
- [Commitlint Documentation](https://commitlint.js.org/)
- [Prettier Documentation](https://prettier.io/)
