#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
} Node;

Node* create_Node(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* create_List() {
    Node* List = create_Node(1);
    Node* current = List;
    for (int i = 2; i <= 5; i++) {
        Node* newNode = create_Node(i);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    return List;
}

Node* add(Node* List, int x) {
    Node* newNode = create_Node(x);
    newNode->next = List;
    if (List != NULL) {
        List -> prev = newNode;
    }
    return newNode;
}

int print(Node* List) {
    Node* current = List;
    while (current != NULL) {
        printf("%d ", current->data);
        if (current->next != NULL) {
            printf("<->");
        }
        current = current->next;
    }
    printf("->NULL\n");
    return 0;
}

int main() {
    Node* List = create_List();
    int x;
    printf("Nhap so nguyen duong: " );
    scanf("%d", &x);
    List = add(List, x);
    printf("Danh sach sau khi them dau la: ");
    print(List);
    return 0;
}