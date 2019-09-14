#include <bits/stdc++.h>

#define ll long long int
#define new_line cout << endl

using namespace std;

int N;

struct Direction {
  int x;
  int y;
  char d;
};

struct Direction directions[4] = {
  {1, 0, 'D'},
  {0, -1, 'L'},
  {0, 1, 'R'},
  {-1, 0, 'U'}
};

bool outSide(int X, int Y)
{
  return X < 0 || Y < 0 || X >= N || Y >= N;
}

bool canMove(vector<int> maze[], vector<int> visited[], int X, int Y)
{
  if (outSide(X, Y) || visited[X][Y] == 1 || maze[X][Y] == 0) return false;

  return true;
}

void printSolution(string &path)
{
  cout<<path<<" ";
}

void ratInAMaze(vector<int> maze[], int X, int Y, string &path, vector<int> visited[])
{
  if (X == N - 1 && Y == N - 1) {
    printSolution(path);
    return;
  }

  for (int i = 0; i < 4; i++)
  {
    int newX = X + directions[i].x;
    int newY = Y + directions[i].y;

    if (canMove(maze, visited, newX, newY)) {
      path.push_back(directions[i].d);

      visited[newX][newY] = 1;

      ratInAMaze(maze, newX, newY, path, visited);

      path.pop_back();
      visited[newX][newY] = 0;
    }
  }
}

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    cin >> N;

    vector<int> maze[N];
    vector<int> visited[N];

    int num;

    for (int i = 0; i < N; i++)
    {
      visited[i] = vector<int>(N);
      for (int j = 0; j < N; j++)
      {
        cin >> num;
        maze[i].push_back(num);
      }
    }

    string path;

    visited[0][0] = 1;

    ratInAMaze(maze, 0, 0, path, visited);

    new_line;
  }

  return 0;
}