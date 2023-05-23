#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct nod
{
    int data;
    struct nod* next;
}node;

int main()
{
    printf("HELLO WORLD\n");
    clock_t begin = clock();
    
    node start;
    start.data=1;
    start.next=NULL;
    push(&start,5);
    push(&start,3);
    list_print(&start);
    insert(&start,1,7);

    list_print(&start);


    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n%f",time_spent);
    return 0;
}



void push(node *head, int info)
{
    node *current=head;

    while (current->next != NULL) {
        current = current->next;
    }

    current->next = (node *) malloc(sizeof(node));
    current->next->data = info;
    current->next->next = NULL;
}

int pop(node *head)
{
    node* current= head;
    while(1)
    {

        if(current->next->next==NULL)
        {
            int data=current->next->data;
            free(current->next);
            current->next=NULL;
            return data;
        }
        else
        {
            current=current->next;
        }
    }
    
}

int get(node* head,int index)
{
    node *current_node=head;
    int counter=0;
    while(1)
    {
        if(counter==index)
        {
            return current_node->data;
        }
        else
        {
            current_node=current_node->next;
            counter++;
        }
    }

}
//overwrites data on there
void set(node* head, int index, int data)
{
    int counter=0;
    node* current_node= head;
    node* nxt = NULL;

    while(1)
    {
        if(counter==index)
        {
            current_node->data=data;
            return;
        }
        else if (current_node->next==NULL)
        {
            return;
        }
        else
        {
            nxt=current_node->next;
            current_node=nxt;
            counter++;
        }
    }
}

//adds the data to the index given and therefore
//pushes the data later on further
void insert(node* head, int index, int data)
{
    int counter=0;
    node* current_node= head;
    node* nxt = NULL;
    if(index==0)
    {
        node *new_node = malloc(sizeof(node));
        new_node->data=data;
        new_node->next=current_node;
        
        return;
    }

    while(1)
    {
        if(counter==index-1)
        {
            node *new_node = malloc(sizeof(node));//creates node
            new_node->data=data;
            new_node->next=current_node->next;//next pointer is set to the pointer present in current node
            current_node->next=new_node;//current node changed to fit new node in chain
            return;
        }
        else if ((*current_node).next==NULL)
        {
            return;
        }
        else
        {
            nxt=(*current_node).next;
            current_node=nxt;
            counter++;
        }
    }
}






void delete(node*head,int index,int data)
{
    int counter=0;
    node* current_node=head;
    node* nxt=NULL;

    if(index==0)
    {
        nxt= (*current_node).next;// the current node
        head=nxt;
    }

    while(1)
    {
        if(counter==index-1)
        {
            node* next_node_pointer=(*current_node).next;
            node next_node=*next_node_pointer;
            (*current_node).next=next_node.next;
            return;
        }
        else if ((*current_node).next==NULL)
        {
            return;
        }
        else
        {
            nxt=(*current_node).next;
            current_node=nxt;
            counter++;
        }
    }

}

void list_print(node* head)
{
    node* current_node=head;
    node* nxt=NULL;
/*
    while(!((*current_node).next==NULL))
    {
        printf("%d\n",(*current_node).data);
        nxt=(*current_node).next;
        current_node=nxt;
    }
*/

    while(1)
    {
        //printf("%d",current_node->data);
        if(current_node->next==NULL)
        {
            printf("%d",current_node->data);
            return;
        }
        else
        {
            printf("%d\n",current_node->data);
            nxt=current_node->next;
            current_node=nxt;
        }
    }
}