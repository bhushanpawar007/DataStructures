/*
 * Array.h
 *
 *  Created on: Feb 11, 2018
 *      Author: BHUSHAN
 */

#ifndef ARRAY_H
#define ARRAY_H
class Array {
public:
	Array(); //Default Constructor for the class
	Array(int); //Copy Constructor with size
	~Array(); //Destructor for the class
	int sizeOfArry; //Array size
	int *arrData; //integer Array
	int getSize(); //Function to access the size
	void displayArray(); //Display the content of the array
	void addToTop(int); //Function to Add an element at the beginning
	void addToEnd(int); //Function to Add an element at the end
	void removeFromTop(); //Function to Remove an element at the beginning
	void removeFromBottom(); //Function to Remove an element at the end
	void reverseArray(); //Function to Inverse the order of the elements in the array
	int returnSum(); //Function to Return the sum of the elements in the array
	int* checkOdd(); //Function to Return an array that contains the odd numbers only
	void writeToFile(char *); //Function to Display the content of the array in a file
	int* operator+(const Array&) const;
//concatenate 2 arrays of size n and m into a new array
protected:
private:
};
#endif // ARRAY_H
