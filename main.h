/**
    Created by: Daniel Stevic
    Date:       19.2.22
    Version:    R01
    Name:       Hexdump

    This is version 2 of the Task Simple Spell Checker and shall represent a more efficient check

    Middle Task:

    Write a program that displays the content of a file byte-by-byte in hexadecimal and ASCII. The program shall provide the following command-line interface:

    $ hexdump.exe FILENAME

    FILENAME is the name of the file to dump.

**/

#ifndef MAIN_H
#define MAIN_H

// Librarys
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Constants
#define BYTESIZE 1
#define HEX_DUMP_LEN 16

//Prototypes
int open_input_file(const char* file_name);
#endif // MAIN_H
