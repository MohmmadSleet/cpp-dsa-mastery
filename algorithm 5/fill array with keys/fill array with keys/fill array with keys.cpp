// fill array with keys.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<cstdlib>
using namespace std;
enum enchartype{smallletter=1,capitalletter=3,special=33,digit=4};
int randomnumber(int from, int to) {
    int randnum = rand() % (to - from + 1) + from;
    return randnum;
}
int ReadPositivenumber(string message) {
    int number = 0;
    do {
        cout << message << endl;
        cin >> number;
    } while (number <= 0);
    return number;
}
char GetRandomnumbers(enchartype chartype)
{
    switch (chartype) {
    case enchartype::capitalletter:
        return randomnumber(65, 90);
    case enchartype::smallletter:
        return randomnumber(97, 122);
    case enchartype::special:
        return randomnumber(33, 47);
    case enchartype::digit:
        return randomnumber(48, 57);
    }
}
string GeneratWord(enchartype chartype, short length) {
    string word;
    for (int i = 1; i <= length; i++) {
        word = word + GetRandomnumbers(chartype);
    }
    return word;
}
string GeneratKeys() {
    string key = "";
    key = key + GeneratWord(enchartype::capitalletter, 4) + "-";
    key = key + GeneratWord(enchartype::capitalletter, 4) + "-";
    key = key + GeneratWord(enchartype::capitalletter, 4) + "-";
    key = key + GeneratWord(enchartype::capitalletter, 4);
    return key;

}
void fillthearray(string arr[100], int arrlength) {
    for (int i = 0; i < arrlength; i++) {
        arr[i] = GeneratKeys();
    }
}
void printarray(string arr[100], int arrlength) {
    for (int i = 0; i < arrlength; i++) {
        cout << "Array[" << i << "] : " << arr[i];
        cout << endl;
    }
    cout << endl;
}
int main()
{
    srand((unsigned)time(NULL));
    string arr[100];
     int arrlength = ReadPositivenumber("how many keys you need ?");
    fillthearray(arr, arrlength);
    printarray(arr, arrlength);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
