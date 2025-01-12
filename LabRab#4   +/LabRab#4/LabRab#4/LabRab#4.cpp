#include "Macros.h"
#define LINE nl;\
			 for(int i =0;i<34;i++){\
				 vi "-";\
			 }\
			 nl

struct AdjencyMatrixGraph {

	int verticles;

	vector<vector<int>> matList;
	vector<vector<int>> seqList;

	AdjencyMatrixGraph(int v) : verticles(v), matList(v, vector<int>(v, INT32_MAX)) {
		seqList = {
					{0, 2, 3, 4, 5, 6},
					{1, 0, 3, 4, 5, 6},
					{1, 2, 0, 4, 5, 6},
					{1, 2, 3, 0, 5, 6},
					{1, 2, 3, 4, 0, 6},
					{1, 2, 3, 4, 5, 0}
		};
	}

	void addEdges(int x, int y, int value) {
		matList[x - 1][y - 1] = value;
	}

	void display() {
		vi "    |";
		for (int i = 1; i <= 6; i++) {
			vi "  \x1B[32m" << i << "\033[0m |";
		}

		LINE;

		for (int i = 0; i < 6; i++) {
			vi "  \x1B[32m" << i + 1 << "\033[0m |";

			for (int j = 0; j < 6; j++) {
				if (matList[i][j] == INT32_MAX) {
					vi "inf |";
				}
				else {
					vi ((matList[i][j] < 10) ? "  " : " ") << matList[i][j] << " |";
				}
			}
			LINE;
		}
		nl nl
		vi "Матрица переходов"; nl
		vi "    |";

		for (int i = 1; i <= 6; i++) {
			vi "  \x1B[32m" << i << "\033[0m |";

		}
		LINE;
		for (int i = 0; i < verticles; i++) {
			vi "  \x1B[32m" << i + 1 << "\033[0m |";
			for (int j = 0; j < verticles; j++) {

				vi "  " << seqList[i][j] << " |";
			}
			LINE;
		}
	}
};

void func(AdjencyMatrixGraph& graph) {
	for (int k = 0; k < graph.verticles; k++) {

		for (int i = 0; i < graph.verticles; i++) {

			for (int j = 0; j < graph.verticles; j++) {

				if (graph.matList[i][k] + graph.matList[k][j] < graph.matList[i][j]) {
					graph.matList[i][j] = graph.matList[i][k] + graph.matList[k][j];
					graph.seqList[i][j] = graph.seqList[i][k];
				}
			}
		}
	}
}

int main()
{
	SCCP1251 SCOCP1251

	AdjencyMatrixGraph graph(6);

	graph.addEdges(1, 1, 0);
	graph.addEdges(1, 2, 28);
	graph.addEdges(1, 3, 21);
	graph.addEdges(1, 4, 59);
	graph.addEdges(1, 5, 12);
	graph.addEdges(1, 6, 27);
	graph.addEdges(2, 1, 7);
	graph.addEdges(2, 2, 0);
	graph.addEdges(2, 3, 24);
	graph.addEdges(2, 5, 21);
	graph.addEdges(2, 6, 9);
	graph.addEdges(3, 1, 9);
	graph.addEdges(3, 2, 32);
	graph.addEdges(3, 3, 0);
	graph.addEdges(3, 4, 13);
	graph.addEdges(3, 5, 11);
	graph.addEdges(4, 1, 8);
	graph.addEdges(4, 3, 5);
	graph.addEdges(4, 4, 0);
	graph.addEdges(4, 5, 16);
	graph.addEdges(5, 1, 14);
	graph.addEdges(5, 2, 13);
	graph.addEdges(5, 3, 15);
	graph.addEdges(5, 4, 10);
	graph.addEdges(5, 5, 0);
	graph.addEdges(5, 6, 22);
	graph.addEdges(6, 1, 15);
	graph.addEdges(6, 2, 18);
	graph.addEdges(6, 5, 6);
	graph.addEdges(6, 6, 0);

	graph.display();

	func(graph);
	nl nl vi " Матрицы после метода Флойда-Уоршелла"; nl nl

	graph.display();

	pause
	ret 0;
}
