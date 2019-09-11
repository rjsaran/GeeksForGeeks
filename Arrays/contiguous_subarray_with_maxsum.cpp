# include <bits/stdc++.h>

# define MAX(a,b) a > b ? a : b;

using namespace std;

int contiguousSubArrayWithMaxSum(int arr[], int n) {
  int local_max = 0;
  int global_max = INT_MIN;

  for (int i = 0; i < n; i++) {
    local_max = MAX(arr[i], arr[i] + local_max);

    global_max = MAX(global_max, local_max);
  }

  return global_max;
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int N;
    cin>>N;
    
    int arr[N];

    for (int i = 0; i < N; i++) {
      cin>>arr[i];
    }
    
    cout<<contiguousSubArrayWithMaxSum(arr, N)<<endl;
  }

	return 0;
}