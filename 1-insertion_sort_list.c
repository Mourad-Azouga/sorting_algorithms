#include "sort.h"
/**
 * insertion_sort_list - sorts the list
 * @list: the double pointer to the doubly linked list made in sort.h
*/
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        temp = current->prev;
        while (temp != NULL && temp->n > current->n)
        {
            if (temp->next != NULL)
                temp->next->prev = current;
            current->prev = temp->prev;
            temp->next = current->next;
            current->next = temp;
            if (temp->prev != NULL)
                temp->prev->next = current;
            else
                *list = current;

            temp->prev = current;

            temp = current->prev;
            print_list(*list);
        }
        current = current->next;
    }
}