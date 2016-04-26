#include<stdio.h>
void prim();
int c[10][10],cnt,t[10][10],d[10],p[10],s[10];
int n,sor;
main()
{
   int i,j;
   
   printf("enter no of nodes ");
   scanf("%d",&n);

	printf("\n enter matrix\n");
	for(i=1;i<=n;i++)
	{
	  for(j=1;j<=n;j++)
	  {
		scanf("%d",&c[i][j]);
	  }
	}
	prim();

}

void prim()
{
	int min=999,i,j,k,sum,u,v=0;
	sor=1;
	for(i=1;i<=n;i++)
	{
	  for(j=1;j<=n;j++)
	  {
		if(c[i][j]<min && c[i][j]!=0)
		{
			min=c[i][j];
			sor=i;
		}
	  }
        }
	  
	  for(i=1;i<=n;i++)
	  {
		s[i]=0;
		d[i]=c[sor][i];
		p[i]=sor;
	  }
	  
	s[sor]=1;
	sum=0;
	cnt=1;
	k=1;
	
     	while(cnt<=n-1)
     	{
	  	min=999;
	  	u=-1;
	  	for(i=1;i<=n;i++)
	  	{
			if(s[i]==0 && d[i]<min)
			{
				min=d[i];
				u=i;
			}
		}
	  	v=p[u];
		t[k][1]=u;
		t[k][2]=v;
		sum+=c[u][v];
		s[u]=1;
		for(i=1;i<=n;i++)
		{
			if(s[i]==0 && d[i]>c[u][i])
			{
				d[i]=c[u][i];
				p[i]=u;
			}
		}
		k++;
		cnt++;
     	}
	printf("\n output \n");
	for(i=1;i<n;i++)
	{
	  	for(j=1;j<=2;j++)
	  	{
			printf("%d\t",t[i][j]);
	  	}
		printf("\n");
	}
	printf("Total distance=%d",sum);
}	
