#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char s1[10] = "Hello";

	cout << strlen(s1) << endl;

	char s2[50];

	strcpy(s2, s1);
	cout << s2 << endl;

	char s3[10] = "World";

	strcat(s2, s3);
	cout << s2 << endl;

	char s4[50] = "HelloWorld";

	if (strcmp(s2, s4) == 0)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	char s5[30];
	strncpy(s5, s4, 5);
	cout << s5 << endl;

	char target[10] = "Hello"; 

	// search for target string in s4
	if (strstr(s4, target) != NULL)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}
