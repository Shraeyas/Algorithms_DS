#include <tr1/unordered_map>
#include <iostream>

using namespace std;

tr1 :: unordered_map <int, tr1 :: unordered_map <int, int> > grid;

int l;

void solve(int, int, int);

void placeNQueens(int n)
{
  l = n;
  solve(n, 0, 0);
}

void mark(int x, int y)
{
  for(int i = 0 ; i < l ; i++)
  {
    grid[i][y] = 1;
  }

  for(int j = 0 ; j < l ; j++)
  {
    grid[x][j] = 1;
  }

  int i = x, j = y;

  while(i < l && j < l)
  {
    grid[i++][j++] = 1;
  }

  i = x, j = y;
  while(i >= 0 && j < l)
  {
    grid[i--][j++] = 1;
  }

  i = x, j = y;
  while(i >= 0 && j >= 0)
  {
    grid[i--][j--] = 1;
  }

  i = x, j = y;
  while(i < l && j >= 0)
  {
    grid[i++][j--] = 1;
  }

  grid[x][y] = 2;

}

void unmark(int x, int y)
{

  for(int i = 0 ; i < l ; i++)
  {
    grid[i][y] = 0;
  }

  for(int j = 0 ; j < l ; j++)
  {
    grid[x][j] = 0;
  }

  int i = x, j = y;

  while(i < l && j < l)
  {
    grid[i++][j++] = 0;
  }

  i = x, j = y;
  while(i >= 0 && j < l)
  {
    grid[i--][j++] = 0;
  }

  i = x, j = y;
  while(i >= 0 && j >= 0)
  {
    grid[i--][j--] = 0;
  }

  i = x, j = y;
  while(i < l && j >= 0)
  {
    grid[i++][j--] = 0;
  }

}

void func()
{
	for(int i = 0 ; i < l ; i++)
    {
      for(int j = 0 ; j < l ; j++)
      {
        cout << (grid[i][j]) << " ";
      }

    cout << endl;
	}
	cout << endl;
}

void solve(int n, int x, int y)
{
  if(n == 0)
  {
  	for(int i = 0 ; i < l ; i++)
    {
      for(int j = 0 ; j < l ; j++)
      {
        cout << (grid[i][j] == 2 ? 1 : 0) << " ";
      }
    }

    cout << endl;

    return;
  }

  for(int i = 0 ; i < l ; i++)
  {
  	int j = x;
    //for(int j = 0 ; j < l ; j++)
    {
      if(grid[i][j] == 0)
      {
        tr1 :: unordered_map <int, tr1 :: unordered_map <int, int> > go;
		for(int p = 0 ; p < l ; p++)
		{
		    for(int s = 0 ; s < l ; s++)
	    	{
	    		go[p][s] = grid[p][s];
	    		//mark(p, s);
	    	}
	    }

		mark(i, j);

		solve(n - 1, i, j);

        //grid = go;
		//unmark(i, j);

		for(int p = 0 ; p < l ; p++)
		{
		    for(int s = 0 ; s < l ; s++)
	    	{
	    		grid[p][s] = go[p][s];

	    	}
	    }
      }
    }
  }
}


int main()
{
	placeNQueens(4);
}
