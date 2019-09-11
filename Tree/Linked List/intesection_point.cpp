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

int intersectionPoint(struct Node* head1, struct Node* head2) {
  int length1 = 0;
  int length2 = 0;

  struct Node* ptr = head1;
  while(ptr) {
    length1++;
    ptr = ptr->next;
  }

  ptr = head2;
  while(ptr) {
    length2++;
    ptr = ptr->next;
  }

  struct Node *fastPtr, *slowPtr;

  if (length1 > length2) {
    fastPtr = head1;
    slowPtr = head2;
  } else {
    fastPtr = head2;
    slowPtr = head1;
  }

  int forwardBy = abs(length1 - length2);

  while(forwardBy--) fastPtr = fastPtr->next;

  while(fastPtr && fastPtr != slowPtr) {
    fastPtr = fastPtr->next;
    slowPtr = slowPtr->next;
  }

  return fastPtr ? fastPtr->data : -1;
}

int main() {
  int T;
  cin>>T;
  
  while(T--) {
    int N1, N2, N3, data;
    cin>>N1>>N2>>N3;

    struct Node *head1 = NULL, *tail1 = NULL;

    for (int i = 0; i < N1; i++) {
      cin>>data;
      insert(&head1, &tail1, data);
    }
    
    struct Node *head2 = NULL, *tail2 = NULL;

    for (int i = 0; i < N2; i++) {
      cin>>data;
      insert(&head2, &tail2, data);
    }

    struct Node *head3 = NULL, *tail3 = NULL;

    for (int i = 0; i < N3; i++) {
      cin>>data;
      insert(&head3, &tail3, data);
    }

    if (tail1) tail1->next = head3;
    if (tail2) tail2->next = head3;

    cout<<intersectionPoint(head1, head2);

    new_line;
  }

  return 0;
}