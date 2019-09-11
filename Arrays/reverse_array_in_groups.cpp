// # include <bits/stdc++.h>
# include <iostream>

# define MIN(a,b) a < b ? a : b
# define ull unsigned long long int
# define ll long long int

using namespace std;

void reverse(ull A[], ll l, ll r) {
  while(l < r) swap(A[l++], A[r--]);
}

void reverseArrayIngroups(ull A[], ll N, ll K) {
  for (ll i = 0; i < N; i+= K) {
    reverse(A, i, MIN(i + K - 1, N - 1));
  }
}

int main() {
  ll T;
  cin>>T;
  
  while(T--) {
    ll N, K;
    cin>>N>>K;
    
    ull A[N];

    for (ll i = 0; i < N; i++) {
      cin>>A[i];
    }

    reverseArrayIngroups(A, N, K);
        
    for (ll i = 0; i < N; i++) {
      cout<<A[i]<<" ";
    }

    cout<<endl;
  }

	return 0;
}