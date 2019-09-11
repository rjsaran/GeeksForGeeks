// # include <bits/stdc++.h>
# include <iostream>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define new_line cout<<endl

using namespace std;

void zigZagArray(ll A[], ll N) {
  int lessThan = 1;

  for (ll i = 0; i < N - 1; i++) {
    if (lessThan & 1) {
      if (A[i] > A[i + 1]) swap(A[i], A[i + 1]);
    } else {
      if (A[i] < A[i + 1]) swap(A[i], A[i + 1]);
    }

    lessThan++;
  } 
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

    zigZagArray(A, N);

   for (ll i = 0; i < N; i++) {
      cout<<A[i]<<" ";
    }

    new_line;
  }

	return 0;
}