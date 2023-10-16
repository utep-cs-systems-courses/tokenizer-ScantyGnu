#include "history.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

List* init_history(){
  struct s_List newList;
  struct s_List *list = malloc (sizeof(struct s_List));
  list->root = NULL;
  return list;
}


void add_history(List *list, char *str){
  struct s_Item *newNode = (struct s_Item*) malloc(sizeof(struct s_Item));
  newNode->str = str;
  newNode->next = NULL;

  if (!list->root){
    newNode->id = 0;
    list->root = newNode;
    return;
  }
  
  struct s_Item *currNode = list->root;
  int id = 1;

  while (currNode->next != NULL) {
    currNode = currNode->next;
    id ++;
  }

  newNode->id = id;
  currNode->next = newNode;
  return;
}

char *get_history(List *list, int id) {
  if (!list->root) {
    return '\0';
  }
  struct s_Item *currNode = list->root;

  do {
    currNode = currNode->next;
  }while (currNode->next && currNode->id != id);

  if (currNode->id == id) {
    return currNode->str;
  }
  return '\0';
}

void print_history(List *list){
  if (!list->root){
    puts("empty");
    return;
  }
  struct s_Item *currNode = list->root;
  
  while (currNode) {
    printf("%s\n", currNode->str);
    currNode = currNode->next;
  }
}

void free_history(List *list){
  free(list);
}
