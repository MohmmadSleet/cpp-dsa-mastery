// encryptordecrypt text.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
using namespace std;

string ReadText() {
	string text = "";

	cout << "please enter the statement\n";
	getline(cin, text);
	return text;
}
string trexafteencryptions(string text, int  encrytionkey) {
	for (int i = 0; i <= text.length(); i++) {
		text[i] = char((int)text[i] - encrytionkey);
	}
	return text;
}
string  textafterdecryptions(string textafterencryption, int encrytionkey) {
	for (int i = 0; i <= textafterencryption.length(); i++) {
		textafterencryption[i] = char((int)textafterencryption[i] + encrytionkey);
	}
	return textafterencryption;
}
int main() {
	const int encrytionkey = 2;
	string text = ReadText();
	string textafterencryption = trexafteencryptions(text, encrytionkey);
	string textafterdecryption = textafterdecryptions(textafterencryption, encrytionkey);

	cout << "\ntext before encryption =" << text;
	cout << "\ntext after encryptione = " << textafterencryption << endl;
	cout << "\ntext after decryptione = " << textafterdecryption << endl;


	return 0;
}