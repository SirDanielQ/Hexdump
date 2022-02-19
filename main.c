#include "main.h"

//#define DEBUG

int main()//int argc, const char *argv[])
{
    int argc=2;
    const char *argv[2]={"program.exe","text.txt",};


    // Check Number of arg
    if( argc!= 2)
    {
        fprintf(stderr,"\nPlease set 1 Parameter in this form:\n");
        fprintf(stderr,"%s FILENAME.suffix\n",argv[0]);
        return -1;
    }

    #ifdef DEBUG

    #endif // DEBUG

    if( open_input_file(argv[1]) == -1) return -1;

    return 0;
}

int open_input_file(const char* file_name)
{
    FILE *fp = fopen(file_name,"rb");
    if(fp == NULL)
    {
        fprintf(stderr,"File %s could not be opended\n",file_name);
        return -1;
    }


    if (ferror(fp))
    {
        fclose(fp);    //close file
        fprintf(stderr,"Error: Reading Text File %s\n",file_name);
        return -1;
    }
    else if (feof(fp))
    {
        fclose(fp);    //close file
        return 0;
    }

    fclose(fp);
    return 0;
}
