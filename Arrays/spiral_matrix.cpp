// # include <bits/stdc++.h>
# include <iostream>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define new_line cout<<endl

using namespace std;

void spiralMatrix(ll A[], ll a, ll b, ll c, ll d, int M, int N) {
  if (!(a <= c && b <= d)) return;

  // Print top view
  for (ll j = b; j <= d; j++) {
    cout<<A[a * N + j]<<" ";
  }

  // Print right view
  for (ll j = a + 1; j <= c - 1; j++) {
    cout<<A[j * N + d]<<" ";
  }

  if (c > a) {
    // Print bottom view
    for (ll j = d; j >= b; j--) {
      cout<<A[c * N + j]<<" ";
    }
  }

  if (d > b) {
    // Print left view
    for (ll j = c - 1; j >= a + 1; j--) {
      cout<<A[j * N + b]<<" ";
    }
  }

  spiralMatrix(A, a + 1, b + 1, c - 1, d - 1, M, N);
}

int main() {
  ll T;
  cin>>T;
  
  while(T--) {
    ll M, N;
    cin>>M>>N;
    
    ll size = M * N;

    ll A[size];

    for (ll i = 0; i < size; i++) {
      cin>>A[i];
    }

    spiralMatrix(A, 0, 0, M - 1, N - 1, M, N);

    new_line;
  }

	return 0;
}