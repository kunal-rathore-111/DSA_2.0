

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

void postOrder(node * root)
{
    if(root == NULL)return;
    //left
    postOrder(root->left);
    //right
    postOrder(root->right);
    //print
    cout<<root->data<<" ";
}

int main(){

    node * root = NULL;
    root = buildTree(root);

    postOrder(root);
cout<<endl;    
}