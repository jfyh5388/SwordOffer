#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

void Combination(char* string, int number, vector<char>& result)
{
	if (number == 0)
	{
		vector<char>::iterator iter = result.begin();
		for (; iter < result.end(); ++iter)
			printf("%c", *iter);
		printf("\n");

		return;
	}

	if (*string == '\0')
		return;

	result.push_back(*string);
	Combination(string + 1, number - 1, result);
	result.pop_back();

	Combination(string + 1, number, result);
}
int main()
{
	char *str = "abc";
	vector<char> ans;
	int size = strlen(str);
	for(int i = 1; i<=size;i++)
		Combination(str, i, ans);
	system("pause");
	return 0;
}