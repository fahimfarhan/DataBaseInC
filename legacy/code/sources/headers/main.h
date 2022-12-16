#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include "HelpingFunctions.h"
#include <stddef.h>

// keep the typedefs over here
typedef struct inputBuffer_t
{
  char* buffer;
  size_t buffer_length;
} InputBuffer;

typedef enum {
  STATEMENT_SELECT,
  STATEMENT_INSERT
}StatementType;

typedef struct _statement_t
{
  /* data */
  StatementType type;
}Statement;

typedef enum {
  PREPARE_SUCCESS,
  PREPARE_UNRECOGNIZED_STATEMENT
}PrepareResult;

typedef enum {
  STRING_TOKEN_MATCHED,
  STRING_TOKEN_UNMATCHED
} StringTokenResult;

// prepare metaCommand
typedef enum {
  PREPARE_METACOMMAND_SUCCESS,
  PREPARE_METACOMMAND_FAILURE
}PrepareMetaCommand;

// statement metacommand
typedef enum {
  METACOMMAND_EXIT,
  METACOMMAND_HELP,
} MetaCommandType;

typedef struct MetaCommand_t
{
  /* data */
  MetaCommandType type;
} MetaCommand;


#endif