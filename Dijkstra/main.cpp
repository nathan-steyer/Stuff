#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <climits>
using namespace std;

class edge
{
public:
	int v1, v2, w;
	edge(int v1, int v2, int w)
	{
		this->v1 = v1 - 1;
		this->v2 = v2 - 1;
		this->w = w;
	}
};

void dijkstra(const vector<vector<edge>> &, int, int, vector<int> &, 
	stack<int> &);

int main()
{
	int v1, v2, w, i, j, extend;
	vector<vector<edge>> edges;
	vector<edge> row;

	ifstream ifs("graphdata.txt");
	while (ifs >> v1)
	{
		ifs >> v2 >> w;
		extend = v1 < v2 ? v2 - edges.size() : v1 - edges.size();
		for (i = 0; i < extend; i++)
			edges.push_back(row);
		edges[v1 - 1].push_back(edge(v1, v2, w));
		edges[v2 - 1].push_back(edge(v2, v1, w));
		ifs.ignore();
	}
	ifs.close();

	cout << "\n\nWhat is the starting vertex? ";
	cin >> v1;
	cout << "What is the target vertex? ";
	cin >> v2;
	cin.ignore();

	vector<int> distances(edges.size(), INT_MAX);
	distances[v1 - 1] = 0;
	stack<int> path;
	dijkstra(edges, v1 - 1, v2 - 1, distances, path);
	
	cout << "Weighted:\npath1 = ";
	int steps = path.size();
	for (i = 0; i < steps; i++) {
		cout << path.top() + 1 << " ";
		path.pop();
	}
	cout << "\nd = " << distances[v2 - 1] << endl << endl;
	
	for (i = 0; i < edges.size(); i++)
		for (int j = 0; j < edges[i].size(); j++)
			edges[i][j].w = 1;
	vector<int> distancesU(edges.size(), INT_MAX);
	distancesU[v1 - 1] = 0;
	stack<int> pathU;
	dijkstra(edges, v1 - 1, v2 - 1, distancesU, pathU);

	cout << "Uneighted:\npath2 = ";
	steps = pathU.size();
	for (i = 0; i < steps; i++) {
		cout << pathU.top() + 1 << " ";
		pathU.pop();
	}
	cout << "\nd = " << distancesU[v2 - 1] << endl;

	cin.get();
	return 0;
}

void dijkstra(const vector<vector<edge>> & edges, int start, int target, 
	vector<int> & distances, stack<int> & path)
{
	int i, current;
	
	vector<int> previous(edges.size(), -1);

	set<int> unvisited;
	for (i = 0; i < edges.size(); i++)
		unvisited.insert(i);

	while (!unvisited.empty())
	{
		current = *unvisited.begin();
		for (auto i : unvisited)
			if (distances[i] < distances[current])
				current = i;
		if (current == target) break;
		unvisited.erase(current);

		for (auto neighbor : edges[current])
			if (unvisited.count(neighbor.v2) == 1)
				if (distances[neighbor.v2] > distances[current] + neighbor.w) {
					distances[neighbor.v2] = distances[current] + neighbor.w;
					previous[neighbor.v2] = current;
				}
	}

	while (previous[current] != -1) {
		path.push(current);
		current = previous[current];
	}
	path.push(start);
}