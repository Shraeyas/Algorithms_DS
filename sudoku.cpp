#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int map[9][9];

bool solve(int [][9], int, int);

bool valid(int row, int col, int val)
{
	for(int i = 0 ; i < 9 ; i++)
	{
		if(map[row][i] == val)
		return false;
		
		if(map[i][col] == val)
		return false;
	}
	
	return true;
}

bool sudokuSolver(int board[][9])
{
	//memset(map, 0, 9*9*sizeof(int));
	
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			map[i][j] = board[i][j];
		}
	}
	
	return solve(map, 0, 0);
}

bool solve(int board[][9], int row, int col)
{
	if(row == 9)
    {
      for(int i = 0 ; i < 9 ; i++)
      {
        for(int j = 0 ; j < 9 ; j++)
        {
          cout << board[i][j] << " ";
        }
        
        cout << endl;
      }
      
      return true;
    }
	
	int ch = 0;
  
    if(map[row][col] != 0)
    {
        if(col == 8)
		{
			return solve(map, row + 1, 0);
		}
		
		else
		{
			return solve(map, row, col + 1);
		}
    }
	
	for(int val = 1 ; val <= 9 ; val++)
	{
		if(valid(row, col, val))
		{
            ch = 1;
			map[row][col] = val;
			
			if(col == 8)
			{
				return solve(map, row + 1, 0);
			}
			
			else
			{
				return solve(map, row, col + 1);
			}
			
			map[row][col] = 0;
		}
	}
  
	if(col == 8)
	{
		return solve(map, row + 1, 0);
	}
		
	else
	{
    	return solve(map, row, col + 1);
	}
  
}

int main()
{
	freopen("in.in", "r", stdin);
	
	int board[9][9];
	
	for(int i = 0 ; i < 9 ; i++)
	{
		for(int j = 0 ; j < 9 ; j++)
		{
			cin >> board[i][j];
		}
	}
	
	cout << (sudokuSolver(board) ? "true" : "false");
}

