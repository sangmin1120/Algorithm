/*
	[PGS]옹알이(1).cpp => 문자열 다루기
	ex) ["aya","ye","woo",ma"] 1
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> words;

void input();
int solution(vector<string> babbling);

void input() {
	string input;
	getline(cin, input);

	// '[',']' 괄호 제거
	input.erase(input.begin());
	input.pop_back();

	stringstream ss(input);
	string word;

	// white label 제거
	while (getline(ss, word, ',')) {
		word.erase(remove(word.begin(),word.end(),'"'), word.end());
		word.erase(remove(word.begin(), word.end(), ' '), word.end());
		words.push_back(word);
	}

	// debug
	//for (const auto& w : words) {
	//	cout << w << '\n';
	//}
}
int solution(vector<string> inputs) {
	int ans = 0;

	// 1. inputs
	for (auto& input : inputs) {
		bool check = false;

		for (int j = 0; j < input.size(); j++) {
			if (input.substr(j, 3) == "aya") j += 2;
			else if (input.substr(j, 2) == "ye") j += 1;
			else if (input.substr(j, 3) == "woo") j += 2;
			else if (input.substr(j, 2) == "ma") j += 1;
			else {
				check = true;
				break;
			}
		}
		if (!check) ans++;
	}

	return ans;
}
int main() {
	input();

	cout << solution(words) << endl;

	return 0;
}