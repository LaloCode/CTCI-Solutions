#include <iostream>
#include <string>

using namespace std;

bool isSubstring(string s1, string s2) {
	string rotationString = s2 + s2;
	if (rotationString.find(s1) != string::npos) {
		return true;
	}
	return false;
}

int main()
{
	string str1, str2;
	cout << "Enter the normal string: ";
	cin >> str1;
	cout << "Enter the string to check for rotation: ";
	cin >> str2;
	if (isSubstring(str1, str2)) {
		cout << "It is a rotation";
	} else {
		cout << "It is not a rotation";
	}
	return 0;
}

