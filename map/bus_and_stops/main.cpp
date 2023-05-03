#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void isNewBus(map<string, vector<string>>&bus_and_stop, map<string, vector<string>>&stop_and_bus){
    string bus;
    cin >> bus;
    int stop_count;
    cin >> stop_count;
    string temp;
    for (int i = 0; i < stop_count; i++){
        cin >> temp;
        bus_and_stop[bus].push_back(temp);
        stop_and_bus[temp].push_back(bus);
    }
}

void isBusesForStop(map<string, vector<string>>&stop_and_bus){
    string stop;
    cin >> stop;
    if (stop_and_bus.count(stop) < 1){
        cout << "No stop" << endl;
    }
    else {
        for (auto i : stop_and_bus[stop]){
            cout << i << " ";
        }
        cout << endl;
    }
}

void isStopsForBus(map<string, vector<string>>&bus_and_stop, map<string, vector<string>>&stop_and_bus){
    string bus;
    cin >> bus;
    if (bus_and_stop.count(bus) == 0){
        cout << "No bus" << endl;
    }
    else {
        for (auto i : bus_and_stop[bus]){
            cout << "Stop " << i << ": ";
            if (stop_and_bus[i].size() == 1){
                cout << "no interchange";
            }
            else {
                for (auto j : stop_and_bus[i]){
                    if (j != bus){
                        cout << j << " ";
                    }
                }
            }
            cout << endl;
        }
    }
}

void isAllBusses(map <string, vector<string>>&bus_and_stop){
    if (bus_and_stop.size() > 0){
        for (auto bus : bus_and_stop){
            cout << "Bus " << bus.first << ": ";
            for (auto stop : bus.second){
                cout << stop << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "No buses" << endl;
    }
}

int main(){
    map<string, vector<string>>bus_and_stop;
    map<string, vector<string>>stop_and_bus;
    cout << "Enter amount operation: " << endl;
    int q;
    cin >> q;
    while(q > 0){
        q--;
        string operation;
        cin >> operation;
        if (operation == "NEW_BUS"){
            isNewBus(bus_and_stop, stop_and_bus);
        }
        else if(operation == "BUSES_FOR_STOP"){
            isBusesForStop(stop_and_bus);
        }
        else if(operation == "STOPS_FOR_BUS"){
            isStopsForBus(bus_and_stop, stop_and_bus);
        }
        else if(operation == "ALL_BUSES"){
            isAllBusses(bus_and_stop);
        }
    }
    return 0;
}