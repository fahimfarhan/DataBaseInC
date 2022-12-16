# Class 2

Create a simple `sqlite3_class_2.db` file, and play around (create table, insert, and select).

```sqlite3
CREATE TABLE users(id INTEGER, name TEXT);
INSERT INTO users VALUES (1, "Shimanto");
SELECT * FROM users;
```

We'll try to develop some structure in c that can be used to to implement these features.

In your terminal, if you type `sqlite3`, you'll get,

```bash
(base) soumic@Zephyrus-G14:~/Codes/poridhi_io/database_in_c/class_2$ sqlite3
SQLite version 3.32.2 2021-07-12 15:00:17
Enter ".help" for usage hints.
Connected to a transient in-memory database.
Use ".open FILENAME" to reopen on a persistent database.
sqlite> 
```

So, we'll print these stuffs first.

```c
#define MAJOR_VERSION 0
#define MINOR_VERSION 1

void printStartingCommand() {
  printf("Welcome to my awesome sqlite %d %d\n", MAJOR_VERSION, MINOR_VERSION);
  printf("SQLITE>>");
}

```

This will only print the lines, and exit. So, we'll have an infinite loop, that will take a buffer input, and by comparing the commands, we'll do the next thing.

To keep things clear, we'll create a header file, and write our code in it.

In c, we can use getline function to read buffer [See details](https://linuxhint.com/getline-function-c/).

```c
size_t getline (char **string, size_t *n, FILE *stream);
```

We create some header files, and reorganize the codes for convenience. We create a struct to hold some values:

```c

typedef struct inputBuffer_t
{
  char* buffer;
  size_t buffer_length;
} InputBuffer;

```

 What is the difference between, (&inputBuffer->buffer) and &(inputBuffer->buffer) ?
&(inputBuffer->buffer) is the correct one, cz (input->buffer) gives the address, so &(address) gives me whatever is in that address.
(&inputBuffer)->buffer will give error.

## Quesion: What is the difference between sizeof and strlen

```c
char* a = "abcde";
char b[50] = "abcde";

int sizeOfA = sizeof(a);  // 6, cz last e terminating character \0 soho se calculate kore
int sizeOfB = sizeof(b);  // 50

int strLenA = strlen(a);  // 5
int strLenB = strlen(b);  // 5

```

## What is cyclomatic complexity?

1:04 to be continued...

## Print in stderr

```c
  fprintf(stderr, "inputBuffer = %s, sizeOfSelect = %ld\n", inputBuffer->buffer, sizeof("SELECT"));
```

HW: complete meta commands.

```c
  RET_TYPE prepareMetaCommand(input);
```

Next class we'll create a table, and when we'll implement search, we'll be using b tree etc.
