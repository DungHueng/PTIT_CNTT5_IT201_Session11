
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* create_Node(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* create_List() {
    Node* head = create_Node(1);
    Node* current = head;
    for (int i = 2; i <= 5; i++) {
        Node* newNode = create_Node(i);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    return head;
}

int search(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    Node* List = create_List();
    int x;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &x);

    int total = search(List, x);
    if (total) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    return 0;
}