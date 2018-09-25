#include <iostream>
#include <queue>

using namespace std;
bool map[5][5];
int dist[5];

void ladder() {
	queue<pair<int, int>> ladderQ;
	int m = 1, n = 1;

	dist[m] = 0;
	ladderQ.push(make_pair(m, n));

	while (!ladderQ.empty()) {
		pair<int, int> now = ladderQ.front();
		m = now.first;
		n = now.second;
		ladderQ.pop();
		if (now.second <= 5) {
			while (m <= 5) {
				if (map[m][n] == true) {
					m += 1;
					n += 1;
				}
				else {
					if (map[m][n - 1] == true) {
						n -= 1;
					}
					m += 1;
				}
			}
			dist[now.second] = n;
			ladderQ.push(make_pair(1, now.second + 1));
			cout << now.second << "," << dist[now.second] << endl;
		}
	}
}

int main() {
	int N, M, H;
	int a, b;

	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a][b] = true;
	}
	// 사다리게임 
	ladder();
	// d[i]==i 못하겟음~!
}