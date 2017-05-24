#include<bits/stdc++.h>
using namespace std;
long long dp[50001];
vector<int> test;
long long maxn=-1;
void chord(){
    memset(dp,0,sizeof(dp));
    int i,j;
    dp[0]=1;
    dp[2]=1;
    for(i=4;i<=maxn;i+=2)
    {
        long long sum=0;
        for(j=0;j<i;j+=2)
        {
            sum=(sum+(dp[j]*dp[i-j-2])%1000000007)%1000000007;
        }
        dp[i]=sum;
    }
    //return dp[A];
}
int main()
{
	freopen("i_rishu3.txt","r",stdin);
	freopen("o_rishu3.txt","w",stdout);
	//chord();
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		long long n;
		scanf("%lld",&n);
		test.push_back((n*n)/2);
		maxn=max(maxn,(n*n)/2);
	}
	chord();
	for(int i=0;i<t;i++)
	{
		//n=(n*n)/2;
		//cout<<n<<" ";
		if(test[i]==0 || test[i]==1)
		printf("0\n");
		else
		printf("%lld\n",dp[test[i]]);
	}
	return 0;
}
