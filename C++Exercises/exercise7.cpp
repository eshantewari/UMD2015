/*
 * Linux and C++ Exercise 7
 *
 *  Created on: Jul 13, 2015
 *      Author: Eshan Tewari
 */
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

//calculate the cross product of two 3X3 vectors specified
//in file exercise7.txt
int main(){

	string line;
	ifstream myfile ("exercise7.txt");
	vector<double> v1 (3);
	vector<double> v2 (3);
	int vectornum = 1;

	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			cout << "Vector " << vectornum << ": " << line << endl;
		    //split input string into vector components

			string buf; // Have a buffer string
		    stringstream ss(line); // Insert the string into a stream

		    vector<string> tokens; // Create vector to hold tokens
		    while (ss >> buf)
		        tokens.push_back(buf);
		    if(vectornum == 1){
		    	for(int i = 0; i < tokens.size(); i++){
		    		v1.at(i) = stod(tokens.at(i));
		    	}
		    }
		    if(vectornum == 2){
		    	for(int i = 0; i < tokens.size(); i++){
		    		v2.at(i) = stod(tokens.at(i));
		    	}
		    }
		    vectornum++;


		}
		myfile.close();
	}
	//compute cross product
	double i, j, k;
	i = v1.at(1)*v2.at(2)-v1.at(2)*v2.at(1);
	j = -(v1.at(0)*v2.at(2)-v1.at(2)*v2.at(0));
	k = v1.at(0)*v2.at(1)-v1.at(1)*v2.at(0);
	int size=3;
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
	cout << "Cross product: " << i << "i + " << j << "j + " << k << "k" << endl;

	return 0;
}

