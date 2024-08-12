// AxonInterview1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ConnectFour.h"

using namespace std;


void test_print2DArray(bool arr[ROWSIZE][COLSIZE], int rows, int cols)
{
	bool			value;
	cout << "Array: " << endl;

	for (int rowIndex = 0; rowIndex < rows; rowIndex++)
	{
		for (int colIndex = 0; colIndex < cols; colIndex++)
		{
			value = arr[rowIndex][colIndex];
			cout << value;
			if (colIndex != cols-1) 
			{
				cout << ",";
			}
		}
		cout << endl;
	}

	
	std::cout << endl;
}
void test_connect4()
{
	ConnectFour		game;
	bool			gameValues[ROWSIZE][COLSIZE] =		{ {true, false, true, false, true, false, true, false},
														  {false, true, true, true, true, false, true, true},
														  {true, false, true, true,  false, false, true, true},
														  {true, false, false, false, true, true, false, false},
														  {false, true, true, false, false, false, true, true},
														  {true, false, true, true,  true, false, true, true},
														  {true, false, false, false, true, true, false, false},
												          {false, false, true, true, false, false, true, true}
														};

	test_print2DArray(gameValues, ROWSIZE, COLSIZE);
	
	
	cout << "Straight line found: " << boolalpha << game.isStraightLine(gameValues, ROWSIZE, COLSIZE) << endl;

	cout << endl;
}

int main()
{
	std::cout << "Welcomes to Axon!" << endl << endl;

	test_connect4();
}
