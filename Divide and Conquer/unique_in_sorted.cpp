// # include <bits/stdc++.h>
# include <iostream>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define new_line cout<<endl

using namespace std;

int N;

ll findUnique(ll A[], ll l, ll r) {
  if (l > r) return -1;

  ll mid = l + ( r - l) / 2;

  bool isOddPositioned = mid & 1;

  ll compareWith1 = isOddPositioned ? mid - 1 : mid + 1;
  ll compareWith2 = isOddPositioned ? mid + 1 : mid - 1;

  if (compareWith1 >= 0 && compareWith1 < N && A[mid] == A[compareWith1]) {
    return findUnique(A, mid + 1, r);
  } else if (compareWith2 >= 0 && compareWith2 < N && A[mid] == A[compareWith2]) {
    return findUnique(A, l, mid - 1);
  } else {
    return A[mid];
  }
}

int main() {
  ll T;
  cin>>T;
  
  while(T--) {
    cin>>N;
    
    ll A[N];

    for (ll i = 0; i < N; i++) {
      cin>>A[i];
    }
  
    cout<<findUnique(A, 0, N - 1);

    new_line;
  }

	return 0;
}