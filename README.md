# Text-Editor
A simple, basic terminal-based text editor.

#### <u>Updates</u>:
- `printStack()` no longer prints `'\n'` after printing the stack elements
- `peek()` returns `'\0'` if stack is empty

#### <u>Known Issues (to work on)</u>:
- the cursor, even though is with the correct letter, is on the next line instead of the current line
    - basically, with current settings, nothing gets printed to the console unless `'\n'` is printed and when that is printed, the cursor moves to the next line..
- when return key is pressed, it does not move to the next line
