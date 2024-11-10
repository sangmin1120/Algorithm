/*
	[PGS]¿Ë¾ËÀÌ(1).cpp
	"aya","ye","woo",ma"
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> words;

void input();
void solution(vector<string> babbling);

void input() {
	string input;
	getline(cin, input);

	// '[',']' °ýÈ£ Á¦°Å
	input.erase(input.begin());
	input.pop_back();

	stringstream ss(input);
	string word;

	// white label Á¦°Å
	while (getline(ss, word, ',')) {
		word.erase(remove(word.begin(),word.end(),'"'), word.end());
		word.erase(remove(word.begin(), word.end(), ' '), word.end());
		words.push_back(word);
	}

	// debug
	for (const auto& w : words) {
		cout << w << '\n';
	}
}
void solution(vector<string> inputs) {

}
int main() {
	input();

	// solution(words);

	return 0;
}