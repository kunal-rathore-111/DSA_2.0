

# include <iostream>
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

void preOrder(node * root)
{
    if(root == NULL)return;
    //print
    cout<<root->data<<" ";
    //left
    preOrder(root->left);
    //right
    preOrder(root->right);
}

int main(){

    node * root = NULL;
    root = buildTree(root);

    preOrder(root);
cout<<endl;    
}