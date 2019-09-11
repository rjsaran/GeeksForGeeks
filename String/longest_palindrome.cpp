# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define new_line cout<<endl

using namespace std;

void longestPalindrome(string &S, int length) {
  int leftIndex = 0;
  int rightIndex = 0;

  int maxLength = INT_MIN;

  // Find odd and even length palindrome at every index
  for (int i = 0; i < length; i++) {
    // Odd length
    int l = i;
    int r = i;

    while(l >= 0 && r < length && S[l] == S[r]) {
      if (r - l + 1 > maxLength) {
        leftIndex = l;
        rightIndex = r;

        maxLength = r - l + 1;
      }

      l--;
      r++;

    }

    // For even length
    l = i - 1;
    r = i;

    while(l >= 0 && r < length && S[l] == S[r]) {
      if (r - l + 1 > maxLength) {
        leftIndex = l;
        rightIndex = r;

        maxLength = r - l + 1;
      }

      l--;
      r++;
    }
  }

  for (int i = leftIndex; i <= rightIndex; i++) cout<<S[i];
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    string S;

    cin>>S;
    
    longestPalindrome(S, S.length());

    new_line;
  }

  return 0;
}