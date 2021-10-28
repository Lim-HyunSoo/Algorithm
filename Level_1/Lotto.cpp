/*
문제 설명
로또 6/45(이하 '로또'로 표기)는 1부터 45까지의 숫자 중 6개를 찍어서 맞히는 대표적인 복권입니다. 아래는 로또의 순위를 정하는 방식입니다.
순위	     당첨 내용
1	      6개 번호가 모두 일치
2	      5개 번호가 일치
3	      4개 번호가 일치
4	      3개 번호가 일치
5	      2개 번호가 일치
6(낙첨)	   그 외

로또를 구매한 민우는 당첨 번호 발표일을 학수고대하고 있었습니다. 하지만, 민우의 동생이 로또에 낙서를 하여, 일부 번호를 알아볼 수 없게 되었습니다. 
당첨 번호 발표 후, 민우는 자신이 구매했던 로또로 당첨이 가능했던 최고 순위와 최저 순위를 알아보고 싶어 졌습니다.
알아볼 수 없는 번호를 0으로 표기하기로 하고, 민우가 구매한 로또 번호 6개가 44, 1, 0, 0, 31 25라고 가정해보겠습니다. 
당첨 번호 6개가 31, 10, 45, 1, 6, 19라면, 당첨 가능한 최고 순위와 최저 순위의 한 예는 아래와 같습니다.

당첨 번호	      31	10	45	1	6	19	    |  결과
최고 순위 번호	31	0→10	44	1	0→6	25  |	4개 번호 일치, 3등
최저 순위 번호	31	0→11	44	1	0→7	25	| 2개 번호 일치, 5등

제한사항
1. lottos는 길이 6인 정수 배열입니다.
2. lottos의 모든 원소는 0 이상 45 이하인 정수입니다.
3. 0은 알아볼 수 없는 숫자를 의미합니다.
4. 0을 제외한 다른 숫자들은 lottos에 2개 이상 담겨있지 않습니다.
5. lottos의 원소들은 정렬되어 있지 않을 수도 있습니다.
6. win_nums은 길이 6인 정수 배열입니다.
7. win_nums의 모든 원소는 1 이상 45 이하인 정수입니다.
8. win_nums에는 같은 숫자가 2개 이상 담겨있지 않습니다.
9. win_nums의 원소들은 정렬되어 있지 않을 수도 있습니다.

입출력 예
        lottos	      |         win_nums	        |   result
[44, 1, 0, 0, 31, 25]	|  [31, 10, 45, 1, 6, 19]	  |   [3, 5]
[0, 0, 0, 0, 0, 0]	  |  [38, 19, 20, 40, 15, 25]	|   [1, 6]
[45, 4, 35, 20, 3, 9]	|  [20, 9, 3, 45, 4, 35]	  |   [1, 1]
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zeroCnt = 0;
    int cnt = 0;
    
    for(int lotto : lottos){
        if(lotto == 0) {
                zeroCnt += 1;
                continue;
            }
        for(int num : win_nums){
            if(num == lotto){
                cnt += 1;
                break;
            }
        }
    }
    
    if(zeroCnt == 6){
        answer.push_back(1);
        answer.push_back(6);
    }
    else if(cnt == 0 && zeroCnt == 0){
        answer.push_back(6);
        answer.push_back(6);
    }
    else{
        answer.push_back(7-cnt-zeroCnt);
        answer.push_back(7-cnt);
    }
    
    return answer;
}
