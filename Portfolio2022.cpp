// Portfolio2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <string>

using namespace std;



//********** Excercise 1***************
//Write a recursive algorithm/method, which takes a positive integer
// as parameter and returns the sum of the odd numbers squares from 1 to N.

int sumOfOddSquare(int N)
{

	if (N==0)
	{
		return 0;
	}
	else if (N%2 == 0)
	{

		return sumOfOddSquare(N - 1);
	}
	else
	{
		return pow(N,2)+ sumOfOddSquare(N - 1);
	}


}

//*******Exercise 2**********
//The algorithm returns true if the string contains a substring of three consecutive numbers 
//where the third character is the sum of the two previous characters.

bool additive(std::string s)
{
	int l = s.length();
	int y = l- 1;
	int a = l- 2;
	int b = l-3;

	if (l == 2)
	{
		return false;
	}
	else if ( int(s.at(y)) + 48 == int( s.at(a)) + int ( s.at(b))) // the ascii value of 0 = 48, 1=49 , etc..
	{
		return true;
	}
	else
	{
		return additive(s.substr(0,l-1));
	}

	return false;
}

int * getPowerOfTwo(int[])
{

	static int myArray[3];

	myArray[0] = 1;
	myArray[1] = 3;
	myArray[2] = 5;


	return myArray;
}
int main()
{
	
	cout << " The sum is " << sumOfOddSquare(8) << endl;

	cout << " Is there additive nr? " << additive("82842605") << endl;

	int random[13] = { 23,56,22,11,65,89,3,44,87,910,45,35,98 };

	int* numbers = getPowerOfTwo(random);

	


}
