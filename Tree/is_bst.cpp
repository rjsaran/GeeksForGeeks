// C++ Program to print Bottom View of Binary Tree
#include<bits/stdc++.h>

using namespace std;

// Tree node class
struct Node {
  int data; //data of the node
  Node *left, *right; //left and right references
  // Constructor of tree node
  Node(int key)
  {
    data = key;
    left = right = NULL;
  }
};

// Method that prints the bottom view.
bool isBST(Node *root);

/* Driver program to test size function*/
int main() {
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
    map<int, Node*> m;
    int n;
    scanf("%d",&n);
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
      m[n2]  = child;
    }
    cout<<isBST(root);
    cout << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references
    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */
// Method that prints the bottom view.

int isBSTUtil (Node* root, int min, int max) {
  if (!root) return 1;

  if (root->data < min || root->data > max) return 0;

  return isBSTUtil(root->left, min, root->data - 1) && isBSTUtil(root->right, root->data + 1, max);
}

bool isBST(Node *root) {
  return isBSTUtil(root, INT_MIN, INT_MAX);
}
