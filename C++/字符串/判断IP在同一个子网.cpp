#include<iostream>
#include<sstream>
#include<vector>
#include<string>

using namespace std;

int isbelong(vector<int> &mask, vector<int> &ip1, vector<int> &ip2){
    for(int i = 0; i <4; i++){
        if((mask[i]&ip1[i]) != (mask[i]&ip2[i]))return 2;
    }
    return 0;
}

vector<int> ismask(string input){
    stringstream iss(input);
    string temp;
    unsigned m = 0;
    vector<int> mask;
    while(getline(iss, temp, '.')){
        m = (m<<8) + stoi(temp);
        mask.emplace_back(stoi(temp));
    }

    if(m == 0 || (m^(m-1)) == 1 || ((m&(m-1)) != (m<<1)) ){//判断子网掩码网络号是否全1，主机号是否全0
        mask.clear();              //子网掩码全0或者全1都不行
    }
    return mask;
    
}
vector<int> isip(string input){
    stringstream iss(input);
    string temp;
    vector<int> ip;
    while(getline(iss, temp, '.')){
        ip.emplace_back(stoi(temp));
    }
    for(auto i:ip){
        if(i < 0 || i >255){
            ip.clear();
            break;
        }
    }
    return ip;
}

int main(){
    string inputs[3];
    while(cin>>inputs[0]>>inputs[1]>>inputs[2]){
        vector<int> mask = ismask(inputs[0]);
        if(mask.empty() || mask.size() != 4){
            cout<<1<<endl;
            continue;
        }
        vector<int> ip1 = isip(inputs[1]);
        if(ip1.empty() || ip1.size() != 4){
            cout<<1<<endl;
            continue;
        }
        vector<int> ip2 = isip(inputs[2]);
        if(ip2.empty() || ip2.size() != 4){
            cout<<1<<endl;
            continue;
        }
        cout<<isbelong(mask, ip1, ip2)<<endl;
    }
    return 0;
}
