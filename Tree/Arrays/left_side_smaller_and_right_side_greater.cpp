# include <bits/stdc++.h>
// # include <iostream>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define new_line cout<<endl

using namespace std;

int leftSideSmallerAndRightSideGreater(ll A[], ll N) {
  ll rightMin[N];
  rightMin[ N - 1] = INT_MAX;

  for (ll i = N - 2; i >= 0; i--) {
    rightMin[i] = MIN(A[i + 1], rightMin[i + 1]);
  }

  ll leftMax = INT_MIN;

  for (ll i = 1; i < N - 1; i++) {
    leftMax = MAX(A[i - 1], leftMax);

    if (leftMax <= A[i] && A[i] <= rightMin[i]) return A[i];
  }

  return -1;
}

int main() {
  ll T;
  cin>>T;
  
  while(T--) {
    ll N;
    cin>>N;
    
    ll A[N];

    for (ll i = 0; i < N; i++) {
      cin>>A[i];
    }

    cout<<leftSideSmallerAndRightSideGreater(A, N);

    new_line;
  }

	return 0;
}