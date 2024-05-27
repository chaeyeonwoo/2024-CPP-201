#include <iostream>
using namespace std;

class Animal {
public:
	string name;
	int weight;
};

class Cat : public Animal {

};

int main() {
	return 0;
}
// class 자식 클래스 : (접근 지정자) + 부모클래스 {
//	파생(자식) 클래스 멤버 리스트
// }

class Cat : public Animal {
private:
	int id;
public:
	Cat(int id, const string name, int weight);
	// 파생 클래스의 생성자 선언
};

Cat:: Cat(int id, const string name, int weight) : Animal(name, weight) {
	//파생 클래스의 생성자 호출
	this->id = id;	// 파생 클래스의 멤버 변수 초기화
}