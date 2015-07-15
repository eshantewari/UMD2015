/*
 * exercise7.cpp
 *
 *  Created on: Jul 13, 2015
 *      Author: eshan
 */
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

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
		    string buf; // Have a buffer string
		    stringstream ss(line); // Insert the string into a stream

		    vector<string> tokens; // Create vector to hold our words
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

	double i, j, k;
	i = v1.at(1)*v2.at(2)-v1.at(2)*v2.at(1);
	j = -(v1.at(0)*v2.at(2)-v1.at(2)*v2.at(0));
	k = v1.at(0)*v2.at(1)-v1.at(1)*v2.at(0);
	cout << "Cross product: " << i << "i + " << j << "j + " << k << "k" << endl;

	return 0;
}

