#include<bits/stdc++.h>
using namespace std;

struct node{
    int l,r;
    int sum;
    node *left, *right;
    node(){
        sum=0;
        left = NULL;
        right = NULL;
    }
};

node *root;
int build(int ar[], int l, int r, node *curr){
    if(root==NULL){
       root = new node();
       curr = root; 
    }
    curr->l = l;
    curr->r = r;
    if(l==r){
        curr->sum = ar[l];
        return curr->sum;
    }
    int mid = (l+r)/2;
    curr->left = new node();
    curr->right = new node();
    int x = build(ar,l,mid,curr->left);
    int y = build(ar,mid+1,r,curr->right);
    curr->sum = x+y;
    return x+y;
}

int query(int ar[], int l, int r, node *curr,int L, int R)
{
    if(L<=l && r<=R) 
    {
        return curr->sum;
    }
    if(R<l || L>r) 
    {
        return 0;
    }
    int mid = (l+r)/2;
    int x = query(ar,l,mid,curr->left,L,R);
    int y = query(ar,mid+1,r,curr->right,L,R);
    return x+y;
}
void update(int ar[], int l, int r, node *curr, int at, int v)
{
    if(l==r) 
    {
        curr->sum = v;
        return;
    }
    int mid = (l+r)/2;
    if(at<=mid)
    {
        update(ar,l,mid,curr->left,at,v);
    }
    else 
    {
        update(ar,mid+1,r,curr->right,at,v);
    }
    curr->sum = curr->left->sum + curr->right->sum;
    // cout<<"NO ["<<curr->l<<", "<<curr->r<<"] "<<curr->sum<<" "<<" "<<curr->left->sum<<" "<<curr->right->sum<<endl;
}
int main()
{
    int n=3;
    int ar[] = {1,2,3};
    build(ar,0,n-1,root);
    update(ar,0,n-1,root,1,5);
    cout<<query(ar,0,n-1,root,0,n-1)<<endl;

    return 0;
}