// # include <bits/stdc++.h>
# include <iostream>

#define ull unsigned long long int

using namespace std;

void sortArrayOf012(int A[], int N) {
  int l = 0, m = 0, h = N - 1;

  while(m <= h) {
    if (A[m] == 0) {
      swap(A[l], A[m]);
      l++;
      m++;
    } else if (A[m] == 2) {
      swap(A[m], A[h]);
      h--;
    } else {
      m++;
    }
  }
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
    
    sortArrayOf012(A, N);

    for (int i = 0; i < N; i++) {
      cout<<A[i]<<" ";
    }

    cout<<endl;
  }

	return 0;
}