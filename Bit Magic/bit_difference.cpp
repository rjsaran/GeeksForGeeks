# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define new_line cout<<endl

using namespace std;

int countSetBit(int N) {
  if (!N) return 0;

  int count = 0;

  int i = 0;

  while(i < sizeof(int) * 8) {
    if (N & (1 << i)) count++;
    i++;
  }

  return count;
}

int bitDifference(int A, int B) {
  return countSetBit(A ^ B);
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int A, B;
    cin>>A>>B;
    
    cout<<bitDifference(A, B);

    new_line;
  }

	return 0;
}