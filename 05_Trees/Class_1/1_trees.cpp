// creating tree and traversing in level order

#include<iostream>
#include<queue>
using namespace std;


class node{
    public:
    int data;
    node *left;
    node *right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node* root){
    int v;
    cout<<"Enter data- ";
    cin>>v;
    if(v == -1)return NULL;

    root = new node(v);
    cout<<"Enter the value for left of "<<v<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the value for right of "<<v<<endl;
    root->right = buildTree(root->right);

    return root;
}

void traverseLevelOrder(node* root){
    
    if(root == NULL) return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node * temp = q.front();
        q.pop();
        if(temp == NULL) {
            cout<<endl;
           if(!q.empty()) q.push(NULL);
        }
        else{
            cout<<temp->data;
            if(temp->left !=NULL) q.push(temp->left);
            if(temp->right !=NULL) q.push(temp->right);
        }
    }
}

int main(){

    node *root =NULL;
    root= buildTree(root);
cout<<endl;
traverseLevelOrder(root);
cout<<endl;
}