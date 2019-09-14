#include <bits/stdc++.h>

#define new_line cout << endl
#define N 9

using namespace std;

bool canBePlaced(vector<int> sudoku[], int x, int y, int k)
{
  for (int i = 0; i < N; i++)
  {
    if (sudoku[x][i] == k || sudoku[i][y] == k)
      return false;
  }

  int _x = 3 * (x / 3);
  int _y = 3 * (y / 3);

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (sudoku[_x + i][_y + j] == k)
        return false;
    }
  }

  return true;
}

void printSudoku(vector<int> sudoku[])
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cout << sudoku[i][j] << " ";
    }
    new_line;
  }
}

void solveSudoku(vector<int> sudoku[], int position)
{
  int row = position / N;
  int col = position % N;

  // Print solution
  if (row >= N || col >= N)
  {
    printSudoku(sudoku);
    return;
  }

  if (sudoku[row][col])
  {
    solveSudoku(sudoku, position + 1);
    return;
  }

  for (int i = 1; i <= N; i++)
  {
    if (canBePlaced(sudoku, row, col, i))
    {
      sudoku[row][col] = i;

      solveSudoku(sudoku, position + 1);

      sudoku[row][col] = 0;
    }
  }
}

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    vector<int> sudoku[N];

    int num;

    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        cin >> num;
        sudoku[i].push_back(num);
      }
    }

    solveSudoku(sudoku, 0);

    new_line;
  }

  return 0;
}