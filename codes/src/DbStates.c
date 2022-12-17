#ifndef DB_STATES
#define DB_STATES

typedef enum {
  META_COMMAND_SUCCESS,             // .exit, .help, etc
  META_COMMAND_UNRECOGNIZED_COMMAND // .foo, .bar
} MetaCommandResult;

typedef enum {
  PREPARE_SUCCESS,               // insert, update, join, etc
  PREPARE_UNRECOGNIZED_STATEMENT // idk, maybe an invalid sql statement such as
                                 // 1ns3rt...
} PrepareResult;

typedef enum {
  STATEMENT_INSERT,
  STATEMENT_SELECT
  // probably we'll add more, eg, statement_delete, statement_join, etc
} StatementType;

#endif /* !DB_STATES */
