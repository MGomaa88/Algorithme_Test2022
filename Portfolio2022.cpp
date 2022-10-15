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

	if (N == 0)
	{
		return 0;
	}
	else if (N % 2 == 0)
	{

		return sumOfOddSquare(N - 1);
	}
	else
	{
		return pow(N, 2) + sumOfOddSquare(N - 1);
	}


}

//*******Exercise 2**********
//The algorithm returns true if the string contains a substring of three consecutive numbers 
//where the third character is the sum of the two previous characters.

bool additive(std::string s)
{
	int l = s.length();
	int y = l - 1;
	int a = l - 2;
	int b = l - 3;

	if (l == 2)
	{
		return false;
	}
	else if (int(s.at(y)) + 48 == int(s.at(a)) + int(s.at(b))) // the ascii value of 0 = 48, 1=49 , etc..
	{
		return true;
	}
	else
	{
		return additive(s.substr(0, l - 1));
	}

	return false;
}

/*
************* Exercise 4 ****************
Write an algorithm that takes an array of unsorted, unique natural numbers as input 
and finds the three numbersin the array whose sum is closest to a power of 2. 
The same number can only be used once.
 */
int* getPowerOfTwo(int input[], int length)
{
    int powerTwo[10];
	static int myArray[4];
	for (size_t i = 0; i < sizeof powerTwo / sizeof(powerTwo[0]); i++)
	{
		powerTwo[i] = pow(2, i + 2);
	}


	for (size_t first = 0; first < length - 2; first++)
	{


		for (size_t second = first + 1; second < length - 1; second++)
		{


			for (size_t third = second + 1; third < length; third++)
			{

				int tot = input[first] + input[second] + input[third];

				for (size_t i = 0; i < sizeof powerTwo / sizeof(powerTwo[0]); i++)
				{
					 if (tot == powerTwo[i] ||  tot == powerTwo[i] - 1)
					{
						myArray[0] = input[first];
						myArray[1] = input[second];
						myArray[2] = input[third];
						myArray[3] = powerTwo[i];

						break;
					}
				}
			}
		}
	}

return myArray;
}

/* ************ Excercise 6 *************
The algorithm returns the sum of integers greater than 0 
and smaller than or equal to N that are divisible by 3.
Called with N = 12 the correct return value is 30 (3+6+9+12).
*/
int sumDivisibleBy3(int N)
{


	if (N == 0)
	{
		return 0;
	}
	else if (N % 3 == 0)
	{

		return N + sumDivisibleBy3(N - 1);
	}
	else
	{
		return sumDivisibleBy3(N - 1);
	}


}
/* ************ Exercise 7 *************

*/

int* getXandY( int Z)
{
	static int myArray[2];	
	bool checkMe = true;;
	int total, x=3 ;


	while (checkMe)
	{
		
	for (int y=3; y < 11; y++)
	{
		total = pow(x, y);
		checkMe = true;
		
			if ( total == Z)
			{
				myArray[0] = x;
				myArray[1] = y;
				checkMe = false;
				y = 10;
				
			}
			else if (total > Z)
			{
				y = 10;
			}

	}

	x++;
	}


	return myArray;
}

int main()
{
	cout << "\n****** Excercise 1 *******"  << endl;
	cout << " The sum of odd square of 8 is " << sumOfOddSquare(8) << endl;


	cout << "\n****** Excercise 2 *******" << endl;
	cout << " Is there additive in 82842605 ? " << additive("82842605") << endl;



	cout << "\n****** Excercise 4 *******" << endl;

	cout << "\n array=  23,56,22,11,65,89,3,44,87,910,45,35,98" << endl;
	cout << "\n The three numbers in the array which their sum is near to power of two are " << endl;
	int random[13] = { 23,56,22,11,65,89,3,44,87,910,45,35,98 };
	int* numbers = getPowerOfTwo(random, 13);
	for (size_t i = 0; i < 4; i++)
	{
		cout << numbers[i] << endl;
	}


	cout << "\n****** Excercise 6 *******" << endl;
	cout << "\nsum of integers that are divisible by 3. The inserted number is 14 " << endl;
	cout << sumDivisibleBy3(14) << endl;



	cout << "\n****** Excercise 7 *******" << endl;
	int* xy = getXandY(6561);

	for (int r = 0; r < 2; r++)
	{

	  cout <<xy[r] << endl;
	}


	cout << pow( 3,10) << endl;

}
