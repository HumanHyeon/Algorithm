#include <iostream>
#include <vector>
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))
#define ABS(X, Y) ((X - Y > 0) ? (X - Y) : (Y - X))
using namespace std;

int N;
vector<vector<int> > S;
int answer;

void calcAbility(vector<int>& teamA, vector<int>& teamB){
	int sumA = 0, sumB = 0;

	for (int i = 0; i < N / 2; i++){
		int sourceA = teamA[i], sourceB = teamB[i];

		for (int j = 0; j < N / 2; j++)	{
			int destA = teamA[j], destB = teamB[j];
			sumA += S[sourceA][destA];
			sumB += S[sourceB][destB];
		}	
	}

	answer = MIN(answer, abs(sumA - sumB));
}

void sperateTeam(vector<int>& teamA, vector<int>& teamB, int depth = 0, int index = 1){
	if (depth == N / 2){
		for (int i = 1, ctrlA = 0, ctrlB = 0; i <= N; i++)
			if (teamA[ctrlA] == i)
				ctrlA++;
			else 
				teamB[ctrlB++] = i;
		calcAbility(teamA, teamB);
		return ;
	}

	for (int who = index; who <= N; who++){
		teamA[depth] = who;
		sperateTeam(teamA, teamB, depth + 1, who + 1);
	}
}

void solution(){
	vector<int> teamA(N / 2);
	vector<int> teamB(N / 2);	
	sperateTeam(teamA, teamB);
}

int main(){
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);	cin.tie(NULL);

	cin >> N;
	S.resize(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> S[i][j];
	answer = 987654321;
	solution();
	cout << answer << endl;
}
