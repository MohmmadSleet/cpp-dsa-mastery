
#include<string>
#include<iostream>

using namespace std;
string ReadString() {
	string str;
	cout << "please enter the string? \n";
	getline(cin, str);
	return str;

}
short CountWord(string S1) {
    string delim = " "; // delimiter

    short counter = 0;
    short pos = 0; string sWord; // define a string variable  

    // use find() function to get the position of the delimiters

    while ((pos = S1.find(delim)) != std::string::npos) {
        sWord = S1.substr(0, pos); // store the word 
        if (sWord != "")
        {
            counter++;
        }
        S1.erase(0, pos + delim.length());
        /* erase() until positon and move to next word. */
    }
    if (S1 != "") {
        counter++;        // it print last word of the string. 
    }
    return counter;
}

int main() {
	string str = ReadString();
	cout << "\nThe Number of word in string = ";
	cout << CountWord(str); 
	return 0;
}







}