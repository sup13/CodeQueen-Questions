#include<iostream>
#include <list>
#include <stack>

using namespace std;

list <int> res;
list <int> *adj;
int n,cnt = 0;

void topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    visited[v] = true;
 
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    Stack.push(v);
}

void topologicalSort()
{
    stack<int> Stack;
 
    bool *visited = new bool[cnt];
    for (int i = 0; i < cnt; i++)
        visited[i] = false;
 
    for (int i = 0; i < cnt; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
 
    while (Stack.empty() == false)
    {
        res.push_back(Stack.top());
        Stack.pop();
    }
}
 
int min(int x, int y)
{
    return (x < y)? x : y;
}

int main()
{
	freopen("in05.txt","r",stdin);
	freopen("out05.txt","w",stdout);
	int desnum,srcnum,thirnum;
    cin >> n;
    char src,dest,thir;
    int hash[26],hashRev[26];
    for (int i = 0; i < 26; i++)
    	hash[i] = -1;
    adj = new list<int>[26];
    
	for (int i = 0; i < n; i++) {
    	cin >> src >> dest >> thir;
    	if (hash[src-'a'] == -1) {
    		hash[src-'a'] = cnt;
    		srcnum = cnt;
    		hashRev[cnt] = src-'a';
    		cnt++;
    	}
    	else 
    		srcnum = hash[src-'a'];
    	if (hash[dest-'a'] == -1) {
    		hash[dest-'a'] = cnt;
    		desnum = cnt;
    		hashRev[cnt] = dest - 'a';
    		cnt++;
    	}
    	else 
    		desnum = hash[dest-'a'];
    	if (hash[thir-'a'] == -1) {
    		hash[thir-'a'] = cnt;
    		thirnum = cnt;
    		hashRev[cnt] = thir - 'a';
    		cnt++;
    	}
    	else 
    		thirnum = hash[thir-'a'];
    adj[srcnum].push_back(desnum);
    adj[desnum].push_back(thirnum);
    adj[srcnum].push_back(thirnum);
	}
    
    topologicalSort();
    //cout << "result\n";
    list <int> :: iterator it;
    char finRes;
    for (it = res.begin(); it != res.end(); it++) {
    	finRes = hashRev[*it] + 'a';
    	cout << finRes;	
    }
    
    return 0;
}
