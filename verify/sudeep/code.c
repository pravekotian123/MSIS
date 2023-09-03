#include<stdio.h>
#include<stdlib.h>
#include"header.h"

//initializing an array
seat *initialize(int total_seat)
{
    seat *my_arr= (seat *)malloc(sizeof(seat));
    my_arr->c_size=0;
    my_arr->t_size=total_seat;
    my_arr->arr= malloc(sizeof(student)*total_seat);
    return my_arr;

}
//inserting student details
int insert_details(seat *my_arr,student data)
{
    /*changes:
    first compare quota and allocate seat based upon required quota
    if(strcmp(&(student.quota),"Mangaement")==0)
    {
        /*if(management csize == managemnet tsize)
        return;
        else
        /*allocate seat starting from maganement indices*/
    }else if(strcmp(&(student.quota),"Nri")==0)
    {
      /*if(nri csize == nri tsize)
        return;
        else
        /*allocate seat starting from nri indices */
    }
    else if(strcmp(&(student.quota),"Rank")==0)
    {
        if(merit csize < merit tsize)
        {
           /*allocate seat starting from merit indices */
        }
        else{
            councelling_sort();
            /*in counselling sort sort only merit indices*/
            if(rank of student > rank of worst in merit slot i.e, my->arr[5])
            {
                /*then replace myar5 with student*/
            }
        }

    }
    
    my_arr->arr[my_arr->c_size ]=data;
    my_arr->c_size ++;
    return 1;

    //seat allotment based on rank
}
 void councelling_sort(seat *my_arr)
 {
     int i,j;
     /*merit csize..better merit tsize*/
     for(i=0;i<my_arr->c_size-1;i++){
        /*merit csize..better merit tsize*/
        for(j=0;j<my_arr->c_size-i-1;j++){
            if(my_arr->arr[j].s_rank >my_arr->arr[j+1].s_rank ){
                student temp = my_arr->arr[j];
                my_arr->arr[j] =my_arr->arr[j+1];
                my_arr->arr[j+1] = temp;

            }
        }
     }
 }

 //displaying admission list

void result(seat *my_arr)
{
     int merit_count = 0;
    int management_count = 0;
    int NRI_count = 0;
    printf("Admitted Student List:\n");

    for (int i = 0; i < my_arr->t_size; i++) {
        if ((my_arr->arr[i].quota[0] == 'M' && management_count < 2) || (my_arr->arr[i].quota[0] == 'N' && NRI_count < 2)) { // M=Management and N=NRI quota
            printf("Name: %s\t\t\t Quota: %s \n", my_arr->arr[i].s_name, my_arr->arr[i].quota);
            if (my_arr->arr[i].quota[0] == 'M') {
                management_count++;
            } else {
                NRI_count++;
            }
        }
        else if (merit_count < 6){ // Merit
            printf("Name: %s\t Rank: %d\t Quota: %s \n",  my_arr->arr[i].s_name, my_arr->arr[i].s_rank, my_arr->arr[i].quota);
            merit_count++;
        }
    }
}
