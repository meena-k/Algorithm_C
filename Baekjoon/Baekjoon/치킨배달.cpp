#include <iostream>
#include <queue>
#include <list>
#include <cmath>
#include <map>

using namespace std;
int N, M;
int bestChicken;
list<int> chicken;
int totalDist;
map<int, int> chickenMap;

bool* home = new bool[2 * N];

int* findDistance(int* sMap) {
	totalDist = 0;
	queue<int> queue;
	map<int, int>::iterator iter;

	for (int i = 0; i < N*N; i++) {
		if (sMap[i] == 1) {
			queue.push(i);
		}
	}

	while (!queue.empty()) {
		int now = queue.front();
		int	min = 100;
		queue.pop();

		for (iter = chickenMap.begin(); iter != chickenMap.end(); iter++) {
			int dist = (abs((now / 5) - ((*iter).first / 5)) + abs((now % 5) - ((*iter).first % 5)));
			if (min > dist) {
				min = dist;
				bestChicken = (*iter).first;
			}
		}
		totalDist += min;
		chickenMap[bestChicken]++;
	}

	// M개 제외하고 치킨집->빈집
	while (chickenMap.size() != M) {
		int min = 100;
		int minChicken;
		for (iter = chickenMap.begin(); iter != chickenMap.end(); iter++) {
			if ((*iter).second < min) {
				min = (*iter).second;
				minChicken = (*iter).first;
			}
		}
		chickenMap.erase(minChicken);
		sMap[minChicken] = 0;
	}

	return sMap;
}


int main()
{
	scanf_s("%d %d", &N,&M);
	//cin >> N >> M;
	int* sMap = new int[N];

	for (int i = 0; i < N*N; i++) {
		scanf_s("%d", &sMap[i]);
	//	cin >> sMap[i];
		if (sMap[i] == 2) {
			chicken.push_back(i);
			chickenMap[i] = 0;
		}
	}

	findDistance(findDistance(sMap));

	cout << totalDist;
}
