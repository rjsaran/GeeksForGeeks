# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define new_line cout<<endl

using namespace std;

int firstSetBit(int N) {
  if (!N) return 0;

  int i = 0;

  while(true) {
    if (N & (1 << i)) return i + 1;
    i++;
  }
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int N;
    cin>>N;
    
    cout<<firstSetBit(N);

    new_line;
  }

	return 0;
}