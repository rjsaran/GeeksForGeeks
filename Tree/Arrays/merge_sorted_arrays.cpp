// # include <bits/stdc++.h>
# include <iostream>

using namespace std;

void mergeSortedArrays(int arr1[], int arr2[], int n1, int n2) {
  int output[n1 + n2];
  int i = 0, j = 0, k = 0;

  while(i < n1 && j < n2) {
    if (arr1[i] <= arr2[j]) {
      output[k++] = arr1[i++];
    } else {
      output[k++] = arr2[j++];
    }
  }

  while(i < n1) {
    output[k++] = arr1[i++];
  }

  while(j < n2) {
    output[k++] = arr2[j++];
  }

  for (int i = 0; i < k; i++) {
    cout<<output[i];

    if(i != k - 1) cout<<" ";
  }
  
  cout<<endl;
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int n1, n2;
    cin>>n1>>n2;
    
    int arr1[n1];
    int arr2[n2];

    for (int i = 0; i < n1; i++) {
      cin>>arr1[i];
    }

    for (int i = 0; i < n2; i++) {
      cin>>arr2[i];
    }

    mergeSortedArrays(arr1, arr2, n1, n2);
  }

	return 0;
}