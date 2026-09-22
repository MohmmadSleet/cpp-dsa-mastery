#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int RandomNumber(int From, int To) {
	int randnum = rand() % (To - From + 1) + From;
	return randnum;
}
enum enchartype{smallletter=1,capitalleter=2,specialcharcter=3,digit=4};

char getcharatertype(enchartype chartype) {
	switch (chartype) {
	case enchartype::smallletter:
		return RandomNumber(97, 122);
	case enchartype::capitalleter:
		return RandomNumber(65, 90);
	case enchartype::specialcharcter:
		return RandomNumber(33, 47);
	case enchartype::digit:
		return RandomNumber(48, 57);
	}
}
int main() {
	srand((unsigned)time(NULL));
	
	cout << getcharatertype(enchartype::smallletter) << endl;
	cout << getcharatertype(enchartype::capitalleter) << endl;
	cout << getcharatertype(enchartype::specialcharcter)  << endl;
	cout << getcharatertype(enchartype::digit) << endl;
	return 0;
}
