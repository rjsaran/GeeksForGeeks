// # include <bits/stdc++.h>
# include <iostream>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define new_line cout<<endl

using namespace std;

int N;

bool isRotationIndex(int A[], int i) {
  return (i + 1 < N && A[i] > A[i + 1]);
}

int search(int A[], int l, int r, int K) {
  if (l > r) return -1;

  int mid = l + (r - l) / 2;

  if (A[mid] == K) return mid;

  bool is_rotation_index = isRotationIndex(A, mid);

  printf("%d, %d, %d %d %d %d \n", l, r, mid, is_rotation_index, A[mid], A[mid + 1]);

  if (is_rotation_index) {
    int leftIndex = search(A, l, mid - 1, K);

    if (leftIndex != -1) return leftIndex;

    return search(A, mid + 1, r, K);
  } else {
     if (A[mid] > K) {
      return search(A, l, mid - 1, K);
    } else {
      return search(A, mid + 1, r, K);
    }
  }
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int K;
    cin>>N;
    
    int A[N];

    for (int i = 0; i < N; i++) {
      cin>>A[i];
    }
  
    cin>>K;

    cout<<search(A, 0, N - 1, K);

    new_line;
  }

	return 0;
}