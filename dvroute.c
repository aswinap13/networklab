#include<stdio.h>
typedef struct Router
{
unsigned dist[20];
unsigned from[20];
} Router;
Router rt[10];
int main()
{
int dmat[20][20];
int n,i,j,k,flag=0;
printf("Enter the number of routers: ");
scanf("%d",&n);
printf("\nEnter the distance matrix:\n");
for(i=0;i<n;i++) {
for(j=0;j<n;j++) {
scanf("%d",&dmat[i][j]);
dmat[i][i]=0;
rt[i].dist[j]=dmat[i][j];
rt[i].from[j]=j;
}
}

do
{
flag=0;
for(i=0;i<n;i++) {
for(j=0;j<n;j++) {
for(k=0;k<n;k++) {
if(rt[i].dist[j] > dmat[i][k] + rt[k].dist[j]) {
rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
rt[i].from[j] = k;
flag=1;
}
}
}
}
} while(flag);
for(i=0;i<n;i++)
{
printf("\n\nRouter info for router %d is \n",i+1);
printf("\nRouter\tVia\tDistance");
for(j=0;j<n;j++)
{
printf("\t\n%d\t%d\t%d",j+1,rt[i].from[j]+1,rt[i].dist[j]);
}
}
printf("\n\n");
}