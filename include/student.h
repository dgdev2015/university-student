#pragma once
#include <stdio.h>
#include <stdbool.h>

#define MAX_STUDENTS 50
#define CODE_LEN 40
#define NAME_LEN 40

typedef enum
{
	INPUT = 1,
	DISPLAY,
	MOD,
	DELETE,
	SORT,
	EXIT
} Menu;

typedef enum
{
	CHINUP = 1,
	CHINDOWN,
	MATHUP,
	MATHDOWN,
	ENGUP,
	ENGDOWN,
	SUMUP,
	SUMDOWN
} Sort;

typedef struct
{
	char code[CODE_LEN];
	char name[NAME_LEN];
	unsigned int chinese;
	unsigned int math;
	unsigned int english;
} Student;

typedef struct
{
	Student students[MAX_STUDENTS];
	unsigned int len;
} StudentsRepo;

void init_students(StudentsRepo *p);
void init_student(Student *p);

bool add_student(StudentsRepo *repo, Student *ps);
void display_students(StudentsRepo *repo, Student *p);
void show_student(Student *p, int idx);
bool mod_student(StudentsRepo *repo, char *code);
bool delete_student(StudentsRepo *repo, char *code);

int cmp_chinese_up(const void *a, const void *b);
int cmp_chinese_down(const void *a, const void *b);

int cmp_math_up(const void *a, const void *b);
int cmp_math_down(const void *a, const void *b);

int cmp_english_up(const void *a, const void *b);
int cmp_english_down(const void *a, const void *b);

int cmp_sum_up(const void *a, const void *b);
int cmp_sum_down(const void *a, const void *b);

void sort_students(StudentsRepo *repo, int (*cmp_func)(const void *a, const void *b));