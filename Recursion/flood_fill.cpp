#include <bits/stdc++.h>

#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

#define ll long long int
#define new_line cout << endl

using namespace std;

int M, N;

pair<int, int> directions[4] = {
  make_pair(0, 1),
  make_pair(1, 0),
  make_pair(0, -1),
  make_pair(-1, 0)
};

map<int, bool> visited;

bool outSide(int X, int Y)
{
  return X < 0 || Y < 0 || X >= M || Y >= N;
}

int position(int X, int Y)
{
  return X * N + Y;
}

void floodFill(int A[], int X, int Y, int K)
{
  int pos = position(X, Y);
  visited[pos] = true;

  for (int i = 0; i < 4; i++) {
    int newPositionX = X + directions[i].first;
    int newPositionY = Y + directions[i].second;

    int newPosition = position(newPositionX, newPositionY);

    if (!outSide(newPositionX, newPositionY) && A[pos] == A[newPosition] && !visited[newPosition]) {
      floodFill(A, newPositionX, newPositionY, K);
    }
  }

  A[pos] = K;
}

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    int X, Y, K;
    cin >> M >> N;

    int size = M * N;

    int A[size];

    for (int i = 0; i < size; i++)
    {
      cin >> A[i];
    }

    cin >> X >> Y >> K;

    visited.clear();

    floodFill(A, X, Y, K);

    for (int i = 0; i < size; i++)
    {
      cout << A[i] << " ";
    }
    new_line;
  }

  return 0;
}