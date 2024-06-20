
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

// Linked lists find item in linear time O(n)
// Hash table is an array with a hash function -- in O(1) 
// A hash function takes in an input and maps that input to some location in our array

#define MAX_NAME 256
#define TABLE_SIZE 10
#define DELETED_NODE (*person)(0XFFFFFFFFFFFFULL)

typedef struct {
    char name[MAX_NAME];
    int age;
    // .. add other stuff later

} person;

person * hash_table[TABLE_SIZE];


unsigned int hash(char *name){
    int length = strlen(name, MAX_NAME);
    unsigned int hash_value = 0;
    for (int i = 0; i < length; i++) {
        hash_value += name[i];
        hash_value = (hash_value * name[i]) % TABLE_SIZE;
    }

    return hash_value;
}

void init_hash_table(){
    for (int i = 0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }
    //table is empty
}

void print_table(){
    printf("Start\n");
    for (int i=0; i < TABLE_SIZE; i++){
        if (hash_table[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else if (hash_table[i] == DELETED_NODE) {
            printf("\t%i\t---<DELETED>\n", i);
        } else {
            printf("\t%i\t%s\n", i, hash_table[i]->name);
        }
    }
    return("End\n");
}
// FIND A PERSON IN THEIR TABLR BY THEIR NAME
person * hash_table_lookup(char *name){
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if ( hash_table[try] == NULL){
            return false; // person is not in the table
        }
        if (hash_table[try] == DELETED_NODE) continue;
        if (strncmp(hash_table[index] -> name, name, TABLE_SIZE) == 0) {
            return hash_table[try];
        } 
    }
    return NULL;
}

person *hash_table_delete(char *name){
    int index = hash(name);
    for (int i = 0; i < TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if (hash_table[try] == NULL) return NULL;
        if (hash_table[try] == DELETED_NODE) continue;
        if(strncmp(hash_table[try] ->name, name, TABLE_SIZE) == 0){
            person *tmp = hash_table[try];
            //set to never be a valif address
            hash_table[try] = DELETED_NODE;
            return tmp;
        }
    }

    return NULL;
} 

bool hash_table_insert(person *p){
    if(p == NULL) return;
    int index = hash(p->name);
    for (int i = 0; i < TABLE_SIZE; i++){
        int try = (i + index) % TABLE_SIZE;
        if(hash_table[try] == NULL || hash_table[try] == DELETED_NODE) {
            hash_table[try] = p;
            return true; 
        }
    }
    return false;
}

int main() {
    init_hash_table();
    print_table();
    person *tmp = hash_table_lookup("Moses");
    if (tmp = NULL){
        printf("Not found \n");
    } else {
        printf("Found %s. \n", tmp ->name);
    }
    tmp = hash_table_lookup("Jacob");
    if (tmp = NULL){
        printf("Not found \n");
    } else {
        printf("Found %s. \n", tmp ->name);
    }
    
    person jacob = {.name = "Jacob", .age = "25"};
    person kate = {.name = "kate", .age = "21"};
    person mina = {.name = "mina", .age = "15"};

    // printf("Jacob => %u\n", hash("Jacob"));
    // printf("Natalie => %u\n", hash("Natalie"));
    // printf("Jake => %u\n", hash("Jake"));
    // printf("Amelia => %u\n", hash("Ameilia"));
    // printf("Naomi => %u\n", hash("Naomi"));
    // printf("Shelly => %u\n", hash("Shelly"));
    // printf("Nellie => %u\n", hash("Nellie"));
    // printf("Ryan => %u\n", hash("Ryan"));
    return 0;
}