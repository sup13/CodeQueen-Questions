#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("i_psort2.txt","r",stdin);
	freopen("o_psort2.txt","w",stdout);
	int n,kn;
	cin>>n>>kn;
	vector<pair<pair<long long,int>,int> > v;
	map<int,string> mp;
	int i,j,k;
	for(i=0;i<n;i++)
	{
		string str;
		cin>>str;
		mp[i+1]=str;
		long long count=0;
		for(j=1;j<(1<<str.length());j++)
		{
			string s;
			for(k=0;k<str.length();k++)
			{
				if(j&(1<<k))
				{
					s+=str[k];
				}
			}
			int l=0,r=s.length()-1,flag=1;
			while(l<r)
			{
				if(s[l]==s[r])
				{
					l++;
					r--;
				}
				else
				{
					flag=0;
					break;
				}
			}
			if(flag)
			count++;
		}
		int vowel=0;
		for(j=0;j<str.length();j++)
		{
			if(str[j]=='a' || str[j]=='e' || str[j]=='i' || str[j]=='o' || str[j]=='u')
			vowel++;
		}
		v.push_back(make_pair(make_pair(-1*count,-1*vowel),i+1));
	}
	sort(v.begin(),v.end());
	for(i=0;i<kn;i++)
	{
		cout<<v[i].second<<" "<<mp[v[i].second]<<" "<<-1*v[i].first.first<<" "<<-1*v[i].first.second<<endl;
	}
	return 0;
}
