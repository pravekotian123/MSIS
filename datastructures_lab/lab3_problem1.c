#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "lab3_problem1.h"

int main(void)
{
    struct ManageStudentDetail *applied_student_detail = InitializeStudentDetail();
    assert(applied_student_detail != NULL);
    assert(AllocateSeat(applied_student_detail,(struct Student){"s1",20,1,kNriQuota}) == 0);
    assert(AllocateSeat(applied_student_detail,(struct Student){"s2",20,1,kNriQuota}) == 0);
    assert(AllocateSeat(applied_student_detail,(struct Student){"s3",20,1,kNriQuota}) == -1);

    assert(AllocateSeat(applied_student_detail,(struct Student){"s4",20,1,kManagementQuota}) == 0);
    assert(AllocateSeat(applied_student_detail,(struct Student){"s5",20,1,kManagementQuota}) == 0);
    assert(AllocateSeat(applied_student_detail,(struct Student){"s6",20,1,kManagementQuota}) == -1);

    assert(AllocateSeat(applied_student_detail,(struct Student){"s7",1,1,kGeneralQuota}) == 0);
    assert(AllocateSeat(applied_student_detail,(struct Student){"s8",2,1,kGeneralQuota}) == 0);
    assert(AllocateSeat(applied_student_detail,(struct Student){"s9",3,1,kGeneralQuota}) == 0);
    assert(AllocateSeat(applied_student_detail,(struct Student){"s10",4,1,kGeneralQuota}) == 0);
    assert(AllocateSeat(applied_student_detail,(struct Student){"s11",8,1,kGeneralQuota}) == 0);
    assert(AllocateSeat(applied_student_detail,(struct Student){"s12",6,1,kGeneralQuota}) == 0);
    assert(AllocateSeat(applied_student_detail,(struct Student){"s13",5,1,kGeneralQuota}) == 0);
    assert(AllocateSeat(applied_student_detail,(struct Student){"s14",9,1,kGeneralQuota}) == -1);
    DisplayAllStudentDetails(applied_student_detail);
    return 0;
}

struct ManageStudentDetail *InitializeStudentDetail(void)
{
    struct ManageStudentDetail *student_detail_array = ( struct ManageStudentDetail *)malloc(sizeof(struct ManageStudentDetail));
    int slot_memory_alloc_success = -1;
    if(student_detail_array != NULL)
    {
        student_detail_array->merit_list = (struct Student *)malloc(sizeof(struct Student)*GENERAL_QUOTA_MAX);
        student_detail_array->management_list = (struct Student *)malloc(sizeof(struct Student)*MANAGEMENT_QUOTA_MAX);
        student_detail_array->nri_list =  (struct Student *)malloc(sizeof(struct Student)*NRI_QUOTA_MAX);
        if(student_detail_array->merit_list != NULL)
        {
            student_detail_array->general_csize = 0;
            student_detail_array->general_tsize = GENERAL_QUOTA_MAX;
            slot_memory_alloc_success = 0;
        }
        else{
            slot_memory_alloc_success = -1;
        }
        if((student_detail_array->management_list != NULL) && (slot_memory_alloc_success == 0))
        {
            student_detail_array->management_csize = 0;
            student_detail_array->management_tsize = MANAGEMENT_QUOTA_MAX;
        }
        else
        {
            slot_memory_alloc_success = -1;
            free(student_detail_array->merit_list);
        }
        if((student_detail_array->nri_list != NULL) && (slot_memory_alloc_success == 0))
        {
            student_detail_array->nri_csize = 0;
            student_detail_array->nri_tsize = NRI_QUOTA_MAX;
        }
        else {
            slot_memory_alloc_success = -1;
            free(student_detail_array->merit_list);
            free(student_detail_array->nri_list);
            free(student_detail_array);
            student_detail_array = NULL;
        }
    }
    return student_detail_array;
}



int AllocateSeat(struct ManageStudentDetail *student_details,struct Student student_data)
{
    int return_value = -1;
    if(student_details != NULL)
    {
       if(student_data.seat_type == kNriQuota)
       {
           return_value = AllocateSeatForNri(student_details,student_data);
       }
       else if(student_data.seat_type == kManagementQuota)
       {
           return_value = AllocateSeatForManagement(student_details,student_data);
       }
       else if(student_data.seat_type == kGeneralQuota)
       {
            return_value = AllocateSeatForGeneral(student_details,student_data);
       }
    }
}

int AllocateSeatForNri(struct ManageStudentDetail *student_details,struct Student student_data)
{
    int return_value = -1;
    if(student_details != NULL)
    {
        if((student_details->nri_csize) < (student_details->nri_tsize))
        {
            memcpy(((student_details->nri_list) + (student_details->nri_csize)),&student_data,sizeof(student_data));
            student_details->nri_csize++;
            return_value = 0;
        }
    }
    return return_value;
}

int AllocateSeatForManagement(struct ManageStudentDetail *student_details,struct Student student_data)
{
    int return_value = -1;
    if(student_details != NULL)
    {
        if((student_details->management_csize) < (student_details->management_tsize))
        {
            memcpy(((student_details->management_list) + (student_details->management_csize)),&student_data,sizeof(student_data));
            student_details->management_csize++;
            return_value = 0;
        }
    }
     return return_value;
}

int AllocateSeatForGeneral(struct ManageStudentDetail *student_details,struct Student student_data)
{
    int return_value = -1;
    
    if(student_details != NULL)
    {
        int j;
        int key = student_data.rank;
        if(student_details->general_csize == student_details->general_tsize)
        {
           
            if((student_details->merit_list + student_details->general_csize - 1)->rank > student_data.rank)
            {
                memcpy((student_details->merit_list + student_details->general_csize - 1),&student_data,sizeof(struct Student));
                return_value = 0;
            }
        }
        else{
            
            memcpy(student_details->merit_list +  student_details->general_csize ,&student_data,sizeof(struct Student));
            student_details->general_csize++;
            return_value = 0;
        }
        
        for (int i = 1; i < student_details->general_csize; i++) {
        struct Student student_key  = (struct Student )(*(student_details->merit_list + i));
        j = i - 1;
  
        while (j >= 0 && (student_details->merit_list + j)->rank > student_key.rank) {
           // arr[j + 1] = arr[j];
            memcpy((student_details->merit_list)+j+1,(student_details->merit_list)+j,sizeof(struct Student));
            j = j - 1;
        }
        memcpy((student_details->merit_list)+j+1,&student_key,sizeof(struct Student));
        //arr[j + 1] = key;
    }
    return return_value;
    } 
}

static void DisplayNriDetail(struct ManageStudentDetail *student_details)
{
    for(int i= 0;i<student_details->nri_csize;i++)
    {
        printf("Mri_student name = %s \n",(student_details->nri_list + i)->name);
    }
}

static void DisplayManagementDetail(struct ManageStudentDetail *student_details)
{
    for(int i= 0;i<student_details->management_csize;i++)
    {
        printf("Management_student name = %s \n",(student_details->management_list+i)->name);
    }
}

static void DisplayMeritDetail(struct ManageStudentDetail *student_details)
{
    for(int i= 0;i<student_details->general_csize;i++)
    {
        printf("Merit student name = %s\n",(student_details->merit_list+i)->name);
    }
}

void DisplayAllStudentDetails(struct ManageStudentDetail *student_details)
{
    DisplayNriDetail(student_details);
    DisplayManagementDetail(student_details);
    DisplayMeritDetail(student_details);
}