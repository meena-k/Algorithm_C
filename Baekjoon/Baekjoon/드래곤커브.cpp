#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool map[102][102];

// 상하좌우
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };

int end_x = 0;
int end_y = 0;

void makeDragon(vector<int> dragon) {
	// 스택의 크기 계산
	int size = (int)dragon.size();

	for (int i = size - 1; i >= 0; i--) {
		int dir = (dragon[i] + 1) % 4;
		
		// 커브 생성 후 지도 표시
		end_x = end_x + dx[dir];
		end_y = end_y + dy[dir];
		map[end_x][end_y] = true;

		// 방향정보 넣기
		dragon.push_back(dir);
	}

}

int main() {
	int n;
	int x, y, d, g;

	cin >> n;
	while (n--) {
		cin >> x >> y >> d >> g;

		vector<int> dragon;

		// 끝 점 갱신
		end_x = x;
		end_y = y;

		// 현재 위치 지도에 표시
		map[end_x][end_y] = true;

		// 0세대 생성
		end_x = x + dx[d];
		end_y = y + dy[d];

		// 0세대 지도에 표시
		map[end_x][end_y] = true;

		dragon.push_back(d);

		// g세대 까지 커브 만들기
		while (g--) {
			makeDragon(dragon);
		}
	}

	// 정사각형 부분
}