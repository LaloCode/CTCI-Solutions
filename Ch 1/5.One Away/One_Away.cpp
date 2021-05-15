#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

bool areOneAway(const string &str1, const string &str2) {
	int lengthDiff = abs((int)str1.length() - (int)str2.length());
	if (lengthDiff > 1) {
		return false;
	}
	string longest, shortest;
	if (str1.length() >= str2.length()) {
		longest = str1;
		shortest = str2;
	} else {
		longest = str2;
		shortest = str1;
	}
	int different = 0;
	for (int i = 0; i < shortest.length(); ++i) {
		if (lengthDiff > 0) {
			if (shortest[i] != longest[i + different]) {
				++different;
				if (different > 1) {
					return false;
				}
			}
		} else if (shortest[i] != longest[i]) {
			++different;
			if (different > 1) {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	string str1 = "xd";
	string str2 = "xd";
	if (areOneAway(str1, str2)) {
		cout << str1 << " and " << str2 << " are one away ";
	} else {
		cout << str1 << " and " << str2 << " are not one away ";
	}
	return 0;
}

