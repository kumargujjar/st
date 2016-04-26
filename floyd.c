#include<stdio.h> 
void floyd(int a[10][10],int n);
int min(int a,int b);
void main()
{
	int n,a[10][10],i,j;
	printf("Enter the Number of Nodes:\n");
	scanf("%d",&n);
	printf("Enter the cost Adjacency Matrix\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
	floyd(a,n);
 }
void floyd(int a[10][10],int n)
{
	int d[10][10],i,j,k;
	for(i=1;i<=n;i++)
    {
	for(j=1;j<=n;j++)
	d[i][j]=a[i][j];
    }
	for(k=1;k<=n;k++)
    {
	for(i=1;i<=n;i++)
    {
	for(j=1;j<=n;j++)
    {
	d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	}
     }
}
	printf("\n Distance Matrix\n");
	for(i=1;i<=n;i++)
     {
	for(j=1;j<=n;j++)
	printf("\t%d\n",d[i][j]);
     }
	printf("\n");
     }}

	int min(int a,int b)	
     {
	if(a<b)
	return a;
	else
	return b;
     }
	
