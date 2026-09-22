#include<iostream>
#include<string>
using namespace std;
enum enCharType
{ SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };
int RandomNumber(int From, int To) {
	//Function to generate a random number
	 int randNum = rand() % (To - From + 1) + From;
	 return randNum;
} 
char GetRandomCharacter(enCharType CharType) {
	switch (CharType) 
	{ 
		case enCharType::SamallLetter:
	{ return char(RandomNumber(97, 122));
	break;
	} 
	case enCharType::CapitalLetter:
	{ return char(RandomNumber(65, 90));
	break;
	} 
	case enCharType::SpecialCharacter:  
	{ return char(RandomNumber(33, 47));
	break;
	} case enCharType::Digit:
	{ return char(RandomNumber(48, 57)); 
	break;
	}
	}
}
int ReadPositiveNumber() {
	int number;
	do {
		cout << "please enter the number ";
		cin >> number;
	} while (number <= 0);
	return number;
}
string Generateword(enCharType chartype, short length)
{
	string word;
	for (int i = 1; i <= length; i++) {
		word = word + GetRandomCharacter(chartype);
	}
	return word;
}
string GenerateKey() {
	string key = "";
	key = Generateword(enCharType::CapitalLetter, 4) + "-";
	key = key+ Generateword(enCharType::CapitalLetter, 4) + "-";
	key = key+ Generateword(enCharType::CapitalLetter, 4) + "-";
	key = key+ Generateword(enCharType::CapitalLetter, 4);
	return key;
}
void GenerateKeys(short numberofkeys) {
	for (int i = 1; i <= numberofkeys; i++) {
		cout << "key[" << i << "]  : ";
		cout << GenerateKey() << endl;
	}

}

int main() {
	srand((unsigned)time(NULL));
	GenerateKeys(ReadPositiveNumber());
}