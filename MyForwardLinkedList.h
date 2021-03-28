//
// Created by Dedrick Mason on 2021/3/27.
//

#ifndef CHAPTER3_LIST_STACK_QUEUE_MYFORWARDLINKEDLIST_H
#define CHAPTER3_LIST_STACK_QUEUE_MYFORWARDLINKEDLIST_H

#include "ElementType.h"

struct _FORWARD_NODE;
struct _MY_FORWARD_LINKED_LIST;

typedef struct _FORWARD_NODE FNode;
typedef struct _MY_FORWARD_LINKED_LIST MyForwardLinkedList;


FNode* CreateFNode(ElementType);
void PrintFNode(FNode*);

MyForwardLinkedList* CreateForwardLinkedList(char*);
MyForwardLinkedList* CreateForwardLinkedListWithArray(char*,ElementType*,int);
void ClearForwardLinkedList(MyForwardLinkedList*);
void DeleteForwardLinkedList(MyForwardLinkedList*);

int ForwardLinkedListIsEmpty(MyForwardLinkedList*);
int IsLastInForwardLinkedList(ElementType,MyForwardLinkedList*);
int IsFirstInForwardLinkedList(ElementType,MyForwardLinkedList*);

FNode* LocateXInForwardLinkedList(ElementType,MyForwardLinkedList*);
int FindXInForwardLinkedList(ElementType,MyForwardLinkedList*);

void InsertNewAtKForwardLinkedList(ElementType,MyForwardLinkedList*,int);
void InsertNewAtFrontForwardLinkedList(ElementType,MyForwardLinkedList*);
void InsertNewAtRearForwardLinkedList(ElementType,MyForwardLinkedList*);

void DeleteKthForwardLinkedList(MyForwardLinkedList*,int);
void DeleteFirstForwardLinkedList(MyForwardLinkedList*);
void DeleteLastForwardLinkedList(MyForwardLinkedList*);
FNode* GetAndDeleteKthForwardLinkedList(MyForwardLinkedList*,int);

FNode* GetKthInForwardLinkedList(MyForwardLinkedList*,int);
int GetSizeOfForwardLinkedList(MyForwardLinkedList*);

void PrintForwardLinkedList(MyForwardLinkedList*);

#endif //CHAPTER3_LIST_STACK_QUEUE_MYFORWARDLINKEDLIST_H
