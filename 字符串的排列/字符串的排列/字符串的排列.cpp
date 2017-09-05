#include<iostream>  
#include<assert.h>  
#include<stdlib.h> 
using namespace std;

//在[nBegin,nEnd)区间中是否有字符与下标为pEnd的字符相等  
bool IsSwap(char* pBegin, char* pEnd)
{
	char *p;
	for (p = pBegin; p < pEnd; p++)
	{
		if (*p == *pEnd)
			return false;
	}
	return true;
}

void Permutation(char* pStr, char* pBegin)
{
	assert(pStr && pBegin);
	
	if (*pBegin == '\0')
		printf("%s\n", pStr);
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; pCh++)
		{
			if (IsSwap(pBegin, pCh))
			{
				swap(*pBegin, *pCh);
				Permutation(pStr, pBegin + 1);
				swap(*pBegin, *pCh);
			}
		}
	}
}

int main(void)
{
	char str[] = "abb";
	Permutation(str, str);	
	system("PAUSE");
	return 0;
}