#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(){
    cout << "Enter amount strings: " << endl;
    int q;
    cin >> q;
    string strtemp;
    set<string>amount_strings;
    while(q > 0){
        q--;
        cin >> strtemp;
        amount_strings.insert(strtemp);
    }
    cout << amount_strings.size();
}