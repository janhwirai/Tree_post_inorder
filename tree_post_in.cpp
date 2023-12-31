#include<bits/stdc++.h>
using namespace std;

struct Node{
        //This class will represent a single node in a particular tree
        int data;
        struct Node* left;
        struct Node* right;

        //Constructor
        Node(int val){
            data=val;
            left=NULL;
            right=NULL;
        }
};

int search(int inorder[], int start,int end,int val){
    for(int i=start;i<=end;i++){
        if(inorder[i]==val){
            return i;
        }
    }
    return -1;
}

void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

Node* buildTree(int postorder[],int inorder[], int start,int end){
    static int idx=4; //n-1
   if(start>end){
    //Base Case
    return NULL;
   }
    int val=postorder[idx];
    idx--;
    Node* curr =new Node(val);
    if(start==end){//No left subtree or right subtree present
        return curr;
    }
    int pos=search(inorder,start,end,val);
    curr->right=buildTree(postorder,inorder,pos+1,end);
    curr->left=buildTree(postorder,inorder,start,pos-1);
  

    return curr;
}

int main(){
    int postorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    Node* root=buildTree(postorder,inorder,0,4);
    inorderPrint(root);
    return 0;
}