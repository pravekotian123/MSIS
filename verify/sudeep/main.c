#include <string.h>
#include <stdlib.h>
#include<assert.h>
#include "header.h"

int main()
{
    seat *admission;
    student data;

    admission = initialize(16);

    //Enter student details
    //note that for NRI students and management students rank should be 1000

    strcpy(data.s_name, "ab");
    data.s_rank = 90;
    strcpy(data.quota, "Rank");
    insert_details(admission,data);


    strcpy(data.s_name, "cd");
    data.s_rank = 18;
    strcpy(data.quota, "Rank");
        insert_details(admission,data);


    strcpy(data.s_name, "ef");
    data.s_rank = 427;
    strcpy(data.quota, "Rank");
       insert_details(admission,data);


    strcpy(data.s_name, "gh");
    data.s_rank = 112;
    strcpy(data.quota, "Rank");
       insert_details(admission,data);



    strcpy(data.s_name, "ij");
    data.s_rank = 56;
    strcpy(data.quota, "Rank");
       insert_details(admission,data);


    strcpy(data.s_name, "kl");
    data.s_rank = 41;
    strcpy(data.quota, "Rank");
       insert_details(admission,data);



    strcpy(data.s_name, "mn");
    data.s_rank = 47;
    strcpy(data.quota, "Rank");
       insert_details(admission,data);



    strcpy(data.s_name, "op");
    data.s_rank = 27;
    strcpy(data.quota, "Rank");
       insert_details(admission,data);



    strcpy(data.s_name, "qr");
    data.s_rank = 79;
    strcpy(data.quota, "Rank");
       insert_details(admission,data);



    strcpy(data.s_name, "jhf");
    data.s_rank = 1000;
    strcpy(data.quota, "Management");
    insert_details(admission,data);

    strcpy(data.s_name, "kjh");
    data.s_rank = 1000;
    strcpy(data.quota, "NRI");
    insert_details(admission,data);

    strcpy(data.s_name, "ghj");
    data.s_rank = 1000;
    strcpy(data.quota, "NRI");
    insert_details(admission,data);

   strcpy(data.s_name, "hj");
    data.s_rank = 1000;
    strcpy(data.quota, "Management");
    insert_details(admission,data);


     strcpy(data.s_name, "bc");
    data.s_rank = 1030;
    strcpy(data.quota, "Management");
    insert_details(admission,data);


    strcpy(data.s_name, "Ak");
    data.s_rank = 100;
    strcpy(data.quota, "Management");
    insert_details(admission,data);


    strcpy(data.s_name, "N");
    data.s_rank = 10;
    strcpy(data.quota, "NRI");
    insert_details(admission,data);

    /*call counselling sort function inside_details coz its easy to replacement worst rank with better rank if merit seat is full*/
    //councelling_sort(admission);/*sorting here not required*/
    result(admission);

    return 0;
}








