
// pre order iterative


#include <iostream>
#include <stack>

using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


node* buildTree(node * root){
    int v;
    cout<<"Enter data- ";
    cin>>v;
    if(v == -1) return NULL;
    root  = new node(v);
    cout<<"Enter the value for left of "<<v<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the value for right of "<<v<<endl;
    root->right = buildTree(root->right);

    return root;
}

// preorder using stack iterative
void preOrder(node * root)
{
    if(root == NULL) return;
    stack<node*> st;
    st.push(root);
    while(!st.empty())
    {
        node *temp = st.top(); 
        st.pop();
        cout<<temp->data<<" ";
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);

    }
}



int main(){
    
    node *root = NULL;
    root = buildTree(root);
    preOrder(root);
    cout<<endl;

    return 0;
}