#include <stdio.h>
#include <stdlib.h>

//calculate modular (linked list to store information)

struct node {
    long long int data;
    struct node *next;
};

struct node *head = NULL;

void addFirstonly(struct node **head, int val);
void printNode(struct node *head);
long long int powermod(long long int a, long long int b, long long int mod) {
    long long x = 1, y = a;

	while (b > 0) {
		if (b % 2 == 1) {
			x = (x * y) % mod;
        }

		y = (y * y) % mod;

		b = b / 2;
	}

	return x % mod;
}

int main(void) {
    unsigned int b, p, m;
    unsigned long long int data = 1;
    int flag = 0;

    scanf("%d%d%d", &b, &p, &m);

    while ((b + p + m) != 0) {
        data = powermod(b, p, m);

        addFirstonly(&head, data);

        scanf("%d%d%d", &b, &p, &m);

        data = 1;
    }
    printNode(head);
}

void addFirstonly(struct node **head, int val)
{
    struct node *temp = *head;

    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = *head;

    *head = newNode;
}

void printNode(struct node *head) {
    if (head == NULL)
       return;
 
    printNode(head->next);
 
    printf("%lld\n", head->data);
}