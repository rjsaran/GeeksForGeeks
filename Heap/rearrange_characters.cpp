#include <bits/stdc++.h>

#define MIN(a, b) a < b ? a : b
#define MAX(a, b) a > b ? a : b

#define new_line cout << endl

using namespace std;

class Comparator
{
public:
  int operator()(pair<char, int> &a, pair<char, int> &b)
  {
    return b.second > a.second;
  }
};

bool rearrangeCharacters(string S)
{
  priority_queue<pair<char, int>, vector<pair<char, int> >, Comparator> pq;

  int fx[26] = {};

  int length = S.length();

  for (int i = 0; i < length; i++)
  {
    fx[S[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++)
  {
    if (fx[i])
      pq.push(make_pair(i + 'a', fx[i]));
  }

  pair<char, int> prev = pq.top();
  pq.pop();

  while (!pq.empty())
  {
    pair<char, int> top = pq.top();
    pq.pop();
  
    prev.second--;

    if (prev.second > 0)
      pq.push(prev);

    prev = top;
  }

  return prev.second <= 1;
}

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    string S;

    cin>>S;

    cout << rearrangeCharacters(S);

    new_line;
  }

  return 0;
}