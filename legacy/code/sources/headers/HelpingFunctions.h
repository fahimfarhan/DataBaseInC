#ifndef HELPING_FUNC_H
#define HELPING_FUNC_H
#include "main.h"

void printStartingCommand();
void printPrompt();
InputBuffer* newInputBuffer();
void readInput(InputBuffer* InputBuffer);
PrepareResult prepareResult(InputBuffer* inputBuffer, Statement* Statement);
PrepareMetaCommand prepareMetaCommand(InputBuffer* inputBuffer, MetaCommand* MetaCommand);

#endif