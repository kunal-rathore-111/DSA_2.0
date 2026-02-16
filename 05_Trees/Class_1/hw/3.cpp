
// in order iterative


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

// inorder using stack iterative
  
void inOrder(Node * root){
    if(root == NULL)return;

    stack<Node*>st;
    Node *curr = root;
    while(!st.empty() || curr !=NULL)
    {
        while(curr !=NULL){
            st.push(curr);
            curr = curr->left;
        }
        Node *temp = st.top();
        cout<<temp->data;
        curr = temp->right;
        st.pop();
    }
}



int main(){
    
    Node *root = NULL;
    root = buildTree(root);
    inOrder(root);
    cout<<endl;

    return 0;
}