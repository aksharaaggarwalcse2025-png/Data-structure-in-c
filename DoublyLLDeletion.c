#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create Doubly Linked List
    for(i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while(temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Deletion from end
    if(head == NULL) {
        printf("List is empty");
    }
    else if(head->next == NULL) {
        free(head);
        head = NULL;
    }
    else {
        temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->prev->next = NULL;
        free(temp);
    }

    // Display
    printf("\nDoubly Linked List after deletion: ");

    temp = head;

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}