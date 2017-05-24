#include <iostream>
#include <vector>

using namespace std;

unsigned long long int getLeftmostBit (long long int n)
{
   unsigned long long int m = 0;
   while (n > 1)
   {
      n = n >> 1;
      m++;
   }
   
   return m;
}

unsigned long long int getNextLeftmostBit (long long int n,unsigned long long int m)
{
   unsigned long long int temp = 1 << m;
   while (n  < temp)
   {
      temp = temp >> 1;
      m--;
   }
   return m;
}

unsigned long long int _countSetBits(long long int n, unsigned long long int m);
 
unsigned long long int countSetBits(long long int n)
{
   unsigned long long int m = getLeftmostBit (n);
   return _countSetBits (n, m);
}
 
unsigned long long int _countSetBits(long long int n, unsigned long long int m)
{
    if (n == 0)
       return 0;

    m = getNextLeftmostBit(n, m);
    
    if (n == ((unsigned long long int)1<<(m+1))-1)
        return (unsigned long long int)(m+1)*(1<<m);

    n = n - (1<<m);
    return (n+1) + countSetBits(n) + m*(1<<(m-1));
}
 
int main()
{
	freopen("in00.txt","r",stdin);
	freopen("out00.txt","w",stdout);
   int t;
   long long int n;
   cin >> t;
   vector <unsigned long long int> res;
   for (int i = 0; i < t; i++) {
   		cin >> n;
   		res.push_back(countSetBits(n));
	}
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
		
	return 0;
}
