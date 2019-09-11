# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define new_line cout<<endl

using namespace std;

bool isOpen(char c) {
  return c == '[' || c == '{' || c == '(';
}

bool isClose(char c) {
  return c == ']' || c == '}' || c == ')';
}

bool isSame (char c1, char c2) {
  return (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}') || (c1 == '(' && c2 == ')');
}

string checkParenthesis(string S) {
  stack<char> stk;
  int length = S.length();

  int i = 0;

  for (; i < length; i++) {
    if (isOpen(S[i])) stk.push(S[i]);

    if (isClose(S[i])) {
      if (stk.empty()) break;

      char top = stk.top();
      stk.pop();

      if (!isSame(top, S[i])) break;
    }
  }

  return i < length || stk.size() ? "not balanced" : "balanced";
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    string S;
    cin>>S;

    cout<<checkParenthesis(S);

    new_line;
  }

	return 0;
}