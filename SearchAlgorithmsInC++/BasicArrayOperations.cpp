/*
 * BasicArrayOperations.cpp
 *
 *  Created on: Feb 11, 2018
 *      Author: BHUSHAN
 */
#include <fstream>
#include "Array.h"
#include<iostream>
#include <stdlib.h>
#include<ostream>
using namespace std;
Array::Array() {
} //Default Constructor for the class
Array::Array(int value) //Copy Constructor with size
		{
	sizeOfArry = value; //User Pass size
	arrData = new int[sizeOfArry];
	for (int i = 0; i < sizeOfArry; i++)
		arrData[i] = i;
}
Array::~Array() {
} // Destructor for the class

//Function to access the size
int Array::getSize() {
	return sizeOfArry;
}

//Display the content of the array
void Array::displayArray() {
	for (int i = 0; i < sizeOfArry; i++)
		cout << arrData[i] << endl;
}
//Function to Add an element at the beginning
void Array::addToTop(int value) {
	sizeOfArry = sizeOfArry + 1;
// with allocate memory
	arrData = (int*) realloc(arrData, sizeof(int) * sizeOfArry);
	for (int i = sizeOfArry - 1; i > 0; i--)
		arrData[i] = arrData[i - 1];
	arrData[0] = value;
}
//Function to Add an element at the end
void Array::addToEnd(int value) {
	sizeOfArry = sizeOfArry + 1;
	// with allocate memory
	arrData = (int*) realloc(arrData, sizeof(int) * sizeOfArry);
	arrData[sizeOfArry - 1] = value;
}
//Function to Remove an element at the beginning
void Array::removeFromTop() {
	for (int i = 0; i < sizeOfArry; i++)
		arrData[i] = arrData[i + 1];
	arrData[sizeOfArry - 1] = NULL;
}
//Function to Remove an element at the end
void Array::removeFromBottom() {
	arrData[sizeOfArry - 1] = NULL;
}
//Function to Inverse the order of the elements in the array
void Array::reverseArray() {
	int temp;
	for (int i = 0; i < sizeOfArry / 2; i++) {
		temp = arrData[i];
		arrData[i] = arrData[sizeOfArry - i - 1];
		arrData[sizeOfArry - i - 1] = temp;
	}
}
//Function to Return the sum of the elements in the array
int Array::returnSum() {
	int Sum = 0;
	for (int i = 0; i < sizeOfArry; i++)
		Sum += arrData[i];
}
//Function to Return an array that contains the odd numbers only
int* Array::checkOdd() {
	bool isOdd = true;
	for (int i = 0; i < sizeOfArry; i++) {
		if (arrData[i] % 2 == 0) {
			isOdd = false;
			break;
		}
	}
	if (isOdd)
		return arrData;
	else
		return NULL;
}
//Function to Display the content of the array in a file through fstream
void Array::writeToFile(char* filename) {
	ofstream myfile;
	myfile.open(filename);
	for (int i = 0; i < sizeOfArry; i++) {
		myfile << arrData[i] << "\n";
	}
	myfile.close();
}

//Overload the + operator so you can concatenate 2 arrays of size n
//and m into a new array of size n+m
int* Array::operator+(const Array& M) const {
	int totalSize = this->sizeOfArry + M.sizeOfArry;
	int *result = new int[totalSize];
	for (int i = 0; i < totalSize; i++) {
		if (i < this->sizeOfArry)
			result[i] = this->arrData[i];
		else
			result[i] = M.arrData[i - this->sizeOfArry];
	}
	return result;
}
int main() {
	Array A(20);
	Array B(20);
	A.addToTop(30);
	A.addToEnd(50);
	A.removeFromTop();
	A.removeFromBottom();
	A.reverseArray();
	int *DD;
	DD = A.checkOdd();
	cout << "Sum: " << A.returnSum() << endl;
	cout << "Size : " << A.getSize() << endl;
	A.writeToFile("Data.txt");
	DD = A + B;
	for (int i = 0; i < (A.getSize() + B.getSize()); i++)
		cout << DD[i] << endl;
	return 0;
}
