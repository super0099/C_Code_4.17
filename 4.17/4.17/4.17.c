#include <stdio.h>
#include "4.17.h"

void PrintStudentfo(const Stu* t) {
	printf("学号 : %d\t姓名 : %-15s\t年龄 : %d\t小组 : %c\t分数 : %.1f\n",
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
	//声明多个结构体变量,也可以说是结构体数组
	Stu students[6] = {
		{"Liping",5,18,'C',145.0},
		{"Zhangping",4,19,'A',130.5},
		{"Hefang",1,18,'A',148.5},
		{"Chengling",2,17,'F',139.0},
		{"Wangming",3,17,'B',144.5},
		{"Lisi",6,17,'B',147.5}
	};
	int count = sizeof(students) / sizeof(Stu);
	//数组传参就传的就是首元素的地址
	PrintStudentsfo(students, count);
	//把学生数据写入文件,创建写入流("./stu.txt", "w+"),可以是相对路径也可以是绝对路径
	FILE* writefile = fopen("./stu.txt", "w+");
	if (!writefile) {
		printf("文件打开失败!");
		return;
	}
	//写入数据 fprintf();
	for (int i = 0; i < count; i++)
	{
		//fprintf文件写入
		fprintf(writefile, "学号 : %d\t姓名 : %-15s\t年龄 : %d\t小组 : %c\t分数 : %.1f\n",
			students[i].num, 
			students[i].name, 
			students[i].age, 
			students[i].group, 
			students[i].score);
	}
	//关闭文件流
	fclose(writefile);


	printf("开始读取文件\n");
	//获取内存空间
	Stu newStus[6];
	//从文件读取学生数据
	//把学生数据写入文件
	FILE* readfile = fopen("./stu.txt", "r+");
	int readIndex = 0;
	int result = 0;
	while (1)
	{
		result = fscanf(readfile, "学号 : %d\t姓名 : %-15s\t年龄 : %d\t小组 : %c\t分数 : %.1f\n",
			&newStus[readIndex].num,
			newStus[readIndex].name,
			&newStus[readIndex].age,
			&newStus[readIndex].group,
			&newStus[readIndex].score);
		readIndex++;
		//如果result 小于等于0,说明读取完毕
		if (result<=0) {
			break;
		}
	}
	fclose(readfile);
	PrintStudentfo(newStus, count);
	return 0;
}