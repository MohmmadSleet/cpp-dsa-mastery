
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
int RandomNumber(int From, int To) {
	int Randnum = rand() % (To - From + 1) + From;
	return Randnum;
}

enum enchartype{smallletter=1,capitalletter=2,specialcharacter=3,digitnumber=4};
char GetRandomcharacter(enchartype chartype){
	switch (chartype) {
	case enchartype::smallletter:
		return RandomNumber(97, 122);
	case enchartype::capitalletter:
		return RandomNumber(65, 90);
	case enchartype::specialcharacter:
		return RandomNumber(33, 47);
	case enchartype::digitnumber:
		return RandomNumber(48, 57);
	}
}

int main() {
	srand((unsigned)time(NULL));
	cout << GetRandomcharacter(enchartype::smallletter) << endl;
	cout << GetRandomcharacter(enchartype::capitalletter) << endl;
	cout << GetRandomcharacter(enchartype::specialcharacter) << endl;
	cout << GetRandomcharacter(enchartype::digitnumber) << endl;

}