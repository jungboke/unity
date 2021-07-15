#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    priority_queue<int> l;
    priority_queue<int,vector<int>,greater<int>> r;

    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        if(l.empty() || r.empty()) l.push(x);
        else
        {
            if(x <= l.top()) l.push(x);
            else if(x >= r.top()) r.push(x);
            else l.push(x);
        }

        while(!(l.size() == r.size() || l.size() == r.size()+1))
        {
            if(l.size() > r.size())
            {
                r.push(l.top());
                l.pop();
            }
            else
            {
                l.push(r.top());
                r.pop();
            }
        }
        cout << l.top() << '\n';
    }

    return 0;
}
// priority queue를 활용한 sort시간 단축, c++에서 priority queue는 maxheap
// minheap으로 만들기 위해서는 priority_queue<int,vector<int>,greater<int>> 으로 선언.