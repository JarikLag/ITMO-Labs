#include <iostream>
#include <string>
#include "ManBearPig.h"
using namespace std;

//task #2
typedef int* (*(*ComplexFunction)(int, int(*)(double)))(const char*);

//task #3
template<typename T, typename S> 
bool compare(const T& first, const T& second, S(T::*Method)() const) {
	return (first.*Method)() < (second.*Method)();
}

//task 4
template<class T>
bool isSameObject(const T* p, const T* q) {
	return dynamic_cast<const void*>(p) == dynamic_cast<const void*>(q);
}

int main()
{
	string s1("Elf");
	string s2("Archer");

	bool r1 = compare(s1, s2, &string::size);
	bool r2 = compare(s1, s1, &string::size);
	cout << r1 << endl;
	cout << r2 << endl;
	ManBearPig mbp(1, 3, 5);
	cout << "ID: " << mbp.id() << " HP: " << mbp.hp() << " IQ: " << mbp.iq() << endl;
	cout << mbp.say() << ' ' << mbp.roar() << ' ' << mbp.oink();
	return 0;
}
