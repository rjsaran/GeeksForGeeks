# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define ull unsigned long long int

# define new_line cout<<endl

using namespace std;

int strstr(string &S, string &X) {
  int lengthS = S.length();
  int lengthX = X.length();

  int matchIndex = -1;

  if (lengthS < lengthX) return matchIndex;

  for(int i = 0; i <= lengthS - lengthX; i++) {
    int k = i;
    int j = 0;

    while(j < lengthX && S[k] == X[j]) {
      k++;
      j++;
    }

    if(j >= lengthX) {
      matchIndex = i;
      break;
    }
  }

  return matchIndex;
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    string S, X;

    cin>>S>>X;
    
    cout<<strstr(S, X);

    new_line;
  }

  return 0;
}