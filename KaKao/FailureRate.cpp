/*
실패율을 구하는 코드를 완성하라.

실패율은 다음과 같이 정의한다.
스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수
전체 스테이지의 개수 N, 게임을 이용하는 사용자가 현재 멈춰있는 스테이지의 번호가 담긴 배열 stages가 매개변수로 주어질 때, 실패율이 높은 스테이지부터 내림차순으로 스테이지의 번호가 담겨있는 배열을 return 하도록 solution 함수를 완성하라.

제한사항
1. 스테이지의 개수 N은 1 이상 500 이하의 자연수이다.
2. stages의 길이는 1 이상 200,000 이하이다.
3. stages에는 1 이상 N + 1 이하의 자연수가 담겨있다.
4. 각 자연수는 사용자가 현재 도전 중인 스테이지의 번호를 나타낸다.
5. 단, N + 1 은 마지막 스테이지(N 번째 스테이지) 까지 클리어 한 사용자를 나타낸다.
6. 만약 실패율이 같은 스테이지가 있다면 작은 번호의 스테이지가 먼저 오도록 하면 된다.
7. 스테이지에 도달한 유저가 없는 경우 해당 스테이지의 실패율은 0 으로 정의한다.
입출력 예
N	 |          stages	        |   result
5	 | [2, 1, 2, 6, 2, 4, 3, 3]	| [3,4,2,1,5]
4	 |       [4,4,4,4,4]        | 	[4,1,2,3]
*/

#include <vector>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	vector <int> num(N+1);
	vector <double> cal(N);

	for (int i : stages) {
		num[i - 1]++;
	}

	double sum = num[N];
	for (int i = N-1; i > -1; i--) {
		//cout << i << endl; //1 3 2 1 0 1 
		sum += num[i];
		cal[i] = num[i] / sum;
	}

	double maxN;
	int maxIndex;
	
	for(int i = 0; i < N; i++){
		maxN = cal[0];
		maxIndex = 0;
		
		for (int j = 0; j < N; j++) {
			if (cal[j] > maxN) {
				maxN = cal[j];
				maxIndex = j;
			}
		}
		cal[maxIndex] = -1;
		answer.push_back(maxIndex+1);

	}
	
	return answer;
}
int main() {
    vector <int> testData = { 2, 1, 2, 6, 2, 4, 3, 3 };

	int n = 5;

	vector<int> result = solution(n, testData);

	for (int r : result) {
		cout << r << ' ';
	}
	cout << endl;

	return 0;
}
