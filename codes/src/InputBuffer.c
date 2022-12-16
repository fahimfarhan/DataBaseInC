#ifndef INPUT_BUFFER
#define INPUT_BUFFER

#include "common_headers.h"

typedef struct {
  char *buffer;
  size_t bufferLength;
  ssize_t inputLength;
} InputBuffer;

InputBuffer *newInputBuffer() {
  InputBuffer *inputBuffer = (InputBuffer *)malloc(sizeof(InputBuffer));

  inputBuffer->buffer = NULL;
  inputBuffer->bufferLength = 0;
  inputBuffer->inputLength = 0;

  return inputBuffer;
}

void closeInputBuffer(InputBuffer *inputBuffer) {
  if (inputBuffer != NULL) {
    if (inputBuffer->buffer != NULL) {
      free(inputBuffer->buffer);
    }
    free(inputBuffer);
  }
}

#endif
