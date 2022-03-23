https://www.acmicpc.net/problem/20056

#include <iostream>
#include <vector>
using namespace std;

typedef struct {
	int m;	//질량
	int s;	//속력
	int d;	//방향
}f_data;

int N, M, K;
vector<f_data> map[51][51];
vector<f_data> t_map[51][51];

int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
int answer;

pair<int, int> findPosition(pair<int, int> pos, int d, int s) {
	int y = pos.first, x = pos.second;

	s %= N;
	y += (dy[d] * s);
	x += (dx[d] * s);
	if (y >= N) y -= N;
	if (x >= N) x -= N;
	if (y < 0) y += N;
	if (x < 0) x += N;

	return (make_pair(y, x));
}

void step1() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			t_map[i][j].clear();
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (const auto& fb : map[i][j]) {
				pair<int, int> pos = findPosition(make_pair(i, j), fb.d, fb.s);
				t_map[pos.first][pos.second].push_back({ fb.m, fb.s, fb.d });
			}
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j].clear();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (const auto& fb : t_map[i][j])
				map[i][j] = t_map[i][j];
}

void step2() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			t_map[i][j].clear();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j].size() < 1)	continue;
			if (map[i][j].size() == 1) {
				t_map[i][j].push_back(map[i][j][0]);
				continue;
			}

			f_data fd = { 0, 0, 0 };
			bool odd = true, even = true;

			for (const auto& f : map[i][j]) {
				fd.m += f.m;
				fd.s += f.s;
				if (f.d % 2 == 0)	odd = false;
				else				even = false;
			}

			fd.m /= 5;
			fd.s /= map[i][j].size();
			
			if (fd.m == 0)	continue;

			for (int k = ((even || odd) ? 0 : 1); k < 8; k += 2) {
				t_map[i][j].push_back({ fd.m, fd.s, k });
			}
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j].clear();
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (const auto& fb : t_map[i][j]) {
				map[i][j] = t_map[i][j];
			}
}

int solution() {
	for (int i = 0; i < K; i++) {
		step1();
		step2();
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (const auto& fb : map[i][j])
				answer += fb.m;
	
				
	return (answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		map[r - 1][c - 1].push_back({ m, s, d });
	}
	cout << solution() << endl;
}
