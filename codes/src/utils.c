#ifndef UTILITIES
#define UTILITIES

#include "CommonHeaders.c"
#include "InputBuffer.c"

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

#endif /* !UTILITIESUTILITIES */
