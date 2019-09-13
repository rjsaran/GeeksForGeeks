# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define new_line cout<<endl

using namespace std;

int countSetBit(int N) {
  int count = 0;

  while(N) {
    N = N & (N - 1);
    count++;
  }

  return count;
}

int countTotalSetBits(int N) {
  int count = 0;

  for (int i = 1; i <= N; i++) {
    count += countSetBit(i);
  }

  return count;
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int N;
    cin>>N;
    
    cout<<countTotalSetBits(N);

    new_line;
  }

	return 0;
}