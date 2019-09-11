// # include <bits/stdc++.h>
# include <iostream>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define new_line cout<<endl

using namespace std;

string pythagoreanTriplet(ll A[], ll N) {
  for (ll i = 0; i < N; i++) {
    A[i] = A[i] * A[i];
  }

  sort(A, A + N);

  for (ll k = N - 1; k >= 2; k--) {
    ll i = 0, j = k - 1;

    while (i < j) {
      ll sum = A[i] + A[j];

      if (sum == A[k]) {
        return "Yes";
        j--;
      } else if (sum > A[k]) {
        j--;
      }
      else i++;
    }
  }

  return "No";
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

    cout<<pythagoreanTriplet(A, N);

    new_line;
  }

	return 0;
}