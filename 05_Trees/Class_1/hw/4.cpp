


// post iterative


#include <iostream>
#include <stack>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


Node* buildTree(Node * root){
    int v;
    cout<<"Enter data- ";
    cin>>v;
    if(v == -1) return NULL;
    root  = new Node(v);
    cout<<"Enter the value for left of "<<v<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the value for right of "<<v<<endl;
    root->right = buildTree(root->right);

    return root;
}

// postorder using stack iterative
  
void postOrder(Node * root){
    if(root == NULL)return;
   stack<Node*> pre;
   stack<Node*> post;
   pre.push(root);
   while(!pre.empty())
   {
      Node *temp = pre.top();
      post.push(temp);
      pre.pop();
      if(temp->left)pre.push(temp->left);
      if(temp->right)pre.push(temp->right);
   }
   while(!post.empty())
   {
    cout<<post.top()->data<<" ";
    post.pop();
   }
}



int main(){
    
    // 9 2 1 1 -1 -1 4 -1 -1 2 -1 -1 4 -1 -1
    Node *root = NULL;
    root = buildTree(root);
    postOrder(root);
    cout<<endl;

    return 0;
}