# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define ull unsigned long long int
# define fill(a, l, r, value) for(int i = l; i <= r; i++) a[i] = value;

# define new_line cout<<endl

using namespace std;


int longestDistinctCharacters(string &S) {
  int length = S.length();
  int index[256] = {};

  fill(index, 0, 255, -1)

  int maxLength = INT_MIN;
  int l = 0;

  for (int h = 0; h < length; h++) {
    int prevIndex = index[S[h]];

    // If previous index is greater than 1
    // previous index lies between l and h
    // update l with prevIndex + 1
    if (prevIndex > -1 && prevIndex >= l) {
      l = prevIndex + 1;
    }

    index[S[h]] = h;

    maxLength = MAX(h - l + 1, maxLength);
  }

  return maxLength;
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    string S;

    cin>>S;
    
    cout<<longestDistinctCharacters(S);

    new_line;
  }

  return 0;
}