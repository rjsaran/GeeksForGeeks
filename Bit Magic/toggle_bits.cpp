# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define new_line cout<<endl

using namespace std;

int toggleBit(int N, int K) {
  return N ^ (1 << K);
}

int toggleBits(int N, int L, int R) {
  while(L <= R) {
    N = toggleBit(N, L - 1);
    L++;
  }

  return N;
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int N, L, R;
    cin>>N>>L>>R;
    
    cout<<toggleBits(N, L, R);

    new_line;
  }

	return 0;
}