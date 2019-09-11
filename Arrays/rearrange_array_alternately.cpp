// # include <bits/stdc++.h>
# include <iostream>

#define ul unsigned long int
using namespace std;

void rearrangeAlternately(ul arr[], int n) {

  ul max = arr[n - 1] + 1;

  for (int i = 0, j = n - 1; i < n; j--) {
    arr[i] = max * (arr[j] % max) + arr[i];

    i += 2;
  }

  for (int i = 1, j = 0; i < n; j++) {
    arr[i] = max * (arr[j] % max) + arr[i];

    i += 2;
  }

  for (int i = 0; i < n; i++) {
    cout<<arr[i] / max;

    if(i != n - 1) cout<<" ";
  }
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int N;
    cin>>N;
    
    ul arr[N];

    for (int i = 0; i < N; i++) {
      cin>>arr[i];
    }

    rearrangeAlternately(arr, N);

    cout<<endl;
  }

	return 0;
}