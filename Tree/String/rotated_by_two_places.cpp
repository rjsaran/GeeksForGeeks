# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define new_line cout<<endl

using namespace std;

int rotatedByTwoPlaces(string &A, string &B, int lengthA, int lengthB) {
  if (lengthA != lengthB) return 0;

  for (int i = 0; i < lengthA; i++) {
    if ((A[(i + 2) % lengthA] != B[i]) && (B[(i + 2) % lengthB] != A[i])) return 0;
  }

  return 1;
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    string A, B;

    cin>>A>>B;
    
    cout<<rotatedByTwoPlaces(A, B, A.length(), B.length());

    new_line;
  }

  return 0;
}