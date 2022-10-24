//
// Created by zhenya on 24.10.2022.
//

#ifndef UNTITLED19_LIST_H
#define UNTITLED19_LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct data{
    char surname[5];
    char group[7];
    int first;
    int second;
    int third;
    int fourth;
    int fifth;
}list_data;

typedef struct listNode{
    list_data data;
    struct listNode *nextItem;
}listNode;

typedef listNode *listNodePtr;

void list_insert(listNodePtr *, list_data);
void list_delete_item(listNodePtr*, list_data data);
void list_print_average(listNodePtr head);
void list_print_all(listNodePtr head);
void update(list_data *, int);
void start(listNodePtr *);

#endif //UNTITLED19_LIST_H
