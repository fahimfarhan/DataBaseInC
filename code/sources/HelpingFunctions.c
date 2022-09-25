
#ifndef HELPING_FUNC_INC
#define HELPING_FUNC_INC

#include "headers/HelpingFunctions.h"
#include "headers/main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#define MAJOR_VERSION 0
#define MINOR_VERSION 1

void printStartingCommand() {
  printf("Welcome to my awesome sqlite %d %d\n", MAJOR_VERSION, MINOR_VERSION);
}

void printPrompt() {
  printf("SQLITE>>");
}

InputBuffer* newInputBuffer() {
  InputBuffer* inputBuffer = malloc(sizeof(InputBuffer));
  inputBuffer->buffer = NULL;
  inputBuffer->buffer_length = 0;
  return inputBuffer;
}

void readInput(InputBuffer* inputBuffer) {
  // getline(&inputBuffer->buffer);

  /**
   * What is the difference between, (&inputBuffer->buffer) and &(inputBuffer->buffer) ?
   * &(inputBuffer->buffer) is the correct one, cz (input->buffer) gives the address, so &(address) gives me whatever is in that address.
   * (&inputBuffer)->buffer will give error 
   */
  
  size_t bytes_read = getline(&(inputBuffer->buffer), &(inputBuffer->buffer_length), stdin);
  if(bytes_read <= 0) {
    printf("Error reading\r\n");
    exit(EXIT_FAILURE);
  }
}


StringTokenResult isToken(char* buffer, char* token) {
  if(strncmp(buffer, token, strlen(token) == 0)) {
    return STRING_TOKEN_MATCHED;
  } else {
    return STRING_TOKEN_UNMATCHED;
  }
}

PrepareResult prepareResult(InputBuffer* inputBuffer, Statement* Statement) {
  // if(strncmp(inputBuffer->buffer, "SELECT", 6) == 0) {
  fprintf(stderr, "inputBuffer = %s, sizeOfSelect = %ld\n", inputBuffer->buffer, strlen("SELECT"));
  if(strncmp(inputBuffer->buffer, "SELECT", strlen("SELECT")) == 0) {
    Statement->type = STATEMENT_SELECT;
  } else if( strncmp(inputBuffer->buffer, "INSERT", strlen("INSERT")) == 0 ) {
    Statement->type = STATEMENT_INSERT;
  } else {
    return PREPARE_UNRECOGNIZED_STATEMENT;
  }
  return PREPARE_SUCCESS;
}

PrepareMetaCommand prepareMetaCommand(InputBuffer* inputBuffer, MetaCommand* metaCommand) { 
  // int isZero = strncmp(inputBuffer->buffer, ".EXIT", strlen(".EXIT"));
  // fprintf(stderr, "inputBuffer = %s, sizeOfSelect = %ld, isZero = %d\n", inputBuffer->buffer, strlen(".EXIT"), isZero);
  
  if( strncmp(inputBuffer->buffer, ".EXIT", strlen(".EXIT")) == 0) {
     metaCommand->type = METACOMMAND_EXIT;
  } else {
    return PREPARE_UNRECOGNIZED_STATEMENT;
  }
  return PREPARE_SUCCESS;
}

#endif