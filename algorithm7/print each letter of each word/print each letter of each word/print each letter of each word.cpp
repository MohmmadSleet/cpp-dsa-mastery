
#include<iostream>
#include<string>
using namespace std;
string ReadString() {
	string str;
	cout << "please enter the string ?\n";
	getline(cin, str);
	return str;
}
void PrintFirstLettresOfEachWords(string str) {
	bool ISFirstLetters = true;
	for (short i = 0; i < str.length(); i++) {
		if (str[i] != ' ' && ISFirstLetters) {
			cout << str[i] << endl;
		}
		ISFirstLetters =(str[i] == ' ') ? true : false;
	}
}
int main() {

	PrintFirstLettresOfEachWords(ReadString());


	return 0;

}