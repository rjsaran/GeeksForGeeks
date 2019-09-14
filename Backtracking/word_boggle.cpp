#include <bits/stdc++.h>

# define MAX(a,b) a > b ? a : b

#define ll long long int
#define new_line cout << endl

using namespace std;

int W, M, N;
int maxLength;

struct Direction {
  int x;
  int y;
};

struct Direction directions[8] = {
  {1, 0},
  {0, -1},
  {0, 1},
  {-1, 0},
  {-1, -1},
  {1, 1},
  {-1, 1},
  {1, -1},
};

bool outSide(int X, int Y)
{
  return X < 0 || Y < 0 || X >= M || Y >= N;
}

bool canMove(vector<char> board[], vector<int> visited[], int X, int Y, string word)
{
  if (outSide(X, Y) || visited[X][Y] == 1 || word.length() == maxLength) return false;

  return true;
}

void wordBoggleUtil(map<string, bool> dict, vector<char> board[], vector<int> visited[], string &word, set<string> &words, int X, int Y)
{
  if (word.length() > maxLength) return;

  if (dict[word] == true) {
    words.insert(word);
  }

  for (int i = 0; i < 8; i++)
  {
    int newX = X + directions[i].x;
    int newY = Y + directions[i].y;

    if (canMove(board, visited, newX, newY, word)) {
      word.push_back(board[newX][newY]);
      visited[newX][newY] = 1;
    
      // printf("(%d, %d) => (%d, %d): ", X, Y, newX, newY);
      // cout<<word<<endl;

      wordBoggleUtil(dict, board, visited, word, words, newX, newY);

      word.pop_back();
      visited[newX][newY] = 0;
    }
  }
}

void wordBoggle(map<string, bool> dict, vector<char> board[], vector<int> visited[], set<string> &words) {
  string word;

  // word.push_back(board[1][0]);
  // visited[1][0] = 1;
  // possibleSolution =  wordBoggleUtil(dict, board, visited, word, words, 1, 0) || possibleSolution;

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      word.push_back(board[i][j]);
      visited[i][j] = 1;
    
      wordBoggleUtil(dict, board, visited, word, words, i, j);

      word.pop_back();
      visited[i][j] = 0;
    }
  }
}

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    cin >> W;

    map<string, bool> dict;

    string str;

    for (int i = 0; i < W; i++) {
      cin>>str;
      dict[str] = true;

      maxLength = MAX(maxLength, str.length());
    }

    cin>>M>>N;

    vector<char> board[M];
    vector<int> visited[M];

    char character;

    for (int i = 0; i < M; i++)
    {
      visited[i] = vector<int>(N);
      for (int j = 0; j < N; j++)
      {
        cin >> character;
        board[i].push_back(character);
      }
    }

    set<string> words;

    string word;

    wordBoggle(dict, board, visited, words);

    for (auto it : words) {
      cout<<it<<" ";
    }

    if (!words.size()) cout<<-1;

    new_line;
  }

  return 0;
}