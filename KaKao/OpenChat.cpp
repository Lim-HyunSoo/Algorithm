#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map <string, string> users;
    users.insert(pair<string, string>("uid1234", "Prodo"));
    users.insert(pair<string, string>("uid4567", "Ryan"));

    for (int i = 0; i < int(record.size()); i++) {
        string id;
        int cnt = 0;
        if (record[i][0] == 'E') {
            cnt = 6;
            while (true) {
                if (record[i][cnt] == ' ') {
                    break;
                }
                id += record[i][cnt];
                cnt++;
            }
            answer.push_back(users[id] + "님이 들어왔습니다.");
        }
        else if (record[i][0] == 'L') {
            cnt = 6;
            for(int j = cnt; j < int(record[i].size()); j++){
                id += record[i][j];
            }
            answer.push_back(users[id] + "님이 나갔습니다.");
        }
        else {
            cnt = 7;
            string name;
            while (true) {
                if (record[i][cnt] == ' ') {
                    break;
                }
                id += record[i][cnt];
                cnt++;
            }
     
            for (int j = cnt + 1; j < int(record[i].size()); j++) {
                name += record[i][j];
            }
            users[id] = name;
        }
    }
    return answer;
}

int main() {
    vector <string> testData = { "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" };

    vector <string> result = solution(testData);

    for (string r : result) {
        cout << r << endl;
    }

	return 0;
}
