#include <iostream>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <queue>
#include <memory>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createTree(int data)
{
    TreeNode* root=new  TreeNode;
    root->data=data;
    root->left=nullptr;
    root->right=nullptr;
    return root;
}

void insertNode(TreeNode* parent, TreeNode* leftNode, TreeNode* rightNode)
{
    parent->left=leftNode;
    parent->right=rightNode;
}

void preorder(TreeNode* root)
{
    if(root==nullptr)
        return;
    cout<<root->data<<'\t';
    preorder(root->left);
    preorder(root->right);
    return ;
}

void midorder(TreeNode* root)
{
    if(root==nullptr)
        return;
    midorder(root->left);
    cout<<root->data<<'\t';
    midorder(root->right);
    return ;
}

void postorder(TreeNode* root)
{
    if(root==nullptr)
        return;
    preorder(root->left);
    preorder(root->right);
    cout<<root->data<<'\t';
    return ;
}

void preorder_bystack(TreeNode* root)
{
    stack<TreeNode*> myst;
    TreeNode* tmp=root;
    while(tmp!=nullptr || myst.empty()==false)
    {
        while(tmp!=nullptr)
        {
            cout<<tmp->data<<'\t';
            myst.push(tmp);
            tmp=tmp->left;
        }
        if(myst.empty()==false)
        {
            tmp=myst.top();
            myst.pop();
            tmp=tmp->right;
        }
    }
    return;
}

void midorder_bystack(TreeNode* root)
{
    stack<TreeNode*> myst;
    TreeNode* tmp=root;
    while(tmp!=nullptr||myst.empty()==false)
    {
        while(tmp!=nullptr)
        {
            myst.push(tmp);
            tmp=tmp->left;
        }
        if(myst.empty()==false)
        {
            tmp=myst.top();
            cout<<tmp->data;
            myst.pop();
            tmp=tmp->right;
        }
    }
    return;
}
int main()
{
    TreeNode* root=createTree(0);
    TreeNode* node1=createTree(1);
    TreeNode* node2=createTree(2);
    TreeNode* node3=createTree(3);
    TreeNode* node4=createTree(4);
    TreeNode* node5=createTree(5);
    TreeNode* node6=createTree(6);
    insertNode(root, node1, node2);
    insertNode(node1, node3, node4);
    insertNode(node2, node5, nullptr);
    insertNode(node4, nullptr, node6);
    //preorder(root);
    //cout<<endl;
    midorder(root);
    cout<<endl;
    //postorder(root);
    //cout<<endl;
    
    //preorder_bystack(root);
    //cout<<endl;
    midorder(root);
    cout<<endl;
}