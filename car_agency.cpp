#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
using namespace std;
/*working with linked list*/
struct node1
{
    char name[20];
    unsigned long price;
    int number;
    node1 *next;
}*head,*temp,*ptr,*save,*loc=NULL,*locp=NULL;
void create()
{
    temp=new node1;
    strcpy(temp->name,"CIAZ");
    temp->price=805000;
    temp->number=10;
    temp->next=NULL;
    head=temp;

    temp->next=new node1;
    temp=temp->next;
    strcpy(temp->name,"CELERIO");
    temp->price=420000;
    temp->number=10;
    temp->next=NULL;

    temp->next=new node1;
    temp=temp->next;
    strcpy(temp->name,"GYPSY");
    temp->price=652000;
    temp->number=10;
    temp->next=NULL;

    temp->next=new node1;
    temp=temp->next;
    strcpy(temp->name,"ERTIGA");
    temp->price=667000;
    temp->number=10;
    temp->next=NULL;

    temp->next=new node1;
    temp=temp->next;
    strcpy(temp->name,"IGNIS");
    temp->price=473000;
    temp->number=10;
    temp->next=NULL;

    temp->next=new node1;
    temp=temp->next;
    strcpy(temp->name,"SWIFT");
    temp->price=497000;
    temp->number=4;
    temp->next=NULL;
}
void insertion()
{   char word[20];
    int flag=0;
    node1 *s;
    temp=new node1;
    cout<<"\nEnter car's name:";
    cin.ignore();
    cin.getline(word,20);
    for(int i=0;word[i]!='\0';i++)
    {
        if(islower(word[i]))
            word[i]=toupper(word[i]);
    }
    strcpy(temp->name,word);
    cout<<"\nHow many cars:";
    cin>>temp->number;
    ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(ptr->name,temp->name)==0)
        {
            ptr->number+=temp->number;
            flag=1;
            break;}

        ptr=ptr->next;
    }
    if(flag==0)
    {   cout<<"\nEnter car's price:";
        cin>>temp->price;
        temp->next=head;
        head=temp;
    }
}
int searching(char word[])
{
    ptr=head;
    for(int i=0;word[i]!='\0';i++)
    {
        if(islower(word[i]))
            word[i]=toupper(word[i]);
    }
    while(ptr!=NULL)
    {
        if(strcmp(ptr->name,word)==0)
            return 1;
        ptr=ptr->next;
    }
return 0;

}
void deletion(char word[])
{  node1 *s;
   if(head==NULL)
   {
       cout<<"\nEmpty.";
       return ;
   }
   else if(strcmp(head->name,word)==0)
   {
       locp=NULL;
       loc=head;
   }
   else
   {
       save=head;
       ptr=head->next;
       while(ptr!=NULL)
       {
           if(strcmp(ptr->name,word)==0)
           {
               locp=save;
               loc=ptr;
           }
           save=ptr;
           ptr=ptr->next;
       }

   }
   if(loc==head)
   {
       head->number=head->number-1;
       if(head->number==0)
       {
           s=head;
           head=head->next;
           delete s;
       }
   }
   else
   {
       loc->number=loc->number-1;
       if(loc->number==0)
       {
           locp->next=loc->next;
           s=loc;
           delete s;
       }
   }
}
void display()
{
 if(head==NULL)
 {
     cout<<"\nEmpty.";
     return;
 }
 ptr=head;
 while(ptr!=NULL)
 {
     cout<<"\nCar's name:";
     cout<<ptr->name;
     cout<<"\nCar's price:";
     cout<<ptr->price;
     cout<<"\n----------------------------------";
     ptr=ptr->next;

 }
}
struct node2
{
    char car_name[20];
    char cust_name[20];
    int cust_no[10];
    node2 *link;
}*top=NULL,*front=NULL,*rear=NULL,*ptr2,*ptr3;

/*working with queue and stack*/
void q_insert(char ca_name[],char cu_name[],int n[])
{   ptr2=new node2;
    strcpy(ptr2->car_name,ca_name);
    strcpy(ptr2->cust_name,cu_name);
    for(int i=0;i<10;i++)
    ptr2->cust_no[i]=n[i];
    ptr2->link=NULL;

    if(front==NULL)
    {
      front=rear=ptr2;
    }
    else
    {
        rear->link=ptr2;
        rear=ptr2;
    }
    deletion(ptr2->car_name);
}
void s_push(char ca_name[],char cu_name[],int n[])
{   ptr3=new node2;
    strcpy(ptr3->car_name,ca_name);
    strcpy(ptr3->cust_name,cu_name);
    for(int i=0;i<10;i++)
    ptr3->cust_no[i]=n[i];

    ptr3->link=top;
    top=ptr3;
}

