#include "InputBuffer.c"
#include "common_headers.h"
#include "utils.c"

int main(int argc, char *argv[]) {
  InputBuffer *inputBuffer = newInputBuffer();
  printf("Database from scratch v0.0.1\n");
  while (1) {
    printPrompt();
    readInput(inputBuffer);
    if (strcmp(inputBuffer->buffer, ".exit") == 0) {
      closeInputBuffer(inputBuffer);
      exit(EXIT_SUCCESS);
    } else {
      printf("Unrecognized command '%s'.\n", inputBuffer->buffer);
    }
  }
  return 0;
}
