#include<iostream>
#include<conio.h>
#include<new>
using namespace std;

void outputarray(int **matrix,const int rows,const int cols){
	
	for (int **iptr = matrix; iptr; iptr++){
		for (int *jptr = *iptr; jptr < *iptr + cols; jptr++){

			cout << *(jptr) << endl;
		}
	}
}
int **transpose(int **arr, const int rows, const int cols){

	for (int i = 0; i < rows; i++){
		for (int j = 0; j< cols; j++){

			*(*(arr + i) + j) = *(*(arr + j) + i);
		}

	}
	return arr;
}
bool isSymmeteric(int **arrptr, int rows, int cols){
	int **temp = transpose(arrptr, rows, cols);
	int flag = 0;
	if (rows == cols){
		for (int i = 0; i < rows; i++){
			for (int j = 0; j < cols; j++){

				if ((*(*arrptr + i) + j) == (*(*temp + i) + j)){
					flag = 1;
				}
				else{
					flag = 0;
						break;

				}
			}
		}


	}
	return flag;
}

int **interchangeRows(int **arr, int rows, int cols){

	int X;
	for (int i = 0; i<cols; i++)
	{
		X = arr[*(*(arr+1)+i) - 1][i];
		arr[(*(*arr+1)+i) - 1][i] = arr[(*(*arr+1)+i) - 1][i];
		arr[(*(*arr+2)+i) - 1][i] = X;
	}
}

void interchangerows(int *& row1, int *& row2){

	int* temp = row1;
	row1 = row2;
	row2 = temp;

	
}
int **addMatrix(int **matrix1, int **matrix2, const int rows, const int cols){

	int **addArr = new int *[rows];
	for (int **iptr = addArr; iptr < addArr + rows; iptr++){

		*iptr = new int[cols];
	}
	int **arrptr1 = matrix1 + 0;
	int **arrptr2 = matrix2 + 0;
	//adding arrays
	for (int **iptr = addArr; iptr < addArr + rows; iptr++){
		for (int *jptr = *iptr; jptr < (*iptr) + cols; jptr++){

			*jptr = **arrptr1 + **arrptr2;

			*arrptr1++;
			*arrptr2++;
		}
		arrptr1++;
		arrptr2++;
	}
	return addArr;
}
int **inputMatrix(int& rows, int& cols){

	int **matrix = 0;
	matrix = new (nothrow) int *[rows];

	for (int **ptr = matrix; ptr<(matrix + rows); ptr++)
	{
		*ptr = new int[cols];
	}


	int indexrow, indexcol;
	if (matrix == NULL){
		cout << "Memory location error\n";
	}
	else{
		for (int **rowptr = matrix; rowptr < (matrix + rows); rowptr++)
		{
			indexrow = 0;

			for (int *colptr = *rowptr; colptr < ((*rowptr) + cols); colptr++)
			{
				indexcol = 0;
				cout << "Enter element of " << indexrow << " row and " << indexcol << " column of matrix" << endl;
				cin >> *colptr;
				indexcol++;
			}
			indexrow++;
		}
	}


	return matrix;
}

void main(){

	int rows, cols;
	cout << "Enter the number of rows for the matrix A: ";
	cin >> rows;
	cout << "Enter the number of columns for matrix A: ";
	cin >> cols;
	int **arrptr = inputMatrix(rows, cols);
	outputarray(arrptr, rows, cols);

	int rows2, cols2;
	cout << "Enter the number of rows for the matrix B: ";
	cin >> rows2;
	cout << "Enter the number of columns for matrix B: ";
	cin >> cols2;
	int **arrptr2 = 0;
	 arrptr2 = inputMatrix(rows, cols);
	outputarray(arrptr2, rows2, cols2);

	int **temp;
	if (rows == cols2){

		temp=addMatrix(arrptr, arrptr2, rows, cols2);
		outputarray(temp, rows, cols2);
	}
	
	//for transpose
	cout << "Transpose of matrix 1:\n";
	temp = transpose(arrptr, rows, cols);
	outputarray(temp, rows, cols);
	
	//Is the matrix symmetric
	bool result = 0;
	cout << "Checking symmetry for matrix 1:\n";
	result = isSymmeteric(arrptr, rows, cols);
	cout << result;
	
	cout << "Transpose of matrix 2:\n";
	temp = transpose(arrptr2, rows2, cols2);
	outputarray(temp, rows2, cols2);

	cout << "Checking symmetry for matrix 2:\n";
	result = isSymmeteric(arrptr2,  rows2, cols2);
	cout << result;
	
	int *rowptr = &rows, *colsptr = &cols;
	//for interchanging rows
	cout << "Interchanged rows for matrix 1 are:\n";
	interchangerows(rowptr, colsptr);
	outputarray(temp, rows, cols);

	cout << "Interchanged rows for matrix 1 are:\n";
	interchangerows(rowptr, colsptr);
		temp = interchangeRows(arrptr, rows, cols);
	outputarray(temp, rows, cols);

	
	cout << "Interchanged rows for matrix 2 are:\n";
	temp = interchangeRows(arrptr2, rows2, cols2);
	outputarray(temp, rows2, cols2);
	delete arrptr;
	delete arrptr2;
	_getch();
}