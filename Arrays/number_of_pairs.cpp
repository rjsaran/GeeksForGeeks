# include <bits/stdc++.h>
// # include <iostream>
#define ul unsigned long int

using namespace std;

int search(int arr[], int n, int x){
  int low = 0, high = n - 1;
  int ans = high + 1;

  while (high >= low) {
    int mid = (high + low) / 2;
    if(arr[mid] > x) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ans;
}
ul numberOfPairs(int X[], int Y[], int N, int M) {
  ul count = 0;

  int fxSpecials[5] = {0};

  sort(Y, Y + M);

  for (int i = 0; i < M && Y[i] < 5; i++) {
    fxSpecials[Y[i]]++;
  }

  for(int i = 0; i < N; i++) {
    int x = X[i];

    if (x == 1) continue;

    int index = search(Y, M, x);

    count += M - index;

    count += fxSpecials[1];

    if (x == 2) count -= (fxSpecials[3] + fxSpecials[4]);

    if (x == 3) count += fxSpecials[2];
  }

  return count;
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int N, M;
    cin>>N>>M;
    
    int X[N], Y[M];

    for (int i = 0; i < N; i++) {
      cin>>X[i];
    }

    for (int i = 0; i < M; i++) {
      cin>>Y[i];
    }

    cout<<numberOfPairs(X, Y, N, M)<<endl;
  }

	return 0;
}