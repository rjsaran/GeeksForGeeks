// # include <bits/stdc++.h>
# include <iostream>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define new_line cout<<endl

using namespace std;

void stockBuyAndSell(ll A[], ll N) {
  bool profit = false;

  for (ll i = 0; i < N; i++) {
    ll buyDay = i;

    ll j = i + 1;
    while(j < N && A[i] <= A[j]) {
      i++;
      j++;
    }

    ll sellDay = i;

    if (buyDay != sellDay) {
      profit = true;

      printf("(%llu %llu) ", buyDay, sellDay);
    }
  }

  if (!profit) cout<<"No Profit"<<endl;
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

    stockBuyAndSell(A, N);

    new_line;
  }

	return 0;
}