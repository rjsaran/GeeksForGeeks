# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define new_line cout<<endl

using namespace std;

int isSparseNumber(int N) {
  return N & (N << 1) ? 0 : 1;
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int N;
    cin>>N;
    
    cout<<isSparseNumber(N);

    new_line;
  }

	return 0;
}