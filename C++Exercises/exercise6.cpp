/*
 * Linux and C++ Exercise 6
 *
 *  Created on: Jul 13, 2015
 *      Author: Eshan Tewari
 */


#include <iostream>
#include <vector>
#include <math.h>


using namespace std;

//return the dot product of two vectors
double dotproduct(vector<double> v1, vector<double> v2){
	int product = 0;
	for(int i = 0; i < v1.size(); i++){
		product += v1.at(i)*v2.at(i);
	}
	return product;
}

//return the magnitude of a vector
double magnitude(vector<double> v){
	int sum = 0;
	for(int i = 0; i < v.size(); i++){
		sum += v.at(i)*v.at(i);
	}
	return sqrt(sum);
}

//calculate the angle between two vectors
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
	double angle = acos(dotproduct(v1, v2)/(magnitude(v1)*magnitude(v2)));
	cout << "Angle: " << angle;

	return 0;
}
