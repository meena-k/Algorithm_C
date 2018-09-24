#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool map[102][102];

// �����¿�
int dx[] = { 0,-1,0,1 };
int dy[] = { 1,0,-1,0 };

int end_x = 0;
int end_y = 0;

void makeDragon(vector<int> dragon) {
	// ������ ũ�� ���
	int size = (int)dragon.size();

	for (int i = size - 1; i >= 0; i--) {
		int dir = (dragon[i] + 1) % 4;
		
		// Ŀ�� ���� �� ���� ǥ��
		end_x = end_x + dx[dir];
		end_y = end_y + dy[dir];
		map[end_x][end_y] = true;

		// �������� �ֱ�
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

		// �� �� ����
		end_x = x;
		end_y = y;

		// ���� ��ġ ������ ǥ��
		map[end_x][end_y] = true;

		// 0���� ����
		end_x = x + dx[d];
		end_y = y + dy[d];

		// 0���� ������ ǥ��
		map[end_x][end_y] = true;

		dragon.push_back(d);

		// g���� ���� Ŀ�� �����
		while (g--) {
			makeDragon(dragon);
		}
	}

	// ���簢�� �κ�
}