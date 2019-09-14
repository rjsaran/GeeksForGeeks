#include <bits/stdc++.h>

#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

#define ll long long int
#define new_line cout << endl

using namespace std;

void combinationSum(int A[], int i, int N, int B, vector<int> &path)
{
  if (i >= N) return;

  if (B == 0) {
    cout<<"(";
    for (auto it : path) {
      cout<<it<<" ";
    }
    cout<<"\b)";
  }

  if (B >= A[i]) { 
    path.push_back(A[i]);

    combinationSum(A, i + 1, N, B - A[i], path);

    path.pop_back();

    combinationSum(A, i + 1, N, B, path);
  }
}

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    int N, B;
    cin >> N;

    int A[N];

    for (int i = 0; i < N; i++)
    {
      cin >> A[i];
    }

    cin >> B;

    vector<int> path;

    sort(A, A + N);

    combinationSum(A, 0, N, B, path);

    new_line;
  }

  return 0;
}