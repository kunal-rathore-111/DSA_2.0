
#include <iostream>
#include <queue>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = this->right= NULL;
    }
};

void buildTreeLevelOrder(Node *&root) 
{
    queue<Node*>q;
    cout<<"Enter data for root- ";
    int data;
    cin>>data;
    if(data == -1) return;
    root = new Node(data);
    q.push(root);
    /// ab ek ek node nikalo or uneke child bnao
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        cout<<"Enter the left for "<<temp->data<<"- ";
        int leftData;
        cin>>leftData;
       
       if(leftData !=-1){
           temp->left = new Node(leftData);
           q.push(temp->left);
        } 
        
        cout<<"Enter the right for "<<temp->data<<"- ";
        int rightData;
        cin>>rightData;
        
        if(rightData!=-1){
            temp->right = new Node(rightData);
            q.push(temp->right);
       } 
    }
}

void printTree(Node *root){
    if(root== NULL)return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty())q.push(NULL);
        }
       else{
         cout<<temp->data<<" ";
        // store left and right only when they are not null
        if(temp->left) q.push(temp->left);
       
        if(temp->right) q.push(temp->right);
       }
    }
}

int main(){

    Node *root = NULL; // pointer of type Node with size 8 bytes
   // cout<<sizeof(root)<<endl;
    buildTreeLevelOrder(root);
   
    printTree(root);
    cout<<endl;
    return 0;
}
