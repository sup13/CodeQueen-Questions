#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
long long power(long long a,long long b)
{
	if(b==0)
	return 1;
	long long ans=power(a,b/2);
	if(b%2==0)
	return (ans*ans)%mod;
	else
	return (((ans*ans)%mod)*a)%mod;
}
long long mat[1005][1005];
int main()
{
	freopen("si.txt","r",stdin);
	freopen("so.txt","w",stdout);
	int n,s,q,ff;
	scanf("%d %d %d %d",&n,&s,&q,&ff);
	
	int i,j,k;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n+1+1;j++)
		{
			mat[i][j]=0;
		}
	}
	while(s--)
	{
		int r1,c1,r2,c2;
		long long val;
		scanf("%d %d %d %d %lld",&r1,&c1,&r2,&c2,&val);
		for(i=c1;i<=c2;i++)
		{
			mat[r1][i]+=val;
			mat[r2+1][i]-=val;
		}
	}
	for(i=1;i<=n+1;i++)
	{
		for(j=1;j<=n+1;j++)
		{
			mat[i][j]+=mat[i-1][j];
		}
	}
	/*for(i=0;i<=n+1;i++)
	{
		for(j=0;j<=n+1;j++)
		{
			printf("%lld ",mat[i][j]);
		}
		printf("\n");
	}*/
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			mat[i][j]+=mat[i-1][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			mat[i][j]+=mat[i][j-1];
		}
	}
	while(q--)
	{
		int r1,c1,r2,c2;
		scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
		long long ans=mat[r2][c2]-mat[r2][c1-1]-mat[r1-1][c2]+mat[r1-1][c1-1];
		if(ff==0)
		printf("%lld\n",ans);
		else if(ff==1)
		{
		long long area=(r2-r1+1)*(c2-c1+1);
		if(ans<0)
		ans=ans+mod;
		long long ans1=(ans%mod*power(area,mod-2))%mod;
		printf("%lld\n",ans1);
	}
	}
	return 0;
}
