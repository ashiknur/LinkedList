#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(){
        left=NULL;
        right=NULL;
    }
};
node* root;
void insert(int data){
    if(root==NULL){
        root = new node();
        root->data = data;
    }
    else
    {
        node* curr = root;
        node* parent;
        while(curr!=NULL)
        {
            parent = curr;
            if(curr->data<data)
            {
                curr = curr->right;
            }
            else {
                curr = curr->left;
            }
        }
        if(data<parent->data) {
            parent->left = new node();
            parent = parent->left;
            parent->data = data;
        }
        else {
            parent->right = new node();
            parent = parent->right;
            parent->data = data;
        }
    }
}

void print_preorder(node* rt)
{
    if(rt==NULL) return;
    print_preorder(rt->left);
    print_preorder(rt->right);
    cout<<rt->data<<" -> ";
}

int main()
{
    insert(10);
    insert(7);
    insert(15);
    insert(12);
    insert(17);
    insert(13);
    insert(11);
    print_preorder(root);
    return 0;
}