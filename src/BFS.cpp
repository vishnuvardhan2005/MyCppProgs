#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int data;
	node* link;
	node(int d,node* ln=NULL)
	{
		data = d;
		link = ln;
	}
};

void Init(node** G,int N)
{
	for(int i=1;i<=N;i++)
	{
		G[i]=NULL;
	}
}

void AddEdge(node** G,int N,int v1,int v2)
{
	if(G[v1]==NULL)
	{
		G[v1] = new node(v2,NULL);
	}
	else
	{
		node* sr = G[v1];
		while(sr->link!=NULL)
		{
			sr =sr->link;
		}
		sr->link = new node(v2,NULL);
	}
}

void BFS(node** G,int N,int S)
{
	bool* visited = new bool[N];
	int* dist = new int[N];
	for(int i=1;i<=N;i++)
	{
		visited[i]=false;
		dist[i] = -1;
	}
	queue<int> q;
	visited[S] = true;
	dist[S] = 0;
	q.push(S);
	
	node* sr = NULL;
	int u;
	
	while(!q.empty())
	{
		u = q.front();q.pop();
		cout << u << " ";
		sr = G[u];
		while(sr!=NULL)
		{
			q.push(sr->data);
			dist[sr->data] = dist[u]+1;
			sr = sr->link;
		}
		visited[u] = true;		
	}
}

// Main
int main()
{
	int V = 8;
	int N = V+1;
	node** G = new node*[N];
	Init(G,N);
	AddEdge(G,N,1,2);
	AddEdge(G,N,1,3);
	AddEdge(G,N,3,4);
	AddEdge(G,N,3,5);
	AddEdge(G,N,6,7);
	AddEdge(G,N,7,8);
	BFS(G,N,1);
	return 0;
}

