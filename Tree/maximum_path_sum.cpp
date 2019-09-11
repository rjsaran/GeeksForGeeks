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
int maxPathSum(Node *root);

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
    cout<<maxPathSum(root);
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

int maxPathSumUtil(Node* root, int sum, int* _maxPathSum) {
  if (!root) return 0;

  if (!root->left && !root->right) return root->data;

  int leftSum = maxPathSumUtil(root->left, _maxPathSum);
  int rightSum = maxPathSumUtil(root->right, _maxPathSum);

  if (root->left && root->right) {
    *_maxPathSum = max(*_maxPathSum, root->data + leftSum + rightSum);

    return max(leftSum, rightSum) + root->data;
  }

  return root->left ? leftSum + root->data : rightSum + root->data;
}

int maxPathSum(Node *root) {
  int _maxPathSum = INT_MIN;

  return maxPathSumUtil(root, &_maxPathSum);

  return _maxPathSum;
}
