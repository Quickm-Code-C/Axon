#pragma once

#include <string>


const int ROWSIZE = 8;
const int COLSIZE = 8;


/**
Input: 2D boolean array
Output: boolean - 4 consecutive trues in a straight line (horiz, vert, diag left, diag right)
*/


class ConnectFour
{
public:
	std::string		isStraightLine(bool arr[ROWSIZE][COLSIZE], int rows, int cols);

protected:
	bool			isVertLine(bool arr[ROWSIZE][COLSIZE], int rows, int cols);
	bool			isHorzLine(bool arr[ROWSIZE][COLSIZE], int rows, int cols);
	bool		isDiagLeftLine(bool arr[ROWSIZE][COLSIZE], int rows, int cols);
	bool		isDiagRightLine(bool arr[ROWSIZE][COLSIZE], int rows, int cols);
};

