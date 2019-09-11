# include <bits/stdc++.h>
// # include <iostream>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define new_line cout<<endl

using namespace std;

void kthLargest(int A[], int N, int K) {
  priority_queue <int, vector<int>, greater<int> > minHeap;

  int top;

  for (int i = 0; i < K - 1; i++) {
    minHeap.push(A[i]);
    cout<<"-1 ";
  }

  minHeap.push(A[K - 1]);
  cout<<minHeap.top()<<" ";

  for (int i = K; i < N; i++) {
    top = minHeap.top();

    if (top < A[i]) {
      minHeap.pop();

      minHeap.push(A[i]);
    }

    top = minHeap.top();

    cout<<top<<" ";
  }
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int N, K;
    cin>>K>>N;
    
    int A[N];

    for (int i = 0; i < N; i++) {
      cin>>A[i];
    }

    kthLargest(A, N, K);

    new_line;
  }

	return 0;
}