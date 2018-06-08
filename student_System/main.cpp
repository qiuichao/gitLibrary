#include <iostream>
#include <vector>
#include "student.h"
#include "studentOperation.h"
using std::cout;
using std::cin;
void showMenu()
{
	std::cout << "【学生信息管理系统】\n";
	cout << "************************************************\n";
	cout << "[1] 查询所有学生信息\n";
	cout << "[2] 查询某学生信息\n";
	cout << "[3] 插入学生信息\n";
	cout << "[4] 修改学生信息\n";
	cout << "[5] 删除学生信息\n";
	cout << "************************************************\n";
}

int main()
{
	int choice;
	Student student;
	long input_Num;
	vector<Student>  studentVec;
	showMenu();
	cout << "输入选择: " << endl;
	cin >> choice;
	while (1)
	{
		switch (choice)
		{
		case 1:
			showAllStudent(studentVec);
			break;
		case 2:
			InquireStudent(studentVec, input_Num);
			break;
		case 3:
			insertStudent(student, studentVec);
			break;
		case 4:
			modifyStudent(studentVec, input_Num);
			break;
		case 5:
			deleteStudent(studentVec, input_Num);
			break;
		}
		cin.clear();
		cin.sync();
		cout << "输入选择: " << endl;
		cin >> choice;
	}
	return 0;
}
