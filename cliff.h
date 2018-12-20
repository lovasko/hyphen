// Copyright (c) 2018 Daniel Lovasko.
// All Rights Reserved
//
// Distributed under the terms of the 2-clause BSD License. The full
// license is in the file LICENSE, distributed as part of this software.

#include <stdlib.h>
#include <stdint.h>


/// Command-line interface.
typedef struct cliff cliff;

/// Create and (possibly) attach a new command.
int cliff_cmd(
  cliff* cli,          ///< Command-line interface.
  uint64_t* cid,       ///< New returned command ID.
  const uint64_t pcid, ///< Parent command ID to attach to (0 for no parent).
  const char* name,    ///< Name.
  void* ptr,           ///< Storage pointer.
  const size_t size    ///< Storage size.
  const char* help,    ///< Usage help text.
);

/// Create and attach a new option.
int cliff_opt(
  cliff* cli,          ///< Command-line interface.
  const uint64_t cid,  ///< Command ID to attach to.
  const char shtn,     ///< Short name (\0 for no short name).
  const char* lngn,    ///< Long name (NULL for no long name).
  const char* mvar,    ///< Meta variable name.
  const uint64_t rmin, ///< Minimal number of repeats.
  const uint64_t rmax, ///< Maximal number of repeats.
  const char* help     ///< Usage help text.
);

/// Create and attach a new flag.
int cliff_flg(
  cliff* cli,          ///< Command-line interface.
  const uint64_t cid,  ///< Command ID to attach to.
  const char shtn,     ///< Short name (\0 for no short name).
  const char* lngn,    ///< Long name (NULL for no long name).
  const uint64_t rmin, ///< Minimal number of repeats.
  const uint64_t rmax, ///< Maximal number of repeats.
  const char* help     ///< Usage help text.
);

/// Create and attach a new argument.
int cliff_arg(
  cliff* cli,          ///< Command-line interface.
  const uint64_t cid,  ///< Command ID to attach to.
  const char* name,    ///< Name.
  const uint64_t cnt,  ///< Number of repeats (UINT64_MAX for all remaining).
  const char* help     ///< Usage help text.
);

/// Skip a number of bytes in the storage structure.
int cliff_pad(
  cliff* cli,          ///< Command-line interface.
  const uint64_t cid,  ///< Command ID.
  const size_t size    ///< Number of bytes to skip.
);

/// Parse the command-line arguments. This function frees all memory allocated
/// the build functions.
int cliff_run(
  cliff* cli,          ///< Command-line interface.
  const uint64_t rcid, ///< Root command ID (name used as program name).
  const int argc,      ///< Argument count.
  const char* argv[],  ///< Argument vector.
  uint64_t* scid       ///< Selected command ID.
);

/// Convert an error code to an English description.
void cliff_err(
  cliff* cli,         ///< Command-line interface.
  const int code,     ///< Function return/error code.
  const char** estr   ///< English description.
);