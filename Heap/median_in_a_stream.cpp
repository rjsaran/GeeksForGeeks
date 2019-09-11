# include <bits/stdc++.h>

# define MAX(a,b) a > b ? a : b;

# define new_line cout<<endl

using namespace std;

/**
 * _smaller will contain elements smaller than desired median
 * and _greater will contain elements larger than desired median
 */
priority_queue<int> _smaller;
priority_queue<int, vector<int>, greater<int> > _greater;
int currentMedian = 0;

int avg(int a, int b) {
  return (a + b) / 2;
}

void median(int K) {
  int _smallerSize = _smaller.size();
  int _greaterSize = _greater.size();

  if (_smallerSize == 0 && _greaterSize == 0) {
    currentMedian = K;
    _smaller.push(K);
    return;
  }

  if (_smallerSize > _greaterSize) {
    if (K > currentMedian) {
      _greater.push(K);
    } else {
      _greater.push(_smaller.top());
      _smaller.pop();
      _smaller.push(K);
    }

    currentMedian = avg(_smaller.top(), _greater.top());
  } else if (_smallerSize < _greaterSize) {
    if (K < currentMedian) {
      _smaller.push(K);
    } else {
      _smaller.push(_greater.top());
      _greater.pop();
      _greater.push(K);
    }

    currentMedian = avg(_smaller.top(), _greater.top());
  } else {
    if (K > currentMedian) {
      _greater.push(K);
      currentMedian = _greater.top();
    } else {
      _smaller.push(K);
      currentMedian = _smaller.top();
    }
  }
}

int main() {
    int N;
    cin>>N;
    
    int K;

    for (int i = 0; i < N; i++) {
      cin>>K;

      median(K);

      cout<<currentMedian;

      new_line;
    }
    
	return 0;
}