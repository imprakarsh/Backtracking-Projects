#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10; 
vector<int> col, diag1, diag2;
vector<vector<string>> ans; 
vector<pair<int, int>> path; 
int n; 
void dfs(int y)  
{
	if (y == n) 
	{
		vector<string> v(n); 
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				v[i].push_back('.'); 
		
		for (auto i : path)  v[i.first][i.second] = 'Q'; 
		
		ans.push_back(v); 
		return; 
	}
	for (int x = 0; x < n; x++) {
		if (col[x] || diag1[x + y] || diag2[x - y + n  - 1]) continue; 
		
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
		path.push_back({y, x}); 
		dfs(y + 1); 
		
		col[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
		path.pop_back(); 
	}
}
		
int32_t main() 
{
	iostream::sync_with_stdio(false); 
    	cin.tie(0); 
    	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	#endif
	
	// Taking size of chess board as input
	cin >> n; 
	col.resize(n, 0); 
	diag1.resize(2*n, 0); 
	diag2.resize(2*n, 0); 
	dfs(0); 
	cout << ans.size() << endl; 
	



	return 0; 
}
	
