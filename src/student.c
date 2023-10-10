#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "student.h"

void init_students(StudentsRepo *p)
{
	memset(p, 0, sizeof(StudentsRepo));
}

void init_student(Student *p)
{
	memset(p, 0, sizeof(Student));
}

bool add_student(StudentsRepo *repo, Student *ps)
{
	if (repo->len >= MAX_STUDENTS)
	{
		return false;
	}
	memcpy(&repo->students[repo->len], ps, sizeof(Student));
	repo->len++;
	return true;
}

void display_students(StudentsRepo *repo, Student *p)
{
	for (unsigned int i = 0; i < repo->len; i++)
	{
		p = &repo->students[i];
		show_student(p, i);
	}
}

bool mod_student(StudentsRepo *repo, char *code)
{
	bool is_found = false;
	int idx = -1;

	for (unsigned int i = 0; i < repo->len; i++)
	{
		int ret = strcmp(repo->students[i].code, code);
		if (ret == 0)
		{
			is_found = true;
			idx = i;
			break;
		}
	}

	if (!is_found)
	{
		return false;
	}

	Student *p = &repo->students[idx];
	Student s;

	printf("��ѧ��ԭ���ĳɼ���:\n����:%d\n��ѧ:%d\nӢ��:%d\n", p->chinese, p->math, p->english);
	printf("�����ĳɼ��ĳ�(����������ԭ���ĳɼ�):\t");
	scanf("%d", &s.chinese);
	p->chinese = s.chinese;
	printf("����ѧ�ɼ��ĳ�(����������ԭ���ĳɼ�):\t");
	scanf("%d", &s.math);
	p->math = s.math;
	printf("��Ӣ��ɼ��ĳ�(����������ԭ���ĳɼ�):\t");
	scanf("%d", &s.english);
	p->english = s.english;
	return true;
}

bool delete_student(StudentsRepo *repo, char *code)
{
	bool is_found = false;
	int idx = -1;

	for (unsigned int i = 0; i < repo->len; i++)
	{
		int ret = strcmp(repo->students[i].code, code);
		if (ret == 0)
		{
			is_found = true;
			idx = i;
			break;
		}
	}
	if (!is_found)
	{

		return false;
	}

	for (unsigned int j = idx; j < repo->len; j++)
	{
		memcpy(&repo->students[j], &repo->students[j + 1], sizeof(Student));
	}
	repo->len--;
	return true;
}

int cmp_chinese_up(const void *a, const void *b)
{
	const Student *pa = a;
	const Student *pb = b;

	return pa->chinese - pb->chinese;
}

int cmp_math_up(const void *a, const void *b)
{
	const Student *pa = a;
	const Student *pb = b;

	return pa->math - pb->math;
}

int cmp_english_up(const void *a, const void *b)
{
	const Student *pa = a;
	const Student *pb = b;

	return pa->english - pb->english;
}

int cmp_chinese_down(const void *a, const void *b)
{
	const Student *pa = a;
	const Student *pb = b;

	return -(int)(pa->chinese - pb->chinese);
}

int cmp_math_down(const void *a, const void *b)
{
	const Student *pa = a;
	const Student *pb = b;

	return -(int)(pa->math - pb->math);
}

int cmp_english_down(const void *a, const void *b)
{
	const Student *pa = a;
	const Student *pb = b;

	return -(int)(pa->english - pb->english);
}

int cmp_sum_up(const void *a, const void *b)
{
	const Student *pa = a;
	const Student *pb = b;

	return (pa->chinese + pa->math + pa->english) - (pb->chinese + pb->math + pb->english);
}

int cmp_sum_down(const void *a, const void *b)
{
	const Student *pa = a;
	const Student *pb = b;

	return -(int)((pa->chinese + pa->math + pa->english) - (pb->chinese + pb->math + pb->english));
	;
}

void sort_students(StudentsRepo *repo, int (*cmp_func)(const void *a, const void *b))
{
	qsort(repo->students, repo->len, sizeof(Student), cmp_func);
}