#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100;  
vector<int> adj[N], visited(N, 0);  
deque<int> path; 
int v, e; 

bool dfs(int start) {
	visited[start] = 1; 
	if (start == v - 1) 
	{
		path.push_front(start); 
		return true; 
	}
	for (auto i : adj[start]) 
	{
		if (!visited[i] && dfs(i))
		{
			path.push_front(start); 
			return true; 
		}
	}
	return false; 
}
int32_t main() 
{
	iostream::sync_with_stdio(false); 
    	cin.tie(0); 
    	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	#endif
	
	
	cin >> v >> e; 
	
	// Formatin of graph

	for (int i = 0; i < e; i++) {
		int start, finish; 
		cin >> start >> finish; 
		adj[start].push_back(finish); 
		adj[finish].push_back(start); 
	}
	
	
	dfs(0); 
	// Printing the path
	for (int i : path) cout << i << " " ; 
	cout << endl; 
	 
	return 0; 
}
	
