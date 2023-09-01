#ifndef LAB3_PROBLEMS_HEADER_INCLUDED
#define LAB3_PROBLEMS_HEADER_INCLUDED

#include <stdint.h>

#define MAX_STUDENTS (10U)
#define MAX_DATABASE_SIZE (20U)
#define GENERAL_QUOTA_MAX (6U)
#define MANAGEMENT_QUOTA_MAX (2U)
#define NRI_QUOTA_MAX (2U)

enum eSeatType
{
    kGeneralQuota  = 0,
    kManagementQuota = 1,
    kNriQuota = 2
};

struct Student
{
    char name[20];
    int rank;
    int application_number;
    enum eSeatType seat_type;
};

struct ManageStudentDetail
{
    struct Student *merit_list;
    struct Student *management_list;
    struct Student *nri_list;
    int general_csize;
    int general_tsize;
    int management_csize;
    int management_tsize;
    int nri_csize;
    int nri_tsize;
};

struct ManageStudentDetail *InitializeStudentDetail(void);
int AllocateSeat(struct ManageStudentDetail *student_details,struct Student student_data);
int AllocateSeatForNri(struct ManageStudentDetail *student_details,struct Student student_data);
int AllocateSeatForManagement(struct ManageStudentDetail *student_details,struct Student student_data);
int AllocateSeatForGeneral(struct ManageStudentDetail *student_details,struct Student student_data);
void DisplayAllStudentDetails(struct ManageStudentDetail *student_details);
#endif