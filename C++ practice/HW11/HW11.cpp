#include <iostream>
#include <vector>
#include <sstream>
#include "bad_from_string.h"

template<class T>
T from_string(std::string const& s) {
	std::istringstream stream(s);
	stream.exceptions(std::istringstream::failbit | std::istringstream::badbit);
	stream >> std::noskipws;
	T result;
	try {
		stream >> result;
	}
	catch (std::istringstream::failure& f) {
		throw bad_from_string(f.what());
	}
	try {
		char c;
		stream >> c;
	}
	catch (std::istringstream::failure& f) {
		return result;
	}
	throw bad_from_string("Coversion failed");
}

int main()
{
	std::cout << "It's exceptions time!" << std::endl;
	std::vector<std::string> strings{ "123", "12.3", "", " ", "abc", " 123", "123 ", "12 3", "-1", "a", "A" , "-10" , "1.000000e-02" };
	for (auto& str : strings) {
		std::cout << std::endl << "from_string(\"" << str << "\"):";

		try { 
			std::cout << std::endl << "<string>: "; 
			std::cout << from_string<std::string>(str); 
		}
		catch (bad_from_string const& e) {
			std::cout << e.what();
		}

		try { 
			std::cout << std::endl << "<double>: "; 
			std::cout << from_string<double>(str); 
		}
		catch (bad_from_string const& e) {
			std::cout << e.what();
		}

		try { 
			std::cout << std::endl << "<int>   : "; 
			std::cout << from_string<int>(str); 
		}
		catch (bad_from_string const& e) {
			std::cout << e.what();
		}

		try { 
			std::cout << std::endl << "<char>  : "; 
			std::cout << from_string<char>(str); 
		}
		catch (bad_from_string const& e) {
			std::cout << e.what();
		}

		std::cout << std::endl;
	}
	return 0;
}