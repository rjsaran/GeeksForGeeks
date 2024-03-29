#include <bits/stdc++.h>

using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
  int data;
  struct Node* left;
  struct Node* right;
  
  Node(int x){
    data = x;
    left = right = NULL;
  }
};

// A wrapper over leftViewUtil()
void leftView(struct Node *root);

/* Driver program to test size function*/
int main() {
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--) {
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
    leftView(root);
    cout << endl;
  }
  return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */
// A wrapper over leftViewUtil()

void leftView(Node *root) {
  map<int, bool> visited;

  queue< pair <Node*, int> > q;

  if (root) q.push(make_pair(root, 0));

  while(!q.empty()) {
    pair<Node*, int> front = q.front();

    Node* node = front.first;
    int level = front.second;

    if (!visited[level]) cout<<node->data<<" ";

    visited[level] = true;

    if (node->left) q.push(make_pair(node->left, level + 1));
    if (node->right) q.push(make_pair(node->right, level + 1));

    q.pop();
  }
}
