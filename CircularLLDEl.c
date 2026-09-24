#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create Circular Linked List
    for(i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;

        if(head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            temp = head;

            while(temp->next != head) {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Deletion of first node
    if(head == NULL) {
        printf("List is empty");
    }
    else if(head->next == head) {
        free(head);
        head = NULL;
    }
    else {
        temp = head;

        while(temp->next != head) {
            temp = temp->next;
        }

        temp->next = head->next;

        temp = head;
        head = head->next;

        free(temp);
    }

    // Display after deletion
    if(head == NULL) {
        printf("List is empty");
    } else {
        printf("Circular Linked List after deletion: ");

        temp = head;

        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while(temp != head);
    }

    return 0;
}