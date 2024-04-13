#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Vehicle {
    string number;
    string brand;
    string renter; 
};

int main() {
    setlocale(LC_ALL, "rus");
    vector<Vehicle> vehicles = {
        {"001", "Toyota", "Enterprise"},
        {"002", "Ford", "Hertz"},
        {"003", "Toyota", "Avis"},
        {"004", "Chevrolet", "Enterprise"}
    };

    string desiredBrand = "Toyota"; 

    map<string, vector<string>> carRenters;

    for (const auto& vehicle : vehicles) {
        if (vehicle.brand == desiredBrand) {
            carRenters[vehicle.renter].push_back(vehicle.number);
        }
    }

    cout << "Список легковых машин марки " << desiredBrand << ":\n";
    for (const auto& pair : carRenters) {
        cout << "Предприятие: " << pair.first << "\n";
        cout << "Легковые машины: ";
        for (const auto& carNumber : pair.second) {
            cout << carNumber << " ";
        }
        cout << "\n";
    }

    return 0;
}
