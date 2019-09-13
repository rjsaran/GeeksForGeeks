# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define new_line cout<<endl

using namespace std;

int setKthBit(int N, int K) {
  return N | (1 << K);
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int N, K;
    cin>>N>>K;
    
    cout<<setKthBit(N, K);

    new_line;
  }

	return 0;
}