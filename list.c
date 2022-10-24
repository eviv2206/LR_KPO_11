//
// Created by zhenya on 24.10.2022.
//

#include "list.h"
#include "string.h"


void list_insert(listNodePtr *head, list_data data) {
    listNodePtr currPtr = *head;
    int isDone = 0;
    if (*head == NULL) {
        listNodePtr tmp = malloc(sizeof(listNode));
        tmp->data = data;
        tmp->nextItem = NULL;
        *head = tmp;
    } else {
        while (currPtr->nextItem != NULL) {
            if ((strcmp(currPtr->data.surname, data.surname) == 0) &&
                (strcmp(currPtr->data.group, data.group) == 0)) {
                currPtr->data.first = data.first;
                currPtr->data.second = data.second;
                currPtr->data.third = data.third;
                currPtr->data.fourth = data.fourth;
                currPtr->data.fifth = data.fifth;
                isDone = 1;
            }
            currPtr = currPtr->nextItem;
        }
        if (!isDone) {
            listNodePtr tmp = malloc(sizeof(listNode));
            tmp->data = data;
            tmp->nextItem = NULL;
            currPtr->nextItem = tmp;
        }
    }
}

void list_delete_item(listNodePtr *head, list_data data) {
    listNodePtr tmpPtr, prevPtr, curPtr;
    if (*head != NULL) {
        if ((strcmp(data.group, (*head)->data.group) == 0) && (strcmp(data.surname, (*head)->data.surname) == 0)) {
            tmpPtr = *head;
            *head = (*head)->nextItem;
            free(tmpPtr);
        } else {
            prevPtr = *head;
            curPtr = (*head)->nextItem;

            while (curPtr != NULL && (strcmp(curPtr->data.surname, data.surname) != 0) &&
                   (strcmp(curPtr->data.group, data.group) != 0)) {
                prevPtr = curPtr;
                curPtr = curPtr->nextItem;
            }
            if (curPtr != NULL) {
                tmpPtr = curPtr;
                prevPtr->nextItem = curPtr->nextItem;
                free(tmpPtr);
            }
        }
    }
}

void list_print_average(listNodePtr head) {
    if (head == NULL) printf("List is empty\n");
    else {
        while (head != NULL) {
            list_data data = head->data;
            double average = (double) (data.first + data.second + data.third + data.fourth + data.fifth) / 5;
            printf("Student %s group %s has %lf\n", data.surname, data.group, average);
            head = head->nextItem;
        }
    }
}

void list_print_all(listNodePtr head) {
    if (head == NULL) printf("List is empty\n");
    else {
        while (head != NULL) {
            list_data data = head->data;
            printf("Student %s group %s has marks %d %d %d %d %d\n", data.surname, data.group, data.first, data.second,
                   data.third, data.fourth, data.fifth);
            head = head->nextItem;
        }
    }
}

void update(list_data *toFind, int option) {
    printf("Input surname: \n");
    scanf("%s", (*toFind).surname);
    printf("Input group: \n");
    scanf("%s", (*toFind).group);
    if (option == 1) {
        printf("Input first mark: \n");
        scanf("%d", &(*toFind).first);

        printf("Input second mark: \n");
        scanf("%d", &(*toFind).second);

        printf("Input third mark: \n");
        scanf("%d", &(*toFind).third);

        printf("Input fourth mark: \n");
        scanf("%d", &(*toFind).fourth);
        printf("Input fifth mark: \n");
        scanf("%d", &(*toFind).fifth);
    }
}

void start(listNodePtr *head) {
    FILE *f1 = fopen("D:/test.txt", "r");
    list_data data;
    while (!feof(f1)) {
        fscanf(f1, "%s %s %d %d %d %d %d", data.surname, data.group,
               &data.first, &data.second, &data.third, &data.fourth, &data.fifth);
        list_insert(head, data);
    }
    fclose(f1);
}

