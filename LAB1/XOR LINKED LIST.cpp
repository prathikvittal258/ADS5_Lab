#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *ptrdif;
};
node *head=NULL;

node* XOR (node *a, node *b)  
{  
    return (node*) ((uintptr_t) (a) ^ (uintptr_t) (b));  
} 

void print_list()
{
   node *ptr = head;
   node *prev=NULL;
   node *store=NULL; 
   while(ptr!=NULL)
   {
       cout<<ptr->data<<" ";
       store=prev;
       prev=ptr;
       ptr=XOR(store,ptr->ptrdif);
   } 
}
void insert_front(int x)
{
   node *temp = new node;
   temp->data = x;
   temp->ptrdif = NULL;
   if(head != NULL)
   {
       temp->ptrdif = XOR(head,NULL);
       head->ptrdif = XOR(head->ptrdif,temp);
   }
   head=temp;
}

void insert_rear(int x)
{
  node *temp = new node;
  temp->data = x;
  temp->ptrdif = NULL;
  if(head == NULL)
    head=temp;
  else
  {
   node *ptr = head;
   node *prev=NULL;
   node *store=NULL;
   while(ptr!=NULL)
   {
       store=prev;
       prev=ptr;
       ptr=XOR(store,ptr->ptrdif);
   }
   prev->ptrdif=XOR(temp,store);
   temp->ptrdif=prev;
  }
}

int main()
{
  int n,x;
  while(100)
  {
    cout<<"\n\n\nEnter 1 to insert at front end...\nEnter 2 to insert at rear end...\nEnter 0 to exit!..\n";
    cin>>n;
    switch(n)
    {
        case 0 : cout<<"*Thank you*\n";
                 return 0;
        case 1 : cout<<"Enter the element\n";
                 cin>>x;
                 cout<<"Before :";
                 print_list();
                 insert_front(x);
                 cout<<"\nAfter insert_front : ";
                 print_list();
                 break;
        case 2 : cout<<"Enter the element\n";
                 cin>>x;
                 cout<<"Before : ";
                 print_list();
                 insert_rear(x);
                 cout<<"\nAfter insert_rear : ";
                 print_list();
    }
  }
    return 0;
    
}
