#include "Taken_Course.h"
#include <iostream>

Taken_Course::Taken_Course(string course,string result)
{
	course_name = course;
	grade =result;
}

void Taken_Course::print()
{
	cout<<course_name;
	cout<<"  <------>   ";
	cout<<grade;
	cout<<endl;
}

Taken_Course::~Taken_Course(void)
{
}
