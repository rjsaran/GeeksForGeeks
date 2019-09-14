#include <bits/stdc++.h>

# define MAX(a,b) a > b ? a : b

#define ll long long int
#define new_line cout << endl

using namespace std;

bool validOctane(string octane) {
  int number = stoi(octane);

  if (number > 255) return false;

  if (octane.length() == 1 && number == 0) return true;

  if (octane[0] == '0') return false;

  return true;
}

void generateIpAddress(string &input, vector<string> &ips, vector<string> &ip, int l) {
  int length = input.length();

  if (ip.size() == 4) {
    string output;

    for (int i = 0; i < 4; i++) {
      output += i == 3 ? ip[i] : (ip[i] + ".");
    }

    if (output.length() == length + 3)
      ips.push_back(output);
  }

  for (int i = 1; i <= 3 && i + l <= length; i++) {
    string octane = input.substr(l, i);

    // printf("(%d, %d) ", l, i);
    // cout<<octane<<endl;

    if (validOctane(octane)) {
      ip.push_back(octane);

      generateIpAddress(input, ips, ip, l + i);

      ip.pop_back();
    }
  }
}

int main()
{
  int T;
  cin >> T;

  while (T--)
  {
    string input;

    cin>>input;

    vector<string> ips;
    vector<string> ip;

    generateIpAddress(input, ips, ip, 0);

    for (auto ip : ips) {
      cout<<ip;

      new_line;
    }
  }

  return 0;
}