# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define new_line cout<<endl

using namespace std;

string anagram(string S1, string S2) {
  int l1 = S1.length();
  int l2 = S2.length();

  if (l1 != l2) return "NO";

  int fx[26] = {0};

  for (int i = 0; i < l1; i++) {
    fx[S1[i] - 'a']++;
    fx[S2[i] - 'a']--;
  }

  for (int i = 0; i < 26; i++) if (fx[i] != 0) return "NO";

  return "YES";
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    string S1, S2;

    cin>>S1;
    cin>>S2;
    
    cout<<anagram(S1, S2);

    new_line;
  }

  return 0;
}