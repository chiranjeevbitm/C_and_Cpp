// A C++ program for splitting a string using strtok()
#include <iostream>
#include <string.h>

int main()
{
	char str[] = "Geeks-for-Geeks";

	// Returns first token
	char *token = strtok(str, "-");

	// Keep printing tokens while one of the
	// delimiters present in str[].
	while (token != NULL)
	{
		std::cout << token << '\n';
		token = strtok(NULL, "-");
	}

	return 0;
}
