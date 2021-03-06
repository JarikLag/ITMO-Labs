#include <iostream>
#include <typeinfo>
#include <tuple>

using namespace std;

//task #1
void print_values(ostream& stream) {}

template<typename T, typename... Args>
void print_values(ostream& stream, const T& value, const Args&... args) {
	stream << typeid(value).name() << ": " << value << endl;
	print_values(stream, args...);
}

//task #3
template<size_t I, size_t J, typename T>
auto to_pair(T const& t) -> decltype(make_pair(get<I>(t), get<J>(t))) {
	return make_pair(get<I>(t), get<J>(t));
}

int main()
{
	print_values(cout, "1", 2, -0.11, 'c');
	cout << endl;
	auto t = make_tuple(0, 3.5, "Hello");
	pair<double, const char*> p = to_pair<1, 2>(t);
	cout << p.first << ' ' << p.second;
	return 0;
}