/*
	[BOJ]14891_��Ϲ���.cpp
	��Ϲ��� �¹����ִ� N/S ���� �ٸ��� ȸ��
	1 �� �ð���� , -1�� �ݽð� ����
*/
#include <iostream>
#include <cstring>
using namespace std;

string wheel[5];
int cnt; // ȸ�� Ƚ��
int n, k;

void input();
void solution();
void rotation(int num,int d);
int compute_score();

void input() {
	// 1. ���� �Է� �ޱ�
	for (int i = 1; i <= 4; i++)
		cin >> wheel[i];
	// 2. ȸ�� Ƚ�� �Է¹ޱ�
	cin >> cnt;

	while (cnt--) {
		cin >> n >> k;
		solution();
	}
}
void rotation(int num,int d) {
	// �ݽð� ȸ��
	if (d == -1) {
		string temp = wheel[num].substr(1, 8);
		wheel[num] = temp + wheel[num][0];
	}
	// �ð� ���� ȸ��
	else if (d == 1) {
		string temp = wheel[num].substr(0, 7);
		wheel[num] = wheel[num][7] + temp;
	}
}
void solution() {
	int rotate[5]; // ȸ������ ������ �����ϴ� �迭
	memset(rotate, 0, sizeof(rotate));

	// �ϴ� �Է� ���� �� ȸ�� ����
	rotate[n] = k;

	for (int left = n - 1; left >= 1; left--) {
		if (wheel[left + 1][6] != wheel[left][2]) {
			rotate[left] = -rotate[left+1];
		}
		else {
			rotate[left] = 0;
			break;
		}
	}
	for (int right = n + 1; right <= 4; right++) {
		if (wheel[right - 1][2] != wheel[right][6]) {
			rotate[right] = -rotate[right - 1];
		}
		else {
			rotate[right] = 0;
			break;
		}
	}

	// ����� �迭�� ���� �ѹ��� ȸ��
	for (int i = 1; i <= 4; i++) {
		if (rotate[i] != 0) {
			rotation(i, rotate[i]);
		}
	}
}
int compute_score() {
	int score = 0;

	for (int i = 1; i <= 4; i++)
		if (wheel[i][0] == '1')
			score += pow(2, (i - 1));

	return score;
}
int main() {
	input();
	cout << compute_score() << endl;
	return 0;
}