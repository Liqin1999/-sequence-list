#include<stdio.h>  
  
struct node{  
    int k;  
    int m;  
}s[100002];  
int main()  
{  
   int i,j;  
   int n;  
   scanf("%d",&n);  
   for(i=0;i<n;i++)  
   {  
    scanf("%d",&s[i].m);  
    s[i].k=1;  
   }  
   for(i=0;i<n-1;i++)  
   {  
     for(j=i+1;j<n;j++)  
     {  
        if(s[j].m>s[j-1].m)  
        {  
            s[i].k++;   
        }  
        else  
        break;  
    }  
   }  
   int sum=-1,t;  
   for(i=0;i<n;i++)  
   {  
       if(s[i].k>sum)  
       {  
          sum=s[i].k;  
          t=i;  
       }  
   }  
   for(i=t;i<t+sum-1;i++)  
   {  
     printf("%d",s[i].m);  
   }  
   printf("%d",s[t+sum-1].m);  
   return 0;  
}  
