#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("i_div1.txt","r",stdin);
	freopen("o_divsqrt1.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int x=0,o=0,a=1;
		int i;
		for(i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				x=x^i;
				o=o|i;
				a=a&i;
				if(i*i!=n)
				{
					int j=n/i;
					x=x^j;
					o=o|j;
					a=a&j;
				}
			}
			
		}
		cout<<x<<" "<<o<<" "<<a<<endl;
	}
	return 0;
}
