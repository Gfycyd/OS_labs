//
// Created by katukha on 05.09.18.
//

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    struct Node* next;
    struct Node* prev;
    int value;
} Node;
int count;
Node * head = NULL, * tail = NULL;
void print_list(){
    Node * temp = head;
    while (temp != NULL ){

        printf("%d  ",temp->value);
        temp = temp->next;

    }
    if (count == 0) printf("No elem in list now");
    printf("\n");

};
Node * constructor(int value, Node * next, Node * prev){
    Node * t = malloc(sizeof(Node));
    t->next = next;
    t->prev = prev;
    t->value = value;
    return t;
}
int find_elem(int val){
    Node * temp = head;
    while (temp != NULL && temp->value != val  ){

        temp = temp->next;

    }
    if (temp != NULL) return 1;
    return 0;
}
void insert_node(int value){
    if (head == NULL){
        head = constructor(value,NULL, NULL);
        tail = head;
        count++;
    }
    else {
        Node * temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = constructor(value, NULL,temp);
        tail = temp->next;
        count ++;
    }
};

void delete_node(){
    if ( count <= 0 ) printf("Unavailable operation, firstly add smth \n");
    else if (count == 1){
        head = NULL;
        count --;
    }
    else {
        Node * temp = head;
        head = temp->next;
        head->prev = NULL;
        count --;
    }
};

int main() {

    insert_node(7);
    insert_node(17);
    insert_node(27);
    insert_node(19);
    insert_node(190);
    insert_node(20);
    printf("tail   %d \n ", tail->value);
    printf("head   %d\n",head->value);
    printf("%d \n", find_elem(9));

    print_list();
    delete_node();
    print_list();
    delete_node();
    delete_node();
    delete_node();
    print_list();
    delete_node();
    delete_node();
    print_list();
    delete_node();
    return 0;
}