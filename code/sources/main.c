
#include <stdio.h>
#include <stdlib.h>
#include "./headers/HelpingFunctions.h"
#include "./HelpingFunctions.c"


int main() {
  printStartingCommand();
  InputBuffer* inputBuffer = NULL;

  inputBuffer = newInputBuffer();

  while (1)
  {
    /* code */
    printPrompt();
    readInput(inputBuffer);

    if(inputBuffer->buffer[0] == '.') {
      // execute meta commands
      printf("Execute meta commands\n");  // things like .open, .exit, .quit, etc
      MetaCommand MetaCommand;
      // PrepareMetaCommand preparemetaCommand = prepareMetaCommand(inputBuffer, &MetaCommand);
      switch (prepareMetaCommand(inputBuffer, &MetaCommand)) {
      case PREPARE_METACOMMAND_SUCCESS: {
        printf("MetaCommand preperation is successful.\n");
        if(MetaCommand.type == METACOMMAND_EXIT) {
          exit(EXIT_SUCCESS);
        }
        break;
      }    

      case PREPARE_METACOMMAND_FAILURE: {
        printf("MetaCommand preperation failed.\n");
        break;      
      }

      default:
        break;
      }

      continue;
    }
    // parse statement, and execute
    Statement statement;
    switch (prepareResult(inputBuffer, &statement))
    {
    case PREPARE_SUCCESS:
      /* code */
      printf("Preperation is successful.\n");
      break;
    case PREPARE_UNRECOGNIZED_STATEMENT:
      printf("Unrecognized statement.\n");
      // break;
      continue; // switch er moddhe for loop er continue, interesting...  
    default:
      break;
    }
    // execute_statement(statement);
    printf("Executed\n");
  }
  

  return 0;
}