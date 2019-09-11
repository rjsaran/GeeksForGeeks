// # include <bits/stdc++.h>
# include <iostream>

#define ull unsigned long long int

using namespace std;

ull inversion_count;

void mergeSortedArrays(int A[], int l, int m, int r) {
  int temp[r - l + 1];
  int i = l, j = m + 1, k = 0;

  while(i <= m && j <= r) {
    if (A[i] <= A[j]) {
      temp[k++] = A[i++];
    } else {
      inversion_count += m - i + 1;
      temp[k++] = A[j++];
    }
  }

  while(i <= m) {
    temp[k++] = A[i++];
  }

  while(j <= r) {
    temp[k++] = A[j++];
  }

  for (int i = 0; i < k; i++) {
    A[l + i] = temp[i];
  }
}

ull inversionCount(int A[], int l, int r) {
  if(l < r) {
    int mid = l + (r - l) / 2;

    inversionCount(A, l, mid);
    inversionCount(A, mid + 1, r);
    mergeSortedArrays(A, l, mid, r);
  }

  return inversion_count;
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
    
    inversion_count = 0;

    cout<<inversionCount(A, 0, N - 1)<<endl;
  }

	return 0;
}