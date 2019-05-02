#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <utility>
using namespace std;

int word_analysis(vector<pair<string, int>>& word, const string expr)
{
    for(int i=0; i<expr.length(); ++i)
    {
        // 如果是 + - * / ( )
        if(expr[i] == '(' || expr[i] == ')' || expr[i] == '+'
            || expr[i] == '-' || expr[i] == '*' || expr[i] == '/')
        {
            string tmp;
            tmp.push_back(expr[i]);
            switch (expr[i])
            {
            case '+':
                word.push_back(make_pair(tmp, 1));
                break;
            case '-':
                word.push_back(make_pair(tmp, 2));
                break;
            case '*':
                word.push_back(make_pair(tmp, 3));
                break;
            case '/':
                word.push_back(make_pair(tmp, 4));
                break;
            case '(':
                word.push_back(make_pair(tmp, 6));
                break;
            case ')':
                word.push_back(make_pair(tmp, 7));
                break;
            }
        }
        // 如果是数字开头
        else if(expr[i]>='0' && expr[i]<='9')
        {
            string tmp;
            while(expr[i]>='0' && expr[i]<='9')
            {
                tmp.push_back(expr[i]);
                ++i;
            }
            if(expr[i] == '.')
            {
                ++i;
                if(expr[i]>='0' && expr[i]<='9')
                {
                    tmp.push_back('.');
                    while(expr[i]>='0' && expr[i]<='9')
                    {
                        tmp.push_back(expr[i]);
                        ++i;
                    }
                }
                else
                {
                    return -1;  // .后面不是数字，词法错误
                }
            }
            word.push_back(make_pair(tmp, 5));
            --i;
        }
        // 如果以.开头
        else
        {
            return -1;  // 以.开头，词法错误
        }
    }
    return 0;
}

// 获取运算符的优先级
int prior(int sym)
{
    switch (sym)
    {
        case 1:
        case 2:
            return 1;
        case 3:
        case 4:
            return 2;
        default:
            return 0;
    }
}

// 通过 种别编码 判定是否是运算符
bool isOperator(int sym)
{
    switch (sym)
    {
        case 1:
        case 2:
        case 3:
        case 4:
            return true;
        default:
            return false;
    }
}

vector<pair<string, int>> getPostfix(const vector<pair<string, int>>& expr)
{
    vector<pair<string, int>> output;  // 输出
    stack<pair<string, int>> s;  // 操作符栈
    for(int i=0; i<expr.size(); ++i)
    {
        pair<string, int> p = expr[i];
        if(isOperator(p.second))
        {
            while(!s.empty() && isOperator(s.top().second) && prior(s.top().second)>=prior(p.second))
            {
                output.push_back(s.top());
                s.pop();
            }
            s.push(p);
        }
        else if(p.second == 6)
        {
            s.push(p);
        }
        else if(p.second == 7)
        {
            while(s.top().second != 6)
            {
                output.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        else
        {
            output.push_back(p);
        }
    }
    while (!s.empty())
    {
        output.push_back(s.top());
        s.pop();
    }
    return output;
}

// 从栈中连续弹出两个操作数
void popTwoNumbers(stack<double>& s, double& first, double& second)
{
    first = s.top();
    s.pop();
    second = s.top();
    s.pop();
}

// 把string转换为double
double stringToDouble(const string& str)
{
    double d;
    stringstream ss;
    ss << str;
    ss >> d;
    return d;
}

// 计算后缀表达式的值
double expCalculate(const vector<pair<string, int>>& postfix)
{
    double first,second;
    stack<double> s;
    for(int i=0; i<postfix.size(); ++i)
    {
        pair<string,int> p = postfix[i];
        switch (p.second)
        {
        case 1:
            popTwoNumbers(s, first, second);
            s.push(second+first);
            break;
        case 2:
            popTwoNumbers(s, first, second);
            s.push(second-first);
            break;
        case 3:
            popTwoNumbers(s, first, second);
            s.push(second*first);
            break;
        case 4:
            popTwoNumbers(s, first, second);
            s.push(second/first);
            break;
        default:
            s.push(stringToDouble(p.first));
            break;
        }
    }
    double result = s.top();
    s.pop();
    return result;
}

int main()
{
    string expr = "()+()+100*100+100*(1 +1)";
    vector<pair<string, int>> word;
    int err_num = word_analysis(word, expr);
    if (-1 == err_num)
        cout << "Word Error!" << endl;
    else
    {
        double result = expCalculate(getPostfix(word));
        cout << expr + " = " << result << endl;
    }
    return 0;
}
