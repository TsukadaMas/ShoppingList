#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product{
char name[20];
int price;
}product;


typedef struct Node{
product item;
struct Node * next;
}node;

typedef struct list{
node * head;

}LinkedList;


void ShowMenu(LinkedList * list){
    printf("Enter your choice as the following\n\n");
    printf("(Verb) (Noun), (Price *if applicable*)\n");
    printf("Enter the verb as lower-case and in present tense\n\n");
    printf("The Verb words you can use are Add,Print,Search,Remove,Terminate,Discount,Quit\n");
    printf("Special function: Pierre's is going bankrupt. (A.K.A: Terminate)\n");
}

void add(LinkedList * list,char item[], int price){
    node * input = (node *)malloc(sizeof(node));
    input->next = NULL;
    strcpy(input->item.name, item);
    input->item.price = price;

    if(list->head == NULL){
        list->head = input;
    }
    else{
        node * current = list->head;
        if(current->item.price >= input->item.price){
            input->next = current;
            list->head = input;
        }else{
            while(current->next != NULL){
                current = current->next;
                }
            current->next = input;
        }
    }
}

void update(LinkedList * list){
    if(list->head == NULL){
        printf("\nThere are no items for sale in this store.\n");
    }else{
    node * current = list->head;
    while(current != NULL){
        if(current->item.name){
        printf("%s,  $%d\n",current->item.name, current->item.price);
        }else{

        }
       current = current->next;
    }
    }
}

void terminate(LinkedList * list){
    if(list->head == NULL){
    //do nothing make the list null
    }else{
    node * current = list->head;
    while(current != NULL){
       list->head = current->next;
      free(current);
    }
    }
    printf("\nterminate has been executed\n");
}

void search(LinkedList * list,char item[]){
    if(list->head == NULL){
        printf("There are no items for sale in this store.\n");
    }else{
    node * current = list->head;
    while(current != NULL){
       if(strcmp(current->item.name,item) == 0){
        printf("\n%s found\n",current->item.name);
        printf("Price: $%d\n\n",current->item.price);
        return;
       }else{
       current = current->next;
       }
       printf("\n%s could not be found\n",item);
    }
    }
}

void take(LinkedList * list,char item[]){
    if(list->head == NULL){
    printf("There are no items for sale in this store.\n");
    }else{
    node * current = list->head;
    node * toBeDeleted = NULL;
    if(strcmp(current->item.name,item) == 0){
        if(current->next == NULL){
            toBeDeleted = current;
            list->head = NULL;
        }else{
            toBeDeleted = current;
            list->head = current->next;
        }
    }
    while(current->next != NULL){
       if(strcmp(current->next->item.name,item) == 0){
            toBeDeleted = current->next;
            current->next = current->next->next;
            return;
        }else if(strcmp(current->item.name,item) == 0 && current->next != NULL){
            toBeDeleted = current;
            current->item = current->next->item;
            current->next = current->next->next;
            return;
        }else if(strcmp(current->item.name,item) == 0 && current->next == NULL){
            toBeDeleted = current;
            current = (node *)malloc(sizeof(node));
            current->next = NULL;
            return;
        }else{
       current = current->next;
       }
    }
    free(toBeDeleted);
    }
}

void discount(LinkedList * list,char item[]){
    if(list->head == NULL){
    printf("There are no items for sale in this store.\n");
    }else{
    node * current = list->head;
    while(current != NULL){
       if(strcmp(current->item.name,item) == 0){
        current->item.price = (int)(current->item.price - (current->item.price * 0.2));
        return;
       }
       current = current->next;
    }
    }
}
