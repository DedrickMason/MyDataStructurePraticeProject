//
// Created by Dedrick Mason on 2021/3/27.
//

#ifndef CHAPTER3_LIST_STACK_QUEUE_MYDOUBLYLINKEDLIST_H
#define CHAPTER3_LIST_STACK_QUEUE_MYDOUBLYLINKEDLIST_H

#include "ElementType.h"

struct _DOUBLY_NODE;
struct _MY_DOUBLY_LINKED_LIST;

typedef struct _DOUBLY_NODE DNode;
typedef struct _MY_DOUBLY_LINKED_LIST MyDoublyLinkedList;

DNode* CreateDNode(ElementType);
void PrintDNode(DNode*);

MyDoublyLinkedList* CreateDoublyLinkedList(char*);
MyDoublyLinkedList* CreateDoublyLinkedListWithArray(char*,ElementType*,int);
void ClearDoublyLinkedList(MyDoublyLinkedList*);
void DeleteDoublyLinkedList(MyDoublyLinkedList*);

int DoublyLinkedListIsEmpty(MyDoublyLinkedList*);
int IsLastInDoublyLinkedList(ElementType,MyDoublyLinkedList*);
int IsFirstInDoublyLinkedList(ElementType,MyDoublyLinkedList*);

DNode* LocateXInDoublyLinkedList(ElementType,MyDoublyLinkedList*);
int FindXInDoublyLinkedList(ElementType,MyDoublyLinkedList*);

void InsertNewAtKDoublyLinkedList(ElementType,MyDoublyLinkedList*,int);
void InsertNewAtFrontDoublyLinkedList(ElementType,MyDoublyLinkedList*);
void InsertNewAtRearDoublyLinkedList(ElementType,MyDoublyLinkedList*);

void DeleteKthDoublyLinkedList(MyDoublyLinkedList*,int);
void DeleteFirstDoublyLinkedList(MyDoublyLinkedList*);
void DeleteLastDoublyLinkedList(MyDoublyLinkedList*);
DNode* GetAndDeleteKthDoublyLinkedList(MyDoublyLinkedList*,int);

DNode* GetKthInDoublyLinkedList(MyDoublyLinkedList*,int);
int GetSizeOfDoublyLinkedList(MyDoublyLinkedList*);

void PrintDoublyLinkedList(MyDoublyLinkedList*);

#endif //CHAPTER3_LIST_STACK_QUEUE_MYDOUBLYLINKEDLIST_H
