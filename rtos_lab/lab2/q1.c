#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
int FileConvertToUpperCase(int argc,char *argv[]);

int main(int argc,char *argv[])
{
    FileConvertToUpperCase(argc,argv); 
    return 0;
}

int FileConvertToUpperCase(int argc,char *argv[])
{
    int return_value = -1;
    char ch;
    FILE *file_ptr_src = NULL,*file_ptr_dest = NULL;
    if(argc >= 3 )
    {
        if(strcmp(argv[1],"toupper") == 0)
        {
            
            file_ptr_src = fopen(argv[2],"r");
            if(file_ptr_src != NULL) 
            {
                file_ptr_dest = fopen(argv[3],"w");
                if(file_ptr_dest != NULL)
                {
                   return_value = 0;
                   ch = getc(file_ptr_src);
                   while( ch != EOF)
                   {
                       if(isalpha(ch) && islower(ch))
                       {
                           ch = toupper(ch);
                       }
                       putc(ch,file_ptr_dest);
                       ch = getc(file_ptr_src);
                   }
                   fclose(file_ptr_dest);
                }
                fclose(file_ptr_src);
                    
            }
        }
        
    }

    return return_value;
    
}

