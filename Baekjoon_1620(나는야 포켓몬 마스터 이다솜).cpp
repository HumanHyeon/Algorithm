https://www.acmicpc.net/problem/1620

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int N, M;
unordered_map<int, string> numMap;
unordered_map<string, int> stringMap;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string name;	cin >> name;

		numMap.insert(make_pair(i, name));
		stringMap.insert(make_pair(name, i));
	}

	for (int j = 0; j < M; j++) {
		string key;		cin >> key;
		
		if (key[0] >= '1' && key[0] <= '9')
			cout << numMap[stoi(key)] << "\n";
		else
			cout << stringMap[key] << "\n";
	}
}
