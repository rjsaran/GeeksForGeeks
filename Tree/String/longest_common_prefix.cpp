# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define ull unsigned long long int
# define fill(a, l, r, value) for(int i = l; i <= r; i++) a[i] = value;

# define new_line cout<<endl

using namespace std;

int commonPrefix(string A, string B) {
  int lengthA = A.length();
  int lengthB = B.length();

  int i = 0;

  while(i < lengthA && i < lengthB && A[i] == B[i]) i++;

  return i;
}

string longestCommonPrefix(vector<string> &A, int N) {
  int longest_common_prefix = A[0].length();
  
  for (int i = 1; i < N; i++) {
    int common_prefix = commonPrefix(A[0], A[i]);

    longest_common_prefix = MIN(common_prefix, longest_common_prefix);
  }

  return longest_common_prefix ? A[0].substr(0, longest_common_prefix) : "-1";
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int N;
    cin>>N;

    vector<string> A;

    string S;

    for (int i = 0; i < N; i++) {
      cin>>S;
      A.push_back(S);
    }
    
    cout<<longestCommonPrefix(A, N);

    new_line;
  }

  return 0;
}