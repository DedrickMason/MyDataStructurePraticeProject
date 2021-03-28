//
// Created by Dedrick Mason on 2021/3/28.
//

#include "ElementType.h"
#include "ElementType.c"
#include "MyDoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _DOUBLY_NODE
{
	ElementType Data;
	DNode* Prior;
	DNode* Next;
};

struct _MY_DOUBLY_LINKED_LIST
{
	char* Name;
	int Size;
	DNode* Head;
	DNode* Tail;
};

DNode* CreateDNode(ElementType X)
{
	DNode* ThisNode = (DNode*) malloc(sizeof(DNode));
	ThisNode->Data = X;
	ThisNode->Prior = NULL;
	ThisNode->Next = NULL;
	return ThisNode;
}

void PrintDNode(DNode* ThisNode)
{
	printf("[%d]\n",ThisNode->Data);
}

MyDoublyLinkedList* CreateDoublyLinkedList(char* InputName)
{
	MyDoublyLinkedList* L = (MyDoublyLinkedList*) malloc(sizeof(MyDoublyLinkedList));
	L->Size = 0;
	L->Head = NULL;
	L->Tail = NULL;
	L->Name = (char*) malloc((1+strlen(InputName))*sizeof(char));
	strcpy(L->Name,InputName);
	return L;
}

MyDoublyLinkedList* CreateDoublyLinkedListWithArray(char* InputName,ElementType* Array,int ArraySize)
{
	MyDoublyLinkedList* L = (MyDoublyLinkedList*) malloc(sizeof(MyDoublyLinkedList));
	L->Size = 0;

	if(ArraySize<=0)
	{
		L->Head = NULL;
	}
	else
	{
		L->Size = ArraySize;
		L->Head = CreateDNode(Array[0]);
		DNode* Cursor = L->Head;
		DNode* SlowCursor = NULL;
		for( int i = 1 ; i < ArraySize ; i++ )
		{
			Cursor->Prior = SlowCursor;
			Cursor->Next = CreateDNode(Array[i]);

			SlowCursor = Cursor;
			Cursor = Cursor->Next;
		}
		L->Tail = Cursor;
	}

	L->Name = (char*) malloc((1+strlen(InputName))*sizeof(char));
	strcpy(L->Name,InputName);
	return L;
}

void ClearDoublyLinkedList(MyDoublyLinkedList* L)
{
	if(DoublyLinkedListIsEmpty(L))
	{
		return; // do nothing
	}
	else
	{
		DNode* Cursor = L->Head;
		while(Cursor!=NULL)
		{
			DNode* PtrForDelete = Cursor;
			Cursor = Cursor->Next;
			free(PtrForDelete);
		}
		L->Size = 0;
		L->Head = NULL;
		L->Tail = NULL;
	}
}

void DeleteDoublyLinkedList(MyDoublyLinkedList* L)
{
	ClearDoublyLinkedList(L);
	free(L->Name);
	free(L);
}

int DoublyLinkedListIsEmpty(MyDoublyLinkedList* L)
{
	return (L->Head==NULL);
}

int IsLastInDoublyLinkedList(ElementType X,MyDoublyLinkedList* L)
{
	return (L->Tail->Data==X);
}

int IsFirstInDoublyLinkedList(ElementType X,MyDoublyLinkedList* L)
{
	return (L->Head->Data==X);
}

DNode* LocateXInDoublyLinkedList(ElementType X,MyDoublyLinkedList* L)
{
	if(DoublyLinkedListIsEmpty(L))
	{
		printf("ForwardLinkedList is empty!\n");
		return NULL;
	}

	DNode* Cursor = L->Head;
	while(Cursor!=NULL)
	{
		if(Cursor->Data==X)
		{
			return Cursor;
		}
		Cursor = Cursor->Next;
	}
	printf("X not found!\n");
	return NULL;
}

int FindXInDoublyLinkedList(ElementType X,MyDoublyLinkedList* L)
{
	if(DoublyLinkedListIsEmpty(L))
	{
		printf("ForwardLinkedList is empty!\n");
		return -1;
	}

	int Pos = 0;
	DNode* Cursor = L->Head;
	while(Cursor!=NULL)
	{
		if(Cursor->Data==X)
		{
			return Pos;
		}
		Cursor = Cursor->Next;
		Pos += 1;
	}
	printf("X not found!\n");
	return -1;
}

void InsertNewAtKDoublyLinkedList(ElementType X,MyDoublyLinkedList* L,int K)
{
	if(K<0||K>L->Size)
	{
		printf("Out of range!\n");
		return;
	}

	if(K==0)
	{
		InsertNewAtFrontDoublyLinkedList(X,L);
		return;
	}
	if(K==L->Size)
	{
		InsertNewAtRearDoublyLinkedList(X,L);
	}
	else
	{
		DNode* ToBeInsert = CreateDNode(X);
		DNode* Cursor = L->Head;
		for( int i = 1 ; i < K ; i++ )
		{
			Cursor = Cursor->Next;
		}

		ToBeInsert->Next = Cursor->Next;
		Cursor->Next->Prior = ToBeInsert;

		Cursor->Next = ToBeInsert;
		ToBeInsert->Prior = Cursor;

		L->Size += 1;
	}
}

void InsertNewAtFrontDoublyLinkedList(ElementType X,MyDoublyLinkedList* L)
{
	if(DoublyLinkedListIsEmpty(L))
	{
		L->Head = CreateDNode(X);
		L->Tail = L->Head;
	}
	else
	{
		DNode* ToBeInsert = CreateDNode(X);
		ToBeInsert->Next = L->Head;
		L->Head->Prior = ToBeInsert;
		L->Head = ToBeInsert;
		L->Size += 1;
	}
}

