#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include "hash_table.h"

int main(void)
{
    struct HashTable *hash_table = InitializeHashTable(26);
    assert(hash_table != NULL);
    InsertToTable(hash_table,"shiva");
    InsertToTable(hash_table,"shankar");
    InsertToTable(hash_table,"param");
    InsertToTable(hash_table,"pavan");
    DisplayBasedOnIndex(hash_table,GenerateKey("p"));
    DisplayBasedOnIndex(hash_table,GenerateKey("s"));
    return 0;
}