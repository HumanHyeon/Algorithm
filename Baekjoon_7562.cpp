https://www.acmicpc.net/problem/7562

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int I;
pair<int, int> Start, End;
int answer;

const int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };
vector<vector<bool>> visited;

bool promising(int y, int x) {
   if (y < 0 || x < 0 || y >= I || x >= I)
      return (false);
   if (visited[y][x] || answer != 0)
      return (false);
   return (true);
}

void solution() {
   queue<pair<pair<int, int>, int>> bfs;
   
   bfs.push(make_pair(make_pair(Start.first, Start.second), 0));
   visited[Start.first][Start.second] = true;
   
   while (!bfs.empty()) {
      int y, nextY;
      int x, nextX;
      int cycle;

      y = bfs.front().first.first;
      x = bfs.front().first.second;
      cycle = bfs.front().second;
      bfs.pop();

      if (y == End.first && x == End.second) {
         answer = cycle;
         return;
      }
      for (int flag = 0; flag < 8; flag++) {
         nextY = y + dy[flag];
         nextX = x + dx[flag];

         if (promising(nextY, nextX)) {
            bfs.push(make_pair(make_pair(nextY, nextX), cycle + 1));
            visited[nextY][nextX] = true;
         }
      }
   }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(NULL);   cout.tie(NULL);

   int cycle;
   
   cin >> cycle;
   for (int i = 0; i < cycle; i++) {
      cin >> I;
      cin >> Start.first >> Start.second;
      cin >> End.first >> End.second;

      answer = 0;
      visited.resize(I, vector<bool>(I, false));
      solution();
      visited.clear();
      cout << answer << endl;
   }
}
