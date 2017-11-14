/* Anagrams by Stack */
/* 《算法设计与分析》P25 */
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

string a, b;
vector<char> opearate;
stack<char> build;
int length;

void dfs(int iPush, int iPop)
{
    // 打印成功构造目标单词时的操作序列
    if (iPush == length && iPop == length)
    {
        for (int i = 0; i < length * 2; i++)
        {
            cout << opearate[i] << " ";
        }
        cout << endl;
    }

    // 入栈操作
    if (iPush + 1 <= length)
    {
        build.push(a[iPush]);
        opearate.push_back('i');
        dfs(iPush + 1, iPop);
        build.pop();
        opearate.pop_back();
    }

    // 出栈操作
    if (iPop + 1 <= iPush && build.top() == b[iPop])
    {
        char c = build.top();
        build.pop();
        opearate.push_back('o');
        dfs(iPush, iPop + 1);
        build.push(c);
        opearate.pop_back();
    }
}

int main()
{
    while (cin >> a >> b)
    {
        length = a.length();
        cout << '[' << endl;
        dfs(0, 0);
        cout << ']' << endl;
    }
}
