// # include <bits/stdc++.h>
# include <iostream>
# include <vector>
# include <utility> 

# define MAX(a,b) a > b ? a : b;
# define ull unsigned long long int

using namespace std;

bool sortVector(pair<int, bool> a, pair<int, bool> b) {
  if(a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}

int minimumPlatforms(vector<pair <int, bool> > timeline, int N) {
  sort(timeline.begin(), timeline.end(), sortVector);

  int minimum_platforms = 0;

  int trains = 0;

  for (int i = 0; i < N; i++) {
    // cout<<timeline[i].first<<" "<<timeline[i].second<<endl;
    bool is_arrival = timeline[i].second;

    is_arrival ? trains++ : trains--;

    minimum_platforms = MAX(minimum_platforms, trains)
  }

  return minimum_platforms;
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int N;
    cin>>N;
    
    vector<pair <int, bool> > timeline;

    int time;

    for (int i = 0; i < N; i++) {
      cin>>time;
      timeline.push_back(make_pair(time, true));
    }
    
    for (int i = 0; i < N; i++) {
      cin>>time;
      timeline.push_back(make_pair(time, false));
    }

    cout<<minimumPlatforms(timeline, 2 * N)<<endl;
  }

	return 0;
}