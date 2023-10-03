#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "ex1_list.h"
#include "history.h"

int main(void)
{
    time_t t = time(NULL);
    struct tm tm;
    struct LinkedList *student_list = InitializeList();
    struct HistorySave *history = InitializeHistorySave();
    assert(student_list != NULL);
    assert(history != NULL);
    tm = *localtime(&t);
    assert(InsertAtBegining(student_list,(struct Student){"Hope",10}) == 0);
    assert(AddToHistory(history,(struct OperationDetail){kInsertData,tm}) == 0);
    tm = *localtime(&t);
    assert(InsertAtBegining(student_list,(struct Student){"Raza",7}) == 0);
    assert(AddToHistory(history,(struct OperationDetail){kInsertData,tm}) == 0);
    tm = *localtime(&t);
    assert(InsertAtBegining(student_list,(struct Student){"Bhuvi",7}) == 0);
    assert(AddToHistory(history,(struct OperationDetail){kInsertData,tm}) == 0);
    tm = *localtime(&t);
    assert(InsertAtBegining(student_list,(struct Student){"Shaheen Afridi",3}) == 0);
    assert(AddToHistory(history,(struct OperationDetail){kInsertData,tm}) == 0);
    DisplayData(student_list);
    DisplayHistory(history);
    return 0;
}