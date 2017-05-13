/*
 * Copyright (c) 2017 Arif Nur Khoirudin
 *
 * mail : <hello@arifnurkhoirudin.com>
 * site : https://arifnurkhoirudin.com
 *
 * Don't redistribute or copying without owner permission
*/

#ifndef __db_H__
#define __db_H__

#include "commons.h"

#define DBNAME                "testdb"

#define MAX_KEY_LEN           256
#define MAX_VAL_LEN           1024*32

#define DB_SUCCESS        0
#define DB_GENERAL_ERROR  1
#define DB_WRITE_ERROR    2
#define DB_READ_ERROR     3
#define DB_DELETE_ERROR   4
#define DB_UPDATE_ERROR   5
#define DB_DESTROY_ERROR  6

#ifdef __cplusplus
extern "C" {
#endif

struct db_t{
  leveldb_t *db;
  leveldb_options_t *options;
  leveldb_readoptions_t *roptions;
  leveldb_writeoptions_t *woptions;
  size_t vallen;
  char* lastError;
};
typedef struct db_t db_t;


int
db_init(db_t* db);

int
db_write(db_t* db, const char* key,
             uint32_t keylen, const char* val, uint32_t vallen);

int
db_read(db_t* db, const char* key,
            uint32_t keylen, char** val);

int
db_delete(db_t* db, const char* key, uint32_t keylen);

void
db_free(db_t* db);

int
db_destroy(db_t* db);


#ifdef __cplusplus
}
#endif

#endif /* __db_H__ */
