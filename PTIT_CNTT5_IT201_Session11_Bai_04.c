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

int long_N(Node* List) {
    int count = 0;
    Node* current = List;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    Node* List = create_List();
    int num = long_N(List);
    printf("Danh sach lien ket co %d phan tu ", num);
    return 0;
}