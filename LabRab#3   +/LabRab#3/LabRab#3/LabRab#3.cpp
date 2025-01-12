#include "Macros.h"
#define LINE nl\
			 for(int i =0;i<49;i++){\
				 vi "-";\
			 }\
			 nl;

struct AdjencyMatrixGraph
{
	int verticles;

	vector<vector<int>> matList;

	AdjencyMatrixGraph(int v) : verticles(v), matList(v, vector<int>(v, 0)) {}

	void addEdges(char cx, char cy, int value) 
	{
		int x = cx - 'A';
		int y = cy - 'A';
		matList[x][y] = value;
		matList[y][x] = value;
	}

	void display()
	{
		vi "    |";
		for (char i = 'A'; i <= 'I'; i++) 
		{
			vi "  " << i << " |";
		}

		LINE;

		for (int i = 0; i < 9; i++) 
		{
			vi "  " << (char)('A' + i) << " |";

			for (int j = 0; j < 9; j++) 
			{
				vi (matList[i][j] < 10 ? "  " : " ") << matList[i][j] << " |";
			}
			LINE;
		}
	}
};

void Deikstra(AdjencyMatrixGraph graph, char cstart)
{
	while (cstart < 'A' || cstart > 'I')
	{
		vi "Нет такой вершины, попробуйте ещё раз"; nl
		vv cstart;
	}

	int start = cstart - 'A';

	vector<int> routes(9, INT32_MAX);
	vector<bool> visited(9, false);
	queue<int> q;

	routes[start] = 0;
	q.push(start);

	while (!q.empty())
	{
		int vertex = q.front();
		q.pop();

		if (!visited[vertex])
		{
			visited[vertex] = true;
		}

		for (int i = 0; i < graph.matList[vertex].size(); i++)
		{
			int way = graph.matList[vertex][i];

			if (graph.matList[vertex][i] != 0 && !visited[i])
			{
				int newRoute = way + routes[vertex];

				if (newRoute < routes[i])
				{
					routes[i] = newRoute;
					q.push(i);
				}
			}
		}
	}
	vi "Мартшруты от вершины " << (char)('A' + start) << ":"; nl
	for (int i = 0; i < graph.matList[start].size(); i++)
	{
		nw vi "->" << (char)('A' + i) << ": " << routes[i]; nl
	}
}

int main()
{
	SCOCP1251 SCCP1251

	AdjencyMatrixGraph graph(9);

	graph.addEdges('A', 'B', 7);
	graph.addEdges('A', 'C', 10);
	graph.addEdges('B', 'F', 9);
	graph.addEdges('B', 'G', 27);
	graph.addEdges('C', 'E', 31);
	graph.addEdges('C', 'F', 8);
	graph.addEdges('D', 'E', 32);
	graph.addEdges('D', 'H', 17);
	graph.addEdges('D', 'I', 21);
	graph.addEdges('F', 'H', 11);
	graph.addEdges('G', 'I', 15);
	graph.addEdges('H', 'I', 15);

	graph.display();

	char start;

	vi "Введите стартовую вершину: ";
	vv start;

	Deikstra(graph, start);
	pause
	ret 0;
}