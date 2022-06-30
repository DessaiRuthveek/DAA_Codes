#include<iostream>
using namespace std;
void dij(int n,int g[100][100],int so,int dist[10])

{
int i,v ,count=1,min;
int visited[10];
for(i=1;i<=n;i++)
{
visited[i]=0;
dist[i]=g[so][i];
}
visited[so]=1;
dist[so]=0;
while(count<=n)
{
min=9999;
for(i=1;i<=n;i++)
if(dist[i]<min && visited[i]==0)
{

min=dist[i];
v=i;

}

visited[v]=1;
count++;
for(i=1;i<=n;i++)
if(dist[i]>dist[v]+g[v][i])
{
dist[i]=dist[v]+g[v][i];
}
}
}
int main()
{
int g[100][100],so,visited[100],n,dist[10],i,j;
cout<<"Enter no of vertices : ";
cin>>n;
for(int i=1;i<=n;i++)
{
for(int j=1;j<=n;j++)
{
cout<<i<<"-"<<j<<": ";
cin>>g[i][j];
if(g[i][j]==0)
g[i][j]=9999;
}
}
cout<<"Enter Source : ";
cin>>so;
dij(n,g,so,dist);
cout<<"The shortest path from source "<<so<<" is:"<<endl;

for(i=1;i<=n;i++)
if(so!=i)
cout<<so<<"->"<<i<<"="<<dist[i]<<endl;

}