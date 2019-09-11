# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define new_line cout<<endl

using namespace std;

// The question was to find next greater element for N distinct elements
// This also works for non distinct elements also
void nextLargerElement(ll A[], int N, ll output[]) {
  stack< pair<ll, int> > stk;
  pair<ll, int> top;
  
  stk.push(make_pair(A[0], 0));

  for (int i = 1; i < N && !stk.empty(); i++) {

    while(true) {
      if (stk.empty()) break;

      pair<ll, int> top = stk.top();

      if (A[i] > top.first) {
        output[top.second] = A[i];
        stk.pop();
      } else break;
    }

    stk.push(make_pair(A[i], i));
  }

  while(!stk.empty()) {
    top = stk.top();

    output[top.second] = -1;

    stk.pop();
  }
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int N;
    cin>>N;

    ll A[N], output[N];
    
    for (int i = 0; i < N; i++) {
      cin>>A[i];
    }

    nextLargerElement(A, N, output);

    for (int i = 0; i < N; i++) {
      cout<<output[i]<<" ";
    }
  
    new_line;
  }

	return 0;
}