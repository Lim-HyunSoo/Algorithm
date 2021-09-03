/*
다음은 숫자의 일부 자릿수를 영단어로 바꾸는 예시입니다.

1478 → "one4seveneight"
234567 → "23four5six7"
10203 → "1zerotwozero3"
이렇게 숫자의 일부 자릿수가 영단어로 바뀌어졌거나, 혹은 바뀌지 않고 그대로인 문자열 s가 매개변수로 주어집니다. s가 의미하는 원래 숫자를 return 하도록 solution 함수를 완성해주세요.

int solution(string s) {
    int answer = 0;

    string num_str[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int len = s.length();

    for (int i = 0; i < len; i++) {
        if (s[i]  >= '0' && s[i] <= '9') {
            answer = answer * 10 + s[i] - '0';
        }
        else {
            for (int j = 0; j < 10; j++) {
                if(!num_str[j].compare(0, num_str[j].length(), s, i, num_str[j].length())) {
                    answer = answer * 10 + j;
                }
            }

        }
    }  

    return answer;
}

*/
#include <string>
#include <vector>
#include <iostream>

int solution(string s) {
    int answer = 0;
    vector <string> nums = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    int ind = 0;
    string num = "";

    while (ind < s.length()) {
        if (int(s[ind]) < 58) {
            if (answer != 0) {
                answer *= 10;
            }
            answer += (int(s[ind]) - 48);
            ind++;
        }

        else {
            num = s.substr(ind, 3);
            ind += 3;
            bool isFind = false;

            while (true) {
                for (int i = 0; i < int(nums.size()); i++) {
                    if (nums.at(i) == num) {
                        isFind = true;
                        if (answer != 0) {
                            answer *= 10;
                        }
                        answer += i;
                        break;
                    }
                }

                if (isFind) {
                    break;
                }
                else {
                    num += s[ind];
                    ind++;
                }
            }
        }
    }

    return answer;
}

int main() {
    
    string s = "one4seveneight";

    cout << solution(s) << endl;

	return 0;
}
