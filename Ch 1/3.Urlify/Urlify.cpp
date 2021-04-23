#include <iostream>

using namespace std;

void Urlify(char *str, int length) {
	int i, j;
	int whitespace = 0;
	for(i = 0; i < length; ++i) {
		if (str[i] == ' ') {
			++whitespace;
		}
	}
	i = length - 1 + 2*whitespace;
	for (j = length - 1; j >= 0; --j) {
		if (str[j] == ' ') {
			str[i--] = '0';
			str[i--] = '2';
			str[i--] = '%';
		} else {
			str[i--] = str[j];	
		}
	}
}

int main()
{
	char str[] = "Mr John Smith    ";
	
	cout << "String: " << str;
	Urlify(str, 13);
	cout << "\nUrlified: " << str;
	
	return 0;
}

