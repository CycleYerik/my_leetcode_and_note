
//!初始模拟
#include <iostream>
#include <vector>
using namespace std;

int main() {
    
    int N,M;

    cin >> N;

    vector<vector<int>> numbers(N,vector<int>(2,0));

    for(int i = 0 ; i < N ; i++)
    {
        cin >> numbers[i][0];
    }

    int result = N;

    cin >> M;
    for(int i = 0 ; i < M ; i++)
    {
        int target = 0;
        cin >> target;

        if(numbers[target][1] != 0) //无效标识
        {
            continue;
        }

        while(target > 0 && numbers[target][1] != -1) //重复进行组合
        {
            int pre = target-1;
            while(numbers[pre][1] == -1) //找到下层的有效值
            {
                pre --; //可能越界
            }
            if(numbers[target][0] == numbers[pre][0]) 
            {
                numbers[pre][0]++;
                numbers[target][1] = -1; //无效了
                numbers[pre][1] = 1; //无标识了
                target = pre;
                result--;
            }
            else
            {
                break;
            }

        }
    }
    cout << result <<endl;


}
// 64 位输出请用 printf("%lld")


//! ========== 标准写法（逻辑同初版，结构更清晰 + 边界安全） ==========
// 注意：同一文件只能有一个 main。使用本段时请注释掉上方 main。

#include <iostream>
#include <vector>

enum LayerState {
    TAG_VALID = 0,  // 原始身份标识仍有效
    HIDDEN    = 1,  // 融合隐藏款，不可被点名升级
    GONE      = -1  // 槽位已空
};

struct Layer {
    int flavor;
    LayerState state;
};

// 找 cur 正下方第一个非 GONE 的层；不存在返回 -1
int findBelow(int cur, const std::vector<Layer>& layers) {
    int p = cur - 1;
    while (p >= 0 && layers[p].state == GONE) {
        --p;
    }
    return p;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<Layer> layers(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> layers[i].flavor;
        layers[i].state = TAG_VALID;
    }

    int remain = N;

    int M;
    std::cin >> M;
    while (M--) {
        int tag;
        std::cin >> tag;

        if (layers[tag].state != TAG_VALID) {
            continue;
        }

        int cur = tag;
        while (cur > 0 && layers[cur].state != GONE) {
            const int below = findBelow(cur, layers);
            if (below < 0) {
                break;
            }
            if (layers[cur].flavor != layers[below].flavor) {
                break;
            }

            layers[below].flavor += 1;
            layers[cur].state = GONE;
            layers[below].state = HIDDEN;
            cur = below;
            --remain;
        }
    }

    std::cout << remain << '\n';
    return 0;
}


//! ========== 最推荐：静态双向链表模拟（O(M+N)，邻居 O(1)） ==========
// 思路：标识固定在下标上，但「当前还活着的层」用 prev/next 串成链表。
// 融合时 O(1) 找正下层、O(1) 删上层，避免数组版反复跳过 GONE 槽位。
// 注意：同一文件只能有一个 main。使用本段时请注释掉上方所有 main。

#include <iostream>
#include <vector>

struct Node {
    int flavor;
    int state;  // 0=有标识  1=隐藏  -1=已空（已从链表摘除）
    int prev;   // 链表中的正下层，-1 表示没有
    int next;   // 链表中的正上层，-1 表示没有
};

static void removeFromList(int u, std::vector<Node>& a) {
    if (a[u].prev != -1) {
        a[a[u].prev].next = a[u].next;
    }
    if (a[u].next != -1) {
        a[a[u].next].prev = a[u].prev;
    }
    a[u].state = -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<Node> a(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> a[i].flavor;
        a[i].state = 0;
        a[i].prev = (i == 0 ? -1 : i - 1);
        a[i].next = (i == N - 1 ? -1 : i + 1);
    }

    int remain = N;

    int M;
    std::cin >> M;
    while (M--) {
        int tag;
        std::cin >> tag;

        if (a[tag].state != 0) {  // 已消失或隐藏款，不能升级
            continue;
        }

        int cur = tag;
        while (true) {
            const int below = a[cur].prev;
            if (below == -1) {
                break;
            }
            if (a[cur].flavor != a[below].flavor) {
                break;
            }

            a[below].flavor += 1;
            a[below].state = 1;  // 融合后变为隐藏款
            removeFromList(cur, a);  // 上层从链表移除
            cur = below;
            --remain;
        }
    }

    std::cout << remain << '\n';
    return 0;
}
