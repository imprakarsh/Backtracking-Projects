#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 100;  
vector<int> adj[N], visited(N, 0);  
deque<int> path; 
int v, e; 

void dfs(int start) {
	visited[start] = 1; 
	path.push_back(start); 
	
	for (auto i : adj[start]) 
	{
		if (!visited[i]) {
			dfs(i); 
			if (path.back() == v - 1) 	return; 
			path.pop_back(); 
		}
	}
			
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
	
