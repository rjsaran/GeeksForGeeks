#include <bits/stdc++.h>

#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

#define ll long long int
#define new_line cout << endl

using namespace std;

int numberOfPaths(int M, int N)
{
  if (M <= 0 || N <= 0)
    return 0;

  if (M == 1 && N == 1)
    return 1;

  return numberOfPaths(M, N - 1) + numberOfPaths(M - 1, N);
}

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    int M, N;
    cin >> M >> N;

    cout<<numberOfPaths(M, N);

    new_line;
  }

  return 0;
}