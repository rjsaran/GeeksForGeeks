#include <bits/stdc++.h>

#define ll long long int
#define new_line cout << endl

using namespace std;

int N;

bool outSide(int i, int j)
{
  return i < 0 || j < 0 || i > N || j > N;
}

bool canBePlaced(vector<int> A[], int x, int y, int N)
{
  // Check current row on left side
  for (int i = 0; i < y; i++)
    if (A[x][i] == 1)
      return false;

  for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
    if (A[i][j] == 1)
      return false;

  for (int i = x, j = y; i < N && j >= 0; i++, j--)
    if (A[i][j] == 1)
      return false;

  return true;
}

void printSolution(vector<int> A[], int N)
{
  cout << "[";
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (A[j][i] == 1)
        cout<<j + 1<<" ";
    }
  }
  cout << "] ";
}

/*
0: empty cell
1: queen
*/
bool NQueen(vector<int> A[], int c, int N)
{
  // Print solution
  if (c >= N)
  {
    printSolution(A, N);
    return true;
  }

  bool possibleSolution = false;

  // Try every row of column c
  for (int i = 0; i < N; i++)
  {
    if (canBePlaced(A, i, c, N))
    {
      // cout<<i<<"  "<<c<<endl;
      // Place queen at ith row, cth column
      A[i][c] = 1;

      // Try new column
      possibleSolution = NQueen(A, c + 1, N) || possibleSolution;

      // Remove queen from ith row, cth column
      A[i][c] = 0;
    }
  }

  return possibleSolution;
}

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    cin >> N;

    vector<int> A[N];

    for (int i = 0; i < N; i++)
    {
      A[i] = vector<int>(N);
    }

    bool possibleSolution = NQueen(A, 0, N);

    if (!possibleSolution) cout<<-1;

    new_line;
  }

  return 0;
}