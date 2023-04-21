#include <iostream>
#include <algorithm>

#include "PriorityQueue.h"
#include "Graph.h"
#include "MatrixGraph.h"

using std::cout;
using std::cin;


int primMST(Graph* g);
int findTheNearestVert(vector<int>& mark, vector<bool>& added);


int main() {

	Graph* g = new MatrixGraph(6);

	g->insert(0, 1, 6);
	g->insert(0, 2, 1);
	g->insert(0, 3, 5);
	g->insert(1, 2, 5);
	g->insert(1, 4, 3);
	g->insert(2, 5, 4);
	g->insert(2, 3, 5);
	g->insert(2, 4, 6);
	g->insert(4, 5, 6);
	g->insert(3, 5, 2);

	cout << primMST(g) << '\n';

	system("pause");
}




int Weight(vector<int>& vec, Graph* g) {
	int minWeight = 0;
	for (int i = 1; i < vec.size(); ++i) {
		cout << vec[i] << "-" << i << '\t' << g->getWeight(i, vec[i]) << '\n';
		minWeight += g->getWeight(i, vec[i]);
	}
	return minWeight;
}


int primMST(Graph* g) {
	int size = g->getSize();

	// Пометки, приписываемые вершинам
	vector<int> mark(size, INT_MAX);
	std::for_each(mark.begin(), mark.end(), [](int& elem) { elem = INT_MAX; });

	// Запись вершин  
	vector<int> edges(size);

	// Для проверки наличия вершины в остове
	vector<bool> addedVertices(size);

	edges[0] = -1;
	int minWeight = 0;

	for (int i = 0; i < size; ++i) {
		int theNearestVert = findTheNearestVert(mark, addedVertices);
		addedVertices[theNearestVert] = true;

		for (int j = 0; j < size; ++j) {
			int weight = g->getWeight(theNearestVert, j);

			if (weight > 0 && !addedVertices[j] && mark[j] > weight) {
				mark[j] = weight;
				edges[j] = theNearestVert;
			}
		}
	}
	
	return Weight(edges, g);;
}


int findTheNearestVert(vector<int>& mark, vector<bool>& added) {
	int min = INT_MAX;
	int index = 0;

	for (int i = 0; i < mark.size(); ++i) {
		if (mark[i] < min && !added[i]) {
			min = mark[i];
			index = i;
		}
	}

	return index;
}