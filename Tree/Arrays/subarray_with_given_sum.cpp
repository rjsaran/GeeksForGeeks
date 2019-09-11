#include <iostream>
#define ull unsigned long long int

using namespace std;

void findSubArray(int arr[], int n, int s) {
    int i = 0, j = 0;
    ull sum = arr[0];

    while(j < n) {
        if (sum == s) {
            cout<<i + 1<<" "<<j + 1<<endl;
            break;
        } else if (sum < s) {
            j++;
            sum += arr[j];
        } else {
            sum -= arr[i];
            i++;
            cout<<i<<" "<<j<<" "<<sum<<endl;
        }
    }
}

int main() {
    int T;
    cin>>T;
    
    while(T--) {
        int N, S;
        cin>>N>>S;
        
        int arr[N];

        for (int i = 0; i < N; i++) {
            cin>>arr[i];
        }
        
        findSubArray(arr, N, S);
    }

	return 0;
}
