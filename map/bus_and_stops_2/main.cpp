#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){
    map<vector<string>, int> bus_and_route;
    int q;
    int count_routes = 0;
    cout << "Enter amount operations: " << endl;
    cin >> q;
    while(q > 0){
        q--;
        vector<string>vectemp;
        string strtemp;
        int q2;
        cin >> q2;
        while(q2 > 0){
            q2--;
            cin >> strtemp;
            vectemp.push_back(strtemp);
        }
        if(bus_and_route.contains(vectemp)){
            cout << "Already exists for " << bus_and_route[vectemp];
        }
        else {
            bus_and_route[vectemp] = ++count_routes;
            cout << "New bus " << count_routes;
        }
    }
    return 0; 
}