void InsertNewAtRearDoublyLinkedList(ElementType X,MyDoublyLinkedList* L)
{
	if(DoublyLinkedListIsEmpty(L))
	{
		L->Head = CreateDNode(X);
		L->Tail = L->Head;
	}
	else
	{
		DNode* ToBeInsert = CreateDNode(X);
		L->Tail->Next = ToBeInsert;
		ToBeInsert->Prior = L->Tail;
		L->Tail = L->Tail->Next;
		L->Size += 1;
	}
}

void DeleteKthDoublyLinkedList(MyDoublyLinkedList* L,int K)
{
	if(K<0||K>=L->Size)
	{
		printf("Out of range!\n");
		return;
	}

	if(DoublyLinkedListIsEmpty(L))
	{
		printf("ForwardLinkedList is empty!\n");
		return;
	}

	if(K==0)
	{
		DNode* ToBeDelete = L->Head;
		L->Head = L->Head->Next;
		L->Head->Prior = NULL;
		L->Size -= 1;
		free(ToBeDelete);
	}
	else
	{
		DNode* Cursor = L->Head;
		for( int i = 1 ; i < K ; i++ )
		{
			Cursor = Cursor->Next;
		}

		DNode* ToBeDelete = Cursor->Next;
		Cursor->Next = Cursor->Next->Next;
		Cursor->Next->Prior = Cursor;
		L->Size -= 1;
		free(ToBeDelete);
	}
}

void DeleteFirstDoublyLinkedList(MyDoublyLinkedList* L)
{
	if(DoublyLinkedListIsEmpty(L))
	{
		printf("Doubly Linked List is Empty!\n");
		return;
	}

	if(L->Size==1)
	{
		free(L->Head);
		L->Head = NULL;
		L->Tail = NULL;
		L->Size = 0;
		return;
	}

	DNode* ToBeDelete = L->Head;
	L->Head = L->Head->Next;
	L->Head->Prior = NULL;
	L->Size -= 1;
	free(ToBeDelete);
}

void DeleteLastDoublyLinkedList(MyDoublyLinkedList* L)
{
	if(DoublyLinkedListIsEmpty(L))
	{
		printf("Doubly Linked List is Empty!\n");
		return;
	}

	if(L->Size==1)
	{
		free(L->Tail);
		L->Head = NULL;
		L->Tail = NULL;
		L->Size = 0;
		return;
	}

	DNode* ToBeDelete = L->Tail;
	L->Tail = L->Tail->Prior;
	L->Tail->Next = NULL;
	L->Size -= 1;
	free(ToBeDelete);
}

DNode* GetAndDeleteKthDoublyLinkedList(MyDoublyLinkedList* L,int K)
{
	if(DoublyLinkedListIsEmpty(L))
	{
		printf("Doubly Linked List is Empty!\n");
		return NULL;
	}

	if(K<0||K>L->Size)
	{
		printf("Out of range!\n");
		return NULL;
	}

	if(K==0)
	{
		if(L->Size==1)
		{
			DNode* ToBeReturn = L->Head;
			L->Head = NULL;
			L->Tail = NULL;
			L->Size -= 1;
			return ToBeReturn;
		}
		else
		{
			DNode* ToBeReturn = L->Head;
			L->Head = L->Head->Next;
			L->Head->Prior = NULL;
			L->Size -= 1;
			return ToBeReturn;
		}
	}

	if(K==L->Size-1)
	{
		if(L->Size==1)
		{
			DNode* ToBeReturn = L->Tail;
			L->Head = NULL;
			L->Tail = NULL;
			L->Size -= 1;
			return ToBeReturn;
		}
		else
		{
			DNode* ToBeReturn = L->Tail;
			L->Tail = L->Tail->Prior;
			L->Tail->Next = NULL;
			L->Size -= 1;
			return ToBeReturn;
		}
	}

	DNode* Cursor = L->Head;
	for( int i = 0 ; i < K ; i++ )
	{
		Cursor = Cursor->Next;
	}

	Cursor->Next->Prior = Cursor->Prior;
	Cursor->Prior->Next = Cursor->Next;
	L->Size -= 1;

	//optional
	Cursor->Next = NULL;
	Cursor->Prior = NULL;

	return Cursor;
}

DNode* GetKthInDoublyLinkedList(MyDoublyLinkedList* L,int K)
{
	if(DoublyLinkedListIsEmpty(L))
	{
		printf("Doubly Linked List is Empty!\n");
		return NULL;
	}

	if(K<0||K>L->Size)
	{
		printf("Out of range!\n");
		return NULL;
	}

	DNode* Cursor = L->Head;
	for( int i = 0 ; i < K ; i++ )
	{
		Cursor = Cursor->Next;
	}
	return Cursor;
}

int GetSizeOfDoublyLinkedList(MyDoublyLinkedList* L)
{
	return L->Size;
}

void PrintDoublyLinkedList(MyDoublyLinkedList* L)
{
	printf("Doubly Linked List Name : %s\n",L->Name);
	if(DoublyLinkedListIsEmpty(L))
	{
		printf("Empty!\n");
	}
	else
	{
		printf("Content : ");
		printf("[%d]",L->Head->Data);
		DNode* Cursor = L->Head->Next;
		for( int i = 1 ; i < L->Size ; i++ )
		{
			printf(" <-> [%d]",Cursor->Data);
			Cursor = Cursor->Next;
		}
		printf("\n\n");
	}
}