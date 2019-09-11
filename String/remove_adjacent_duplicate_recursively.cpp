#include <iostream>

# define new_line cout<<endl

using namespace std;

void removeAdjacentDuplicate(string &S, int high) {
  int i = high;

  while(i - 1 >= 0 && S[i] != S[i - 1]) i--;

  int j = i;

  while(j - 1 >= 0 && S[j] == S[j - 1]) j--;

  int duplicates = i - j + 1;

  i++;

  while(i <= high) {
    swap(S[i], S[j]);
    i++;
    j++;
  }

  if (duplicates == 0) {
    for(int i = 0; i <= high; i++) cout<<S[i];
    return;
  };

  removeAdjacentDuplicate(S, high - duplicates);
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    string S;

    cin>>S;
    
    removeAdjacentDuplicate(S, S.length() - 1);

    new_line;
  }

  return 0;
}