/*
 * RecursionAndLoops.cpp
 *
 *  Created on: Feb 11, 2018
 *      Author: BHUSHAN
 */
#include<iostream>
#include <stdlib.h>
using namespace std;
//Implementation of factorial with “for loop”
int factFor(int n) {
	int sum = 1;
	for (int i = 1; i <= n; i++)
		sum *= i;
	return sum;
}
//Implementation of factorial with “while loop”
int factWhile(int n) {
	int sum = 1;
	int i = 1;
	while (i <= n) {
		sum *= i;
		i++;
	}
	return sum;
}
//Implementation of factorial with recursion
int fact(int n) {
	if (n == 0)
		return 1;
	else
		return fact(n - 1) * n;
}
//Implementation of Fibonacci with “for loop”
int FibFor(int n) {
	int sum = 1;
	int prevSum = 1;
	int temp;
	if (n < 2)
		return n;
	for (int i = 2; i < n; ++i) {
		temp = sum;
		sum += prevSum;
		prevSum = temp;
	}
	return sum;
}
//Implementation of Fibonacci with “while loop”
int FibWhile(int n) {
	int sum = 1;
	int prevSum = 1;
	int temp;
	int i = 2;
	if (n < 2)
		return n;
	while (i < n) {
		i++;
		temp = sum;
		sum += prevSum;
		prevSum = temp;
	}
	return sum;
}
//Implementation of Fibonacci with recursion
int fib(int n) {
	if (n < 2)
		return n;
	else
		return (fib(n - 1) + fib(n - 2));
}
//Find an implementation of the Hanoi Tower recursively
void Hanoi(int n, int A, int B, int C) {
	if (n > 0) {
		Hanoi(n - 1, A, C, B);
		cout << "Move Disk from " << A << " to " << C << endl;
		Hanoi(n - 1, B, A, C);
	}
}
int main() {
	cout << factFor(5) << endl;
	cout << factWhile(5) << endl;
	cout << fact(5) << endl;
	cout << FibFor(5) << endl;
	cout << factWhile(5) << endl;
	cout << fact(5) << endl;
	Hanoi(4, 1, 2, 3);
	return 0;
}
