#ifndef UTILITIES
#define UTILITIES

#include "InputBuffer.c"
#include "common_headers.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

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

#endif /* !UTILITIESUTILITIES */
