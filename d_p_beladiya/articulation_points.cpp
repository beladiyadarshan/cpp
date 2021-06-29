/**
 * usage is_artculation_points(). 
 * is_art[i] denotes wheather the node is AP 
 * is_artculation is list of all nodes that are AP
 */
vector <vector <int> > graph;
vector <int> is_artculation, vis, tin, low;
vector <bool> is_art;
int n, ptr;
void is_art_dfs(int u, int p) {
	vis[u] = 1;
	tin[u] = low[u]= ptr++;
	int kf = 0;
	for (auto v : graph[u]) {
		if (v == p)
			continue;
		else if (vis[v])
			low[u] = min(low[u], tin[v]);
		else {
			is_art_dfs(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= tin[u] && p != 0) {
				if (!is_art[u])
					is_artculation.push_back(u);
				is_art[u] = true;
			}
			kf++;
		}
	}
	if (p == 0 && kf > 1) {
		if (!is_art[u])
			is_artculation.push_back(u);
		is_art[u] = true;
	}
}
void is_artculation_points() {
	ptr = 0;
	vis.assign(n + 1, 0);
	tin.assign(n + 1, 0);
	is_art.assign(n + 1, 0);
	low.assign(n + 1, 0);
	is_artculation.clear();
	for (int i = 1; i <= n; ++i)
	if (!vis[i])
		is_art_dfs(i, 0);
}
                                                                                                                  