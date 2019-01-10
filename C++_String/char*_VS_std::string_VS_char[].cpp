// Do not use cstring or string.h functions when you are declaring string with std::string keyword
//because std::string strings are of basic_string class type and cstring strings are of const char* type.
#include <iostream>
using namespace std;

int main()
{
	string s1 = "Hello";
	string s2 = "World";
  
	cout << s1.size() << endl;
	cout << s2.length() << endl;

	s1 = s1 + s2;
	cout << s1 << endl;

	s1.append("chiranjeev");
	cout << s1 << endl;

	string s3 = "HelloWorldChiranjeev";

	if (s1.compare(s3) == 0)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	string sub = s1.substr(0, 5);
	cout << sub << endl; // Hello

	s1.insert(10, "For");
	cout << s1 << endl;

	string target = "World";
	size_t pos = s1.find(target);
	if (pos != std::string::npos) // npos=-1
		cout << "Found at Position:" << pos << endl; // pos=5

	cout << s1.replace(5, 5, "Geeks") << endl;

	return 0;
}


// When to prefer char* to std::string
// 1. When dealing with lower level access like talking to the OS, but usually, if you’re passing the string to the
//   OS then std::string::c_str has it covered.
// 2. Compatibility with old C code (although std::string’s c_str() method handles most of this).
// 3. To conserve memory (std::string will likely have more overhead).
