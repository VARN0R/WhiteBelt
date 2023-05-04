#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int q;
    cin >> q;
    vector<int>nums;
    while(q > 0){
        q--;
        int val;
        cin >> val;
        nums.push_back(val);
    }
    sort(begin(nums), end(nums), [](int a, int b){
        return (abs(a) < abs(b));
    });
    
    //const позволяет явно указывыать, что мы не изменяем значения вектора
    for (const auto x: nums){
        cout << x << " ";
    }
    return 0;
}