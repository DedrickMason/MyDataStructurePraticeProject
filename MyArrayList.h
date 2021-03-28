//
// Created by Dedrick Mason on 2021/3/27.
//

#ifndef CHAPTER3_LIST_STACK_QUEUE_MYARRAYLIST_H
#define CHAPTER3_LIST_STACK_QUEUE_MYARRAYLIST_H

#include "ElementType.h"

struct _MY_ARRAY_LIST;

typedef struct _MY_ARRAY_LIST MyArrayList;

static int FixedArrayCapacity = 1024;

MyArrayList* CreateEmptyArrayList(char*);
MyArrayList* CreateArrayListWithArray(char*,ElementType*,int);
void ClearArrayList(MyArrayList*);
void DeleteArrayList(MyArrayList*);

int ArrayListIsEmpty(MyArrayList*);
int IsLastInArrayList(ElementType,MyArrayList*);
int IsFirstInArrayList(ElementType,MyArrayList*);

ElementType* LocateXInArrayList(ElementType,MyArrayList*);
int FindXInArrayList(ElementType,MyArrayList*);

void InsertNewAtKArrayList(ElementType,MyArrayList*,int);
void InsertNewAtFrontArrayList(ElementType,MyArrayList*);
void InsertNewAtRearArrayList(ElementType,MyArrayList*);

void DeleteKthArrayList(MyArrayList*,int);
void DeleteFirstArrayList(MyArrayList*);
void DeleteLastArrayList(MyArrayList*);
ElementType* GetAndDeleteKthArrayList(MyArrayList*,int);

ElementType* GetKthInArrayList(MyArrayList*,int);
int GetSizeOfArrayList(MyArrayList*);

void PrintArrayList(MyArrayList*);

#endif //CHAPTER3_LIST_STACK_QUEUE_MYARRAYLIST_H
