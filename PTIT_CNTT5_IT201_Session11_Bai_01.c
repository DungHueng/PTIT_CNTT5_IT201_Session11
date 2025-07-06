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
    int arr[5] = {10, 20, 30, 40, 50};
    Node* head = create_Node(arr[0]);
    Node* current = head;

    for (int i = 1; i < 5; i++) {
        Node* newNode = create_Node(arr[i]);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }

    return head;
}

int print_List(Node* head) {
    Node* current = head;
    int count = 0;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
        count++;
    }
    return count;
}

int main() {
    Node* danhSach = create_List();
    printf("Danh sach lien ket doi gom: ");
    int num = print_List(danhSach);
    printf("So luong phan tu: %d", num);
    return 0;
}