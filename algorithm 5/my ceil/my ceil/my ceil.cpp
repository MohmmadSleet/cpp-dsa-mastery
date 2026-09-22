 #include<iostream>
#include<math.h>
using namespace std;
float ReadNumber() {
	float number = 0;
	cout << "please enter the number ?";
	cin >> number;
	return number;
}

float GetFractionPart(float Number) {
	return Number - int(Number);
}

int myceil(float number) {

	float fractionpart = GetFractionPart(number);
	if (abs(fractionpart) > 0) {
		if (number > 0)
			return int(number) + 1;
		else
			return int(number);
	}
	else {
		return int(number);
	}
	
}

int main() {
	float number = ReadNumber();
	cout << "my ceil number " << number << " = " << myceil(number) << endl;
	cout << "c++ ceil number " << number << " = " << ceil(number) << endl;


	return 0;
}