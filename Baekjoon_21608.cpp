https://www.acmicpc.net/problem/21608

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
//int placeOrder[400];
//int hopeNumList[401][4];
//int map[21][21];

#define SIZE 25
int placeOrder[SIZE * SIZE];
int hopeNumList[SIZE * SIZE][4];
int map[SIZE][SIZE];

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };
bool placed[21];
int answer;

void printPosList(vector<pair<int, int>>& posList) {
	cout << "[pos List]" << endl;
	for (auto pos : posList) {
		cout << pos.first << " " << pos.second << endl;
	}
	cout << "[end of Pos List]" << endl;
}

void printMap() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cout << map[y][x] << " ";
		}
		cout << endl;
	}
}

void step1(vector<pair<int, int>>& posList, int student) {
	//좋아하는 학생 수가 가장 많은 곳들 좌표값 넣기
	int hope[4] = { hopeNumList[student][0], hopeNumList[student][1], hopeNumList[student][2], hopeNumList[student][3] };
	int hopeCnt = 0;
	int stdAdj = 0;

	for (int i = 0; i < 4; i++)
		if (placed[hope[i]])	hopeCnt++;
	
//	cout << student << " - " << hopeCnt << "------> ";
//	for (int i = 1; i <= N * N; i++)
//		if (placed[i])	cout << "[" << i << "]";
//	cout << endl;
		
	if (hopeCnt == 0)	return;		//희망 학생이 아무도 없다면

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (map[y][x] == 0) {	//빈 자리
				//놓았을 때 희망 인접 학생이 얼마나 있는가 계산
				int adjCnt = 0;

				for (int flag = 0; flag < 4; flag++) {	//현재 기준 8개 인접 방향 전부 탐색
					int ny = y + dy[flag], nx = x + dx[flag];

					if (ny <= 0 || nx <= 0 || ny > N || nx > N)	continue;
					if (map[ny][nx] != 0)
						for (int i = 0; i < 4; i++)
							if (map[ny][nx] == hope[i])
								adjCnt++;
				}
	//			cout << "[" << y << ", " << x << "] " << adjCnt << endl;
				//기준에 따라 넣는 부분
				if (adjCnt > stdAdj) {
					posList.clear();
					posList.push_back(make_pair(y, x));
					stdAdj = adjCnt;
				}
				else if (adjCnt == stdAdj) {
					posList.push_back(make_pair(y, x));
				}
				else {	//ajdCnt < stdAdj

				}
			}
		}
	}
}

void step2(vector<pair<int, int>>& posList) {
	//인접칸들 개수 세고 posList에 반영
	vector<pair<int, int>> posTmp;
	int stdEmpty = 0;

	if (posList.size() == 0) {
		//cout << "예상 리스트가 없음" << endl;
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				int emptyCnt = 0;

				if (map[y][x] != 0)	continue;
				
				for (int flag = 0; flag < 4; flag++) {	//현재 기준 8개 인접 방향 전부 탐색
					int ny = y + dy[flag], nx = x + dx[flag];

					if (ny <= 0 || nx <= 0 || ny > N || nx > N)	continue;
					if (map[ny][nx] == 0) emptyCnt++;
				}
				
				if (stdEmpty < emptyCnt) {
					posTmp.clear();
					posTmp.push_back(make_pair(y, x));
					stdEmpty = emptyCnt;
				}
				else if (stdEmpty == emptyCnt) {
					posTmp.push_back(make_pair(y, x));
				}
				else {

				}
			}
		}

	}
	else {
		for (auto pos : posList) {
			int y = pos.first, x = pos.second;
			int emptyCnt = 0;

			for (int flag = 0; flag < 4; flag++) {
				int ny = y + dy[flag], nx = x + dx[flag];

				if (ny <= 0 || nx <= 0 || ny > N || nx > N)	continue;
				if (map[ny][nx] == 0) emptyCnt++;
			}

			if (stdEmpty < emptyCnt) {
				posTmp.clear();
				posTmp.push_back(pos);
				stdEmpty = emptyCnt;
			}
			else if (stdEmpty == emptyCnt) {
				posTmp.push_back(pos);
			}
			else {

			}
		}
	}
	posList.clear();
	posList = posTmp;
	//copy(posTmp.begin(), posTmp.end(), posList.begin());
	//cout << posList[0].first << " " << posList[0].second << endl;
}

pair<int, int> step3(const vector<pair<int, int>>& posList) {
	//배치될 좌표 값 반환
	pair<int, int> finalPos;
	//int stdRow = N + 1, stdColumn = N + 1;
	int stdRow = N + 1, stdColumn = N + 1;

	for (auto pos : posList) {
		int y = pos.first, x = pos.second;

		if (stdRow > y) {
			finalPos = pos;
			stdRow = y;
			stdColumn = x;
		}
		else if (stdRow == y) {
			if (stdColumn > x) {
				finalPos = pos;
				stdRow = y;
				stdColumn = x;
			}
			else {	//stdColumn < x

			}
		}
		else {	//stdRow < y

		}
	}

	return (finalPos);
}

void map_place() {
	for (int i = 0; i < N * N; i++) {
		vector<pair<int, int>> posList;
		pair<int, int> pos;
		int student = placeOrder[i];

	//	cout << "<<<<<<<<<<<<< " << student << " >>>>>>>>>>>>>>>>" << endl;
		//printMap();
		step1(posList, student);
		step2(posList);
		//printPosList(posList);
		pos = step3(posList);
		
		map[pos.first][pos.second] = student;
		placed[student] = true;
	}
}

void calc_satisfaction() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			int stdStu = map[y][x];
			int hope[4] = { hopeNumList[stdStu][0], hopeNumList[stdStu][1], hopeNumList[stdStu][2], hopeNumList[stdStu][3] };
			int satisfaction = 0;

			for (int flag = 0; flag < 4; flag++) {	//현재 기준 8개 인접 방향 전부 탐색
				int ny = y + dy[flag], nx = x + dx[flag];

				if (ny <= 0 || nx <= 0 || ny > N || nx > N)	continue;
				for (int i = 0; i < 4; i++)
					if (map[ny][nx] == hope[i])
						satisfaction++;
			}

			if (satisfaction == 0)	answer += 0;
			else if (satisfaction == 1)	answer += 1;
			else if (satisfaction == 2)	answer += 10;
			else if (satisfaction == 3)	answer += 100;
			else answer += 1000;
		}
	}
}

int solution() {
	map_place();	//맵에 학생들 배치
	//printMap();		//디버그를 위해 맵 한 번 찍어봄
	calc_satisfaction();	//만족도 계산
	return (answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);	cin.tie(NULL);

	cin >> N;
	for (int i = 0, stu; i < N * N; i++) {
		cin >> stu;
		placeOrder[i] = stu;
		for (int j = 0, hope; j < 4; j++) {
			cin >> hope;
			hopeNumList[stu][j] = hope;
		}
	}
	cout << solution() << endl;
}
