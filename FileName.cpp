#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int find(int* parent, int u) {
	return (parent[u] < 0) ? u : parent[u] = find(parent, parent[u]);
}

void uniComps(int* parent, int* s, int& numOfComps, int u, int v) {
	int root_u = find(parent, u);
	int root_v = find(parent, v);
	if (root_u != root_v) {
		if (s[root_u] > s[root_v])
			std::swap(root_u, root_v);
		s[root_v] += s[root_u];
		parent[root_u] = root_v;
		numOfComps--;		
	}
}

int main() {
	std::ifstream fin("input.txt");
	std::ofstream fout("output.txt");

	int n, q;
	fin >> n >> q;
	//std::cin >> n >> q;
	int numOfComps = n;
	int* parent = new int[n + 1];
	int* s = new int[n + 1];
	std::vector<int>result;

	for (int i = 1; i <= n; ++i) {
		parent[i] = -1;
		s[i] = 1;
	}

	int u, v;
	for (int i = 0; i < q; ++i) {
		fin >> u >> v;
		//std::cin >> u >> v;
		uniComps(parent, s, numOfComps, u, v);
		result.push_back(numOfComps);
	}
	
	for (auto& r : result) {
		fout << r << std::endl;
		//std::cout << r << std::endl;
	}
}