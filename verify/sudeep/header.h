#define FULL 0;
#define SUCCESS 1;

struct _studentdetails_{
int s_rank;
char s_name[30];
char quota[20];
};typedef struct  _studentdetails_ student;



struct _nrimanagement_
{
    int  application_num;
};
typedef struct _nrimanagement_ application;

/*Changes : declare seperate c_size for merit ,management and nri*/
struct _seatallot_{
student *arr;
application *arr1;
int c_size,t_size;
};
typedef struct  _seatallot_ seat;


seat *initialize(int total_seat);
int insert_details(seat *my_arr,student data);
void councelling_sort(seat *my_arr);
void result(seat *my_arr);
