#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int N;
    vector<int> numbers;

    cin >>N;
    
    int temp_num = 0;
    for(int i = 0; i < N ; i++)
    {
        cin >> temp_num;
        numbers.push_back(temp_num);
    }

    int start = 0, end = 0;

    vector<int> length;
    vector<int> start_indexs;
    vector<int> end_indexs;
    int count = 0;

    for(int i = 0 ; i < N ; i++)
    {
        if(numbers[i] >= 18 && numbers[i] <= 24)
        {
            int start = i, end = i; 
            int min_number = numbers[i], max_number = numbers[i];
            for(int j = i+1; j < N ; j++)
            {
                if(numbers[j] >= 18 && numbers[j] <= 24 )
                {
                    min_number = min(min_number,numbers[j]);
                    max_number = max(max_number,numbers[j]);
                    if(max_number - min_number <= 4)
                    {
                        end ++;
                        continue;
                    }
                    else {
                        break;
                    }
                }
                else 
                {
                    break;
                }
            }
            length.push_back(end - start + 1);
            start_indexs.push_back(start);
            end_indexs.push_back(end);

        }
    }

    int max_length = 0;
    for(auto temp : length)
    {
        if(temp > max_length)
        {
            max_length = temp;
        }
    }

    for(int i = 0 ; i < length.size() ; i++)
    {
        if(length[i] == max_length)
        {
            cout << start_indexs[i] << " " << end_indexs[i] <<endl;
        }
    }


}
// 64 位输出请用 printf("%lld")



#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int maxLen = 0;
    vector<pair<int, int>> ans;

    multiset<int> window; //用multiset可以直接获取最大值和最小值
    int left = 0;

    for (int right = 0; right < n; right++) {
        // 约束1：必须在 [18, 24]
        if (a[right] < 18 || a[right] > 24) {
            window.clear();
            left = right + 1;
            continue;
        }

        window.insert(a[right]);

        // 约束2：max - min <= 4
        while (!window.empty() && *window.rbegin() - *window.begin() > 4) {
            window.erase(window.find(a[left]));
            left++;
        }

        int len = right - left + 1;
        if (len > maxLen) {
            maxLen = len;
            ans.clear();
            ans.push_back({left, right});
        } else if (len == maxLen && maxLen > 0) {
            ans.push_back({left, right});
        }
    }

    for (auto& p : ans) {
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);

    int bestLen = 0;
    vector<pair<int,int>> results;
    int left = 0;
    deque<int> maxq, minq;

    for(int right = 0; right < n; right++){
        if(a[right] < 18 || a[right] > 24){ //如果不在，队列直接清空
            left = right + 1;
            maxq.clear();
            minq.clear();
            continue;
        }
        while(!maxq.empty() && a[maxq.back()] <= a[right]) maxq.pop_back(); //如果队列不为空，并且队列尾部的值小于等于当前值，则队列尾部的值出队
        maxq.push_back(right);
        while(!minq.empty() && a[minq.back()] >= a[right]) minq.pop_back(); //如果队列不为空，并且队列尾部的值大于等于当前值，则队列尾部的值出队
        minq.push_back(right);

        //做到这里，队列中存储的值就是当前窗口内的最大值和最小值

        while(a[maxq.front()] - a[minq.front()] > 4){
            left++;
            if(maxq.front() < left) maxq.pop_front();
            if(minq.front() < left) minq.pop_front();
        }

        int len = right - left + 1;
        if(len > bestLen){
            bestLen = len;
            results.clear();
            results.push_back({left, right});
        } else if(len == bestLen){
            results.push_back({left, right});
        }
    }

    for(auto& p : results)
        printf("%d %d\n", p.first, p.second);
    return 0;
}


#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    
    int N;
    vector<int> numbers;

    cin >>N;
    
    int temp_num = 0;
    for(int i = 0; i < N ; i++)
    {
        cin >> temp_num;
        numbers.push_back(temp_num);
    }

    int left = 0, right = 0;

    vector<pair<int,int>> result;
    int max_length = 0;


    deque<int> max_queue;
    deque<int> min_queue;

    for(right = 0; right < numbers.size() ; right++)
    {
        if(numbers[right] < 18 || numbers[right] > 24) //如果不满足，立刻清零
        {
            max_queue.clear();
            min_queue.clear();
            left = right + 1;
            continue;;
        }

        //开始更新队列
        while(!max_queue.empty() && numbers[max_queue.back()] <= numbers[right] )
        {
            max_queue.pop_back();
        }
        max_queue.push_back(right);
        while(!min_queue.empty() && numbers[min_queue.back()] >= numbers[right])
        {
            min_queue.pop_back();
        }
        min_queue.push_back(right);

        //收缩，看是否满足条件
        while(numbers[max_queue.front()] - numbers[min_queue.front()] > 4)
        {
            left++;
            if(max_queue.front() < left)
            {
                max_queue.pop_front();
            }
            if(min_queue.front() < left)
            {
                min_queue.pop_front();
            }
        }

        //此时满足条件了
        int length = right - left + 1;
        if(length > max_length)
        {
            result.clear();
            result.push_back({left,right});
            max_length = length;
        }
        else if(length == max_length)
        {
            result.push_back({left,right});
        }


    }

    for(auto temp: result)
    {
        cout << temp.first << " " << temp.second <<endl;
    }
    


}
// 64 位输出请用 printf("%lld")