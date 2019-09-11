// # include <bits/stdc++.h>
# include <iostream>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define new_line cout<<endl

using namespace std;

ll trappingRainWater(ll A[], ll N) {
  ll rightMax[N], leftMax[N];

  leftMax[0] = A[0];

  for (ll i = 1; i < N; i++) {
    leftMax[i] = MAX(A[i], leftMax[i - 1]);
  }

  rightMax[N - 1] = A[N - 1];

  for (ll i = N - 2; i >= 0; i--) {
    rightMax[i] = MAX(A[i], rightMax[i + 1]);
  }


  ll trappedWater = 0;

  for (ll i = 0; i < N; i++) {
    trappedWater += (MIN(leftMax[i], rightMax[i])) - A[i];
  }

  return trappedWater;
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

    cout<<trappingRainWater(A, N);

    new_line;
  }

	return 0;
}