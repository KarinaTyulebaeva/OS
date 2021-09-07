#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
 struct Node 
 {
        int data;
        struct Node* next;
    };
    
 void print_list(struct Node* node)
 {
    while (node != NULL) {
        printf(" %d \n", node->data);
        node = node->next;
    }
     }
  void create_node( struct Node** new_node,int value)
  {
    *new_node = (struct Node*)malloc(sizeof(struct Node));
    (*new_node)->data=value;
    (*new_node)->next=NULL;
    }
  
 void insert_node(struct Node* head, int value)
 {
     struct Node *new_node;
     create_node(&new_node, value);
     struct Node* temp =  head->next;
     head->next=new_node;
     new_node->next=temp;
    } 
 
 void delete_node(struct Node** head, int value)
{
     struct Node *temp_node = *head, *prev_node;

    if (temp_node != NULL && temp_node->data == value) {
        *head = temp_node->next;
        free(temp_node);
        return;
    }

    while (temp_node != NULL && temp_node->data != value) {
        prev_node = temp_node;
        temp_node = temp_node->next;
    }

    if (temp_node == NULL)
        return;
    prev_node->next = temp_node->next;
    free(temp_node);
}

int main()
{
    struct Node *head;
    insert_node(&head,1);
    insert_node(&head,2);
    insert_node(&head,3);
    print_list(&head);
    
    return 0;
}
