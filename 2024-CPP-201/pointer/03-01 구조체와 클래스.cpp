﻿#include <iostream>
#include <string>
using namespace std;

// 클래스는 디폴트가 private이여서 가능함.

class Student {
public:
	// 생성자 : 객체를 생성할 때 호출되는 함수
	// 반환형이 없다. return x
	 Student(int hakbun, string name) 
		 : hakbun_(hakbun), name_(name) {}
	
	// 생성자 오버로딩
	Student()
	 :hakbun_(2121), name_("JWP") {}
			 
	 // 객체의 멤버를 출력하는 함수
	 void print(void) {
		 cout << hakbun_ << " " << name_ << endl;
	 }

private:
	int hakbun_;
	string name_;
};

void main(void) {
	
	Student* stu = new Student[3]{
		{2115, "윤주영" },
		{ 2121, "JWP" },
		{ 2104, "위즈덤" } 
	};
	
	for (int i = 0; i < 3; i++)
		stu[i].print();
	 
	 // 동적할당된 메모리는 반드시 delete를 해주어야 한다. 
	 delete []stu;

}