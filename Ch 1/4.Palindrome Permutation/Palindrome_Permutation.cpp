#include <string>
#include <iostream>

using namespace std;

bool isPalindromePermutation(string &str) {
	if (str.length() == 0) {
		return false;
	}
	if (str.length() == 1) {
		return true;
	}
	for (int i = 0; i < str.length(); ++i) {
		str[i] = tolower(str[i]);
	}
	int char_count[128] = {0};
	int real_length = 0;
	for (char c : str) {
		if (c != ' ') {
			++real_length;
			++char_count[c];	
		}
	}
	int evenChars = 0;
	int oddChars = 0;
	for (int i : char_count) {
		if (i > 0) {
			evenChars += i/2;
			oddChars += i%2;
		}
	}
	if (real_length % 2 == 0) {
		if (evenChars > 0 && oddChars < 1) {
			return true;
		}
	} else {
		if (oddChars == 1) {
			return true;
		}
	}
    return false;
}

int main()
{
	string str = "Tact Coa";
	cout << "String: " << str << " is ";
	if (!isPalindromePermutation(str)) {
		cout << "not ";
	}
	cout << "a palindrome permutation.";
	return 0;
}

