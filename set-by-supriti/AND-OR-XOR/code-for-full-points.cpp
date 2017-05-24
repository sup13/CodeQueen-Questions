#include<bits/stdc++.h>
using namespace std;
int xor_a[1000005],or_a[1000005],and_a[1000005];
int main()
{
	freopen("i_div1.txt","r",stdin);
	freopen("o_div1.txt","w",stdout);
	int t,i,j;
	scanf("%d",&t);
	for(i=0;i<1000005;i++)
	and_a[i]=1;
	for(i=1;i<1000005;i++)
	{
		for(j=i;j<1000005;j+=i)
		{
			xor_a[j]=xor_a[j]^i;
			or_a[j]=or_a[j]|i;
			and_a[j]=and_a[j]&i;
		}
	}
	while(t--)
	{
		int n;
		scanf("%d",&n);
		printf("%d %d %d\n",xor_a[n],or_a[n],and_a[n]);
	}
	return 0;
}
