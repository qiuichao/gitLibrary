#ifndef	 _STUDENT_H_
#define	 _STUDENT_H_
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
private:
	string name;
	long number;
	string sex;
	string subject;
	int score;
public:
	Student();
	~Student();
	Student(string& s_name, long s_num, string& s_sex,  int s_score);
	inline string getName()	{ return name;  }
	inline long getNumber() { return number; }
	inline string getSex() { return sex; }
	inline string getSubject() { return subject; }
	inline int getScore() { return score; }
	inline void setName(string& s_name ) { name = s_name; }
	inline void setNumber(long s_num ) { number = s_num; }
	inline void setSex(string& s_sex) { sex = s_sex;  }
	inline void setSubject(string& sub) { subject = sub; }
	inline void setScore(int s_score = 0) { if (s_score >=0 && s_score <= 100) score = s_score; }
	void ShowStudent() const;
	friend ostream& operator<<(ostream& os, const Student& s);
};

#endif
