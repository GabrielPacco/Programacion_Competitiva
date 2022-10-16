#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

string getInput();

int main() {
	int N;
	cin >> N;
	unordered_map<string,int> popularidad;
	for (int i = 0; i < N; i++) {
		string estudiante = getInput();
		if (popularidad.count(estudiante) == 0) {
			popularidad[estudiante] = 1;
		}
		else {
			popularidad[estudiante] = popularidad[estudiante] + 1;

		}
	}

	int count = 0;
	int bestNum = 0;
	for (unordered_map<string,int>::iterator it = popularidad.begin(); it != popularidad.end(); it++) {
		if (it->second > bestNum) {
			count = 0;
			bestNum = it->second;
		}
		if (it->second == bestNum) {
			count += 1;
		}
	}
	cout << bestNum * count << endl;

}

string getInput() {
	string result;
	vector<int> schedule;
	int item;
	for (int j = 0; j < 5; j++) {
		cin >> item;
		schedule.insert(schedule.end(), item);
	}
	sort(schedule.begin(), schedule.end());
	for (int j = 0; j < 5; j++) {
		result += to_string(schedule.at(j));
	}
	return result;
}