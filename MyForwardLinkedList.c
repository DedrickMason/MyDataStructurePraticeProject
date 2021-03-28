//
// Created by Dedrick Mason on 2021/3/28.
//

#include "ElementType.h"
#include "ElementType.c"
#include "MyForwardLinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _FORWARD_NODE
{
	ElementType Data;
	FNode* Next;
};

struct _MY_FORWARD_LINKED_LIST
{
	char* Name;
	int Size;
	FNode* Head;
};

FNode* CreateFNode(ElementType X)
{
	FNode* ThisNode = (FNode*) malloc(sizeof(FNode));
	ThisNode->Data = X;
	ThisNode->Next = NULL;
	return ThisNode;
}

void PrintFNode(FNode* ThisFNode)
{
	printf("[%d]\n",ThisFNode->Data);
}

MyForwardLinkedList* CreateForwardLinkedList(char* InputName)
{
	MyForwardLinkedList* L = (MyForwardLinkedList*) malloc(sizeof(MyForwardLinkedList));
	L->Size = 0;
	L->Head = NULL;
	L->Name = (char*) malloc((1+strlen(InputName))*sizeof(char));
	strcpy(L->Name,InputName);
	return L;
}

MyForwardLinkedList* CreateForwardLinkedListWithArray(char* InputName,ElementType* Array,int ArraySize)
{
	MyForwardLinkedList* L = (MyForwardLinkedList*) malloc(sizeof(MyForwardLinkedList));
	L->Size = 0;

	if(ArraySize<=0)
	{
		L->Head = NULL;
	}
	else
	{
		L->Size = ArraySize;
		L->Head = CreateFNode(Array[0]);
		FNode* Cursor = L->Head;
		for( int i = 1 ; i < ArraySize ; i++ )
		{
			Cursor->Next = CreateFNode(Array[i]);
			Cursor = Cursor->Next;
		}
	}

	L->Name = (char*) malloc((1+strlen(InputName))*sizeof(char));
	strcpy(L->Name,InputName);
	return L;
}

void ClearForwardLinkedList(MyForwardLinkedList* L)
{
	if(ForwardLinkedListIsEmpty(L))
	{
		return; // do nothing
	}
	else
	{
		FNode* Cursor = L->Head;
		while(Cursor!=NULL)
		{
			FNode* PtrForDelete = Cursor;
			Cursor = Cursor->Next;
			free(PtrForDelete);
		}
		L->Size = 0;
		L->Head = NULL;
	}
}

void DeleteForwardLinkedList(MyForwardLinkedList* L)
{
	ClearForwardLinkedList(L);
	free(L->Name);
	free(L);
}

int ForwardLinkedListIsEmpty(MyForwardLinkedList* L)
{
	return (L->Head==NULL);
}

int IsLastInForwardLinkedList(ElementType X,MyForwardLinkedList* L)
{
	if(ForwardLinkedListIsEmpty(L))
	{
		printf("ForwardLinkedList is empty!\n");
		return -1;
	}

	FNode* Cursor = L->Head;
	while(Cursor!=NULL)
	{
		if( Cursor->Data==X && Cursor->Next==NULL )
		{
			return 1;
		}
		Cursor = Cursor->Next;
	}
	return 0;
}

