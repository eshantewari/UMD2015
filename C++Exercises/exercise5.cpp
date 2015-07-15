/*
 * exercise5.cpp
 *
 *  Created on: Jul 13, 2015
 *      Author: eshan
 */

#include <iostream>
#include <vector>


using namespace std;



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
	cout << "Enter vector 2 values" << endl;
	for(int i = 0; i < size; i++){
		int temp;
		cin >> temp;
		v2.at(i) = temp;
	}

	int product = 0;
	for(int i = 0; i < size; i++){
		product += v1.at(i)*v2.at(i);
	}
	cout << "Dot Product: "<< product;
	return 0;
}
