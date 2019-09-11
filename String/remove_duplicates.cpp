# include <bits/stdc++.h>

# define new_line cout<<endl

using namespace std;

void removeDuplicates(string &S, int length) {
  int fx[255] = {0};

  int j = 0;

  for (int i = 0; i < length; i++) {
    fx[S[i]]++;

    if (fx[S[i]] == 1) {
      S[j++]= S[i];
    }
  }

  for (int i = 0; i < j; i++) cout<<S[i];
}

int main() {
  int T;
  cin>>T;

  cin.ignore();

  while(T--) {
    string S;

    getline(cin, S);
    
    removeDuplicates(S, S.length());

    new_line;
  }

  return 0;
}