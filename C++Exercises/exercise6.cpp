/*
 * angle.cpp
 *
 *  Created on: Jul 13, 2015
 *      Author: eshan
 */


#include <iostream>
#include <vector>
#include <math.h>


using namespace std;

double dotproduct(vector<double> v1, vector<double> v2){
	int product = 0;
	for(int i = 0; i < v1.size(); i++){
		product += v1.at(i)*v2.at(i);
	}
	return product;
}

double magnitude(vector<double> v){
	int sum = 0;
	for(int i = 0; i < v.size(); i++){
		sum += v.at(i)*v.at(i);
	}
	return sqrt(sum);
}

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

	double angle = acos(dotproduct(v1, v2)/(magnitude(v1)*magnitude(v2)));
	cout << "Angle: " << angle;

	return 0;
}
