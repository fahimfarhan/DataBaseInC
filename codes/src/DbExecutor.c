#ifndef DB_EXECUTOR
#define DB_EXECUTOR

#include "CommonHeaders.c"
#include "DbStates.c"
#include "InputBuffer.c"
#include "Statement.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printPrompt() { printf("db > \n"); }

void readInput(InputBuffer *inputBuffer) {

  char **linePtr = &(inputBuffer->buffer);
  size_t *ptrToSizeOfAllocatedBuffer = &(inputBuffer->bufferLength);

  ssize_t bytesRead = getline(linePtr, ptrToSizeOfAllocatedBuffer, stdin);

  if (bytesRead <= 0) {
    printf("Error reading input\n");
    exit(EXIT_FAILURE);
  }
  // Ignore trailing newline
  inputBuffer->inputLength = bytesRead - 1;
  inputBuffer->buffer[bytesRead - 1] = 0;
}

void processInput(InputBuffer *inputBuffer) {
  if (inputBuffer->buffer[0] == '.') {
    // todo: process meta commands
  } else {
    // execute sql statement
  }
}

MetaCommandResult doMetaCommand(InputBuffer *inputBuffer) {
  if (strcmp(inputBuffer->buffer, ".exit") == 0) {
    closeInputBuffer(inputBuffer); // todo: needs further reorganization
    exit(EXIT_SUCCESS);
  } else {
    return META_COMMAND_UNRECOGNIZED_COMMAND;
  }
}

PrepareResult prepareStatement(InputBuffer *inputBuffer, Statement *statement) {
  if (strncmp(inputBuffer->buffer, "insert", 6) == 0) {
    statement->type = STATEMENT_INSERT;
    return PREPARE_SUCCESS;
  }

  if (strncmp(inputBuffer->buffer, "select", 6) == 0) {
    statement->type = STATEMENT_SELECT;
    return PREPARE_SUCCESS;
  }

  return PREPARE_UNRECOGNIZED_STATEMENT;
}

void executeStatement(Statement *statement) {
  switch (statement->type) {
  case STATEMENT_INSERT: {
    printf("todo: process insert command...\n");
    break;
  }
  case STATEMENT_SELECT: {
    printf("todo: process select command...\n");
    break;
  }
  default: {
    printf("did not match any of the statements!\n");
    break;
  }
  }
}
#endif /* !DB_EXECUTOR */
