#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long 
#define inf 1000000000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n;
char mp[105][105];
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			mp[i][j]='D';
	for(int i=1;i<=n/2+1;i++)
		for(int j=1;j<=n/2+1-i;j++)
			mp[i][j]=mp[n-i+1][j]=mp[i][n-j+1]=mp[n-i+1][n-j+1]='*';
	for(int i=1;i<=n;i++)
		printf("%s\n",mp[i]+1);
	return 0;
}