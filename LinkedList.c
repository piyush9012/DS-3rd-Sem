#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head;    // initially head is 0 

void begin_insert()
{
    struct node *newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter value\n");
        scanf("%d", &newnode->data);
        newnode->next = head;
        head = newnode;
        printf("Node inserted\n");
    }
}

void last_insert()
{
    struct node *newnode,*temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter value:\n");
        scanf("%d", &newnode->data);
        if(head == NULL) 
        {
            newnode->next = NULL;
            head = newnode;
            printf("Node inserted\n");
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = NULL;
            printf("Node inserted\n");
        }
    }
}

void specific_insert()
{
    int loc;
    struct node *newnode, *temp;
    newnode = (struct node *) malloc (sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter value\n");
        scanf("%d", &newnode->data);
        printf("Enter the location after which you want to insert\n");
        scanf("%d", &loc);
        temp = head;
        for(int i=0; i<loc; i++)
        {
            temp = temp->next;
            if(temp == NULL)
            {
                printf("Can't insert\n");
            }
        }
        newnode->next = temp->next; 
        temp->next = newnode;
        printf("Node inserted\n");
    }
}

void begin_delete()  
{
    struct node *temp;  
    if(head == NULL)  
    {  
        printf("Can't delete, List is empty\n");  
    }  
    else   
    {  
        temp = head;  
        head = temp->next;  
        free(temp);  
        printf("Node deleted from the begining\n");  
    }  
}

void last_delete()  
{  
    struct node *temp,*prevnode;  
    if(head == NULL)  
    {  
        printf("List is empty\n");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;  
        free(head);  
        printf("Node deleted from the last\n");  
    }          
    else
    {
        temp = head;   
        while(temp->next != NULL)  
        {
            prevnode = temp;  
            temp = temp->next;  
        }  
        prevnode->next = NULL;  
        free(temp);  
        printf("Deleted Node from the last\n");  
    }     
}

void specific_delete()
{  
    struct node *temp,*nextnode;  
    int i = 1, pos;    
    printf("Enter the node after which you want to delete\n");
    scanf("%d", &pos);  
    temp = head;  
    while (i < pos-1)
    {
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
    printf("Deleted node %d\n", pos+1);
}

void search()
{
    struct node *temp;
    int item, i=1, flag;
    temp = head;
    if(temp == NULL)  
    {  
        printf("List is empty\n");  
    }  
    else  
    {   
        printf("Enter item which you want to search\n");   
        scanf("%d",&item);
        while (temp != NULL)
        {
            if(temp->data == item)
            {
                printf("Item found at location %d\n", i);
                flag = 0;
                break;
            }
            else
            {
                flag = 1;
            }
            i++;  
            temp = temp->next;  
        }
        if (flag == 1)
        {
            printf("Item not found\n");
        }   
    }            
}  
  
void display()  
{  
    struct node *temp;  
    temp = head;   
    if(temp == NULL)  
    {  
        printf("List is empty\n");  
    }  
    else  
    {  
        printf("Printing Values\n");   
        while (temp != NULL)  
        {  
            printf("%d\t", temp->data);  
            temp = temp->next;  
        }
        printf("\n");
    }  
}

void main()  
{  
    int choice;  
    while(1)   
    {   
        printf("\nSelect the operation:\n");  
        printf("---------------------\n");  
        printf("1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search for an element\n8.Display\n9.Exit\n");           
        scanf("%d", &choice);  
        switch(choice)  
        {  
            case 1: begin_insert(); break;  
            case 2: last_insert(); break;  
            case 3: specific_insert(); break;  
            case 4: begin_delete(); break;  
            case 5: last_delete(); break;  
            case 6: specific_delete(); break;  
            case 7: search(); break;  
            case 8: display(); break;  
            case 9: exit(0);  
            default: printf("Please enter valid choice..");  
        }  
    }  
}