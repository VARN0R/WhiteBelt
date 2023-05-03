#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(){
    map<set<string>, int>m;
    int q;
    cin >> q;
    int count_routes;
    while(q > 0){
        q--;
        int q2;
        cin >> q2;
        set<string>set_temp;
        while(q2 > 0){
            q2--;
            string str_temp;
            cin >> str_temp;
            set_temp.insert(str_temp);
        }
        if (m.contains(set_temp)){
            cout << "Already exists for " << m[set_temp] << endl;
        }
        else {
            m[set_temp] = ++count_routes;
            cout << "New bus " << count_routes << endl;
        }
    }
    return 0;
}