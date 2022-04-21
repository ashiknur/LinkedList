#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *prev, *next;
    node(){
        prev = NULL;
        next = NULL;
    }
};
node *root;
node *tail;
void push_back(int data){
    node *curr;
    if(root==NULL) {
        root = new node();
        root->data = data;
        tail = root;
    }
    else
    {
        curr = tail;
        tail->next = new node();
        tail = tail->next;
        tail->data = data;
        tail->prev = curr;
    }
}
void push_front(int data){
    node *curr;
    if(root==NULL) {
        root = new node();
        root->data = data;
        tail = root;
    }
    else{
        curr = root;
        root->prev = new node();
        root = root->prev;
        root->data = data; 
        root->next = curr;
    }
}
void printforward(node *rt)
{
    if(rt!=NULL){
        cout<<rt->data;
        rt=rt->next;
    }
    while(rt!=NULL)
    {
        cout<<" -> "<<rt->data;
        rt = rt->next;
    }
    cout<<endl;
}
void printbackward(node *rt)
{
    if(rt!=NULL){
        cout<<rt->data;
        rt=rt->prev;
    }
    while(rt!=NULL)
    {
        cout<<" -> "<<rt->data;
        rt = rt->prev;
    }
    cout<<endl;
}
int main()
{
    push_back(1);
    push_back(2);
    push_back(3);
    push_back(4);
    push_front(-1);
    printbackward(tail);
    printforward(root);

    return 0;
}