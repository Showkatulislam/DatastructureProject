/*2-1-2021 Owner:showkatul islam.
About link list
1.Insert function
2.Delete function
3.Count node function
4.Merge function
5.Max find function
6.Remove duplicate function
7.Revere function*/
#include<stdio.h>
typedef struct Node node;
struct Node
{
 int data;
 node *next;
}*head=NULL,*t=NULL,*second=NULL;
void createa(int a[],int n)
{
    node *last,*temp;
    int i;
    head=(node*)malloc(sizeof(node));
    head->data=a[0];
    head->next=NULL;
    last=head;
    for(i=1;i<n;i++)
    {
     temp=(node*)malloc(sizeof(node));
     temp->data=a[i];
     temp->next=NULL;
     last->next=temp;
     last=temp;
    }
}
void createb(int a[],int n)
{
    node *last,*temp;
    int i;
    second=(node*)malloc(sizeof(node));
    second->data=a[0];
    second->next=NULL;
    last=second;
    for(i=1;i<n;i++)
    {
     temp=(node*)malloc(sizeof(node));
     temp->data=a[i];
     temp->next=NULL;
     last->next=temp;
     last=temp;
    }
}
void display(node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void insert(int data,int pos)
{
    int i;
    node *temp,*p;
    if(pos==0)
    {
        temp=(node*)malloc(sizeof(node));
        temp->data=data;
        temp->next=head;
        head=temp;
    }
    else{
        p=head;
        for(i=1;i<pos;i++)
        {
             p=p->next;
        }
        temp=(node*)malloc(sizeof(node));
        temp->data=data;
        temp->next=p->next;
        p->next=temp;
    }
}
void Delete(int pos)
{
  int i;
  node *p=head,*q;
  if(pos==1)
  {
     head=head->next;
     free(p);
  }
  else{
    for(i=1;i<pos;i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    free(p);
  }
}
int CountNode(node *p)
{
  int c=0;
  while(p)
  {
     c++;
     p=p->next;
  }
  return c;
}
void Merge(node *f,node *s)
{
  node *l;
  if(f->data<s->data)
  {
      t=l=f;
      f=f->next;
      t->next=NULL;
  }
  else{
    t=l=s;
    s=s->next;
    t->next=NULL;
  }
  while(f && s)
  {
      if(f->data < s->data)
      {
          l->next=f;
          l=f;
          f=f->next;
          l->next=NULL;
      }
      else{
        l->next=s;
        l=s;
        s=s->next;
        l->next=NULL;
      }
  }
  if(f){
    l->next=f;
    l=f;
  }
  else{
    l->next=s;
    l=s;
  }
}
int Max(node *p)
{
  int max=p->data;
  while(p)
  {
      if(p->data >max)
        max=p->data;
      p=p->next;
  }
  return max;
}
void Removedup(node *q)
{
    node *p;
    p=q->next;
    while(p)
    {
       if(q->data !=p->data)
       {
           q=p;
           p=p->next;
       }
       else{
        q->next=p->next;
        free(p);
        p=q->next;
       }
    }
}
void Reverse(node *p)
{
    node *r=NULL,*q=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
}
void print()
{
    printf("1.Insert Node in any position.\n");
    printf("2.Delete Node in any position.\n");
    printf("3.Count Node in through the link list.\n");
    printf("4.Marge Two list.\n");
    printf("5.Find Max node in list.\n");
    printf("6.Remove duplicate from list\n");
    printf("7.Reverse Link list \n");

}
int main()
{
    int num,pos,data;;
    int array[5]={5,5,8,10,12};
    int array1[5]={1,3,4,15,19};
while(1){
    print();
    createa(array,5);
    createb(array1,5);
    display(head);
    scanf("%d",&num);
    switch(num)
    {
    case 1:
        {
            printf("Enter the data and position\n");
            scanf("%d %d",&data,&pos);
            insert(data,pos);
            display(head);
            break;
        }
    case 2:
        {
            printf("Enter position \n");
            scanf("%d",&pos);
            Delete(pos);
            display(head);
            break;
        }
    case 3:{
            printf("Number of Node : %d\n",CountNode(head));
            break;
           }
    case 4:{
            Merge(head,second);
            display(t);
           }
    case 5:{
            printf("The Maximum node data :%d\n",Max(head));
            break;
           }
    case 6:{
            Removedup(head);
            display(head);
            break;
           }
    case 7:{
            Reverse(head);
            display(head);
            break;
           }
    }
}
}
