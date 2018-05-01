// mystring.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "String.h"


int _tmain(int argc, _TCHAR* argv[])
{
	String str("123456sdfghjjyttr");
	int n = str.Find("jj");
	printf("n=%d\n", n);
	return 0;
}

