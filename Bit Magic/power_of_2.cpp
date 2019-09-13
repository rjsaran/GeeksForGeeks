# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define new_line cout<<endl

using namespace std;

string powerOf2(ll N) {
  if (N == 0) return "NO";
  return N & (N - 1) ? "NO" : "YES";
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    ll N;
    cin>>N;
    
    cout<<powerOf2(N);

    new_line;
  }

	return 0;
}