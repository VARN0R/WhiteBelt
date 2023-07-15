#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Person {
public:
    string FindNameYear(map <int, string> m, int year){
        string str_name;
        for (auto x : m){
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
private:
    map<int, string>m_f;
    map<int, string>m_l;
};

int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}