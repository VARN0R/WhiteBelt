#include <iostream>
#include <set>
#include <map>
using namespace std;

set<string> buildMapValuesSet(const map<int, string>& m1){
    set<string>res;
    for (auto i : m1){
        res.insert(i.second);
    }
    return res;
}

int main(){
    set<string> values = buildMapValuesSet({
        {1, "odd"},
        {2, "even"},
        {3, "odd"},
        {4, "even"},
        {5, "odd"}
    });

    for (const string& value : values) {
        cout << value << endl;
    }
}