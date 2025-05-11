// 我的屎山，主要问题还是索引的越界情况不明，未引入尾指针，

class MyLinkedList {
public:

    struct node{
        int val;
        node* next;
        node(int x):val(x),next(nullptr){}
    };

    MyLinkedList() {
        void_head = new node(0);
        size = 0;
    }
    
    int get(int index) {
        int count = 0;
        node* temp = void_head->next;
        if(index <0 || index >= size)
        {
            return -1;
        }
        while(count < index)
        {
            count ++;
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        node* new_node = new node(val);
        new_node->next = void_head->next;
        void_head->next = new_node;
        size ++;

    }
    
    void addAtTail(int val) {
        node* new_node = new node(val);
        node *temp = void_head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index == size)
        {
            addAtTail(val);
        }
        else if(index == 0)
        {
            addAtHead(val);
        }
        else if(index < size && index >0)
        {
            node*temp = new node(val);
            node*temp_head = void_head;
            int count = 0;
            while(count < index)
            {
                count ++;
                temp_head = temp_head->next;
            }
            node* temp_node_store = temp_head->next;
            temp_head->next = temp;
            temp->next = temp_node_store;
            size++;
        }
        
    }
    
    void deleteAtIndex(int index) {
    if (index < 0 || index >= size) return;  // 无效的索引
    node* temp_head = void_head;
    for (int count = 0; count < index; count++) {
        temp_head = temp_head->next;
    }
    node* temp_node_store = temp_head->next;
    temp_head->next = temp_head->next->next;
    delete temp_node_store;  // 删除目标节点
    size--;
}


private:
    int size;
    node* void_head;

};


//gpt的代码：

class MyLinkedList {
public:

    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(nullptr) {}
    };

    MyLinkedList() {
        head = new Node(0);  // 创建虚拟头结点
        size = 0;
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* temp = head->next;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head->next;
        head->next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;  // 插入位置无效
        if (index == size) {
            addAtTail(val);
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }
        
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;  // 索引无效
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
        size--;
    }

    ~MyLinkedList() {
        Node* temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }

private:
    int size;
    Node* head;  // 虚拟头结点，方便简化边界处理
};


