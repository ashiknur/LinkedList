#include<bits/stdc++.h>
using namespace std;

struct node
{
    int roll;
    node *next;
};
node *root = NULL;
node *tail = NULL;
void append(int roll){
    if(root==NULL){
        root = new node();
        root->roll = roll;
        root->next = NULL;
        tail = root;
    }
    else
    {
        tail->next = new node();
        tail=tail->next;
        tail->roll = roll;
        tail->next = NULL;
    }

}

void delete_node(int roll)
{
    node *current = root;
    node *previous = NULL;
    while(current!=NULL && current->roll != roll)
    {
        previous = current;
        current = current->next;
    }

    if(previous==NULL)
    {
        node *temp = root;
        root = root->next;
        delete(temp);
    }
    else
    {
        previous->next = current->next;
        delete(current);
    }
}

void print(node *rt){
    while(rt!=NULL){
        cout<<rt->roll<<" -> ";
        rt = rt->next;
    }
}

int main()
{
    append(1);
    append(3);
    append(5);
    print(root);
    delete_node(3);
    cout<<endl;
    print(root);
    return 0;
}