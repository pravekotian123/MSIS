#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_


struct HashTable {
    struct List *table;
    int size;
};

struct HashTable *InitializeHashTable(int size);
int GenerateKey(char *str);
int InsertStringAtPosition(struct HashTable *,int position,void *data_ptr,int size);
int DisplayBasedOnIndex(struct HashTable *hash_table,int index);
int InsertToTable(struct HashTable *hash_table,void *data_ptr);
#endif