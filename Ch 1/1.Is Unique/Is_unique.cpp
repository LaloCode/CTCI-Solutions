#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool isUnique(const string &str) {
  if (str.length() > 128) {
    return false;
  }
  vector<bool> char_set(128);
  for (char c : str) {
    if (char_set[c]) {
      return false;
    }

    char_set[c] = true;
  }
  return true;
}

bool IsUniqueNoDS(const string& str) {
  for (int i = 0; i < str.length(); ++i) {
    for (int j = i + 1; j < str.length(); ++j) {
      if (str[i] == str[j]) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  vector<string> words = { "Hello", "HeElLo", "banana", "Ouch!", "Yum!" };
  for (string word : words) {
    cout << "The word: " + word + " is ";
    if (!isUnique(word)) {
      cout << "not ";
    }
    cout << "unique\n";
  }
  cout << "\nNo DS version\n";
  for (string word : words) {
    cout << "The word: " + word + " is ";
    if (!IsUniqueNoDS(word)) {
      cout << "not ";
    }
    cout << "unique\n";
  }
}
