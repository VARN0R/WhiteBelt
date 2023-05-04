#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    str.push_back(s);
  }
  vector<string> GetSortedStrings() {
    sort(begin(str), end(str));
    return str;
  }
private:
  vector<string>str;
};

int main(){
    SortedStrings strings;
    strings.AddString("abd");
    strings.AddString("effefe");
    strings.AddString("dsgdgs");
    for (const auto& x : strings.GetSortedStrings()){
        cout << x << " ";
    }
    return 0;
}