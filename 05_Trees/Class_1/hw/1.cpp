// reverse level order traversal

#include <iostream>
#include <queue>
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

stack<node*> st;

 void reverseOrder(node *root){
     if(root == NULL) return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node * temp = q.front();
        st.push(temp);
        q.pop();
        if(temp == NULL){
            if(!q.empty())q.push(NULL);
        }
        else{
            if(temp->right!= NULL){q.push(temp->right);}

            if(temp->left != NULL){q.push(temp->left);}
        }
        
    }
    while(!st.empty()){
        node * temp = st.top();
        st.pop();
        if(temp == NULL)cout<<endl;
        else cout<<temp->data<<" ";
    }
    
}



int main(){
    
    node *root = NULL;
    root = buildTree(root);
    reverseOrder(root);
    cout<<endl;

    return 0;
}