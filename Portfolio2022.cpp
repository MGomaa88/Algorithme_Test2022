// Portfolio2022.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <math.h>
#include <string>
#include <cmath>
#include <array>
#include <vector>

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
		int temp = N - 2;
		if (temp > 0)
		  return pow(N, 2) + sumOfOddSquare(temp);

		
		else 
			return pow(N, 2) + sumOfOddSquare(N - 1);
	}


}

//*******Exercise 3 **********
//The algorithm returns true if the string contains a substring of three consecutive numbers 
//where the third character is the sum of the two previous characters.

bool additive(std::string s)
{
	size_t l = s.length();
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
		return additive(s.substr(0, y));
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
	// Time complexity : n * 1 + n * n * n * 1 * n * 4 = n + 4n^4 = O(n^4)
	int powerTwo[10];
	static int myArray[4];
	for (int i = 0; i < sizeof powerTwo / sizeof(powerTwo[0]); i++)
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
					if (tot == powerTwo[i] || tot == powerTwo[i] - 1 || tot == powerTwo[i] + 1)
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
Write an algorithm that can decide if a given natural number Z < 100,000 (the parameter of the algorithm)
can be written as Z=X^Y where X and Y are integers with X > 2 and Y > 2.
6561 is an example of a natural number that can be written as X^Y
  where X and Y are integers, i.e. 9^4. Another example is 3125 (5^5).
*/
// Optimize the algorithm by finding X
int optimizeX(int Z)
{
	int x;

	for (int y = 3; y < 11; y++)
	{
		double yFraction = static_cast<double> (1) / y;
		x = std::round(pow(Z, yFraction));

		int zFake = pow(x, y);

		if (zFake == Z)
			return x;

	}

	return 0;
}

int* getXandY(int Z)
{
	static int myArray[2];
	bool checkMe = true;
	int total = 0;
	int x = 3;


	// Solution before optimizing
	/*while (checkMe)
	{
		for (int y = 3; y < 11; y++)
		{
			total = pow(x, y);

			if (total == Z)
			{
				myArray[0] = x;
				myArray[1] = y;

			}

			if (pow(x,3) > 100000)
				checkMe = false;

		}

		x++;
	}*/

	// solution after optmizing 
	if (optimizeX(Z) > 2)
	{
		myArray[0] = optimizeX(Z);

		for (int y = 3; y < 11; y++)
		{
			total = pow(optimizeX(Z), y);

			if (total == Z)
				myArray[1] = y;



		}
	}
	return myArray;
}

/* ****** Excercise 10 *************
The algorithm returns the base 2 logarithm of N, and it is a precondition that N is a positive number and a power of 2.
Called with N = 32 it returns 5, and with N = 4096 returns 12.
*/
int logTo(int N)
{
	if (N == 1)
		return 0;


	else
		return logTo(N / 2) + 1;

}

/* ************ Excercise 11 **********
*/
int getNumberOfVotes(int input[], int length)
{
	
	// First solution to this excercise 
	// Time complexity: 1 + 1 + 1+ n + 1+ n + n = 4 + 3n = O(n)
	int majority = length/2;
	int min = input[0];
	int max = 0;

	for (size_t i = 0; i < length; i++)
	{
		if (input[i] > max)
		{
			max = input[i];
		}
		if (input[i] < min)
		{
			min = input[i];
		}
	}
     // int myArr [max +1];  // not possible
	vector <int> v(max+1);

	for (int j = 0; j < length; j++)
	{
		int value = input[j];

		// we incerment by one for each value
		v[value] = v[value]+1;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > majority)
			return i;
		
	}



	// Here another solution with 
	// time complextiy: 1 + 1 + n * (1 + 1 + n + 1 + 1 + 1 ) = 2 + 5n + n^2 = O(n^2) 
	/*
	int temp = 0;
	int counter = 0;
	vector <vector< int > > bigVec;

	
	for (size_t i = min; i <= max; i++)
	{
		vector <int> myVec;
		myVec.push_back(i);
		temp = i;
		for (size_t r = 0; r < length; r++)
		{

			if (temp == input[r])
			{
				counter++;
			}
		}
		if (counter > majority)
		{
			return i ;
		}
		myVec.push_back(counter);
		bigVec.push_back(myVec);
		counter = 0;

	}*/

	return -1;
}

int main()
{
	cout << "\n****** Excercise 1 *******" << endl;
	cout << " The sum of odd square of 8 is " << sumOfOddSquare(8) << endl;
	cout << " The sum of odd square of 15 is " << sumOfOddSquare(15) << endl;

	cout << "\n****** Excercise 3 *******" << endl;
	cout << " Is there additive in 82842605 ? " << additive("82842605") << endl;
	cout << " Is there additive in 8284605 ? " << additive("8284605") << endl;


	cout << "\n****** Excercise 4 *******" << endl;

	cout << "\n The three numbers in the array which their sum is near to power of two are " << endl;
	cout << "\n array 1 =  23,56,22,11,65,89,3,44,87,910,45,35,98" << endl;
	int random[13] = { 23,56,22,11,65,89,3,44,87,910,45,35,98 };
	int* numbers = getPowerOfTwo(random, 13);
	for (size_t i = 0; i < 4; i++)
	{
		cout << numbers[i] << endl;
	}
	cout << "\n array 2 =  25,18,22,11,88,77,5,22,87,317,95,35,69" << endl;
	int random2[13] = { 25,18,22,11,88,77,5,22,87,317,95,35,69 };
	int* numbers2 = getPowerOfTwo(random2, 13);
	for (size_t i = 0; i < 4; i++)
	{
		cout << numbers2[i] << endl;
	}


	cout << "\n****** Excercise 6 *******" << endl;
	cout << "\nsum of integers that are divisible by 3.  " << endl;
	cout << "The inserted number is 14= " << sumDivisibleBy3(14) << endl;
	cout << "The inserted number is 21= " << sumDivisibleBy3(21) << endl;


	cout << "\n****** Excercise 7 *******" << endl;
	int* xy = getXandY(2401);
	cout << " getXandY(2401) " << endl;
		cout << " X= " << xy[0] <<endl;
		cout << " Y= " << xy[1] << endl;


	cout << "\n****** Excercise 10 *******" << endl;
	cout << "LogTo(1000) is " << logTo(1000) << endl;
	cout << "LogTo(4096) is " << logTo(4096) << endl;
 
	cout << "\n****** Excercise 11 *******" << endl;
	int myArr[] = { 7,4,3,5,3,1,6,4,5,1,7,5 };
	cout << "Array { 7,4,3,5,3,1,6,4,5,1,7,5}" << endl;
	cout <<" Is there majority? " << getNumberOfVotes(myArr, 12) << endl;

	cout << " Another array { 5,4,3,5,5,5,6,5,5,1,5,7}" << endl;
	int myArr2[] = { 5,4,3,5,5,5,6,5,5,1,5,7 };
	cout << " Is there majority? " << getNumberOfVotes(myArr2, 12) << endl;

}
