#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#inlude "classes.h"
int main()
{
LinkedList * list = (LinkedList*)malloc(sizeof(LinkedList));
list->head = NULL;
ShowMenu();
char string[40];
char verb[30];
char item[20];
int price = 0;

while (strcmp(verb,"quit") != 0) {
    fgets(string, 39, stdin);
    sscanf(string, "%s %s %d",verb,item,&price);
    if(strcmp(verb,"add") == 0){
        add(list,item, price);
    }else if(strcmp(verb,"print") == 0){
        printf("\n");
        update(list);
    }else if(strcmp(verb,"search") == 0){
        search(list,item);
    }else if(strcmp(verb,"remove") == 0){
        take(list,item);
    }else if(strcmp(verb,"terminate") == 0){
        terminate(list);
    }else if(strcmp(verb,"discount") == 0){
        discount(list, item);
    }else if(strcmp(verb,"pierre's") == 0){
        terminate(list);
    }

  }


}
