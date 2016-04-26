#include<stdio.h>
#include<sys/time.h>
struct timeval tv;
void merge_sort(int [],int ,int );
void merge(int[] ,int ,int ,int );
void main()
{
FILE *fp;
int i,n,a[100];
double end,start;
printf("enter no. of elements\n");
scanf("%d",&n);
printf("random elements are \n");
for(i=0;i<n;i++)
{
a[i]=rand()%100;
printf("%d\t\n",a[i]);
}
fp=fopen("merge1.txt","a");
gettimeofday(&tv,NULL);
start=tv.tv_sec+(tv.tv_usec/1000000.00);
printf("start time=%f\n",start);
merge_sort(a,0,n);
gettimeofday(&tv,NULL);
end=tv.tv_sec+(tv.tv_usec/1000000.00);
printf("end time=%f\n",end);
printf("diff=%f\n",end-start);
printf("sorted elements are\n");
for(i=0;i<n;i++)
{
printf("%d\n",a[i]);
}
fprintf(fp,"%d\t%f\n",n,end-start);
fclose(fp);
system("gnuplot");
}
	
void merge_sort(int a[],int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
merge_sort(a,low,mid);
merge_sort(a,mid+1,high);
merge(a,low,mid,high);
}
}

void merge(int a[],int low,int mid ,int high)
{
int i,k,j,b[100];
i=k=low;
j=mid+1;
while(i<=mid && j<=high)
{
if(a[i]<=a[j])
{
b[k++]=a[i++];
}
else
{
b[k++]=a[j++];
}
}
while(i<=mid)
{
b[k++]=a[i++];
}
while(j<=high)
{
b[k++]=a[j++];
}
for(i=low;i<=high;i++)
{	
a[i]=b[i];
}
}	

