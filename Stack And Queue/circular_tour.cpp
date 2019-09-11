#include<bits/stdc++.h>

using namespace std;

struct petrolPump {
  int petrol;
  int distance;
};

int tour(petrolPump [],int );

int main() {
  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    petrolPump p[n];
    for(int i=0;i<n;i++)
      cin>>p[i].petrol>>p[i].distance;
    cout<<tour(p,n)<<endl;
  }
}

/*This is a function problem.You only need to complete the function given below*/
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/
/*You are required to complete this method*/

int tour(petrolPump p[], int n) {
  int front = 0, rear = 1;

  int currentPetrol = p[front].petrol - p[front].distance;

  while(front != rear || currentPetrol < 0) {
    if (currentPetrol < 0 && front != rear) {
      currentPetrol -= p[front].petrol - p[front].distance;

      front = (front + 1) % n;
      if (front == 0) return -1;
    }

    currentPetrol += p[rear].petrol - p[rear].distance;

    rear = (rear + 1) % n;
  }

  return front;
}
