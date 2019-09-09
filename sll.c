#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *first=NULL;

void insert_front();
void insert_rear();
void delet_front();
void delet_rear();
void display();

void main()
{
    int choice;
    while(1)
    {
        printf("Press 1 to insert from front\n");
        printf("Press 2 to insert from rear\n");
        printf("Press 3 to delete from front\n");
        printf("Press 4 to delete from rear\n");
        printf("Press 5 to display from front\n");
        printf("Press  any key to exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert_front();
                    break;
            case 2:insert_rear();
                    break;
            case 3:delet_front();
                    break;
            case 4:delet_rear();
                    break;
            case 5:display();
                    break;
            default:exit(0);
        }
    }
}
    void insert_front()
    {
        int item;
        struct node *p;
        p=(struct node*)malloc(sizeof(struct node));
        printf("Enter the no to inserted: ");
        scanf("%d",&item);
        p->data=item;
        p->link=NULL;
        if(first==NULL)
        {
           first=p;
        }
        else
        {
          p->link=first;
          first=p;
        }
    }
    void insert_rear()
    {
        int item;
        struct node *p;
        p=(struct node*)malloc(sizeof(struct node));
        printf("Enter the no to inserted: ");
        scanf("%d",&item);
        p->data=item;
        p->link=NULL;
        if(first==NULL)
        {
           first=p;
        }
        else
        {
          struct node *temp;
          temp=first;
          while(temp->link!=NULL)
          {
              temp=temp->link;
          }
          temp->link=p;
        }
    }
    void delet_front()
    {
        struct node *temp;
        if(first==NULL)
        {
            printf("NP\n");
        }
        else if(first->link==NULL)
        {
            printf("dleted element is :%d\n",first->data);
            free(first);
            first=NULL;
        }
        else
       {
           printf("element deleted is :%d\n",first->data);
            temp=first;
            first=first->link;
            free(temp);
       }
    }
    void delet_rear()
    {
        struct node *temp;
        temp=first;
        if(first==NULL)
        {
            printf("Deletion not possible\n");
        }
        else if(first->link==NULL)
        {
            printf("deleted element is :%d\n",first->data);
            free(first);
            first=NULL;
        }
        else{
            temp=first;
            while(temp->link->link!=NULL)
            {
                temp=temp->link;
            }
            printf("Deleted item is: %d\n",temp->link->data);
            free(temp->link);
            temp->link=NULL;
        }
    }
    void display()
    {
        struct node *temp;
        if(first==NULL)
        {
            printf("NP\n");
        }
        else if(first->link==NULL)
        {
            printf("%d\n",first->data);
        }
        else{
            struct node *temp;
            temp=first;
            while(temp!=NULL)
            {
                printf("%d\t",temp->data);
                temp=temp->link;
            }
            printf("\n");
        }
     }
