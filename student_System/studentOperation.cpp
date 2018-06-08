#include "studentOperation.h"
#include "student.h"

void insertStudent(Student& stu)
{
	string s_name, s_sex, s_subject;
	long s_num;
	int s_score = 0;
	cout << "输入学生姓名: " << endl;
	cin >> s_name;
	stu.setName(s_name);
	cout << "输入学生学号: " << endl;
	cin.clear();
	cin.sync();
	cin >> s_num;
	stu.setNumber(s_num);
	cout << "输入学生性别: " << endl;
	cin >> s_sex;
	stu.setSex(s_sex);
	cout << "输入学生学科：" << endl;
	cin >> s_subject;
	stu.setSubject(s_subject);
	cout << "输入学生分数: " << endl;
	cin.clear();
        cin.sync();
	cin >> s_score;
	stu.setScore(s_score);
}

void showStudent(const vector<Student>& stu)
{
	vector<Student>::const_iterator  iter;
	for (iter = stu.begin(); iter != stu.end(); ++iter)
	{
		cout << *iter << endl;
	}
}

//match student number
void matchShowStudent(vector<Student>& stu, long n)
{
	for (vector<Student>::iterator iter = stu.begin(); iter != stu.end(); ++iter)
	{
		if (n == iter->getNumber())
			iter->ShowStudent();
	}
}

void matchModifyStudent(vector<Student>& stu, long n)
{
	int temp;
	string m_name, m_sex, m_subject;
	int m_score;
	long m_num;
	vector<Student>::iterator iter = stu.begin();
	for (; iter != stu.end(); ++iter)
	{
		if (n == iter->getNumber()) {
			cout << "找到该名学生！" << endl;
			break;
		}
	}
	cout << "修改学生属性：" << endl;
	cout << "【0】退出，【1】姓名 , 【2】学号，【3】性别，【4】学科，【5】分数\n";
	cin >> temp;
	while (temp < 0 || temp >5)  {
		cout << "输入错误，重新输入：";
		cin.clear();
		cin.sync();
		cin >> temp;
	}
	while (temp != 0) {
		switch (temp) {
		case 1:
			cout << "输入修改姓名:  ";
			cin >> m_name;
			iter->setName(m_name);
			break;
		case 2:
			cout << "输入修改的学号:  ";
			cin >> m_num;
			iter->setNumber(m_num);
			break;
		case 3:
			cout << "输入修改的性别:  ";
			cin >> m_sex;
			iter->setSex(m_sex);
			break;
		case 4:
			cout << "输入修改的学科:  ";
			cin >> m_subject;
			iter->setSubject(m_subject);
			break;
		case 5:
			cout << "输入修改成绩:  ";
			cin >> m_score;
			iter->setScore(m_score);
			break;
		}
		cin.clear();
		cin.sync();
		cout << "修改学生属性：\n";
		cin >> temp;
		if (temp == 0) {
			cout << "退出修改\n";
			break;
		}
	}
}

void matchDeleteStudent(vector<Student>& stu, long n)
{
	vector<Student>::iterator iter = stu.begin();
	for (; iter != stu.end(); ++iter)
	{
		if (n == iter->getNumber()) {
			cout << "找到该名学生, 显示完整信息并删除！" << endl;
			iter->ShowStudent();
			stu.erase(iter);
			break;
		}
	}
}


void showAllStudent(const vector<Student>& vecStudent)
{
	if (!vecStudent.empty()) {
		cout << "显示所有学生信息: " << endl;
		showStudent(vecStudent);
	}
	else {
		cout << "学生信息为空！\n";
	}
}

void InquireStudent(vector<Student>& vecStudent, long& num)
{
	cout << "【查询的学生信息】:  " << endl;
	cout << "输入学生学号：" << endl;
	cin >> num;
	matchShowStudent(vecStudent, num);
}

void insertStudent(Student& stu, vector<Student>& vecStudent)
{
	cout << "【插入学生信息】: " << endl;
	insertStudent(stu);
	vecStudent.push_back(stu);
}

void modifyStudent(vector<Student>& vecStudent, long& num)
{
	cout << "【修改学生信息】：\n";
	cout << "输入学生学号：\n";
	cin >> num;
	matchModifyStudent(vecStudent, num);
}

void deleteStudent(vector<Student>& vecStudent, long& num)
{
	cout << "【删除学生信息】：\n";
	cout << "输入删除学生学号：\n";
	cin >> num;
	matchDeleteStudent(vecStudent, num);
}

