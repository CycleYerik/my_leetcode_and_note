#include <unordered_map>
using namespace std;


class LRUCache {
    public:

        struct MyNode{
            int key;
            int value;
            MyNode* pre;
            MyNode* next;
        };

        int size = 0;
        int now_count = 0;
        unordered_map<int,MyNode*> my_map; //存key对应的节点
        MyNode *dummy;
        MyNode *tail;

        LRUCache(int capacity) {
            dummy = new MyNode{0,0,nullptr,nullptr};
            tail = dummy;
            size = capacity;
            now_count = 0;
        }
        
        int get(int key) {
            if(my_map.find(key) != my_map.end())
            {
                int result = my_map[key]->value;
                moveToTail(my_map[key]);
                return result;
            }
            else
            {
                return -1;
            }
        }
        
        void put(int key, int value) {
            if(my_map.find(key) != my_map.end()) //存在
            {
                my_map[key]->value = value;
                moveToTail(my_map[key]);
            }
            else 
            {
                if(now_count == size) //如果满了
                {
                    MyNode* toDelete = dummy->next; //要删除的节点
                    int delete_key = toDelete->key; //要删除的节点的key
                    MyNode* temp = toDelete->next; //要删除的节点的下一个节点
                    delete toDelete; //删除要删除的节点
                    dummy->next = temp; //将dummy的next指向temp
                    if(temp != nullptr) //如果temp不为空，则将temp的pre指向dummy
                    {
                        temp->pre = dummy;
                    }
                    else //如果temp为空，则将tail指向dummy
                    {
                        tail = dummy;
                    }
                    my_map.erase(delete_key); //删除map中的key
                }
                else
                {
                    now_count++; //如果没满，则now_count加1
                }
                MyNode* newNode = new MyNode{key,value,tail,nullptr}; //创建新节点
                tail->next = newNode; //将tail的next指向新节点
                tail = newNode; //将tail指向新节点
                my_map[key] = newNode; //将key映射到新节点
            }
        }

    private:
        // 将节点移到链表尾部
        void moveToTail(MyNode* node) {
            if(node == tail) //如果节点是尾节点，则直接返回
            {
                return;
            }
            MyNode* temp_next = node->next; //进行节点的拼接
            MyNode* temp_pre = node->pre;
            temp_pre->next = temp_next;
            temp_next->pre = temp_pre;
         
            
            node->next = nullptr;
            node->pre = tail;
            tail->next = node;
            tail = node;
        }
};
    
    

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