void q_delete()
{   node2 *r;
    if(front==NULL)
    {
        cout<<"\nCurrently no order.";
        return ;
    }
    else{
         r=front;
         front=front->link;
         for(int i=0;r->cust_name[i]!='\0';i++)
         {
             if(islower(r->cust_name[i]))
              r->cust_name[i]=toupper(r->cust_name[i]);
         }
         s_push(r->car_name,r->cust_name,r->cust_no);
         cout<<"\nONE ORDER COMPLETED.(According to first come first served rule.)";
         delete r;
    }
}

void s_display()
{ if(top==NULL)
  {
      cout<<"\nNEW STORE.\nNO SALES.";
      return ;
  }
  else
  {
      ptr3=top;
      cout<<"\n";
      while(ptr3!=NULL)
      {
          cout<<"\nCar's name: ";
          cout<<ptr3->car_name;
          cout<<"\nCustomer's name: ";
          cout<<ptr3->cust_name;
          cout<<"\nCustomer's contact number: ";
          for(int i=0;i<10;i++)
          cout<<ptr3->cust_no[i];
          cout<<"\n-----------------------------------\n";
          ptr3=ptr3->link;
      }
  }
}

int main()
{
    int choice1,choice2=0,x;
    char word[20];
    char ch;
    char a[20],b[20];
    int c[10];
    unsigned long d,e;
    create();
    cout<<"WELCOME TO AUTOBURN!!!\n-------------------------------------------";
    while(1)
    {cout<<"\n1.Work related to company's side.";
    cout<<"\n2.Work related to customers.";
    cout<<"\n3.Exit";
    cout<<"\nEnter choice:";
    cin>>choice1;
    if(choice1==1)
    { while(1)
      {
        cout<<"\n1.Add a new car.";
        cout<<"\n2.Display of sale's record.";
        cout<<"\n3.Exit";
        cout<<"\nEnter choice:";
        cin>>choice2;
        switch(choice2)
        {
            case 1:insertion();
                   break;
            case 2:s_display();
                   break;
            case 3:break;
           default:cout<<"\nWrong Entry!!!Please enter a valid input.";
        }
        cout<<"\n";
       if(choice2==3)
       break;
     }
    }
    else if(choice1==2)
    {
        while(1)
        {
            cout<<"\n1.Taking order.";
            cout<<"\n2.Completing order.";
            cout<<"\n3.Exit.";
            cout<<"\nEnter choice:";
            cin>>choice2;
            switch(choice2)
            {
                case 1:cout<<"\nCars available in the store are:\n";
                       display();
                       cout<<"\nEnter car's name you want to purchase:";
                       cin.ignore();
                       cin.getline(a,20);
                       x=searching(a);
                       if(x==0)
                       {
                           cout<<"\nCar not there in the store currently.\nSORRY!!";
                           break;
                       }
                       else if(x==1)
                       { cout<<"\nCar available in the store.";
                         cout<<"\nDo you want to confirm the order.(**Enter y/Y to confirm.**):";
                         cin>>ch;
                         if(ch=='y'||ch=='Y')
                         { cout<<"\nPlease enter your details:";
                         cout<<"\nName:";
                         cin.ignore();
                         cin.getline(b,20);
                         cout<<"\nEnter contact number(digit separated by space):";
                         for(int i=0;i<10;i++)
                         cin>>c[i];
                         cout<<"\nBOOKING CONFIRMED.\nTHANK YOU";
                         q_insert(a,b,c);
                         break;
                         }
                         else
                         {
                             cout<<"\nNo problem.\nThank you for contacting us.";
                             break;
                         }
                         }
                case 2:q_delete();
                       break;
                case 3:break;
                default:cout<<"\nWrong Entry!!!Please enter a valid input.";
            }
            cout<<"\n";
         if(choice2==3)
         break;
        }
    }
    else if(choice1==3)
    {
        exit(0);
    }
    else
    cout<<"\nWrong Entry!!!Please enter a valid input.\n";
    }

    return 0;
}
