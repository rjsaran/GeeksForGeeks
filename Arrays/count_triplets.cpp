#include <iostream>

using namespace std;

int countTriplets(int arr[], int n) {
  int count = 0;

  sort(arr, arr + n);

  for (int k = n - 1; k >= 2; k--) {
    int i = 0, j = k - 1;

    while (i < j) {
      int sum = arr[i] + arr[j];

      if (sum == arr[k]) {
        count++;
        j--;
      } else if (sum > arr[k]) {
        j--;
      }
      else i++;
    }
  }

  return count == 0 ? -1 : count;
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
    
    cout<<countTriplets(arr, N)<<endl;
  }

	return 0;
}