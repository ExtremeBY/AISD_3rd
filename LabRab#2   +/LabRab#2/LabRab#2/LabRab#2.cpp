#include "Macros.h"
#define LINE nl;\
			 for(int i =0;i<34;i++){\
				 vi "-";\
			 }\
			 nl

struct EdgeListGraph 
{
	int verticles;

	vector<pair<int, int>> edges;

	EdgeListGraph(int v) : verticles(v) {}

	void addEdges(int x, int y) 
	{
		edges.push_back({ x,y });
	}

	void displayEdges()
	{
		for (auto edge : edges)
		{
			vi "( " << edge.first << "; " << edge.second << " )"; nl
		}
	}
};


struct AdjencyMatrixGraph
{
	int verticles;

	vector<vector<int>> matList;

	AdjencyMatrixGraph(int v) : verticles(v), matList(v, vector<int>(v, 0)) {}

	void addEdges(int x, int y)
	{
		matList[x - 1][y - 1] = 1;
		matList[y - 1][x - 1] = 1;
	}

	void displayEdges()
	{
		vi "    ";
		for (int i = 0; i < verticles; i++)
		{
			vi "| " << i + 1 << "  ";
		}

		LINE;

		for (int x = 0; x < verticles; x++)
		{
			vi " " << x + 1 << (x == 9 ? " " : "  ");
			for (int y = 0; y < verticles; y++)
			{
				vi "| " << matList[x][y] << "  ";
			}
			LINE;
		}
	}
};



struct AdjencyListGraph
{
	int verticles;
	vector<vector<int>> adjlist;

	AdjencyListGraph(int v) : verticles(v), adjlist(v) {}
	
	void addEdges(int v, int u)
	{
		adjlist[v - 1].push_back(u);
		adjlist[u - 1].push_back(v);
	}

	void displayEdges()
	{
		for (int i = 0; i < verticles; i++)
		{
			vi i + 1 << ": ";
			for (auto v : adjlist[i])
			{
				vi v << " ";
			}
			nl
		}
	}
};



void BFS(AdjencyListGraph graph, int start)
{
	vector<bool> visited(graph.verticles, false);

	queue<int> q;

	q.push(start - 1);
	visited[start - 1] = true;

	vi "Путь прохождения графа методом BFS: ";

	while (!q.empty())
	{
		int vertex = q.front();

		q.pop();

		vi vertex + 1 << " ";

		for (auto verticle : graph.adjlist[vertex])
		{
			if (!visited[verticle - 1])
			{
				visited[verticle - 1] = true;
				q.push(verticle - 1);
			}
		}
	}
	nl
}



void DFS(AdjencyListGraph graph, int start)
{
	vector<bool> visited(graph.verticles, false);
	stack<int> s;

	s.push(start - 1);

	vi "Путь прохождения графа методом DFS: ";

	while (!s.empty()) 
	{
		int vertex = s.top();
		s.pop();

		if (!visited[vertex]) 
		{
			vi vertex + 1 << " ";
			visited[vertex] = true;
		}

		for (int i = graph.adjlist[vertex].size() - 1; i >= 0; --i) 
		{
			int verticle = graph.adjlist[vertex][i];
			if (!visited[verticle - 1])
			{
				s.push(verticle - 1);
			}
		}
	}
	nl
}



void BFS(EdgeListGraph graph, int start) 
{
	vector<bool> visited(graph.verticles, false);

	queue<int> q;

	q.push(start - 1);
	visited[start - 1] = true;

	vi "Путь прохождения графа методом BFS: ";

	while (!q.empty()) 
	{
		int vertex = q.front();

		q.pop();

		vi vertex + 1 << " ";

		for (auto edge : graph.edges)
		{
			int u = edge.first - 1;
			int v = edge.second - 1;

			if (u == vertex && !visited[v])
			{
				visited[v] = true;
				q.push(v);
			}
			else if (v == vertex && !visited[u])
			{
				visited[u] = true;
				q.push(u);
			}
		}
	}
	nl
}

void DFS(EdgeListGraph graph, int start)
{
	vector<bool> visited(graph.verticles, false);
	stack<int> s;

	s.push(start - 1);

	vi "Путь прохождения графа методом DFS: ";

	while (!s.empty())
	{
		int vertex = s.top();
		s.pop();

		if (!visited[vertex])
		{
			visited[vertex] = true;
			vi vertex + 1 << " ";
		}

		for (int i = graph.verticles - 1; i >= 0; i--) 
		{
			int u = graph.edges[i].first - 1;
			int v = graph.edges[i].second - 1;

			if (u == vertex && !visited[v])
			{
				s.push(v);
			}
			else if (v == vertex && !visited[u])
					{
						s.push(u);
					}
		}
	}
	nl
}

void BFS(AdjencyMatrixGraph graph, int start)
{
	vector<bool> visited(graph.verticles, false);
	queue<int> q;

	q.push(start - 1);
	visited[start - 1] = true;

	vi "Путь прохождения графа методом BFS: ";

	while (!q.empty()) 
	{
		int vertex = q.front();

		q.pop();

		vi vertex + 1 << " ";

		for (int i = 0; i < graph.verticles; i++)
		{
			if (graph.matList[vertex][i] == 1 && !visited[i])
			{
				visited[i] = true;
				q.push(i);
			}
		}
	}
	nl
}

void DFS(AdjencyMatrixGraph graph, int start)
{
	vector<bool> visited(graph.verticles, false);
	stack<int> s;

	s.push(start - 1);

	vi "Путь прохождения графа методом DFS: ";

	while (!s.empty()) 
	{
		int vertex = s.top();
		s.pop();

		if (!visited[vertex])
		{
			visited[vertex] = true;
			vi vertex + 1 << " ";
		}

		for (int i = graph.verticles - 1; i >= 0; i--) 
		{
			if (graph.matList[i][vertex] == 1 && !visited[i]) 
			{
				s.push(i);
			}
		}
	}
	nl
}

int main()
{
	SCOCP1251
	SCCP1251

	int verticles = 10;

	EdgeListGraph graph(verticles);

	graph.addEdges(1, 2);
	graph.addEdges(1, 5);
	graph.addEdges(2, 7);
	graph.addEdges(2, 8);
	graph.addEdges(4, 6);
	graph.addEdges(4, 9);
	graph.addEdges(5, 6);
	graph.addEdges(6, 9);
	graph.addEdges(8, 3);
	graph.addEdges(9, 10);

	AdjencyListGraph graph_(verticles);

	graph_.addEdges(1, 2);
	graph_.addEdges(1, 5);
	graph_.addEdges(2, 7);
	graph_.addEdges(2, 8);
	graph_.addEdges(4, 6);
	graph_.addEdges(4, 9);
	graph_.addEdges(5, 6);
	graph_.addEdges(6, 9);
	graph_.addEdges(8, 3);
	graph_.addEdges(9, 10);

	AdjencyMatrixGraph graph__(verticles);
	graph__.addEdges(1, 2);
	graph__.addEdges(1, 5);
	graph__.addEdges(2, 7);
	graph__.addEdges(2, 8);
	graph__.addEdges(4, 6);
	graph__.addEdges(4, 9);
	graph__.addEdges(5, 6);
	graph__.addEdges(6, 9);
	graph__.addEdges(8, 3);
	graph__.addEdges(9, 10);

	graph.displayEdges();
	graph_.displayEdges();
	graph__.displayEdges();

	BFS(graph, 1);
	DFS(graph, 1);
	BFS(graph_, 1);
	DFS(graph_, 1);
	BFS(graph__, 1);
	DFS(graph__, 1);

	pause
	ret 0;
} // O(V+E); вершины + грани