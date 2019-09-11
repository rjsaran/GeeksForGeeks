// # include <bits/stdc++.h>
# include <iostream>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define new_line cout<<endl

using namespace std;

void findMissingAndRepeating(ll A[], ll N) {
  for (ll i = 0; i < N; i++) {
    if (A[abs(A[i]) - 1] < 0) {
      cout<<abs(A[i])<<" ";
    } else {
      A[abs(A[i]) - 1] *= -1;
    }
  }

  for (ll i = 0; i < N; i++) {
    if (A[i] > 0) {
      cout<<i + 1<<" ";
      break;
    }
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

    findMissingAndRepeating(A, N);

    new_line;
  }

	return 0;
}