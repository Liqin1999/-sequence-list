#include <stdio.h>
#define MAXSIZE 20
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�0��ʼ�洢 */
void PrintList( List L ); /* ����ʵ�֣�ϸ�ڲ��� */
List Delete( List L, ElementType minD, ElementType maxD );

int main()
{
    List L;
    ElementType minD, maxD;
    int i;

    L = ReadInput();
    scanf("%d %d", &minD, &maxD);
    L = Delete( L, minD, maxD );
    PrintList( L );

    return 0;
}

List Delete( List L, ElementType minD, ElementType maxD ){
	int i=0,count=0,a=0; //count���ڼ���
	while(i<=L->Last){ 
	if((L->Data[i]>minD)&&(L->Data[i]<maxD)) 
		count++;
	else{                           
		L->Data[a]=L->Data[i]; 
	    a++;
	 }
	 i++;
	} 
	L->Last-=count;//˳����ȼ���count
	return L;
}

