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

int nthElementFromEnd(struct Node* head, int k) {
  struct Node *slowPtr = head, *fastPtr = head;

  int i = 0;
  while(i++ < k) fastPtr = fastPtr->next;

  while(fastPtr) {
    fastPtr = fastPtr->next;
    slowPtr = slowPtr->next;
  }

  return slowPtr->data;
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int N, K, data;
    cin>>N>>K;

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < N; i++) {
      cin>>data;
      insert(&head, &tail, data);
    }

    K < N ? cout<<nthElementFromEnd(head, K) : cout<<-1;

    new_line;
  }

  return 0;
}