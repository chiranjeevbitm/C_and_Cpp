#include<iostream>
#include <sstream>
using namespace std;

string removeSpaces(string str)
{
	stringstream ss;
	string temp;

	/* Storing the whole string into string stream */
	ss << str;

	/* Making the string empty */
	str = "";

	/* Running loop till end of stream */
	while (!ss.eof())
	{
		/* extracting word by word from stream */
		ss >> temp;

		/* concatenating in the string to be
		returned*/
		str = str + temp;
	}
	return str;
}
int main()
{
	string s = "This is a test";
	cout << removeSpaces(s) << endl;

	s = "chiranjeev kumar";
	cout << removeSpaces(s) << endl;

	s = "Data Science is awsome!";
	cout << removeSpaces(s) << endl;

	s = "I love	     Machine Learning     ";
	cout << removeSpaces(s) << endl;

	return 0;
}
