#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
using namespace std;

class Person {
public:
    string FindNameYear(const map <int, string>& m, int year){
        string str_name;
        for (const auto& x : m){
            if(x.first <= year){
                str_name = x.second;
            }
        }
        return str_name;
    }
    
    void ChangeFirstName(int year, const string& first_name){
        m_f[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        m_l[year] = last_name;
    }
  
    string GetFullName(int year) {
        string first_name = FindNameYear(m_f, year);
        string last_name = FindNameYear(m_l, year);
        
        if (first_name != "" && last_name == ""){
            return first_name + " with unknown last name";
        } 
        
        else if(first_name == "" && last_name != ""){
            return last_name + " with unknown first name";
        }
        
        else if(first_name != "" && last_name != ""){
            return first_name + " " + last_name;
        }
        
        else {
            return "Incognito";
        }
    }

    string GetFullNameWithHistory(int year){
        string first_name = FindNameYear(m_f, year);
        string last_name = FindNameYear(m_l, year);
        string str_temp;
        
        if (first_name != "" && last_name == ""){
            str_temp = "";
            str_temp = BuildHistory(m_f, first_name, year);
            return first_name + str_temp + " with unknown last name";
        } 
        
        else if(first_name == "" && last_name != ""){
            str_temp = "";
            str_temp = BuildHistory(m_l, last_name, year);
            return last_name + str_temp + " with unknown first name";
        }
        
        else if(first_name != "" && last_name != ""){
            string str1 = BuildHistory(m_f, first_name, year);
            string str2 = BuildHistory(m_l, last_name, year);
            return first_name + str1 + " " + last_name + str2;
        }
        
        else {
            return "Incognito";
        }
    }

    string BuildHistory(const map<int, string>& m, const string& temp_name, int year){
        string str_current = "(";
        stack<string>st;
        
        for (auto x : m){
            if(x.first <= year){
                st.push(x.second);
            }
            else {
                break;
            }
        }
        
        while(!st.empty()){
            if (st.top() == temp_name){
                st.pop();
            }
            else {
                break;
            }
        }

        while(!st.empty()){
            str_current += (st.top());
            st.pop();
            if (!str_current.empty() && !st.empty()){
                str_current += ", ";
            }
        }
        
        str_current += ")";
        
        if (str_current == "()"){
            return "";
        }
        return str_current;
    }

private:
    map<int, string>m_f;
    map<int, string>m_l;
};

int main() {
    Person person;
    
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}