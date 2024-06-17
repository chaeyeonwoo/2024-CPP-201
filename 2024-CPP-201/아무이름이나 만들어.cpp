#include <iostream>
#include <string>
using namespace std;

class dad {
private :
	int money; // 돈
	int stink; // 발냄새
};

class mom {
public:
	string job; // 직업
	string vehicle; // 자전거
};

class jjangku : public dad, mom {
	string favorite;
	string pet;

	jjangku(int money1, int stink1, string job1, string vehicle1, string favorite1, string pet1) 
		: money(money1), stink (stink1), job(job1), vehicle(vehicle1), favorite(favorite1), pet(pet1)
};