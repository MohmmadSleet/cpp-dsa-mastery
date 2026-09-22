#include<string>
#include<iostream>
#include<vector>

using namespace std;
string ReadString() {
	string S1;
	cout << "please enter the String ?\n";
	getline(cin, S1);
	return S1;
}
vector<string> SplitString(string s1, string delim) {
	vector<string>vString;
	short pos = 0;
	string Sword;
	while ((pos = s1.find(delim)) != std::string::npos) {
		Sword = s1.substr(0, pos);
		if (Sword != "") {
			vString.push_back(Sword);
		}
		s1.erase(0, pos + delim.length());
	}
	if (s1 != "") {
		vString.push_back(s1);
	}
	return vString;
}
int main() {
	vector<string>vString;
	vString = SplitString(ReadString(), " ");
	cout << "Tokens = " << vString.size() << endl;
	
	for (string& s : vString) {
		cout << s << endl;
	}

	return 0;
}