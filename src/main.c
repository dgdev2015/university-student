#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "student.h"

#define _CRT_SECURE_NO_WARNINGS

void sort_menu();
void show_menu();
Student input_student();
void show_student(Student *p, int idx);

int main()
{
	StudentsRepo students;
	unsigned int *plen;
	int menu;
	Student s;
	bool ret;
	unsigned int sort;
	Student *p = &s;

	char code[CODE_LEN];

	init_students(&students);
	init_student(p);
	do
	{
		show_menu();
		scanf("%d", &menu);
		if (menu < INPUT || menu > EXIT)
		{
			continue;
		}
		switch ((Menu)menu)
		{
		case INPUT:
			s = input_student();
			add_student(&students, &s);
			break;
		case DISPLAY:

			display_students(&students, p);
			plen = &students.len;
			if (plen == 0)
			{
				printf("目前没有学生数据\n");
			}

			break;
		case MOD:
			printf("请输入要删除的学生的学号: ");
			scanf("%s", code);
			ret = mod_student(&students, code);
			if (!ret)
			{
				printf("没有找到该学号\n");
			}
			break;
		case DELETE:
			printf("请输入要删除的学生的学号: ");
			scanf("%s", code);
			ret = delete_student(&students, code);
			// if (ret == false)
			if (!ret)
			{
				printf("没有找到该学号\n");
			}
			break;
		case SORT:
			sort_menu();
			scanf("%d", &sort);
			if (sort < CHINUP || sort > SUMDOWN)
			{
				continue;
			}
			switch ((Sort)sort)
			{
			case CHINUP:
				sort_students(&students, cmp_chinese_up);
				printf("已完成排序\n");
				printf("+---------------------------------+\n");
				break;
			case CHINDOWN:
				sort_students(&students, cmp_chinese_down);
				printf("已完成排序\n");
				printf("+---------------------------------+\n");
				break;
			case MATHUP:
				sort_students(&students, cmp_math_up);
				printf("已完成排序\n");
				printf("+---------------------------------+\n");
				break;
			case MATHDOWN:
				sort_students(&students, cmp_math_down);
				printf("已完成排序\n");
				printf("+---------------------------------+\n");
				break;
			case ENGUP:
				sort_students(&students, cmp_english_up);
				printf("已完成排序\n");
				printf("+---------------------------------+\n");
				break;
			case ENGDOWN:
				sort_students(&students, cmp_english_down);
				printf("已完成排序\n");
				printf("+---------------------------------+\n");
				break;
			case SUMUP:
				sort_students(&students, cmp_sum_up);
				printf("已完成排序\n");
				printf("+---------------------------------+\n");
				break;
			case SUMDOWN:
				sort_students(&students, cmp_sum_down);
				printf("已完成排序\n");
				printf("+---------------------------------+\n");
				break;
			}
		}
	} while ((Menu)menu != EXIT);
	return 0;
}

void sort_menu()
{
	printf("请选择排序方式\n");
	printf("1.按语文成绩升序排列\n");
	printf("2.按语文成绩降序排列\n");
	printf("3.按数学成绩升序排列\n");
	printf("4.按数学成绩降序排列\n");
	printf("5.按英语成绩升序排列\n");
	printf("6.按英语成绩降序排列\n");
	printf("7.按总成绩升序排列\n");
	printf("8.按总成绩降序排列\n");
}

void show_menu()
{
	printf("1.输入学生信息\n");
	printf("2.显示学生信息\n");
	printf("3.修改学生成绩\n");
	printf("4.删除学生信息\n");
	printf("5.排序学生信息\n");
	printf("6.退出\n");
	printf("请输入一个数字>");
}

Student input_student()
{
	Student s;
	printf("请输入学生学号: ");
	scanf("%s", &s.code);
	printf("请输入学生姓名: ");
	scanf("%s", &s.name);
	printf("请输入学生语文成绩: ");
	scanf("%d", &s.chinese);
	printf("请输入学生数学成绩: ");
	scanf("%d", &s.math);
	printf("请输入学生英语成绩: ");
	scanf("%d", &s.english);
	return s;
}

void show_student(Student *p, int idx)
{
	printf("+---------------------------------+\n");
	printf("序    号:\t%d\n学    号:\t%s\n姓    名:\t%s\n语文成绩:\t%d\n数学成绩:\t%d\n英语成绩:\t%d\n", (idx + 1), p->code, p->name, p->chinese, p->math, p->english);
	printf("+---------------------------------+\n");
}