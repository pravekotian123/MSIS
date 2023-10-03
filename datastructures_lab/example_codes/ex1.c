#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "ex1_list.h"
#include "history.h"

int InsertEntry(struct HistorySave *history,struct LinkedList * my_list,  struct Student data);
int DeleteEntry(struct HistorySave *history,struct LinkedList * my_list);
int SearchEntryByName(struct HistorySave *history,struct LinkedList *my_list,char *name);

int main(void)
{
    struct LinkedList *student_list = InitializeList();
    struct HistorySave *history = InitializeHistorySave();
    assert(student_list != NULL);
    assert(history != NULL);
    assert(InsertEntry(history,student_list,(struct Student){"Hope",10}) == 0);
    assert(InsertEntry(history,student_list,(struct Student){"Raza",7}) == 0);
    assert(InsertEntry(history,student_list,(struct Student){"Bhuvi",1}) == 0);
    assert(InsertEntry(history,student_list,(struct Student){"deSilva",8}) == 0);
    assert(DeleteEntry(history,student_list) == 0);
    assert(SearchEntryByName(history,student_list,"Bhuvi") == 0);
    assert(SearchEntryByName(history,student_list,"Hope") == -1);
    DisplayHistory(history);

    history = FreeHistory(history);
    assert(history == NULL);
    student_list = FreeList(student_list);
    assert(student_list == NULL);

    return 0;
}

int InsertEntry(struct HistorySave *history,struct LinkedList * my_list,  struct Student data)
{
    int return_data  = 0;
    time_t t = time(NULL);
    struct tm tm;
    tm = *localtime(&t);
    return_data = InsertAtBegining(my_list,data);
    if(return_data == 0)
    {
        AddToHistory(history,(struct OperationDetail){kInsertData,tm});
    }
    return return_data;

}

int DeleteEntry(struct HistorySave *history,struct LinkedList * my_list)
{
    int return_value = 0;
    time_t t = time(NULL);
    struct tm tm;
    tm = *localtime(&t);
    return_value = DeleteAtEnd(my_list);
    if(return_value == 0)
    {
        AddToHistory(history,(struct OperationDetail){kDeleteData,tm});
    }
    return return_value;
}

int SearchEntryByName(struct HistorySave *history,struct LinkedList *my_list,char *name)
{
    int return_value = 0;
    time_t t = time(NULL);
    struct tm tm;
    tm = *localtime(&t);
    return_value = SearchElementByName(my_list,name);
    if(return_value == 0)
    {
        AddToHistory(history,(struct OperationDetail){kSearchData,tm});
    }
    return return_value;
}

