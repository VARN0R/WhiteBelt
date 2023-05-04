#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    string temp;
    cin >> temp;
    int q = stoi(temp);
    vector<string>nums;
    while(q > 0){
        q--;
        string str_temp;
        cin >> str_temp;
        nums.push_back(str_temp);
    }

    //передаём в функцию sort третьим параметром лямбда выражение,
    //возвращает результат работы лексикографической фунции
    sort(begin(nums), end(nums), [](string& a, string& b){
        
        //сравниваем строки без учета регистра (т.е. как нижний)
        return lexicographical_compare(
            begin(a), end(a), begin(b), end(b), [](char ca, char cb){
                return tolower(ca) < tolower(cb);
            });
    });

    for (const auto& x : nums){
        cout << x << " ";
    }
    return 0;
}