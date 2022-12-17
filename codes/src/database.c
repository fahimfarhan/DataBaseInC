#include "CommonHeaders.c"
#include "DbExecutor.c"
#include "DbStates.c"
#include "InputBuffer.c"
#include <stdio.h>

int main(int argc, char *argv[]) {
  InputBuffer *inputBuffer = newInputBuffer();
  printf("Database from scratch v0.0.1\n");
  while (1) {
    printPrompt();
    readInput(inputBuffer);

    // handle metacommands
    if (inputBuffer->buffer[0] == '.') {
      MetaCommandResult mcr = doMetaCommand(inputBuffer);
      if (mcr == META_COMMAND_SUCCESS) {
        continue; // instead of a top level else branch, use continue for ease
                  // of readibility...
      } else if (mcr == META_COMMAND_UNRECOGNIZED_COMMAND) {
        printf("Unrecognized command '%s'\n", inputBuffer->buffer);
        continue; // instead of a top level else branch, use continue for ease
                  // of readibility...
      }
    }

    // handle sql queries...
    Statement statement;
    PrepareResult pr = prepareStatement(inputBuffer, &statement);

    switch (pr) {
    case PREPARE_SUCCESS:
      break;
    case PREPARE_UNRECOGNIZED_STATEMENT:
      printf("Unrecognized keyword at start of '%s'.\n", inputBuffer->buffer);
      continue; // so don't proceed
    }

    // code comes here. this means the statement was prepared successfully
    // time to execute the statement
    executeStatement(&statement);
    printf("Executed\n");
  }
  return 0;
}
