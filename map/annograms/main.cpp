#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

map<char, int> BuildCharCounters(map<char, int> &func_map, string& func_s){
    for (int i = 0; i < func_s.size(); i++){
        func_map[func_s[i]]++;
    }
    return func_map;
}

int main(){
    int N;
    string s, s2;
    map<char, int> m, m2;
    cout << "Enter pairs words: " << endl;
    cin >> N;
    cout << "Enter words: " << endl;
    while(N > 0){
        N--;
        cin >> s >> s2;
        if(BuildCharCounters(m, s) != BuildCharCounters(m2, s2)){
            cout << "NO" << " ";
        }
        else {
            cout << "YES" << " ";
        }
        m.clear();
        m2.clear();
    }
    return 0;
}