#include <iostream>
using namespace std;

struct listNode
{
	int dest;
	listNode* link;
	
	~listNode()
	{
	}
	
	listNode(){
	}
	
	listNode(int data,listNode* link=NULL)
	{
		this->dest = data;
		this->link = link;
	}
};

struct graph
{
	int V;
	listNode** adj;
	graph(int V)
	{
		this->V = V;
		adj = new listNode*[V];
		for(int i=0;i<V;i++)
		{
			adj[i]=NULL;
		}
	}
	
	~graph()
	{
		listNode* sr = NULL;
		listNode* temp = NULL;
		for(int i=0;i<V;i++)
		{
			sr = adj[i];
			while(sr!=NULL)
			{
				temp = sr;
				sr =sr->link;
				delete temp;
			}
		}
	}
};

void addEdge(graph* g,int v1,int v2)
{
	g->adj[v1] = new listNode(v2,g->adj[v1]);
	
	// for undrirect graph
	g->adj[v2] = new listNode(v1,g->adj[v2]);
}

void dfs(graph* g,int u,bool* visited)
{
	cout << u << endl;
	visited[u] = true;
	listNode* sr = g->adj[u];
	while(sr!=NULL)
	{
		if(visited[sr->dest]!=true)
		{
			dfs(g,sr->dest,visited);
		}
		sr = sr->link;
	}
}

void dfs(graph* g,int s)
{
	bool* visited = new bool[g->V];
	for(int i=0;i<g->V;i++) 
		visited[i]=false;
	dfs(g,s,visited);
	delete[] visited;
}

// Main
int main()
{
	graph* g = new graph(4);
	addEdge(g,0,1);
	addEdge(g,0,2);
	addEdge(g,1,2);
	addEdge(g,2,0);
	addEdge(g,2,3);
	addEdge(g,3,3);
	
	dfs(g,2);
	
	delete g;
	return 0;
}

