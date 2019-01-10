// C++ program to demonstrate uses of some string function
#include<iostream>
using namespace std;

// this function returns floating point part of a number-string
string returnFloatingPart(string str)
{
	int pos = str.find(".");
	if (pos == string::npos)
		return "";
	else
		return str.substr(pos + 1);
}

// this function checks whether string contains all digit or not
bool containsOnlyDigit(string str)
{
	int l = str.length();
	for (int i = 0; i < l; i++)
	{
		if (str.at(i) < '0' || str.at(i) > '9')
			return false;
	}

	return true;
}

string replaceBlank(string str)
{
	string replaceby = ".";
	int n = 0; 

	// loop till all space are replaced
	while ((n = str.find(" ", n)) != string::npos )
	{
		str.replace(n, 1, replaceby);
		n += replaceby.length();
	}
	return str;
}

int main()
{
	string fnum = "23.342";
	cout << "Floating part is : " << returnFloatingPart(fnum)
		<< endl;

	string num = "3452";
	if (containsOnlyDigit(num))
		cout << "string contains only digit" << endl;

	string urlex = "google com in";
	cout << replaceBlank(urlex) << endl;

	return 0;
}
