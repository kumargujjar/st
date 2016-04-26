/*#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
int merge(int a[],int low,int mid,int high)
{
  int i,k,j,b[high];
   i=k=low;
   j=mid+1;
   while(i<=mid && j<=high)
   {
      if(a[i]<=a[j])
       b[k++]=a[i++];
      else
       b[k++]=a[j++];
   }
   while(i<=mid)
    b[k++]=a[i++];
   while(j<=high)
    b[k++]=a[j++];
   for(i=low;i<=high;i++)
    {
          
     a[i]=b[i];
    }
}
int mergesort(int a[],int low,int high)
{
  if(low<high)
  {
    int  mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
  }
}
int main()
{
  int j,n,i,low,high,y;
  struct timeval tv;
  double start,end;
  FILE *fp;
  fp=fopen("plot.txt","w");
  for(j=100;j<=1000;j+=100)
 {
  n=j;
  int a[n];
  low=0;
  high=n-1;
  gettimeofday(&tv,NULL);
  start=tv.tv_sec+(tv.tv_usec/1000000.0);
  for(i=0;i<n;i++)
  {
    a[i]=rand()%1000;
    printf("%d\t",a[i]);
  }
  y=mergesort(a,low,high);
  printf("\n sorted array:");
  for(i=0;i<n;i++)
  {
   printf("%d\t",a[i]);
  }
  gettimeofday(&tv,NULL);
  end=tv.tv_sec+(tv.tv_usec/1000000.0);
  fprintf(fp,"%d\t%lf\n",j,end-start);
  
}
fclose(fp);
system("gnuplot");
}
*/      
 #include<stdio.h>
#include<sys/time.h>

main()
{
    FILE *fp;
   fp=fopen("plot.txt","w");

  int l,h;
  int n,s,i,j,y;
  struct timeval tv;
  double start, end;
  	int a[100000];
	
	//l=0;
	//h=x-1;
	gettimeofday(&tv, NULL);
	start=tv.tv_sec+(tv.tv_usec/1000000.0);
	for(j=100;j<900;j=j+100)
{
	l=0;
        h=j-1;

	for(i=0;i<j;i++)
	{
	a[i]=rand()%1000;
	}
	y=as(a,l,h);
	printf("sorted array is\n");
	for(i=0;i<j;i++)
	{
	printf("%d\t",a[i]);
	}

	gettimeofday(&tv,NULL);
	end=tv.tv_sec+(tv.tv_usec/1000000.0);
	fprintf(fp,"%d\t%f\n",j,end-start);
}
fclose(fp);
system("gnuplot");

	
}
/*  printf("enter the number of elements\n");
  scanf("%d",&n);

  printf("enter the unsorted array\n");
  for(i=0;i<n;i++)
 {
    scanf("%d",&a[i]);
 }
 l=0;
 h=n-1;
 as(a,l,h);
 printf("sorted array is\n");
 for(i=0;i<n;i++)
 {
  printf("%d\n",a[i]);
 } 
*/


int as(int a[],int l,int h)
{
 int s;
 
 if(l<h)
{
  s=part(a,l,h);
  as(a,l,s-1);
  as(a,s+1,h);
}

}


int part(int a[],int l,int h)
{
  int i,j,p,temp;
  p=a[l];
  i=l;
  j=h;
  while(i<j)
{
  while((a[i]<=p) && (i<h))
{
  i++;
 }
 while((a[j]>=p) && (j>l))
{
  j--;
}
 if(i<j)
 {
   temp=a[i];
   a[i]=a[j];
   a[j]=temp;
 }
}
 
 
   temp=a[i];
   a[l]=a[j];
   a[j]=temp;
 
 return j;
}
