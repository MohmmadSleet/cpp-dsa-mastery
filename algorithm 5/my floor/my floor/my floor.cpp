#include<iostream>
#include<math.h>
using namespace std;
float ReadNumber() {
	float number = 0;
	cout << "please enter the number ?";
	cin >> number;
	return number;
}


int myfloor(float number) {
	
	if (abs(number) > 0)
		return int(number);
	else
		return int(number) - 1;
}

int main() {
	float number = ReadNumber();
	cout << "my floor number " << number << " = " << myfloor(number) << endl;
	cout << "c++ floor number " << number << " = " << floor(number) << endl;


	return 0;
}