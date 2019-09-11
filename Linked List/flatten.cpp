#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
};

void printList(Node *Node) {
  while (Node != NULL)
  {
      printf("%d ", Node->data);
      Node = Node->bottom;
  }
}

Node* flatten (Node* root);
void mergeSorted (Node* head1, Node* head2);

int main(void) {
	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			temp = (struct Node*)malloc(sizeof(struct Node));
			scanf("%d",&temp->data);
			temp->next=NULL;
			temp->bottom=NULL;
			if(flag){
				head=temp;
				pre=temp;
				flag=0;
				flag1=1;
			}
			else{
				pre->next=temp;
				pre=temp;
				flag1=1;
			}
			for(int j=0;j<m;j++){
				tempB = (struct Node*)malloc(sizeof(struct Node));
				scanf("%d",&tempB->data);
				tempB->next=tempB->bottom=NULL;
				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;
		   /*
		while(fun!=NULL)
            {
                cout<<fun->data<<" ";
                fun2 = fun->bottom;
                fun=fun->next;
                while(fun2){
                cout<<fun2->data<<" ";
                fun2=fun2->bottom;
                }
                cout<<endl;
            }*/
            Node* root = flatten(head);
            printList(root);
            cout<<endl;
	}
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
}; */
/*  Function which returns the  root of 
    the flattened linked list. */
void mergeSorted(Node *head1, Node* head2) {
  Node *next, *prev;

  while(head1 && head2) {
    if (head1->data <= head2->data) {
      prev = head1;
      head1 = head1->bottom;
    } else {
      next = head1->bottom;
      head1->bottom = head2;
      head2 = head2->bottom;
      head1->bottom->bottom = next;

      swap(head1->data, head1->bottom->data);
    }
  }

  if(head2) prev->bottom = head2;
}

Node *flatten(Node *root) {
  Node* ptr1 = root;
  Node* ptr2 = root->next;

  while(ptr2) {
    mergeSorted(ptr1, ptr2);

    Node* prev = ptr2;
    ptr2 = ptr2->next;
    prev->next = NULL;
  }

  ptr1->next = NULL;
  return root;
}