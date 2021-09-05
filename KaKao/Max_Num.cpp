/*
"100-200*300-500+20"

일반적으로 수학 및 전산학에서 약속된 연산자 우선순위에 따르면 더하기와 빼기는 서로 동등하며 곱하기는 더하기, 빼기에 비해 우선순위가 높아 * > +,- 로 우선순위가 정의되어 있습니다.
대회 규칙에 따라 + > - > * 또는 - > * > + 등과 같이 연산자 우선순위를 정의할 수 있으나 +,* > - 또는 * > +,- 처럼 2개 이상의 연산자가 동일한 순위를 가지도록 연산자 우선순위를 정의할 수는 없습니다.
수식에 연산자가 3개 주어졌으므로 가능한 연산자 우선순위 조합은 3! = 6가지이며, 그 중 + > - > * 로 연산자 우선순위를 정한다면 결괏값은 22,000원이 됩니다.
반면에 * > + > - 로 연산자 우선순위를 정한다면 수식의 결괏값은 -60,420 이지만, 규칙에 따라 우승 시 상금은 절댓값인 60,420원이 됩니다.

참가자에게 주어진 연산 수식이 담긴 문자열 expression이 매개변수로 주어질 때, 우승 시 받을 수 있는 가장 큰 상금 금액을 return 하도록 solution 함수를 완성해주세요.

[제한사항]
1. expression은 길이가 3 이상 100 이하인 문자열입니다.
2. expression은 공백문자, 괄호문자 없이 오로지 숫자와 3가지의 연산자(+, -, *) 만으로 이루어진 올바른 중위표기법(연산의 두 대상 사이에 연산기호를 사용하는 방식)으로 표현된 연산식입니다.
   잘못된 연산식은 입력으로 주어지지 않습니다. 즉, "402+-561*"처럼 잘못된 수식은 올바른 중위표기법이 아니므로 주어지지 않습니다.
3. expression의 피연산자(operand)는 0 이상 999 이하의 숫자입니다. 즉, "100-2145*458+12"처럼 999를 초과하는 피연산자가 포함된 수식은 입력으로 주어지지 않습니다.
   "-56+100"처럼 피연산자가 음수인 수식도 입력으로 주어지지 않습니다.
4. expression은 적어도 1개 이상의 연산자를 포함하고 있습니다.
5. 연산자 우선순위를 어떻게 적용하더라도, expression의 중간 계산값과 최종 결괏값은 절댓값이 9,223,372,036,854,775,807 이하가 되도록 입력이 주어집니다.
6. 같은 연산자끼리는 앞에 있는 것의 우선순위가 더 높습니다.

*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long calc(long long a,long long b, char op)
{
    if(op == '-')   return a-b;
    else if(op == '+')  return a+b;
    else    return a*b;
}

long long solution(string expression) {
    long long answer = 0;
    vector <char> oper_list =  { '*', '+', '-' };
    vector <long long> number;
    vector <char> oper;
    string num = "";
    

    for(int i=0;i<expression.size();i++)
    {
        if(expression[i] == '+' || expression[i] =='*' || expression[i] == '-')
        {
            oper.push_back(expression[i]);
            number.push_back(atoi(num.c_str()));
            num="";
        }
        else    num+= expression[i];  
    }
    number.push_back(atoi(num.c_str()));
    long long _max =0;
    do{
        vector <char> tmp_oper = oper;
        vector <long long> tmp_num = number;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<tmp_oper.size();j++)
            {
                if(tmp_oper[j] == oper_list[i])
                {
                    tmp_num[j] = calc(tmp_num[j],tmp_num[j+1],oper_list[i]);
                    tmp_num.erase(tmp_num.begin()+j+1);
                    tmp_oper.erase(tmp_oper.begin()+j);
                    j--;
                }
            }
        } 
        if(_max < abs(tmp_num[0]))   _max = abs(tmp_num[0]);
    }while(next_permutation(oper_list.begin(),oper_list.end()));
    answer = _max;
    return answer;
}
