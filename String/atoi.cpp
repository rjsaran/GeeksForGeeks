# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define ull unsigned long long int

# define new_line cout<<endl

using namespace std;

int atoi(string &S) {
  int length = S.length();

  int i = 0;
  bool negative = false;

  if (S[0] == '-') {
    negative = true;
    i++;
  }

  int number = 0;

  while (i < length) {
    if (S[i] >= '0' && S[i] <= '9') {
      number = number * 10 + (S[i] - '0');
    } else {
      return -1;
    }

    i++;
  }

  return negative ? number * -1 : number;
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    string S;

    cin>>S;
    
    cout<<atoi(S);

    new_line;
  }

  return 0;
}