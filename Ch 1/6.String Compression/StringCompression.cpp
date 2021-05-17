#include <iostream>
#include <string>

using namespace std;

string stringCompress(const string& str) {
	string result = "";
	for (int i = 0; i < str.length(); ++i) {
		int count = 1;
		while(str[i] == str[i+1]) {
			++count;
			++i;
		}
		result += str[i] + to_string(count);
	}
	if (result.length() > str.length()) {
		return str;
	}
	return result;
}

int main()
{
	string s1 = "aabcccccaaa";
	cout << "String: " << s1 << '\n';
	cout << "Compressed: " << stringCompress(s1);
	return 0;
}

