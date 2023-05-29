//	Week 5 -- Vectors, iterators, and algorithms

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main() {
	cout << "We stumble upon an arcade game.\n";
	cout << "It's Aladdin's Castle.\n";
	srand(time(0));
	vector<int> scores;
	for(int i = 0; i < 10; i++) {
		scores.push_back((rand() % 4500) + 500);
		cout << i + 1 << ", " << scores[i] << endl;
	}

	cout << "Why are they random? Let's sort these scores out.\n";
	sort(scores.begin(), scores.end());
	reverse(scores.begin(), scores.end());
	cout << "The high scores: \n";

	for(int i = 0; i < 10; i++) {
		scores.push_back((rand() % 4500) + 500);
		cout << i + 1 << ", " << scores[i] << endl;
	}

	cout << "Video games are cool!  Let's randomize these scores.\n";
	cout << "Just because we can.\n";
	random_shuffle(scores.begin(), scores.end());
	cout << "The Scores: \n";
	for(int i = 0; i < 10; i++) {
		scores.push_back((rand() % 4500) + 500);
		cout << i + 1 << ", " << scores[i] << endl;
	}

	cout << "We play a few rounds, but we're WAY out of practice.\n";
	vector<int> myScores;
	for(int i = 0; i < 10; i++) {
		myScores.push_back((rand() % 150) + 50);
		cout << i + 1 << ", " << myScores[i] << endl;
	}

	cout << "Here are our scores with the other high scores.\n";
	vector<int> allScores(scores.size() + myScores.size());
	merge(scores.begin(), scores.end(),
			myScores.begin(), myScores.end(),
			allScores.begin());
	sort(allScores.begin(), allScores.end());
	reverse(allScores.begin(), allScores.end());
	cout << "The scores: \n";
	for(int i = 0; i < allScores.size(); i++) {
		cout << i + 1 << ", " << allScores[i] << endl;
	}
	// 10 high scores to vector random, between 500 and 5000 4500+500
	return 0;
}
