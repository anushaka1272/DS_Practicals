#include <iostream>
#include <queue>
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
    ~BinaryTreeNode() {
    	if(left) 
       		delete left;
    	if(right) 
       		delete right;
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
int lcaInBST(BinaryTreeNode<int>* root , int val1 , int val2){
    int leftans=-1,rightans=-1;
if(root==NULL)
    {
        return -1;
    }
    if(root->data==val1 || root->data==val2)
    {
        return root->data;
    }
    if(val1<root->data && val2<root->data)
    leftans=lcaInBST(root->left,val1,val2);
    else if(val1>root->data && val2>root->data)
     rightans=lcaInBST(root->right,val1,val2);
   else
   {
       leftans=lcaInBST(root->left,val1,val2);
       rightans=lcaInBST(root->right,val1,val2); 
   }
if(leftans==-1 && rightans==-1)
    return -1;
    else if(leftans==-1)
    {
        return rightans;
    }
    else if(rightans==-1)
    {
        return leftans;
    }
    else
    {
        return root->data;
    }
}



int main() {
    BinaryTreeNode<int>* root = takeInput();
    int a, b;
    cin >> a >> b;
    cout << lcaInBST(root, a, b);
    delete root;
}
