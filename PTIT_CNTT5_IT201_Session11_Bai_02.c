
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

int print_List(Node* head) {
    Node* current = head;
    int index = 1;
    while (current != NULL) {
        printf("Node %d: %d\n", index, current->data);
        current = current->next;
        index++;
    }
    return index - 1;
}

int main() {
    Node* List = create_List();
    int num = print_List(List);
    printf("Tong so node: %d", num);
    return 0;
}