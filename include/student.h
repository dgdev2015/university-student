#pragma once
#include <stdio.h>
#include <stdbool.h>

#define MAX_STUDENTS 50
#define CODE_LEN 50
#define NAME_LEN 50

typedef struct
{
    char code[CODE_LEN];
    char name[NAME_LEN];
    unsigned int chinese;
    unsigned int math;
    unsigned int english;
} Student;