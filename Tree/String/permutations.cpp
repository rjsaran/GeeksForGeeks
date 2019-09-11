# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define new_line cout<<endl

using namespace std;

void permutations(string &S, int l, int r, vector<string> &output) {
  if (r == l) {
    output.push_back(S);
    return;
  }

  for (int i = l; i <= r; i++) {
    swap(S[i], S[l]);
    permutations(S, l + 1, r, output);
  }
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    string S;

    cin>>S;
    
    vector<string> output;

    permutations(S, 0, S.length() - 1, output);

    sort(output.begin(), output.end());

    for (vector <string>::iterator it = output.begin(); it != output.end(); it++) cout<<*it<<" ";

    new_line;
  }

  return 0;
}