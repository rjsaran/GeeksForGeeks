// # include <bits/stdc++.h>
# include <iostream>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define new_line cout<<endl

using namespace std;

ll chocolateDistribution(ll A[], ll N, ll M) {
  sort(A, A + N);

  ll minDiff = INT_MAX;

  for (ll i = 0; i + M <= N; i ++) {
    minDiff = MIN(minDiff, A[i + M - 1] - A[i]);
  }

  return minDiff;
}

int main() {
  ll T;
  cin>>T;
  
  while(T--) {
    ll N, M;
    cin>>N;
    
    ll A[N];

    for (ll i = 0; i < N; i++) {
      cin>>A[i];
    }

    cin>>M;

    cout<<chocolateDistribution(A, N, M);

    new_line;
  }

	return 0;
}