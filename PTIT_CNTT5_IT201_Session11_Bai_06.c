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

Node* delete_First(Node* List) {
    if (List == NULL) return NULL;

    Node* newHead = List->next;
    if (newHead != NULL) {
        newHead->prev = NULL;
    }
    free(List);
    return newHead;
}

int print_List(Node* List) {
    Node* current = List;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL)
            printf("<->");
        current = current->next;
    }
    printf("->NULL\n");
    return 0;
}

int main() {
    Node* List = create_List();

    printf("Truoc khi xoa: ");
    print_List(List);

    List = delete_First(List);

    printf("Sau khi xoa phan tu dau: ");
    print_List(List);

    return 0;
}