#include <stdio.h>
#include "4.17.h"

void PrintStudentfo(const Stu* t) {
	printf("ѧ�� : %d\t���� : %-15s\t���� : %d\tС�� : %c\t���� : %.1f\n",
		t->num,t->name,t->age,t->group,t->score);

}

void PrintStudentsfo(const Stu* t, int count)
{
	for (int i = 0; i < count; i++)
	{
		PrintStudentfo(&t[i]);
	}
}

int main() {
	//��������ṹ�����,Ҳ����˵�ǽṹ������
	Stu students[6] = {
		{"Liping",5,18,'C',145.0},
		{"Zhangping",4,19,'A',130.5},
		{"Hefang",1,18,'A',148.5},
		{"Chengling",2,17,'F',139.0},
		{"Wangming",3,17,'B',144.5},
		{"Lisi",6,17,'B',147.5}
	};
	int count = sizeof(students) / sizeof(Stu);
	//���鴫�ξʹ��ľ�����Ԫ�صĵ�ַ
	PrintStudentsfo(students, count);
	//��ѧ������д���ļ�,����д����("./stu.txt", "w+"),���������·��Ҳ�����Ǿ���·��
	FILE* writefile = fopen("./stu.txt", "w+");
	if (!writefile) {
		printf("�ļ���ʧ��!");
		return;
	}
	//д������ fprintf();
	for (int i = 0; i < count; i++)
	{
		//fprintf�ļ�д��
		fprintf(writefile, "ѧ�� : %d\t���� : %-15s\t���� : %d\tС�� : %c\t���� : %.1f\n",
			students[i].num, 
			students[i].name, 
			students[i].age, 
			students[i].group, 
			students[i].score);
	}
	//�ر��ļ���
	fclose(writefile);


	printf("��ʼ��ȡ�ļ�\n");
	//��ȡ�ڴ�ռ�
	Stu newStus[6];
	//���ļ���ȡѧ������
	//��ѧ������д���ļ�
	FILE* readfile = fopen("./stu.txt", "r+");
	int readIndex = 0;
	int result = 0;
	while (1)
	{
		result = fscanf(readfile, "ѧ�� : %d\t���� : %-15s\t���� : %d\tС�� : %c\t���� : %.1f\n",
			&newStus[readIndex].num,
			newStus[readIndex].name,
			&newStus[readIndex].age,
			&newStus[readIndex].group,
			&newStus[readIndex].score);
		readIndex++;
		//���result С�ڵ���0,˵����ȡ���
		if (result<=0) {
			break;
		}
	}
	fclose(readfile);
	PrintStudentfo(newStus, count);
	return 0;
}