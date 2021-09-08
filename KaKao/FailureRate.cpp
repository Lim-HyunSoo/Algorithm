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

#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
bool Cmp(pair<double, int> A, pair<double, int> B)
{
    if (A.first >= B.first)
    {
        if (A.first == B.first)
        {
            if (A.second < B.second)
            {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}
 
vector<int> solution(int N, vector<int> stages) 
{
    vector<int> answer;
    vector<pair<double, int>> Fail;
    for (int i = 1; i <= N; i++)
    {
        int Cur_Stage = i;
        int Clear_Num = 0;
        int Progress_Num = 0;
        for (int j = 0; j < stages.size(); j++)
        {
            if (stages[j] >= Cur_Stage) Clear_Num++;
            if (stages[j] == Cur_Stage) Progress_Num++;
        }
        if (Clear_Num == 0) Fail.push_back(make_pair(0, Cur_Stage));
        else
        {
            double FailPercent = (double)Progress_Num / (double)Clear_Num;
            Fail.push_back(make_pair(FailPercent, Cur_Stage));
        }
    }
    sort(Fail.begin(), Fail.end(), Cmp);
    for (int i = 0; i < Fail.size(); i++) answer.push_back(Fail[i].second);
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
