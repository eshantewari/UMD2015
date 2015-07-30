/*
 * Linux and C++ Exercise 5
 *
 *  Created on: Jul 13, 2015
 *      Author: Eshan Tewari
 */

#include <iostream>
#include <vector>


using namespace std;


//Calculate the dot product of two vectors
int main(){
	int size;
	cout << "Enter size of array: " << endl;
	cin >> size;
	vector<double> v1(size);
	vector<double> v2(size);
	cout << "Enter vector 1 values" << endl;
	for(int i = 0; i < size; i++){
		int temp;
		cin >> temp;
		v1.at(i) = temp;
	}
	cout << "Enter vector 2 values separated by space" << endl;
	for(int i = 0; i < size; i++){
		int temp;
		cin >> temp;
		v2.at(i) = temp;
	}

	int product = 0;
	for(int i = 0; i < size; i++){
		product += v1.at(i)*v2.at(i);
	}
	cout << "Vector 1: " << endl;
	cout << "<";
	for(int i = 0; i < size-1; i++){
		cout << v1.at(i) << ", ";
	}
	cout << v1.at(size-1) << ">" << endl;
	cout << "Vector 2: " << endl;
	cout << "<";
	for(int i = 0; i < size-1; i++){
		cout << v2.at(i) << ", ";
	}
	cout << v2.at(size-1) << ">" << endl;
	cout << "Dot Product: "<< product << endl;
	return 0;
}
