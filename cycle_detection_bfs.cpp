#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
	int V;
	list<int> *adj;
	vector<int> parent;
	vector<bool> visited;

public:
	Graph(int x);
	void addEdges(int u, int v);
	bool isCycle(int s);
	bool isVisited(int n);
};

Graph::Graph(int x) {
	V = x+1;
	adj = new list<int>[V];
	parent.assign(x+1, 0);
	visited.assign(x+1, false);
}

void Graph::addEdges(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool Graph::isCycle(int s) {
	queue<int> q;
	visited[s]=true;
	parent[s]= -1;
	q.push(s);

	while(!q.empty()) {
		int node = q.front();
		q.pop();

		for(auto x: adj[node]) {
			if(visited[x] && x!=parent[node]) return true;
			else if(!visited[x]) {
				q.push(x);
				visited[x]=true;
				parent[x]= node;
			}
		}
	}

	return false;
}

bool Graph::isVisited(int n) {
	return visited[n];
}


int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cout<< "BFS to detect if a graph has a cycyle" << "\n" << endl; 

	int n,m;
	cin >> n >> m;

	Graph g(n);

	for(int i=0;i<m;i++) {
		int u, v;
		cin >> u >> v;
		g.addEdges(u, v);
	}

	bool ans = false;

	// to handle disconnected graphs
	for(int i=1;i<=n;i++) {
		if(!g.isVisited(i) && g.isCycle(i)) {
			ans = true;
			break;
		}
	}

	if(ans) cout<< "There is a cycle in the graph !" << endl;
	else cout<< "There is no cycle in the graph" << endl;;

	return 0;
}