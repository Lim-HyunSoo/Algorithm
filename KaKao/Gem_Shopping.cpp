#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer,v;
    map<string, int> m;
    
    int num = 0;
    
    for(int i=0;i<gems.size();i++){
        string str = gems[i];
        if(m[str] == 0)
            m[str] = ++num;
    }
    
    for(int i=0;i<=num;i++)
        v.push_back(0);
    
    int l=0, r=0, cnt=1, len = gems.size(), minLen = len+1, L=0, R=0;
    
    string sr,sl;
    
    int idx = m[gems[0]];
    
    v[idx]++;
    
    while(r<len){
        while(num==cnt || r+1==len){
            if(minLen>r-l && num==cnt){
                minLen = r-l;
                R=r;
                L=l;
            }
            if(l==r) break;
            int idx = m[gems[l++]];
            v[idx]--;
            if(v[idx]==0) cnt--;
        }
        if(r+1==len) break;
        int idx = m[gems[++r]];
        v[idx]++;
        if(v[idx]==1) cnt++;
    }
    answer.push_back(L+1);
    answer.push_back(R+1);
    return answer;
}
