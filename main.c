#include "main.h"

//#define DEBUG

int main(int argc, const char *argv[])
{
    //int argc=2;
    //const char *argv[2]={"program.exe","Hexdump.exe",};


    // Check Number of arg
    if( argc!= 2)
    {
        fprintf(stderr,"\nPlease set 1 Parameter in this form:\n");
        fprintf(stderr,"%s FILENAME.suffix\n",argv[0]);
        return -1;
    }

    switch(open_input_file(argv[1]))
    {
    case -1:
        return -1;
        break;
    case 1:
        fprintf(stderr,"Output Error");
        break;
    default:
        return 0;
    }

}

int open_input_file(const char* file_name)
{
    unsigned char line_string[HEX_DUMP_LEN+1] = {0};
    unsigned char line_variable;

    FILE *fp = fopen(file_name,"rb");
    if(fp == NULL)
    {
        fprintf(stderr,"File %s could not be opended\n",file_name);
        return -1;
    }

    unsigned int x=0;
    while(!feof(fp))
    {
        if( (x % HEX_DUMP_LEN) == 0) fprintf(stdout,"%08x ",x);

        fread(&line_string[x%HEX_DUMP_LEN], BYTESIZE, BYTESIZE, fp);
        line_variable = line_string[x%HEX_DUMP_LEN];
        if(!isprint(line_string[x%HEX_DUMP_LEN]) || isspace(line_string[x%HEX_DUMP_LEN]))
        {
            line_string[x%HEX_DUMP_LEN] = '.';
        }

        if( fprintf(stdout,"%02x ",line_variable) < 0 ) return 1;

        if( (x % HEX_DUMP_LEN) == HEX_DUMP_LEN-1)
        {
            if( fprintf(stdout,"%s\n",line_string) < 0) return 1;
            for(int i=0; i<HEX_DUMP_LEN; i++) line_string[i] = '\0';
        }
        x++;
    }

    if((x % HEX_DUMP_LEN) != 0)
    {
        for(int j=(x % HEX_DUMP_LEN); j<HEX_DUMP_LEN; j++) if( fprintf(stdout,"   ") < 0) return 1;
        if ( fprintf(stdout,"%s\n",line_string) < 0) return 1;

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
