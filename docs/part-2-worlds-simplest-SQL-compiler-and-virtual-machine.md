# Part 2: World's Simplest SQL Compiler and Virtual Machine
The sqlite frontend parses the input, and creates an internal representation called bytecode. This bytecode is passed to the virtual machine, which then executes it.

Breaking into 2 separate steps has some advantages:
 
* reduces complexity of each part (e.g. virtual machine does not worry about syntax errors),
* Allows compiling common queries once and caching the bytecode for improved performance 

Non-SQL statements like .exit are called “meta-commands”. They all start with a dot, so we check for them and handle them in a separate function.

Next, we add a step that converts the line of input into our internal representation of a statement. This is our hacky version of the sqlite front-end.

Lastly, we pass the prepared statement to execute_statement. This function will eventually become our virtual machine.

We'll add more enums as we progress through the tutorial.

`doMetaCommand` is just a wrapper for existing functionality that leaves room for more commands.

Currently prepare statement enum has 2 values, insert, and select.

We also have a wrapper method named `executeStatement(...)`. Now the skeleton of our code has changed.