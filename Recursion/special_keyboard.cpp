#include <bits/stdc++.h>

#define ll long long int
#define new_line cout << endl

using namespace std;

map<int, int> memo;

int specialKeyboard(int N)
{
  if (memo[N]) return memo[N];

  if (N > 75) return -1;

  if (N <= 6) return N;

  int _max = 0;

  for (int i = N - 3; i >= 1; i--) {
    _max = max(_max, (N - i - 1) * specialKeyboard(i));
  }

  memo[N] = _max;

  return memo[N];
}

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    int N;
    cin >> N;

    cout<<specialKeyboard(N);

    new_line;
  }

  return 0;
}