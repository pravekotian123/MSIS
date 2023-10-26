#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hash_table.h"
#include "../linked_list/list.h"


struct HashTable * InitializeHashTable(int size)
{
    struct HashTable * hash_table = NULL;
    if(size > 0)
    {
        hash_table = (struct HashTable *)malloc(sizeof(struct HashTable));
        if(hash_table != NULL)
        {
            hash_table->table =(struct List *)malloc(sizeof(struct List)*size);
            if(hash_table->table != NULL)
            {
                hash_table->size = size;
                for(int i=0;i<size;i++)
                {
                    (hash_table->table + i)->head = NULL;
                }
            }
            else{
                 hash_table->size = 0;
            }
        }
    }
    return hash_table;
}


int GenerateKey(char *str)
{
    int return_value  = -1;
    if(str != NULL)
    {
        return_value = toupper(str[0]) - 'A';
    }
    return return_value;
}

int InsertStringAtPosition(struct HashTable *hash_table,int position,void *data_ptr,int size)
{
    int return_value = -1;
    if(hash_table != NULL)
    {
        InsertAtEnd(hash_table->table + position,data_ptr,size);
    }
    return return_value;
}
int InsertToTable(struct HashTable *hash_table,void *data_ptr)
{
    if((hash_table != NULL) && (data_ptr != NULL))
    {
        char *ptr = (char *)data_ptr;
        InsertStringAtPosition(hash_table,GenerateKey(ptr),ptr,sizeof(char *));
    }
}
int DisplayBasedOnIndex(struct HashTable *hash_table,int index)
{
    int return_value  = -1;
    char *ptr = NULL;
    if((hash_table != NULL) && (index >= 0))
    {
        int position = 0;
        do  {
            ptr = (char *)FetchDataByPosition(hash_table->table + index,position++);
            if(ptr != NULL)
               printf("%s ",ptr);
        }while(ptr!= NULL);
        printf("\n");
        return_value = 0;
    }
    return return_value;
}
