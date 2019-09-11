// # include <bits/stdc++.h>
# include <iostream>

#define ull unsigned long long int
# define MAX(a,b) a > b ? a : b;

using namespace std;

int missingNumber(int arr[], int n) {
  // ull seriesSum = (n * (n + 1)) / 2;

  int missing_number = 1;

  for (int i = 0; i < n - 1; i++) {
    missing_number += (i + 2);

    missing_number -= arr[i];
  }

  return missing_number;
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int N;
    cin>>N;
    
    int arr[N - 1];

    for (int i = 0; i < N - 1; i++) {
      cin>>arr[i];
    }
    
    cout<<missingNumber(arr, N)<<endl;
  }

	return 0;
}