int IsFirstInForwardLinkedList(ElementType X,MyForwardLinkedList* L)
{
	if (ForwardLinkedListIsEmpty(L))
	{
		printf("ForwardLinkedList is empty!\n");
		return -1;
	}

	if (L->Head->Data == X)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

FNode* LocateXInForwardLinkedList(ElementType X,MyForwardLinkedList* L)
{
	if(ForwardLinkedListIsEmpty(L))
	{
		printf("ForwardLinkedList is empty!\n");
		return NULL;
	}

	FNode* Cursor = L->Head;
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

int FindXInForwardLinkedList(ElementType X,MyForwardLinkedList* L)
{
	if(ForwardLinkedListIsEmpty(L))
	{
		printf("ForwardLinkedList is empty!\n");
		return -1;
	}

	int Pos = 0;
	FNode* Cursor = L->Head;
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

// all insert options means insert X to be Kth

void InsertNewAtKForwardLinkedList(ElementType X,MyForwardLinkedList* L,int K)
{
	if(K<0||K>L->Size)
	{
		printf("Out of range!\n");
		return;
	}

	if(K==0)
	{
		InsertNewAtFrontForwardLinkedList(X,L);
	}
	else
	{
		FNode* ToBeInsert = CreateFNode(X);
		FNode* Cursor = L->Head;
		for( int i = 1 ; i < K ; i++ )
		{
			Cursor = Cursor->Next;
		}

		ToBeInsert->Next = Cursor->Next;
		Cursor->Next = ToBeInsert;
		L->Size += 1;
	}
}

void InsertNewAtFrontForwardLinkedList(ElementType X,MyForwardLinkedList* L)
{
	FNode* ToBeInsert = CreateFNode(X);
	ToBeInsert->Next = L->Head;
	L->Head = ToBeInsert;
	L->Size += 1;
}

void InsertNewAtRearForwardLinkedList(ElementType X,MyForwardLinkedList* L)
{
	if(ForwardLinkedListIsEmpty(L))
	{
		InsertNewAtFrontForwardLinkedList(X,L);
	}
	else
	{
		FNode* ToBeInsert = CreateFNode(X);
		FNode* Cursor = L->Head;
		while(Cursor->Next!=NULL)
		{
			Cursor = Cursor->Next;
		}
		Cursor->Next = ToBeInsert;
		L->Size += 1;
	}
}

void DeleteKthForwardLinkedList(MyForwardLinkedList* L,int K)
{
	if(K<0||K>=L->Size)
	{
		printf("Out of range!\n");
		return;
	}

	if(ForwardLinkedListIsEmpty(L))
	{
		printf("ForwardLinkedList is empty!\n");
		return;
	}

	if(K==0)
	{
		FNode* ToBeDelete = L->Head;
		L->Head = L->Head->Next;
		L->Size -= 1;
		free(ToBeDelete);
	}
	else
	{
		FNode* Cursor = L->Head;
		for( int i = 1 ; i < K ; i++ )
		{
			Cursor = Cursor->Next;
		}

		FNode* ToBeDelete = Cursor->Next;
		Cursor->Next = Cursor->Next->Next;
		L->Size -= 1;
		free(ToBeDelete);
	}
}

void DeleteFirstForwardLinkedList(MyForwardLinkedList* L)
{
	if(ForwardLinkedListIsEmpty(L))
	{
		printf("ForwardLinkedList is empty!\n");
		return;
	}

	FNode* ToBeDelete = L->Head;
	L->Head = L->Head->Next;
	L->Size -= 1;
	free(ToBeDelete);
}

void DeleteLastForwardLinkedList(MyForwardLinkedList* L)
{
	if(ForwardLinkedListIsEmpty(L))
	{
		printf("ForwardLinkedList is empty!\n");
		return;
	}

	if(L->Size==1)
	{
		FNode* ToBeDelete = L->Head;
		L->Head = L->Head->Next;
		L->Size -= 1;
		free(ToBeDelete);
		return;
	}

	FNode* Cursor = L->Head;
	while(Cursor->Next->Next!=NULL)
	{
		Cursor = Cursor->Next;
	}

	FNode* ToBeDelete = Cursor->Next;
	Cursor->Next = Cursor->Next->Next;
	L->Size -= 1;
	free(ToBeDelete);
}

FNode* GetAndDeleteKthForwardLinkedList(MyForwardLinkedList* L,int K)
{
	if(K<0||K>=L->Size)
	{
		printf("Out of range!\n");
		return NULL;
	}

	if(ForwardLinkedListIsEmpty(L))
	{
		printf("ForwardLinkedList is empty!\n");
		return NULL;
	}

	if(K==0)
	{
		FNode* ToBeReturn = L->Head;
		L->Head = L->Head->Next;
		L->Size -= 1;
		return ToBeReturn;
	}
	else
	{
		FNode* Cursor = L->Head;
		for( int i = 1 ; i < K ; i++ )
		{
			Cursor = Cursor->Next;
		}

		FNode* ToBeReturn = Cursor->Next;
		Cursor->Next = Cursor->Next->Next;
		L->Size -= 1;
		return ToBeReturn;
	}
}

FNode* GetKthInForwardLinkedList(MyForwardLinkedList* L,int K)
{
	if(K<0||K>=L->Size)
	{
		printf("Out of range!\n");
		return NULL;
	}

	if(ForwardLinkedListIsEmpty(L))
	{
		printf("ForwardLinkedList is empty!\n");
		return NULL;
	}

	FNode* Cursor = L->Head;
	for( int i = 0 ; i < K ; i++ )
	{
		Cursor = Cursor->Next;
	}

	return Cursor;
}

int GetSizeOfForwardLinkedList(MyForwardLinkedList* L)
{
	return L->Size;
}

void PrintForwardLinkedList(MyForwardLinkedList* L)
{
	printf("Forward Linked List Name : %s\n",L->Name);
	if(ForwardLinkedListIsEmpty(L))
	{
		printf("Empty!\n");
	}
	else
	{
		printf("Content : ");
		printf("[%d]",L->Head->Data);
		FNode* Cursor = L->Head->Next;
		for( int i = 1 ; i < L->Size ; i++ )
		{
			printf(" -> [%d]",Cursor->Data);
			Cursor = Cursor->Next;
		}
		printf("\n\n");
	}
}

