#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("in01.txt","r",stdin);
	freopen("out01.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(((a+b)>c) && ((b+c)>a) && ((a+c)>b))
		{
			double peri=(double)(a+b+c);
			double semi=peri/2.0;
			double area=sqrt(semi*(semi-a)*(semi-b)*(semi-c));
			printf("%d %d\n",(int)peri,(int)area);
		}
		else
		printf("-1\n");
	}
	return 0;
}
