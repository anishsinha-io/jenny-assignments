#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* next;
    struct node* prev;
};

typedef struct node node_t;

void printlist(node_t *head){
    node_t *temp = head;

    while (temp != NULL){
        printf("%d - ", temp->value);
        temp = temp->next;
    }

    printf("\n");
}

node_t *create_new_node(int value){
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    result->prev = NULL;
    return result;
}

node_t *insert_at_head(node_t *head, node_t *node_to_insert){
    node_to_insert->next = head;
    return node_to_insert;
}

node_t *new_insert_at_head(node_t **head, node_t *node_to_insert){
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

void remove_node(node_t **head, node_t *node_to_remove){
    if(node_to_remove == NULL){
        return;
    }
    if(head&& *head == node_to_remove){
        *head = node_to_remove->next;
        if (*head != NULL){
            (*head)->prev = NULL; 
        }
    } else {
        //frind the previous node in the list
        node_to_remove->prev && (node_to_remove->prev->next = node_to_remove->next);
        if(node_to_remove == NULL){
            node_to_remove->next && (node_to_remove->next->prev = node_to_remove->prev);
        }
        node_to_remove->next = NULL;
    }
    return;
}

node_t *find_node(node_t *head, int value){
    node_t *temp = head;
    while (temp != NULL){
        if (temp->value == value) return temp;
        temp = temp->next;
    }
    return NULL;
}

void insert_after_node(node_t *node_to_insert_after, node_t *newnode){
    newnode->next = node_to_insert_after->next;
    if(newnode->next != NULL){
        newnode->next->prev = node_to_insert_after;
    }
    newnode->prev = node_to_insert_after;
    node_to_insert_after->next = newnode;
}

int main(){
    //usually we use linked lists when we don't know how many nodes we will need!
    //we want a list to grow to the size it needs to be
    node_t n1,n2,n3;
    node_t *head;

    
    //n1 = malloc(sizeof(node_t));
    n1.value = 45;
    n2.value = 8;
    n3.value = 32;

    //link them up

    head = &n1;
    n3.next = NULL;
    n2.next = &n3;
    n1.next = &n2;


    printlist(head); // 32 - 8 - 45 - 

    node_t n4;
    n4.value = 13;
    n4.next = &n3;
    n2.next = &n4;

    //head = head->next;
    //printlist(head); //45 - 8 - 13 - 32 - 

    printlist(head); // 8 - 13 - 32 - 


    //Using node_t *create_new_node(int value) function

    node_t *new_head;
    node_t *temp;

    temp = create_new_node(10);
    new_head = temp;
    temp = create_new_node(20);
    temp->next = new_head;
    new_head = temp;
    temp = create_new_node(30);
    temp->next = new_head;
    new_head = temp;

    printlist(new_head); // 30 - 20 - 10 - 


    // using a for loop
     node_t *loop_temp;
     node_t *loop_head;

    for (int i = 0; i<12; i++){
        loop_temp = create_new_node(i);
        loop_temp->next = loop_head;
        loop_head = loop_temp;
    }
    printlist(loop_head);

    // using insert_at_head function
    for (int i = 0; i<12; i++){
        loop_temp = create_new_node(i);
        loop_head = insert_at_head(loop_head, loop_temp);
    }
    printlist(loop_head);

    //using new_insert_at_head function
    for (int i = 0; i<12; i++){
        loop_temp = create_new_node(i);
        insert_at_head(loop_head, loop_temp);
    }
    printlist(loop_head);

    temp = find_node(head,13);
    printf("found node with value %d\n", temp->value);

    insert_after_node(temp, create_new_node(75));
    printlist(head);

    // remove_node(&head, temp);
    // remove_node(&head, head);



    return 0;

}

