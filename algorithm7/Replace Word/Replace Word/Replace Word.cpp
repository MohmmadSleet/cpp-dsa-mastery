

#include<string>
#include<vector>
#include<iostream>

using namespace std;
string StringReplace(string str,string YouNeedReplace,string Replace) {
	
	short pos = str.find(YouNeedReplace);
	
	while (pos != std::string::npos) {
		str = str.replace(pos, YouNeedReplace.length(), Replace);
		pos = str.find(YouNeedReplace);
	}
	return str;

}

int main() {
	string str = "mohmmad abu sleet,sleet is my parents";
	string YouNeedReplace = "sleet";
	string Replace= "hussin";
	cout << "String after Replace : \n";
	cout << StringReplace(str, YouNeedReplace, Replace);

}