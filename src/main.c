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
				printf("Ŀǰû��ѧ������");
			}

			break;
		case MOD:
			printf("������Ҫ�޸ĵ�ѧ����ѧ��: ");
			scanf("%s", code);
			ret = mod_student(&students, code);
			if (!ret)
			{
				printf("û���ҵ���ѧ��\n");
			}
			break;
		case DELETE:
			printf("������Ҫɾ����ѧ����ѧ��: ");
			scanf("%s", code);
			ret = delete_student(&students, code);
			// if (ret == false)
			if (!ret)
			{
				printf("û���ҵ���ѧ��\n");
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
				printf("���������\n");
				printf("+---------------------------------+\n");
				break;
			case CHINDOWN:
				sort_students(&students, cmp_chinese_down);
				printf("���������\n");
				printf("+---------------------------------+\n");
				break;
			case MATHUP:
				sort_students(&students, cmp_math_up);
				printf("���������\n");
				printf("+---------------------------------+\n");
				break;
			case MATHDOWN:
				sort_students(&students, cmp_math_down);
				printf("���������\n");
				printf("+---------------------------------+\n");
				break;
			case ENGUP:
				sort_students(&students, cmp_english_up);
				printf("���������\n");
				printf("+---------------------------------+\n");
				break;
			case ENGDOWN:
				sort_students(&students, cmp_english_down);
				printf("���������\n");
				printf("+---------------------------------+\n");
				break;
			case SUMUP:
				sort_students(&students, cmp_sum_up);
				printf("���������\n");
				printf("+---------------------------------+\n");
				break;
			case SUMDOWN:
				sort_students(&students, cmp_sum_down);
				printf("���������\n");
				printf("+---------------------------------+\n");
				break;
			}
		}
	} while ((Menu)menu != EXIT);
	return 0;
}

void sort_menu()
{
	printf("��ѡ������ʽ\n");
	printf("1.�����ĳɼ���������\n");
	printf("2.�����ĳɼ���������\n");
	printf("3.����ѧ�ɼ���������\n");
	printf("4.����ѧ�ɼ���������\n");
	printf("5.��Ӣ��ɼ���������\n");
	printf("6.��Ӣ��ɼ���������\n");
	printf("7.���ܳɼ���������\n");
	printf("8.���ܳɼ���������\n");
}

void show_menu()
{
	printf("1.����ѧ����Ϣ\n");
	printf("2.��ʾѧ����Ϣ\n");
	printf("3.�޸�ѧ���ɼ�\n");
	printf("4.ɾ��ѧ����Ϣ\n");
	printf("5.����ѧ����Ϣ\n");
	printf("6.�˳�\n");
	printf("������һ������>");
}

Student input_student()
{
	Student s;
	printf("������ѧ��ѧ��: ");
	scanf("%s", &s.code);
	printf("������ѧ������: ");
	scanf("%s", &s.name);
	printf("������ѧ�����ĳɼ�: ");
	scanf("%d", &s.chinese);
	printf("������ѧ����ѧ�ɼ�: ");
	scanf("%d", &s.math);
	printf("������ѧ��Ӣ��ɼ�: ");
	scanf("%d", &s.english);
	return s;
}

void show_student(Student *p, int idx)
{
	printf("+---------------------------------+\n");
	printf("��    ��:\t%d\nѧ    ��:\t%s\n��    ��:\t%s\n���ĳɼ�:\t%d\n��ѧ�ɼ�:\t%d\nӢ��ɼ�:\t%d\n", (idx + 1), p->code, p->name, p->chinese, p->math, p->english);
	printf("+---------------------------------+\n");
}