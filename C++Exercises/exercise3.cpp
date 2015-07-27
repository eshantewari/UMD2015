/*
 * Linux and C++ Exercise 3
 *  Created on: Jul 13, 2015
 *      Author: Eshan Tewari
 */
#include <iostream>

using namespace std;

//Display all factors of i, in pairs
int main(){
	for(int i = 1; i <= 100; i++){
		cout << "Factors of " << i << ":";
		cout << endl;
		for(int j = 1; j <= i; j++){
			if(i % j == 0){
				cout << j << " ";
			}
		}
		cout << endl;
	}

	return 0;
}



