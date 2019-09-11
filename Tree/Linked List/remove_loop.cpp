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

struct Node* detectLoop(struct Node* head) {
  struct Node* loopNode = NULL;

  struct Node *slowPtr = head, *fastPtr = head;

  while(slowPtr && fastPtr && fastPtr->next && !loopNode) {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;

    if(slowPtr == fastPtr) loopNode = slowPtr;
  }

  return loopNode;
}

int loopCount(struct Node* head) {
  struct Node* ptr = head->next;

  int count = 1;

  while(ptr != head) {
    count++;
    ptr = ptr->next;
  }

  return count;
}

void removeTheLoop(struct Node* head) {
  struct Node* loopNode = _detectLoop(head);

  if (!loopNode) return;

  int loop_count = _loopCount(loopNode);

  struct Node* kthNode = head, *ptr = head;

  int i = 0;

  while(i < loop_count) {
    kthNode = kthNode->next;
    i++;
  }
 
  while(ptr != kthNode) {
    ptr = ptr->next;
    kthNode = kthNode->next;
  }

  while(ptr->next != kthNode) {
    ptr = ptr->next;
  }
  
  ptr->next = NULL;
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

    removeTheLoop(head);

    new_line;
  }

  return 0;
}