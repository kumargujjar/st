#include<stdio.h>
#include<stdlib.h>
void main()
{
  
         int n,CALL,j,i;
         int a[10][10];
    
         printf("\n enter no. of nodes\t");
         scanf("%d",&n);

         printf("\n Enter Matrix\n");
         for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
               scanf("%d",&a[i][j]);
	printf("\n\n\n\n\n");
        CALL=topology(a,n);
}
int topology(int a[10][10],int n)
{     
      int i,top=-1,k=0,j;
      int ind[20],s[20],out[10];
       
	
      for(i=1;i<=n;i++)
      {
         ind[i]=0;
         
         for(j=1;j<=n;j++)
         {
            if(a[j][i]==1)
    	         ind[i]++;
	
         }
      
     }
     while(1)
     {
           for(i=1;i<=n;i++)
           {
             
              if(ind[i]==0)
              {
                 s[++top]=i;
                  ind[i]=-1;
              }
	}
            
           if(top==-1)
             break;
            out[k]=s[top--];
    
            for(j=1;j<=n;j++)
            {
                if(a[out[k]][j]==1)
                    ind[j]--;
                
             }
	k++;
       }


       if(k==n)
        { 
          for(k=0;k<n;k++)
         {
          printf("%d\n",out[k]);
          }
	} 
       
       else
          printf("\n ERROR");
 } 
