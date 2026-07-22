#include <iostream>
#include <string>
#include <map>
using namespace std;


struct node{
    node* pre;
    string value;
    map<string,node*> next;
};


int main() {
    
    map<string,node*> root_next;
    map<string,node*> usr_next;
    node * root = new node{nullptr,"/",root_next};
    node * usr = new node{root,"usr",usr_next};
    root->next[usr->value] = usr;
    node * now_root = usr;

    string command;
    int M;
    cin >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> command;
        if(command == "mkdir")
        {
            string new_name = "";
            cin >> new_name;
            if (now_root->next.count(new_name) == 0)
            {
                map<string,node*> new_next;
                now_root->next[new_name] = (new node{now_root,new_name,new_next});
            }
        }
        else if(command == "cd")
        {
            string target;
            cin >> target;
            if(target == "..")
            {
                if(now_root->pre)
                {
                    now_root = now_root->pre;
                }
            }
            else 
            {
                if (now_root->next.count(target))
                {
                    now_root = now_root->next[target];
                }
            }
        }
        else if(command == "ls")
        {
            if(now_root->next.empty())
            {
                cout << " " << endl;
            }
            else 
            {
                bool first = true;
                for (const auto& entry : now_root->next) {
                    if (!first) {
                        cout << ' ';
                    }
                    cout << entry.first;
                    first = false;
                }
                cout << endl;
            }
        }

    }









}
// 64 位输出请用 printf("%lld")


#include <bits/stdc++.h>
using namespace std;

struct Dir {
    map<string, int> children;
    int parent;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Dir> dirs;
    dirs.push_back({{}, -1});       // 0: root /
    dirs.push_back({{}, 0});        // 1: /usr
    dirs[0].children["usr"] = 1;

    int cur = 1;
    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        string line;
        getline(cin, line);

        if (line.substr(0, 6) == "mkdir ") {
            string name = line.substr(6);
            if (dirs[cur].children.find(name) == dirs[cur].children.end()) {
                int id = dirs.size();
                dirs.push_back({{}, cur});
                dirs[cur].children[name] = id;
            }
        } else if (line == "cd ..") {
            if (dirs[cur].parent != -1)
                cur = dirs[cur].parent;
        } else if (line.substr(0, 3) == "cd ") {
            string name = line.substr(3);
            if (dirs[cur].children.count(name))
                cur = dirs[cur].children[name];
        } else if (line == "ls") {
            if (dirs[cur].children.empty()) {
                cout << " " << "\n";
            } else {
                bool first = true;
                for (auto& [name, id] : dirs[cur].children) {
                    if (!first) cout << " ";
                    cout << name;
                    first = false;
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
