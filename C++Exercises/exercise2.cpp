#include <iostream>
using namespace std;

int factorial(int n){
	if(n == 0) return 1;
	return n*factorial(n-1);


}

int main() {
	for(int i = 1; i <= 10; i++){
		cout << i << " Factorial = " << factorial(i);
		cout << endl;
	}

	return 0;
}



