#include <iostream>
using namespace std;

string reverseWords(string S, int length) {
  for (int i = 0; i < length; i++) {
    int j = i;
    while(j < length && S[j] != '.') j++;

    int l = i;
    int r = j - 1;

    while(l < r) {
      swap(S[l], S[r]);
      l++;
      r--;
    }

    i = j;
  }

  int l = 0;
  int r = length - 1;

  while(l < r) {
    swap(S[l], S[r]);
    l++;
    r--;
  }

  return S;
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    string S;

    cin>>S;
    
    cout<<reverseWords(S, S.length())<<endl;
  }

  return 0;
}