# DSA + Memory Assignments for Jenny

Hey baby. This is where you can submit answers to your assignments. This is also where I will upload answers after the due dates. You'll be submitting your homework by making a pull request.

### Before anything:

- Fork this repository. You have to push solutions to your own fork and then make a pull request (PR). This is an industry standard way of handling projects with a large number of contributors.
- Clone your fork to your local machine (use ssh since we set up ssh keys a few days ago on call).

### To complete an assignment...

- Create a new branch with the naming convention `jenny/<assignment-name>`. You can use the following command to help you out: `git switch -c <branch-name>`. This will create a new branch. For more information on `git switch` please consult [the docs](https://git-scm.com/docs/git-switch).
- Solve the assignment (all necessary code, short answer questions, etc.). To save your progress at certain points, get into the habit of typing out the following commands: `git status`, `git add`, `git commit`, `git push`. _*A note about `git push`*_: The first time you try to push to a new branch, you'll need to set your upstream branch. Do this by typing in: `git push -u origin <branch-name>` the first time you push to a new branch. Every time after this you can just use `git push` and it will automatically work.
- Once you're done with the assignment _*and have pushed all changes to the fork you have on GitHub*_, you need to make a pull request (PR). This is easy to do in the GitHub UI. You can figure out how to do this or read the docs (or message me and I'll help you). I will merge your changes if you have answered everything correctly. If you haven't, I'll request changes in the PR, and you will need to correct your mistakes. Once everything is correct, I will merge your answers into `main`.

### Reporting Problems/Requesting Clarification

- To report problems (issues with questions) or request clarification on questions, please create a GitHub Issue. Again, this is simple to do on the GitHub UI but if you have issues, just call me and I'll help you out. I want you to use GitHub issues because it's important that in the future you understand how they work.

### License

- All non-code material (questions, solutions) are CC BY-NC-SA licensed
- All code is licensed under the MIT License.
