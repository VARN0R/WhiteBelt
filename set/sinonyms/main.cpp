#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;

void add(map<string, set<string>>& m){
    string word1, word2;
    cin >> word1 >> word2;
    m[word1].insert(word2);
    m[word2].insert(word1);
}

int isCount(map<string, set<string>>&m){
    string word;
    cin >> word;
    int count;
    count = m[word].size();
    return count;
} 

string isCheck(map<string, set<string>>&m){
    string word1, word2;
    cin >> word1 >> word2;
    if(m[word1].contains(word2)){
        return "YES";
    }
    return "NO";
}

int main(){
    map<string, set<string>>sinonyms;
    int q;
    cin >> q;
    while(q > 0){
        q--;
        string operation;
        cin >> operation;
        if (operation == "ADD"){
            add(sinonyms);
        }
        else if(operation == "COUNT"){
            cout << isCount(sinonyms) << endl;
        }
        else if(operation == "CHECK"){
            cout << isCheck(sinonyms) << endl;
        }
    }
    return 0;
}