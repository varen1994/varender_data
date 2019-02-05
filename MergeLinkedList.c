#include<stdio.h>
#include<stdlib.h>

struct node {
   int data;
   struct node *next;
};

struct node *insertNode(struct node *head, int data)  {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->next = NULL;
  if(head == NULL)  {
    return newNode;
  } 
  else {
     struct node *headPreserved = head;
     while(head != NULL)  {
       if(head->next == NULL)  {
          head->next = newNode;
          return headPreserved;
       }
       head = head->next;
     }
  }
  printf("Program exited");
 return NULL;
}

void printLinkedList(struct node* head)  {
  printf("\n");
   while(head!=NULL)  {
     printf("%d->",head->data);
     head = head->next;
  }
  printf("NULL\n");
}

void mergeLinkedList(struct node *head1,struct node *head2)  {
  struct node *head3 = NULL;
  while(head1 != NULL &&  head2 != NULL)  {
    if((head1->data <= head2->data) && head1 != NULL)  { 
       head3 = insertNode(head3,head1->data);
       head1 = head1->next;
     }
     else {
       printf("Add Element from List 2");
       head3 = insertNode(head3,head2->data);
       head2 = head2->next; 
    }
  }

  if(head1 != NULL)  {
     while(head1!= NULL)  {
      head3 = insertNode(head3,head1->data);
       head1 = head1->next;
     }
   }
   else {
      if(head2 != NULL)  {
       while(head2!=NULL)  {
         head3 = insertNode(head3,head2->data);
         head2 = head2->next;
        }
      }
   }

  printf("Merged List");
  printLinkedList(head3);
}


int main()  {
  struct node *head = NULL;
  struct node *head2 = NULL;
  head = insertNode(head,5);
  head = insertNode(head,10);
  head = insertNode(head,15);
  head = insertNode(head,1000);
  head2 = insertNode(head2,2);
  head2 = insertNode(head2,3);
  head2 = insertNode(head2,20);
  head2 = insertNode(head2,100);
  printLinkedList(head);
  printLinkedList(head2);
  mergeLinkedList(head,head2);
  return 0;
}













