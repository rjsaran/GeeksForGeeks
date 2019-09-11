// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
  int data;
  Node *next;
};

Node *mergeKLists(Node *arr[], int N);

/* Function to print nodes in a given linked list */
void printList(Node *node)
{
  while (node != NULL)
  {
    printf("%d ", node->data);
    node = node->next;
  }
  cout << endl;
}
// Utility function to create a new node.
Node *newNode(int data)
{
  struct Node *temp = new Node;
  temp->data = data;
  temp->next = NULL;
  return temp;
}
// Driver program to test above functions
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N;
    cin >> N;
    struct Node *arr[N];
    for (int j = 0; j < N; j++)
    {
      int n;
      cin >> n;
      int x;
      cin >> x;
      arr[j] = newNode(x);
      Node *curr = arr[j];
      n--;
      for (int i = 0; i < n; i++)
      {
        cin >> x;
        Node *temp = newNode(x);
        curr->next = temp;
        curr = temp;
      }
    }
    Node *res = mergeKLists(arr, N);
    printList(res);
  }
  return 0;
}

class Comparator
{
public:
  int operator()(Node *a, Node *b)
  {
    return b->data < a->data;
  }
};

Node *mergeKLists(Node *arr[], int N)
{
  priority_queue<Node *, vector<Node *>, Comparator> minHeap;

  for (int i = 0; i < N; i++)
  {
    minHeap.push(arr[i]);
  }

  struct Node *result = NULL, *head = NULL;

  while (!minHeap.empty())
  {
    Node *top = minHeap.top();

    // cout << top->data << " ";

    minHeap.pop();

    if (top->next)
      minHeap.push(top->next);

    if (!result)
    {
      head = top;
      result = top;
    }
    else
    {
      result->next = top;
      result = result->next;
    }
  }

  return head;
}