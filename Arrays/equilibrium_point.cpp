// # include <bits/stdc++.h>
# include <iostream>

#define ull unsigned long long int

using namespace std;

int equilibriumPoint(int A[], int N) {
  ull leftSum = 0;
  ull sum = 0;

  for (int i = 0; i < N; i++) {
    sum += A[i];
  }

  for (int i = 0; i < N; i++) {
    // Update right sum
    sum -= A[i];

    if (sum == leftSum) return i + 1;

    leftSum += A[i];
  }

  return -1;
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
    
    cout<<equilibriumPoint(A, N)<<endl;
  }

	return 0;
}