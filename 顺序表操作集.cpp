#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
//typedef enum {false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &P);
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
    }
    return 0;
}


List MakeEmpty()
{ //����������һ���յ����Ա� 
    List S;
    S = (List)malloc(sizeof(struct LNode));
    S->Last = -1;
    return S;
}
Position Find(List L, ElementType X)
{ //�������Ա���X��λ�á����Ҳ����򷵻�ERROR
    int i;
    for (i = 0; i<=L->Last; i++)
    {
        if (L->Data[i] == X) return i;
    }
    return -1;
}
bool Insert(List L, ElementType X, Position P)
{ //��X������λ��P������true
    int i;
    if (L->Last == (MAXSIZE - 1))
    {
        printf("FULL");
        return 0;
    }
    else if (P<0 || P>L->Last+1)
    {
        printf("ILLEGAL POSITION");
        return 0;
    }
    else
    {
        for (i = L->Last; i >= P; i--)
        {
            L->Data[i + 1] = L->Data[i];
        }
        L->Data[P] = X;
        L->Last = L->Last + 1;
        return 1;
    }
}
bool Delete(List L, Position P)
{ //��λ��P��Ԫ��ɾ��������true 
    int i;
    if (P<0 || P>L->Last)
    {
        printf("POSITION %d EMPTY", P);
        return 0;
    }
    for (i = P; i<L->Last; i++)
    {
        L->Data[i] = L->Data[i + 1];
    }
    L->Last = L->Last - 1;
    return 1;
}
