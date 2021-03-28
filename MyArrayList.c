//
// Created by Dedrick Mason on 2021/3/27.
//

#include "ElementType.h"
#include "ElementType.c" // to get the Size
#include "MyArrayList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct _MY_ARRAY_LIST
{
	int Size;
	char* Name;
	ElementType* LinearArray;
};

MyArrayList* CreateEmptyArrayList(char* InputName)
{
	MyArrayList* L = (MyArrayList*) malloc(sizeof(MyArrayList));
	L->Size = 0;
	L->LinearArray = (ElementType*) malloc(FixedArrayCapacity*sizeof(ElementType));
	L->Name = (char*) malloc((1+strlen(InputName))*sizeof(char));
	strcpy(L->Name,InputName);
	return L;
}

MyArrayList* CreateArrayListWithArray(char* InputName,ElementType* InputArray,int InputSize)
{
	MyArrayList* L = (MyArrayList*) malloc(sizeof(MyArrayList));
	L->Size = InputSize;
	L->LinearArray = (ElementType*) malloc(FixedArrayCapacity*sizeof(ElementType));
	for( int i = 0 ; i < InputSize ; i++ )
	{
		L->LinearArray[i] = InputArray[i];
	}
	L->Name = (char*) malloc((1+strlen(InputName))*sizeof(char));
	strcpy(L->Name,InputName);
	return L;
}

void ClearArrayList(MyArrayList* L)
{
	free(L->LinearArray);
	L->LinearArray = (ElementType*) malloc(FixedArrayCapacity*sizeof(ElementType));
	L->Size = 0;
}

void DeleteArrayList(MyArrayList* L)
{
	free(L->LinearArray);
	free(L->Name);
	free(L);
}

int ArrayListIsEmpty(MyArrayList* L)
{
	if(L->Size==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int IsLastInArrayList(ElementType X,MyArrayList* L)
{
	if( L->LinearArray[L->Size-1] == X )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int IsFirstInArrayList(ElementType X,MyArrayList* L)
{
	if( L->LinearArray[0] == X )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

ElementType* LocateXInArrayList(ElementType X,MyArrayList* L)
{
	if(ArrayListIsEmpty(L))
	{
		printf("Empty!\n");
		return NULL;
	}
	else
	{
		for( int i = 0 ; i < L->Size ; i++ )
		{
			if(L->LinearArray[i]==X)
			{
				return &(L->LinearArray[i]);
			}
		}
		printf("Not Found!\n");
		return NULL;
	}
}

int FindXInArrayList(ElementType X,MyArrayList* L)
{
	if(ArrayListIsEmpty(L))
	{
		printf("Empty!\n");
		return -1;
	}
	else
	{
		for( int i = 0 ; i < L->Size ; i++ )
		{
			if(L->LinearArray[i]==X)
			{
				return i;
			}
		}
		printf("Not Found!\n");
		return -1;
	}
}

void InsertNewAtKArrayList( ElementType X , MyArrayList* L , int K )
{
	if(K<0||K>L->Size)
	{
		printf("Out Of Range!\n");
		return;
	}
	if(K==L->Size)
	{
		L->LinearArray[L->Size++] = X;
		return;
	}

	// trivial situation
	for( int i = L->Size ; i > K ; i-- )
	{
		L->LinearArray[i] = L->LinearArray[i-1];
	}
	L->LinearArray[K] = X;
	L->Size += 1;
}

void InsertNewAtFrontArrayList(ElementType X,MyArrayList* L)
{
	for( int i = L->Size ; i > 0 ; i-- )
	{
		L->LinearArray[i] = L->LinearArray[i-1];
	}
	L->LinearArray[0] = X;
	L->Size += 1;
}

void InsertNewAtRearArrayList(ElementType X,MyArrayList* L)
{
	L->LinearArray[L->Size++] = X;
}

void DeleteKthArrayList(MyArrayList* L,int K)
{
	if(K<0||K>L->Size)
	{
		printf("Out Of Range!\n");
		return;
	}
	else
	{
		for( int i = K ; i < L->Size-1 ; i++ )
		{
			L->LinearArray[i] = L->LinearArray[i+1];
		}
		L->LinearArray[L->Size - 1] = 0;
		L->Size -= 1;
	}
}

void DeleteFirstArrayList(MyArrayList* L)
{
	if(!ArrayListIsEmpty(L))
	{
		for( int i = 0 ; i < L->Size - 1 ; i++ )
		{
			L->LinearArray[i] = L->LinearArray[i+1];
		}
		L->LinearArray[L->Size - 1] = 0;
		L->Size -= 1;
	}
}
void DeleteLastArrayList(MyArrayList* L)
{
	if(!ArrayListIsEmpty(L))
	{
		L->LinearArray[L->Size - 1] = 0;
		L->Size -= 1;
	}
}

ElementType* GetAndDeleteKthArrayList(MyArrayList* L,int K)
{
	if(K<0||K>L->Size)
	{
		printf("Out Of Range!\n");
		return NULL;
	}
	else
	{
		ElementType* PtrToReturn = (ElementType*) malloc(sizeof(ElementType));
		*PtrToReturn = L->LinearArray[K];
		for( int i = K ; i < L->Size-1 ; i++ )
		{
			L->LinearArray[i] = L->LinearArray[i+1];
		}
		L->LinearArray[L->Size - 1] = 0;
		L->Size -= 1;
		return PtrToReturn;
	}
}


ElementType* GetKthInArrayList(MyArrayList* L,int K)
{
	if(K<0||K>=L->Size)
	{
		printf("Out Of Range!\n");
		return NULL;
	}
	else
	{
		return &(L->LinearArray[K]);
	}
}

int GetSizeOfArrayList(MyArrayList* L)
{
	return L->Size;
}

void PrintArrayList(MyArrayList* L)
{
	printf("ArrayList Name : %s\n",L->Name);
	if(ArrayListIsEmpty(L))
	{
		printf("Empty!\n\n");
		return;
	}
	else
	{
		printf("Content : { ");
		printf("%d",L->LinearArray[0]);
		for( int i = 1 ; i < L->Size ; i++ )
		{
			printf(", %d",L->LinearArray[i]);
		}
		printf(" }\n\n");
	}
}