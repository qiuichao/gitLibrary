#include "student.h"

Student::Student()
{ 

}

Student::Student(string& s_name, long s_num, string& s_sex, int s_score)
{
	this->name = s_name;
	this->number = s_num;
	this->sex = s_sex;
	this->score = s_score;
}

Student::~Student() { }

void Student::ShowStudent() const
{
	cout << "name: " << name << endl
		<< "num: " << number << endl
		<< "sex: " << sex << endl
		<< "subject:" << subject << endl
		<< "score: " << score << endl;
}

ostream& operator<<(ostream& os, const Student& s)
{
	os << "student name: " << s.name << ", number: " << s.number << ", sex:  " << s.sex
		<< ",subject" << s.subject <<  ", score: " << s.score << endl;
	return os;
}
