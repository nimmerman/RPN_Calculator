RPN_Calculator
==============
RPN Calculator
The first application you must write is a simple Reverse-Polish Notation calculator. An RPN calculator is one in which the operators appear after their respective operands, rather than in between them. So, instead of computing the following:
(2 + 3) * 5
an RPN calculator would compute this equivalent expression:
23+5*
RPN notation is convenient for several reasons. First, no parentheses are necessary since the computation is always unambiguous. Second, such a calculator is easy to implement given a stack. This is particularly useful, because it is possible to use the Dlist as a stack.
The calculator is invoked with no arguments, and starts out with an empty stack. It takes its input from the standard input stream, and writes its output to the standard output stream. Here are the commands your calculator must respond to and what you must do for each:
<some number> a number has the form: one or more digits [0 – 9] optionally followed by a decimal point and one or more digits. For example, 3 4.56 and 0.12 are all numbers,
but -2, a123, and abc are not. A number, when entered, is pushed on the stack. This input is always valid.
+ pop the top two numbers off the stack, add them together, and push the result onto the top of the stack. This requires a stack with at least two operands.
- pop the top two numbers off the stack, subtract the first number from the second, and push the result onto the top of the stack. This requires a stack with at least two operands.
* pop the top two numbers off the stack, multiply them together, and push the result onto the top of the stack. This requires a stack with at least two operands.
/ pop the top two numbers off the stack, divide the second popped number by the first, and push the result onto the top of the stack. This requires a stack with at least two operands.
n negate: pop the top item off the stack, multiply it by -1, and push the result onto the top of the stack. This requires a stack with at least one operand.
d duplicate: pop the top item off the stack and push two copies of the number onto the top of the stack. This requires a stack with at least one operand.
r reverse: pop the top two items off the stack, push the first popped item onto the top of the stack and then the push the second item onto the top of the stack (this just reverses the order of the top two items on the stack). This requires a stack with at least two operands.
p print: print the top item on the stack to the standard output, followed by a newline. This requires a stack with at least one operand and leaves the stack unchanged.
￼
c clear: pop all items from the stack. This input is always valid.
a print-all: print all items on the stack in one line, from top-most to bottom-most, each separated by a single space. The end of the output must be followed by a single space and a newline. This input is always valid and leaves the stack unchanged.
q quit: exit the calculator. This input is always valid.
Each command is separated by whitespace. You may not assume that user input is always correct. There are three error messages to report:
1. If a user enters something other than one of the commands above, leave the stack unchanged, advance to the next whitespace character, and print the following message:
     cout << "Bad input\n";
2. If a user enters a command that requires more operands than are present, leave the stack unchanged, advance to the next whitespace character, and print the following message:
     cout << "Not enough operands\n";
3. If a user enters the divide command with a zero on the top of the stack, leave the stack unchanged, advance to the next whitespace character, and print the following message:
     cout << "Divide by zero\n";
Note that the phrase "leave the stack unchanged" is not to be taken literally. It is okay to pop the top two operands off the stack for testing and, if there are any problems, push them back onto the stack (in the proper order) before reading the next command. You may assume that the user will not type End- of-File (EOF) before quitting. Here is a short example:
     2
     3
     4
     +
     *
     p
     14
     +
     Not enough operands
     d
+ p 28 2 - p 26 q
