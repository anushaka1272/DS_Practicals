#include <iostream>
#include <queue>
#include<limits.h>
using namespace std;


template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
	q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void preOrder(BinaryTreeNode<int>* root) {
    if(root == NULL) {
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

class isBst{
    public:
    int maxi,mini;
    bool isbst;
};
isBst helper(BinaryTreeNode<int> *root)
{
       isBst output;
if(root==NULL)
{
    output.maxi=INT_MIN;
    output.mini=INT_MAX;
    output.isbst=true;
    return output;
}
    isBst leftans=helper(root->left);
    isBst rightans=helper(root->right);
    output.mini=min(root->data,min(leftans.mini,rightans.mini));
    output.maxi=max(root->data,max(leftans.maxi,rightans.maxi));
    if(root->data<rightans.mini && root->data>leftans.maxi && leftans.isbst==true && rightans.isbst==true)
        output.isbst=true;
    else
        output.isbst=false;
    return output;
}
bool isBST(BinaryTreeNode<int> *root){
  return helper(root).isbst;  
}


int main() {
    int size;
    cin>>size;
    int *input=new int[1+size];
    
    for(int i=0;i<size;i++)
        cin>>input[i];
    
    BinaryTreeNode<int>* root = constructTree(input, size);
    preOrder(root);
    
}
