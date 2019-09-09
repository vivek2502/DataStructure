#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *llink;
    int data;
    struct node *rlink;
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
        p->llink=NULL;
        p->data=item;
        p->rlink=NULL;
        if(first==NULL)
        {
           first=p;
        }
        else
        {
          p->rlink=first;
          first->llink=p;
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
        p->llink=NULL;
        p->data=item;
        p->rlink=NULL;
        if(first==NULL)
        {
           first=p;
        }
        else
        {
          struct node *temp;
          temp=first;
          while(temp->rlink!=NULL)
          {
              temp=temp->rlink;
          }
          temp->rlink=p;
          p->llink=temp;
        }
    }
    void delet_front()
    {
        struct node *temp;
        if(first==NULL)
        {
            printf("NP\n");
        }
        else if(first->rlink==NULL)
        {
            printf("dleted element is :%d\n",first->data);
            free(first);
            first=NULL;
        }
        else
       {
           printf("element deleted is :%d\n",first->data);
            temp=first;
            first=first->rlink;
            free(temp);
            first->llink=NULL;
       }
    }
    void delet_rear()
    {
        struct node *temp;
        if(first==NULL)
        {
            printf("Deletion not possible\n");
        }
        else if(first->rlink==NULL)
        {
            printf("deleted element is :%d\n",first->data);
            free(first);
            first=NULL;
        }
        else{
            temp=first;
            while(temp->rlink->rlink!=NULL)
            {
                temp=temp->rlink;
            }
            printf("Deleted item is: %d\n",temp->rlink->data);
            free(temp->rlink);
            temp->rlink=NULL;
        }
    }
    void display()
    {
        struct node *temp;
        if(first==NULL)
        {
            printf("NP\n");
        }
        else if(first->rlink==NULL)
        {
            printf("%d\n",first->data);
        }
        else{
            struct node *temp;
            temp=first;
            while(temp!=NULL)
            {
                printf("%d\t",temp->data);
                temp=temp->rlink;
            }
            printf("\n");
        }
     }
