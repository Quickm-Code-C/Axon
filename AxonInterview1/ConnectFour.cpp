#include <iostream>
#include "ConnectFour.h"

using namespace std;

string ConnectFour::isStraightLine(bool arr[ROWSIZE][COLSIZE], int rows, int cols)
{
	string		result;
	bool		found = false;

	found = (isVertLine(arr, rows, cols)  ||
			  isHorzLine(arr, rows, cols) ||
		      isDiagLeftLine(arr, rows, cols) || 
			  isDiagRightLine(arr, rows, cols)
		     );

	result = (found) ? "true" : "false";

	return result;
}

bool	ConnectFour::isVertLine(bool arr[ROWSIZE][COLSIZE], int rows, int cols)
{
	bool	result	 = false;
	int		count	 = 0;
	bool    value = false;

	for (int colIndex = 0; colIndex < cols && !result; colIndex++)
	{
		for (int rowIndex = 0; rowIndex < cols && !result; rowIndex++)
		{
			value = arr[rowIndex][colIndex];

			if (value)
			{
				count = count + 1;
			}
			
			else
			{
				count = 0;
			}

			if (count == 4)
			{
				result = true;
			}
		}

		count = 0;
	}


	return result;
}

bool	ConnectFour::isHorzLine(bool arr[ROWSIZE][COLSIZE], int rows, int cols)
{
	bool	result = false;
	int		count = 0;
	bool    value = false;

	for (int rowIndex = 0; rowIndex < rows && !result; rowIndex++)
	{
		for (int colIndex = 0; colIndex < cols && !result; colIndex++)
		{
			value = arr[rowIndex][colIndex];

			if (value)
			{
				count = count + 1;
			}

			else
			{
				count = 0;
			}

			if (count == 4)
			{
				result = true;
			}
		}

		count = 0;
	}


	return result;
}

bool	ConnectFour::isDiagLeftLine(bool arr[ROWSIZE][COLSIZE], int rows, int cols)
{
	bool	result = false;
	int		count = 0;
	bool    value = false;
	int		start = 0;
	// start at rowIndex = 0, colIndex = 3
	// iterate rowIndex++, colInndex--

	// covers diagonal right slices up to (0,0) --> (7,7)
	while (start <= cols)
	{
		for (int colIndex = start, rowIndex = 0; (colIndex < cols && rowIndex < rows) && !result; colIndex++, rowIndex++)
		{
			value = arr[rowIndex][colIndex];

			if (value)
			{
				count = count + 1;
			}

			else
			{
				count = 0;
			}

			if (count == 4)
			{
				result = true;
			}
		}
		count = 0;

		start++;
	}

	// covers below diagonal start used for rows, colIndex always starts at 7
	start = 1;
	while (start <= rows)
	{
		for (int colIndex = 0, rowIndex = start; (colIndex < cols && rowIndex < rows) && !result; colIndex++, rowIndex++)
		{
			value = arr[rowIndex][colIndex];

			if (value)
			{
				count = count + 1;
			}

			else
			{
				count = 0;
			}

			if (count == 4)
			{
				result = true;
			}
		}
		count = 0;

		start++;
	}



	return result;

}

bool	ConnectFour::isDiagRightLine(bool arr[ROWSIZE][COLSIZE], int rows, int cols)
{
	bool	result = false;
	int		count = 0;
	bool    value = false;
	int		start = 3;
	// start at rowIndex = 0, colIndex = 3
	// iterate rowIndex++, colInndex--

	// covers diagonal right slices up to (0,7) --> (7,0)
	while (start <= cols)
	{
		for (int colIndex = start, rowIndex = 0; colIndex >= 0 && !result; colIndex--, rowIndex++)
		{
			value = arr[rowIndex][colIndex];

			if (value)
			{
				count = count + 1;
			}

			else
			{
				count = 0;
			}

			if (count == 4)
			{
				result = true;
			}
		}
		count = 0;

		start++;
	}

	// covers below diagonal start used for rows, colIndex always starts at 7
	start = 1;
	while (start <= rows)
	{
		for (int colIndex = cols-1, rowIndex = start; (colIndex >= 0 && rowIndex < rows) && !result; colIndex--, rowIndex++)
		{
			value = arr[rowIndex][colIndex];

			if (value)
			{
				count = count + 1;
			}

			else
			{
				count = 0;
			}

			if (count == 4)
			{
				result = true;
			}
		}
		count = 0;

		start++;
	}



	return result;

}
