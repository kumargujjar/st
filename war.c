#include<stdio.h>
int r[10][10],n;
void warsh()
{
	int i,j,k;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(r[i][j] || (r[i][k] && r[k][j]))
					r[i][j]=1;
			}
		}
	}
}
main()
{
	int i,j;
	printf("Enter the No of Nodes:\n");

	scanf("%d",&n);
	printf("Enter the matrix:\n");

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&r[i][j]);
		}
	}
	warsh();
	printf("Transitive closure\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%d\t",r[i][j]);
		}
		printf("\n");
	}
}	

