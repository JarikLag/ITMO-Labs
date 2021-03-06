#include <iostream>
#include "Quaternion.hpp"
#include <string>
#include <vector>

using namespace std;

int main()
{
	Quaternion a, b({ 5, 0, 3, 4 });
	cin >> a;
	cout << a << endl << b << endl;
	cout << "a + b: " << a + b << endl;
	cout << "a * b: " << a * b << endl;
	cout << "a / b: " << a / b << endl;
	Quaternion c;
	c = a % b;
	cout << "a % b: " << c << endl;
	cout << "a | b: "<< (a | b) << endl;
	cout << "a ^ b: " << (a ^ b) << endl;
	cout << "a == b: " << (a == b) << endl;
	a >>= 1;
	cout << "a >>= 1: " << a << endl;
	b <<= 2;
	cout << "a <<= 2: " << b << endl;
	cout << "*b: " << *b << endl;
	cout << "a(v): " << a(3, 4, 5) << endl;
	vector<bool> v = { 1, 0, 0, 1 };
	cout << "a->v: " << a->*v << endl;
	cout << "a.isEqual(b): " << a.isEqual(b) << endl;
	return 0;
}