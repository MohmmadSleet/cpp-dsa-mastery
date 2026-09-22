
#include<iostream>
#include<math.h>
using namespace std;
float ReadNumber() {
	float number = 0;
	cout << "please enter the number ?";
	cin >> number;
	return number;
}
float GetFractionPart(float number) {
	return number - int(number);
}

int myround(float number) {
	int IntNumber = int(number);
	float Fractionpart = GetFractionPart(number);
	if (abs(Fractionpart) >= 0.5)
	{
		if (number > 0)
			return ++IntNumber;
		else
			return --IntNumber;
	}
	else
		return IntNumber;
}

int main() {
	float number = ReadNumber();
	cout << "my round number " << number << " = " << myround(number) << endl;
	cout << "c++ round number " << number << " = " << round(number) << endl;


	return 0;
}