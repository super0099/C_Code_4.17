#pragma once
/*�����ṹ��*/
typedef struct  stu
{
	char name[15];
	int num;
	int age;
	char group;
	float score;
}Stu;

void PrintStudentfo(const Stu* t);
void PrintStudentsfo(const Stu* t,int count);
