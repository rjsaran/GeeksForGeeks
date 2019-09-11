// C++ Program to print Bottom View of Binary Tree
#include <bits/stdc++.h>

using namespace std;

// Tree node class
struct Node
{
  int data;           //data of the node
  Node *left, *right; //left and right references
  // Constructor of tree node
  Node(int key)
  {
    data = key;
    left = right = NULL;
  }
};

// Method that prints the bottom view.
int printSpiral(Node *root);

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
    map<int, Node *> m;
    int n;
    scanf("%d", &n);
    struct Node *root = NULL;
    while (n--)
    {
      Node *parent;
      char lr;
      int n1, n2;
      scanf("%d %d %c", &n1, &n2, &lr);
      if (m.find(n1) == m.end())
      {
        parent = new Node(n1);
        m[n1] = parent;
        if (root == NULL)
          root = parent;
      }
      else
        parent = m[n1];
      child = new Node(n2);
      if (lr == 'L')
        parent->left = child;
      else
        parent->right = child;
      m[n2] = child;
    }
    printSpiral(root);
    cout << endl;
  }
  return 0;
}

void printSpiral(Node *root)
{
  stack<Node*> stack1, stack2;

  stack1.push(root);

  while(!stack1.empty() || !stack2.empty()) {
    while(!stack1.empty()) {
      Node* top = stack1.top();

      cout<<top->data<<" ";

      if (top->right) stack2.push(top->right);
      if (top->left) stack2.push(top->left);

      stack1.pop();
    }

    while(!stack2.empty()) {
      Node* top = stack2.top();

      cout<<top->data<<" ";

      if (top->left) stack1.push(top->left);
      if (top->right) stack1.push(top->right);

      stack2.pop();
    }
  }
}
