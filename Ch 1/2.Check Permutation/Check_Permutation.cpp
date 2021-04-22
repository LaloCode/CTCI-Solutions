#include <iostream>
#include <string>

using namespace std;

bool arePermutation(const string &str1, const string &str2) {
	if (str1.length() != str2.length()) {
		return false;
	}
	int char_count[128] = {0};
	for (char c : str1) {
		++char_count[c];
	}
	for (char c : str2) {
		--char_count[c];
		if (char_count[c] < 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	string str1 = "woohoo";
	string str2 = "ohoowo";
	cout << str1 + " and " + str2 + " are ";
	if (!arePermutation(str1, str2)) {
		cout << "not ";
	}
	cout << "permutations.";
	return 0;
}

