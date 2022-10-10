#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int S;

int solution() {
	queue<tuple<int, int, int>> q;
	bool vistied[1001][1001] = { {false, }, };
	int answer = -1;

	q.push(make_tuple(1, 0, 0));	//display, cilpboard, time
	while (!q.empty()) {
		int display = get<0>(q.front()), clipboard = get<1>(q.front()), time = get<2>(q.front());
		q.pop();

		if (display == S) {
			answer = time;
			break;
		}
		else if (display > S || display < 0)	continue;
		

		//1번 클립보드로 이동
		if (!vistied[display][display]) {
			vistied[display][display] = true;
			q.push(make_tuple(display, display, time + 1));
		}

		//2번 클립보드 내용 붙여넣기
		if (display + clipboard <= 1000) {
			if (!vistied[display + clipboard][clipboard]) {
				vistied[display + clipboard][clipboard] = true;
				q.push(make_tuple(display + clipboard, clipboard, time + 1));
			}
		}

		//3번 화면에 있는 이모티콘 하나 삭제
		if (!vistied[display - 1][clipboard]) {
			vistied[display - 1][clipboard] = true;
			q.push(make_tuple(display - 1, clipboard, time + 1));
		}
	}
	return (answer);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	cin >> S;
	cout << solution() << endl;
}
