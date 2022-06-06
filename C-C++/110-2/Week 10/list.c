#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

void addFirstonly(struct node **head, int val);
void deleteNode(struct node **head, int val);
void addFirst(struct node **head, int val);
int searchNode(struct node *head, int key);
void printNode(struct node *head);
void arrangeNode(struct node *head);

int main(void) {
    int choice;
    int num;

    scanf("%d", &choice);

    while (choice != 0) {
        switch (choice) {
            case 1:
                scanf("%d", &num);
                addFirstonly(&head, num);
                break;
            case 2:
                scanf("%d", &num);
                addFirst(&head, num);
                arrangeNode(head);
                printNode(head);
                break;
            case 3:
                scanf("%d", &num);
                deleteNode(&head, num);
                printNode(head);
                break;
            case 4:
                scanf("%d", &num);
                int found = searchNode(head, num);
                if (found) {
                    printf("Yes\n");
                }
                else {
                    printf("No\n");
                }
                break;
            
        }
        scanf("%d", &choice);
    }
}

void addFirstonly(struct node **head, int val)
{
    struct node *temp = *head;

    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = *head;

    *head = newNode;

    for (newNode = *head; newNode != NULL; newNode = newNode->next) {
        printf("%d\n", newNode->data);
    }
}

void addFirst(struct node **head, int val)
{
    struct node *temp = *head;

    while(temp != NULL)
    {
        if(temp->data == val)
            return;      
        temp = temp->next;
    }
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = *head;

    *head = newNode;
}

int searchNode(struct node *head, int key)
{
    struct node *temp = head;

    while(temp != NULL)
    {
        if(temp->data == key)
            return 1;
      
        temp = temp->next;
    }

    return 0;
}

void printNode(struct node *head) {
    struct node *current_node = head;
   	
    for (; current_node != NULL; current_node = current_node->next) {
        printf("%d", current_node->data);
        if (current_node->next != NULL) {
            printf(" ");
        }
    }
    
    printf("\n");
}

void deleteNode(struct node **head, int key) {
      struct node *temp;

      if((*head)->data == key)
      {
          temp = *head;
          *head = (*head)->next;
          free(temp);
      }
      

      else
      {
          struct node *current  = *head;
          while(current->next != NULL)
          {
              if(current->next->data == key)
              {
                  temp = current->next;
                  current->next = current->next->next;
                  free(temp);
                  break;
              }
              else
                  current = current->next;
          }
      }
}

void arrangeNode(struct node *head) {
    struct node *current = head;
    struct node *temp = NULL;

    int tempdata;

    while (current != NULL) {
        temp = current;
        while (temp->next != NULL) {
            if (temp->data > temp->next->data) {
                tempdata = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempdata;
            }
            temp = temp->next;
        }
        current = current->next;
    }
}