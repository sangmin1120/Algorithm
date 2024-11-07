/*
	[BOJ]14891_톱니바퀴.cpp
	톱니바퀴 맞물려있는 N/S 극이 다르면 회전
	1 은 시계방향 , -1은 반시계 방향
*/
#include <iostream>
#include <cstring>
using namespace std;

string wheel[5];
int cnt; // 회전 횟수
int n, k;

void input();
void solution();
void rotation(int num,int d);
int compute_score();

void input() {
	// 1. 바퀴 입력 받기
	for (int i = 1; i <= 4; i++)
		cin >> wheel[i];
	// 2. 회전 횟수 입력받기
	cin >> cnt;

	while (cnt--) {
		cin >> n >> k;
		solution();
	}
}
void rotation(int num,int d) {
	// 반시계 회전
	if (d == -1) {
		string temp = wheel[num].substr(1, 8);
		wheel[num] = temp + wheel[num][0];
	}
	// 시계 방향 회전
	else if (d == 1) {
		string temp = wheel[num].substr(0, 7);
		wheel[num] = wheel[num][7] + temp;
	}
}
void solution() {
	int rotate[5]; // 회전할지 말지를 저장하는 배열
	memset(rotate, 0, sizeof(rotate));

	// 일단 입력 받은 거 회전 시켜
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

	// 저장된 배열에 따라 한번에 회전
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