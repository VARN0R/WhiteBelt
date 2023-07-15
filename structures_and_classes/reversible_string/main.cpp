#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ReversibleString{
public:
    ReversibleString(){
        str = "";
    }

    ReversibleString(const string& str_temp){
        str = str_temp;
    }

    void Reverse(){
        string temp = "";
        for (int i = str.size(); i >= 0; i--){
            temp += str[i];
        }
        str = temp;
    }

    string ToString() const{
        return str;
    }
private:
    string str;
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}