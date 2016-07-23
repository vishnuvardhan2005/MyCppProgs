#include <iostream>
#include <queue>
#include <Windows.h>
using namespace std;

struct listNode
{
	int dest;
	listNode* link;
	
	listNode(){	}
	listNode(int d,listNode* l=NULL)
	{
		dest = d;
		link = l;
	}
};

struct graph
{
	int V;
	listNode** adj;
	
	graph(int V)
	{
		this->V = V;
		adj = new listNode*[V+1];
		for(int i=1;i<=V;i++)
		{
			adj[i]=NULL;
		}
	}
};

void addEdge(graph* g,int v1,int v2)
{
	g->adj[v1] = new listNode(v2,g->adj[v1]);
	
	// for undrirect graph
	g->adj[v2] = new listNode(v1,g->adj[v2]);
}

void bfs(graph* g,int s)
{
	bool* visited = new bool[g->V+1];
	int* dist = new int[g->V+1];
	
	for(int i=1;i<=g->V;i++)
	{
		visited[i]=false;
		dist[i] = -1;
	}
	queue<int> q;
	visited[s] = true;
	dist[s] = 0;
	q.push(s);
	int u,v;
	listNode* sr = NULL;
	while(!q.empty())
	{
		u = q.front();q.pop();
	//	cout << u << " ";
		sr = g->adj[u];
		while(sr!=NULL)
		{
			if(visited[sr->dest]!=true)
			{
				q.push(sr->dest);
				visited[sr->dest] = true;
				dist[sr->dest] = dist[u]+6;
			}
			sr = sr->link;
		}
	}
	
	for(int i=1;i<=g->V;i++)
	{
		if(i!=s)
		cout << dist[i] << " ";
	}
	cout << endl;
	
}

// Main
int main()
{
	int testCases;
	int V;
	int edges;
	int v1,v2;
	int s;
	cin >> testCases;
	while(testCases--)
	{
		cin >> V;
		graph* g = new graph(V);
		cin >> edges;
		while(edges--)
		{
			cin >> v1;
			cin >> v2;
			addEdge(g,v1,v2);
		}
		cin >> s;
		bfs(g,s);
		delete g;
	}
	
	return 0;
}
