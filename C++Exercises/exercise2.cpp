/*
 * Linux and C++ Exercise 2
 * Created on: Jul 13, 2015
 *      Author: Eshan Tewari
 */
#include <iostream>
using namespace std;

//Recursive Factorial Method
int factorial(int n){
	if(n == 0) return 1;
	return n*factorial(n-1);


}

//Call the factorial method with parameters 1,2,...10
int main() {
	for(int i = 1; i <= 10; i++){
		cout << i << " Factorial = " << factorial(i);
		cout << endl;
	}

	return 0;
}



