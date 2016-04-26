#include<stdio.h>
void dijk(int,int);
int c[30][30],d[30],s[30],p[30];
void dijk(int sor,int n)
{
int i,j,min,a,b;
for(i=1;i<=n;i++)
 {
  s[i]=0;
  d[i]=c[sor][i];
  p[i]=sor;
  s[sor]=1;
 }
for(i=2;i<=n;i++)
  {
    min=999;
    a=-1;
    for(j=1;j<=n;j++)
  {
     if(s[j]==0)
   { 
     if(d[j]<min)
    {
     min=d[j];
     a=j;
    }
   }
  }
    if(a==-1)
    return;
    s[a]=1;
    for(b=1;b<=n;b++)
   {    
    if(s[b]==0)
     {   
      if(d[a]+c[a][b]<d[b])
      {
       d[b]=d[a]+c[a][b];
       p[b]=a;
      }
     }
   }
  }
for(j=1;j<=n;j++)
    {
       i=j;
      while(i!=sor)
     {
         printf("%d->",i);
         i=p[i];
}
         printf("%d\t%d\n",sor,d[j]);

}
}
void main()
{
int i,n, j ,sor;
printf("enter the no of nodes");
scanf("%d",&n);
printf("enter the matrix");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&c[i][j]);
}
}
printf("enter the source");
scanf("%d",&sor);
dijk(sor,n);
}

