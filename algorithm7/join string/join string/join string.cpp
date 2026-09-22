#include<string>
#include<vector>
#include<iostream>

using namespace std;
string JoinString(vector<string>vString, string delim) {
	string S1 = " ";
	for (string& s : vString) {
		S1 = S1 + s + delim;
	}
	return S1.substr(0, S1.length() - delim.length());
}

int main() {

	vector<string>vString = { "mohmmad ","ahmad","jamal","ali" };

	cout << "After join string = \n";
	cout << JoinString(vString, "%%");

	return 0;
}