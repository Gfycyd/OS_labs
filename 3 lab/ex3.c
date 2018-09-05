#include <stdio.h>
#include <stdlib.h>

//
// Created by katukha on 05.09.18.
//
typedef struct Node {
    struct Node* next;
    int value;
} Node;
int count;
Node * head = NULL;
void print_list(){
    Node * temp = head;
    while (temp != NULL ){

        printf("%d  ",temp->value);
        temp = temp->next;

    }
    if (count == 0) printf("No elem in list now");
    printf("\n");

};
Node * constructor(int value, Node * next){
    Node * t = malloc(sizeof(Node));
    t->next = next;
    t->value = value;
    return t;
}
void insert_node(int value){
    if (head == NULL){
        head = constructor(value,NULL);
        count++;
    }
    else {
        Node * temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = constructor(value, NULL);
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
        count --;
    }
};

int main(){

    insert_node(7);
    insert_node(17);
    insert_node(27);
    insert_node(19);
    insert_node(190);
    insert_node(20);
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