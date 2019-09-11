// # include <bits/stdc++.h>
# include <iostream>

#define ull unsigned long long int

using namespace std;

void leadersInArray(int A[], int N, int index, int leader) {
  if (index < 0) return;
  bool changeInLeader = false;

  if (A[index] >= leader) {
    leader = A[index];
    changeInLeader = true;
  }

  leadersInArray(A, N, --index, leader);

  if (changeInLeader) cout<<leader<<" ";
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int N;
    cin>>N;
    
    int A[N];

    for (int i = 0; i < N; i++) {
      cin>>A[i];
    }
    
    leadersInArray(A, N, N - 1, INT_MIN);

    cout<<endl;
  }

	return 0;
}