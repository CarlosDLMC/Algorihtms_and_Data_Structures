#include <iostream>
#include<chrono>
#include <string>

using namespace std;

string reverseIt(string st){
	string sol;
	for(int i = st.length () - 1; i >= 0; i--){
		sol += st[i];
	}
	return sol;
}

string reverseRec(string st){
	if(st == ""){
		return "";
	}
	return reverseRec(st.substr (1)) + st[0];
}
int FibonacciRec(int n){
	if(n == 0){
		return 0;
	}
	if(n == 1){
		return 1;
	}
	return FibonacciRec (n - 1) + FibonacciRec (n - 2);
}

int FibonacciIt(int n){
	int a = 0;
	int b = 1;
	int temp;
	for(int i = 0; i < n; i++){
		temp = a;
		a = b;
		b = temp + b;
	}
	return a;
}

int indexFibIt(int n){
	int a = 0;
	int count = 0;
	int b = 1;
	int temp;
	while(a != n){
		temp = a;
		a = b;
		b = temp + b;
		count++;
	}
	return count;
}

long int factorial(long int n){
	if(n == 0){
		return 1;
	}
	return n * factorial(n - 1);

}

long int factorialit(int n){
	long int r = 1;
	for(int i = 1; i <= n; i++){
		r *= i;
	}
	return r;
}
int main()
{
	cout << "Recursivo:" << endl;
	auto t1 = chrono::high_resolution_clock::now();
	for(int i = 0; i < 30; i++){
		cout << "factorial(" << i << ") = " << factorial(i) << endl;
	}
	auto t2 = chrono::high_resolution_clock::now();
	cout << "Iterativo: " << endl;
	for(int i = 0; i < 30; i++){
		cout << "factorial(" << i << ") = " << factorial(i) << endl;
	}
	auto t3 = chrono::high_resolution_clock::now();
	auto difRec = chrono::duration_cast<chrono::microseconds>(t2 - t1);
	auto difIt = chrono::duration_cast<chrono::microseconds>(t3 - t2);
	cout << "Tiempo en hacerlo recursivo: " << difRec.count () << " microsegundos" << endl;
	cout << "Tiempo en hacerlo iterativo: " << difIt.count () << " microsegundos" << endl;
	cout << "\n\nFIBONACCI\n\n";
	cout << "Recursivo:" << endl;
	t1 = chrono::high_resolution_clock::now();
	for(int i = 0; i <= 20; i++){
		cout << " (recursive) At index " << i << ", Fibonacci = " << FibonacciRec (i) << endl;
	}
	t2 = chrono::high_resolution_clock::now();
	cout << "Iterativo: " << endl;
	for(int i = 0; i <= 20; i++){
		cout << "At index " << i << ", Fibonacci = " << FibonacciIt (i) << endl;
	}
	t3 = chrono::high_resolution_clock::now();

	difRec = chrono::duration_cast<chrono::microseconds>(t2 - t1);
	difIt = chrono::duration_cast<chrono::microseconds>(t3 - t2);
	cout << "Tiempo en hacerlo recursivo: " << difRec.count () << " microsegundos" << endl;
	cout << "Tiempo en hacerlo iterativo: " << difIt.count () << " microsegundos" << endl;

	cout << "Adivinando el index del numero" << endl;
	for(int n : {5, 8, 34, 21}){
		cout << "El numero " << n << " esta en el index " << indexFibIt (n) << endl;
	}
	cout << "\n\nREVERSE STRING\n\n";
	string frase;
	cout << "Escribe una frase: ";
	getline(cin, frase);
	cout << "Al reves es: " << reverseIt(frase) << endl;
	cout << "(recursivo) Al reves es: " << reverseIt(frase) << endl;
	return 0;
}
