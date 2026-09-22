#include<iostream>
#include<vector>
#include<string>
using namespace std;
string ReadString() {
	string str;
	cout << "please enter the string ? \n";
	getline(cin, str);
	return str;
}
vector<string> SpiltString(string str, string delim) {
	vector<string>vString;
	short pos = 0;
	string Sword;
	while ((pos = str.find(delim)) != std::string::npos) {
		Sword = str.substr(0, pos);
		if (Sword != "") {
			vString.push_back(Sword);
		}
		str.erase(0, pos + delim.length());
	}
	if (str != " ") {
		vString.push_back(str);
	}
	return vString;
}
string ReversString(string str) {
	vector<string>vString;
	vString = SpiltString(str, " ");
	string S2;
	vector <string>::iterator iter = vString.end();
	while (iter != vString.begin()) {
		--iter;
		S2 += *iter + " ";
	}
	S2 = S2.substr(0,S2.length() - 1);
	return S2;

}
int main() {

	string str = ReadString();
	cout << "\nString After Reversing : \n";
	cout << ReversString(str) << endl;
	return 0;



}