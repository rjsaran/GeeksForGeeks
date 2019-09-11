#include<bits/stdc++.h>

using namespace std;

class LRUCache {
  public:
    LRUCache(int );

    int get(int );

    void set(int , int );
};

int main() {
  int t;
  cin>>t;
  while(t--)
  {
  int n;
  cin>>n;
  LRUCache *l  = new LRUCache(n);
  int q;
  cin>>q;
  for(int i=0;i<q;i++) {
      string a;
      cin>>a;
      if(a=="SET")
      {
          int aa,bb;
          cin>>aa>>bb;
          l->set(aa,bb);
      }else if(a=="GET")
      {
          int aa;
          cin>>aa;
          cout<<l->get(aa)<<" ";
      }
  }
  cout<<endl;
  }
}

/*This is a function problem.You only need to complete the function given below*/
/*The structure of the class is as follows 
class LRUCache
{
public:
    LRUCache(int );
    int get(int );
    void set(int , int );
};*/
/*You are required to complete below methods */
/*Inititalize an LRU cache with size N */
map<int, list< pair <int, int> >::iterator> hashMap;
list< pair <int, int> > dqueue;
int capacity;

LRUCache::LRUCache(int N) {
  capacity = N;

  hashMap.clear();
  dqueue.clear();
}

/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y) {
  if (hashMap.find(x) != hashMap.end()) {
    dqueue.erase(hashMap[x]);
  }

  // If size of dqueue is equal to capacity
  if (dqueue.size() == capacity) {
    pair <int, int> last = dqueue.back();

    int key = last.first;

    hashMap.erase(key);

    dqueue.pop_back();
  }

  dqueue.push_front(make_pair(x, y));

  hashMap[x] = dqueue.begin();
}

/*Returns the value of the key x if 
present else returns -1 */
int LRUCache::get(int x) {
  if (hashMap.find(x) == hashMap.end()) return -1;

  list < pair <int, int> >::iterator it = hashMap[x];

  int y = it->second;

  dqueue.erase(it);

  dqueue.push_front(make_pair(x, y));

  hashMap[x] = dqueue.begin();

  return y;
}