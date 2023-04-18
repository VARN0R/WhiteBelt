#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){
    int N;
    cout << "Enter amount operations: " << endl;
    cin >> N;
    cout << "Enter operation: " << endl;
    string S;
    map<string, string> m;
    string country, new_capital, old_country_name, new_country_name;
    while(N > 0){
        N--;
        cin >> S;
        if (S == "CHANGE_CAPITAL"){
            cin >> country >> new_capital;
            if(m.count(country) == 0){
                m[country] = new_capital;
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
            }
            else if (m[country] == new_capital){
                cout << "Country " << country <<  " hasn't changed its capital" << endl;
            }
            else if(m.count(country) == 1 && m[country] != new_capital){
                cout << "Country " << country << " has changed its capital from " << m[country] << " to " << new_capital << endl;
                m[country] = new_capital;
            }
        }
        else if (S == "RENAME"){
            cin >> old_country_name >> new_country_name;
            if (m.count(new_country_name) > 0 || old_country_name == new_country_name || m.count(old_country_name) < 1){
                cout << "Incorrect rename, skip " << endl;
            }
            else {
              m[new_country_name] = m[old_country_name];
              m.erase(old_country_name);
              
              cout << "Country " << old_country_name << " with capital " << m[new_country_name] << " has been renamed to " << new_country_name << endl; 
            }
        }
        else if(S == "ABOUT"){
            cin >> country;
            if (m.count(country) < 1){
                cout << "Country " << country << " doesn't exist" << endl;
            }
            else {
                cout << "Country " << country << " has capital " << m[country] << endl;
            }
        }
        else if(S == "DUMP"){
            if (m.empty()){
                cout << "There are no countries in the world" << endl;
            }
            else {
                for (auto [key, value] : m){
                    cout << key << "/" << value << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}