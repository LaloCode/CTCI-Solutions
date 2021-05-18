#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate_matrix(vector<vector<int>>& matrix, int n) {
	for (int curr_row = 0; curr_row < n/2; ++curr_row) {
		int end_col = n - 1 - curr_row;
		for(int offset = 0; curr_row + offset < end_col; ++offset) {
			swap(matrix[curr_row][curr_row + offset], matrix[curr_row + offset][end_col]);
			swap(matrix[curr_row][curr_row + offset], matrix[end_col][end_col - offset]);
			swap(matrix[curr_row][curr_row + offset], matrix[end_col - offset][curr_row]);
		}
	}
}

int main()
{
	int n = 8;
	vector<vector<int>> matrix;
	for (int i = 0; i < n; ++i) {
		matrix.push_back(vector<int>());
		for (int j = 0; j < n; ++j) {
			matrix[i].push_back(i + j);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "\n\nAfter rotation:\n";
	rotate_matrix(matrix, n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

