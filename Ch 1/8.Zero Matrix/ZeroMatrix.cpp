#include <iostream>

void nullifyRow(int** matrix, int n, int row) {
	for(int j = 0; j < n; ++j) {
		matrix[row][j] = 0;
	}
}

void nullifyCol(int** matrix, int m, int col) {
	for (int i = 0; i < m; ++i) {
		matrix[i][col] = 0;
	}
}

void nullifyMatrix(int** matrix, int m, int n) {
	bool firstRow = false;

	for( int i = 0; i < n; ++i ) {
		if ( matrix[0][i] == 0 ) {
			firstRow = true;
			break;
		}
	}

	for( int i = 1; i < m; ++i ) {
		bool nullifyThisRow = false;
		for ( int j = 0; j < n; ++j ) {
			if ( matrix[i][j] == 0 ) {
				matrix[0][j] = 0;
				nullifyThisRow = true;
			}
		}
		if (nullifyThisRow)
			nullifyRow(matrix, n, i);
	}

	for ( int j = 0; j < n; ++j ) {
		if ( matrix[0][j] == 0 ) {
			nullifyCol(matrix, m,  j);
		}
	}

	if ( firstRow ) {
		nullifyRow(matrix, n, 0);
	}
}

void printMatrix(int **matrix, int m, int n) {
	for ( int i = 0; i < m; ++i ) {
		for ( int j = 0; j < n; ++j ) {
			std::cout << matrix[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


int main()
{
	int m, n;
	std::cout << "Enter number of rows:";
	std::cin >> m;
	std::cout << "Enter number of cols:";
	std::cin >> n;
	int **matrix = new int*[m];
	for (int i = 0; i < m; ++i) {
		matrix[i] = new int[n];
	}
	std::cout << "Provide m x n matrix \n";
	for ( int i = 0; i < m; ++i ) {
		for ( int j = 0; j < n; ++j ) {
			std::cin >> matrix[i][j];
		}
	}

	std::cout << "Matrix Before:\n";
	printMatrix(matrix, m, n);
	nullifyMatrix(matrix, m, n);
	std::cout << "Matrix After:\n";
	printMatrix(matrix, m, n);
	
	for (int i = 0; i < m; ++i) {
		delete [] matrix[i];
	}
	delete [] matrix;
	
	return 0;
}

