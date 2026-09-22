

#include<string>
#include<iostream>

using namespace std;
string TrimLeft(string S1) {
	for (short i = 0; i < S1.length(); i++) {
		if (S1[i] != ' ') {
			return S1.substr(i, S1.length() - i);
		}
	}
}

string TrimRight(string S1) {
	for (short i = S1.length() - 1; i >= 0; i++) {
		if (S1[i] != ' ') {
			return S1.substr(0, i + 1);
		}
	}
}
string Trim(string S1) {
	return (TrimRight(TrimLeft(S1)));
}

int main() {
	string S1 = "    mohmmad  Abu sleet     ";
	cout << "String : " << S1 << endl;
	cout << "String after Trim Left : " << TrimLeft(S1)<<endl;
	cout << "String after Trim Right : " << TrimRight(S1)<<endl;
	cout << "String after Trim : " << Trim(S1)<<endl;



	return 0;
}