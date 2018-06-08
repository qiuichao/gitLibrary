#ifndef	 _STUDENTOPERATION_H_
#define	 _STUDENTOPERATION_H_
#include "student.h"

void insertStudent(Student& stu);
void showStudent(const vector<Student>& stu);
void matchShowStudent(vector<Student>& stu, long n);
void matchModifyStudent(vector<Student>& stu, long n);
void matchDeleteStudent(vector<Student>& stu, long n);
void showAllStudent(const vector<Student>& vecStudent);
void InquireStudent(vector<Student>& vecStudent, long& num);
void insertStudent(Student& stu, vector<Student>& vecStudent);
void modifyStudent(vector<Student>& vecStudent, long& num);
void deleteStudent(vector<Student>& vecStudent, long& num);

#endif
