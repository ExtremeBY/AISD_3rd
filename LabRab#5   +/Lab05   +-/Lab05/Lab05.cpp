#include <iostream>
#include <vector>
#include <algorithm>

#define LINE cout<<"\n ";\
			 for(int i =0;i<44;i++){\
				 cout<<"-";\
			 }\
			 cout<<"\n";

using namespace std;

#define el(x, y) graph.matList[x][y]


struct Edge {
    int from, to, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct AdjencyMatrixGraph {
    int verticles;
    vector<vector<int>> matList;

    AdjencyMatrixGraph(int v) : verticles(v), matList(v, vector<int>(v, INT_MAX)) {}

    void addEdges(int x, int y, int value) {
        matList[x - 1][y - 1] = value;
        matList[y - 1][x - 1] = value;
    }

    void display() {
        cout << "    |";
        for (int i = 1; i <= verticles; i++) {
            cout << "  \x1B[32m" << i << "\033[0m |";

        }

        LINE;

        for (int i = 0; i < verticles; i++) {
            cout << "  \x1B[32m" << i + 1 << "\033[0m |";

            for (int j = 0; j < verticles; j++) {

                if (matList[i][j] == INT32_MAX) {
                    cout << "inf |";
                }
                else {
                    cout << ((matList[i][j] < 10) ? "  " : " ") << matList[i][j] << " |";
                }
            }
            LINE;
        }


    }

    vector<Edge> getAllEdges() {
        vector<Edge> edges;
        for (int i = 0; i < verticles; i++) {
            for (int j = i + 1; j < verticles; j++) {
                if (matList[i][j] != INT_MAX) {
                    edges.push_back({ i, j, matList[i][j] });
                }
            }
        }
        return edges;
    }
};

int find(vector<int>& parent, int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find(parent, parent[v]);
}

void unionSets(int a, int b, vector<int>& parent) {
    a = find(parent, a);
    b = find(parent, b);
    if (a != b) {
        parent[b] = a;
    }
}




void prima(AdjencyMatrixGraph& graph) {
    int start;
    cout << "Введите начальную вершину (от 1 до " << graph.verticles << "): ";
    cin >> start;
    start--;

    if (start < 0 || start >= graph.verticles) {
        cout << "Неверная вершина!" << endl;
        return;
    }

    vector<bool> visited(graph.verticles, false);
    vector<pair<int, int>> mst;
    visited[start] = true;

    int totalWeight = 0;

    for (int i = 1; i < graph.verticles; i++) {
        int minEdge = INT_MAX;
        pair<int, int> minEdgeCoords;

        
        for (int i = 0; i < graph.verticles; i++) {
            if (visited[i]) {
                for (int j = 0; j < graph.verticles; j++) {
                    if (!visited[j] && el(i, j) < minEdge) {
                        minEdge = el(i, j);
                        minEdgeCoords = { i, j };
                    }
                }
            }
        }

        mst.push_back(minEdgeCoords);
        visited[minEdgeCoords.second] = true; 
        totalWeight += minEdge; 

        cout << "Добавлено ребро: " << minEdgeCoords.first + 1 << " - "
            << minEdgeCoords.second + 1 << " с весом " << minEdge << endl;
    }

    cout << "Общий вес MST (Прим): " << totalWeight << endl;
}




void kruskal(AdjencyMatrixGraph& graph) {
    vector<Edge> edges = graph.getAllEdges();
    sort(edges.begin(), edges.end()); 

    vector<int> parent(graph.verticles);
    for (int i = 0; i < graph.verticles; i++)
        parent[i] = i;  

    int totalWeight = 0;
    vector<Edge> mst; 

    
    for (const Edge& edge : edges) {
        if (find(parent, edge.from) != find(parent, edge.to)) {
            mst.push_back(edge); 
            totalWeight += edge.weight;
            unionSets(edge.from, edge.to, parent); 
        }

        if (mst.size() == graph.verticles - 1) {
            break;
        }
    }

    cout << "\nМинимальное остовное дерево (Краскал):" << endl;
    for (const Edge& edge : mst) {
        cout << edge.from + 1 << " - " << edge.to + 1 << " : " << edge.weight << endl;
    }
    cout << "Общий вес MST (Краскал): " << totalWeight << endl;
}



int main() {
    setlocale(LC_ALL, "Ru");


    AdjencyMatrixGraph graph(8);


    graph.addEdges(1, 2, 2);
    graph.addEdges(1, 5, 2);
    graph.addEdges(1, 4, 8);
    graph.addEdges(2, 5, 5);
    graph.addEdges(2, 3, 3);
    graph.addEdges(2, 4, 10);
    graph.addEdges(3, 5, 12);
    graph.addEdges(3, 8, 7);
    graph.addEdges(4, 5, 14);
    graph.addEdges(4, 6, 3);
    graph.addEdges(4, 7, 1);
    graph.addEdges(5, 6, 11);
    graph.addEdges(5, 7, 4);
    graph.addEdges(5, 8, 8);
    graph.addEdges(6, 7, 6);
    graph.addEdges(7, 8, 9);


    graph.display();

    cout << "\n\nПрима\n";
    prima(graph);


    cout << "\n\nКраскала\n";

    kruskal(graph);



}
