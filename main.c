#include <stdio.h>
#include "list.h"
int main() {
    int choice = 10;
    listNodePtr head = NULL;
    start(&head);
    list_data data;
    while ( choice != 0){
        printf("1 - add\n");
        printf("2 - delete\n");
        printf("3 - update\n");
        printf("4 - print\n");
        printf("0 - exit\n \n");

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                list_print_all(head);
                update(&data, 1);
                list_insert(&head, data);
                break;
            case 2:
                list_print_all(head);
                update(&data, 0);
                list_delete_item(&head, data);
                break;
            case 3:
                list_print_all(head);
                update(&data, 1);
                list_insert(&head, data);
                break;
            case 4:
                list_print_average(head);
                break;
            case 0:
                break;
            default: choice = 10;
        }
    }
}
