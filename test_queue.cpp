//测试队列的使用

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> my_queue;
    my_queue.push(1);
    my_queue.push(2);
    my_queue.push(3);
    cout << my_queue.front() << endl;
    my_queue.pop();
    cout << my_queue.front() << endl;
    my_queue.pop();
    cout << my_queue.front() << endl;
    my_queue.pop();
    cout << my_queue.empty() << endl;
    return 0;
}