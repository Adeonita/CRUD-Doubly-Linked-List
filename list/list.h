#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "./helpers/helper.h"
#include "struct.h"

#define DATABASE "./database.txt"

List* create()
{
    List* list = (List*) malloc(sizeof(List));
    list->first = NULL;
    list->last = NULL;
    list->totalElements = 0;

    return list;
}

int getId(List* list)
{
    return list->totalElements;
}

void insertFirst(List* list, Client client)
{
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    
    client.id = getId(list);

    node->client = client;

    node->next = list->first; //Seta o fim da lista, atribuindo null a última posição do ponteiro na primeira atribuição
    node->previous = NULL;

    if (list->first == NULL) {
        list->last = node;
    }
    
    list->first = node;

    list->totalElements ++;
    
    return;
}

void insertLast(List* list, Client client)
{
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));

    client.id = getId(list);
    node->client = client;

    node->previous = list->last;
    node->next = NULL;

    if (list->last != NULL) {
        list->last->next = node;
    } else {
        list->first = node;
    }

    list->last = node;

    list->totalElements ++;

    return;
}


void removeFirst(List* list)
{
    ListNode* actualElement = list->first;

    if (actualElement != NULL)
    {
        list->first = actualElement->next;
    }

    free(actualElement);

    return;
}


void removeLast(List* list)
{
    ListNode* last = list->last;
    ListNode* ant = last->previous;

    if (list->first == list->last) {
        list->first = NULL;
        list->last = NULL;
    }else {
        ant->next = NULL;
        list->last = ant;
    }

    free(last);

    return;    
}


void getAll(List* list)
{
    for (ListNode* ln = list->first; ln != NULL; ln = ln->next)
    {
        printf("Id: %d ", ln->client.id);
        printf("Nome: %s ", ln->client.name);
        printf("Idade: %d ", ln->client.age);
        printf("\n");
    }

    return;
}

ListNode* get(List* list, int id)
{   
    ListNode* node = NULL;

    for (ListNode* ln = list->first; ln != NULL; ln = ln->next)
    {
        if (ln->client.id == id) {
            printf("\n\n");
            printf("Id: %d ", ln->client.id);
            printf("Nome: %s ", ln->client.name);
            printf("Idade: %d", ln->client.age);
            printf("\n\n");

            node = ln;
        }  
    }

    return node;
}

void toRemove(List* list, int id)
{
    ListNode* node = get(list, id);

    if (node == NULL) {
        return;
    }

    if (node == list->first) {
        return removeFirst(list);
    }

    if (node->client.id == list->last->client.id) {
        return removeLast(list);
    }

    node->previous->next = node->next;
    node->previous->previous = node->previous;

    free(node);
}

ListNode* getAndUpdate(List* list, int id, Client client)
{
    printf("Old: ");
    ListNode* node = get(list, id);

    node->client.id = id;
    strcpy(node->client.name, client.name);
    node->client.age = client.age;

    printf("\nUpdated: ");
    get(list, id);

    return node;
}

ListNode* update(List* list, int id, Client client)
{
    ListNode* node;

    for (ListNode* ln = list->first; ln != NULL; ln = ln->next)
    {
        if (ln->client.id == id) {
            ln->client.id = id;
            strcpy(ln->client.name, client.name);
            ln->client.age = client.age;

            node = ln;
        }  
    }

    return node;
}
