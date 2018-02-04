#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int map[9][9];

bool solve(int [][9], int, int);

bool valid(int row, int col, int val)
{
    int s1 = row/2, s2 = col/2;
    s1 *= 3;
    s2 *= 3;
    
    for(int i = s1 ; i < s1 + 3 ; i++)
    {
        for(int j = s2 ; j < s2 + 3 ; j++)
        {
            if(map[i][j] == val)
              return false;
        }
    }
    
	for(int i = 0 ; i < 9 ; i++)
	{
		if(map[row][i] == val)
		return false;
		
		if(map[i][col] == val)
		return false;
	}
	
	return true;
}

bool fill(int board[][9])
{
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			if(board[i][j] == 0)
			{
				return false;
			}
		}
	}
	
	return true;
}

bool sudokuSolver(int board[][9])
{
	if(fill(board))
	{
		return true;
	}
	
	for(int  val = 1 ; val <= 9 ; val++)
	{
		
	}
}
