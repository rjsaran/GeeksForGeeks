// # include <bits/stdc++.h>
# include <iostream>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define new_line cout<<endl

using namespace std;

ll random (ll l, ll r) {
  return (rand() % (r - l + 1)) + l;
}

ll partition(ll A[], ll l, ll r) {
  ll pivot = A[r];

  ll i = l;

  for (ll j = l; j <= r; j++) {
    if (A[j] < pivot) swap(A[i++], A[j]);
  }

  swap(A[i], A[r]);

  return i;
}

ll kthSmallestElement(ll A[], ll l, ll r, ll K) {
  ll pivotIndex = random(l, r);
  swap(A[pivotIndex], A[r]);

  ll partitionIndex = partition(A, l, r);

  // cout<<partitionIndex<<" "<<A[partitionIndex]<<endl;

  if (partitionIndex + 1 == K) return A[partitionIndex];
  
  if (partitionIndex + 1 > K)
    return kthSmallestElement(A, l, partitionIndex - 1, K);
  else 
    return kthSmallestElement(A, partitionIndex + 1, r, K);
}

int main() {
  ll T;
  cin>>T;
  
  while(T--) {
    ll N, K;
    cin>>N;
    
    ll A[N];

    for (ll i = 0; i < N; i++) {
      cin>>A[i];
    }

    cin>>K;

    cout<<kthSmallestElement(A, 0, N - 1, K);

    new_line;
  }

	return 0;
}