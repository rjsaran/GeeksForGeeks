# include <bits/stdc++.h>

# define MIN(a,b) a < b ? a : b
# define MAX(a,b) a > b ? a : b

# define ll long long int
# define ull unsigned long long int
# define fill(a, l, r, value) for(int i = l; i <= r; i++) a[i] = value;

# define new_line cout<<endl

using namespace std;

struct Node {
  int data;
  struct Node* next;
};

struct Node* newNode(int data) {
  struct Node* node = new Node;

  node->data = data;
  node->next = NULL;

  return node;
}

void insert(struct Node** head_ref, struct Node** tail_ref, int data) {
  struct Node* node = newNode(data);

  if (!*head_ref) *head_ref = node;
  else (*tail_ref)->next = node;

  *tail_ref = node;
}

void print(struct Node* head) {
  while(head) {
    cout<<head->data<<" ";

    head = head->next;
  }
}

int detectLoop(struct Node* head) {
  bool loopDetected = 0;

  struct Node *slowPtr = head, *fastPtr = head;

  while(slowPtr && fastPtr && fastPtr->next && !loopDetected) {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;

    if(slowPtr == fastPtr) loopDetected = 1;
  }

  return loopDetected;
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int N, K, data;
    cin>>N;

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < N; i++) {
      cin>>data;
      insert(&head, &tail, data);
    }
      
    cin>>K;

    cout<<detectLoop(head);

    new_line;
  }

  return 0;
}