#include <iostream>
#define MAX_CITIES 50 
using namespace std;

//structure of a city node in list 
struct City {
    string cityName; //name of city 
    int X; //X coordinate of city
    int Y; //y coordinate of city
    };

//class de!nition of city database 
class CityDB {
private:
    City* cities[MAX_CITIES]; //array to store cities
    int numCities; //number of cities in database   
    public:
    CityDB(); //constructor
    bool insertCity(City* city); //inserts a city in DB
    bool deleteCityByName(string cityName); //deletes a city by name
    bool deleteCityByCoordinates(int X, int Y); //deletes city by coordinates 
    bool searchCityByName(string cityName); //searches a city by name 
    bool searchCityByCoordinates(int X, int Y); //searches city by coordinates
};
//implementation of functions 
CityDB::CityDB() {
    numCities = 0; 
    }

bool CityDB::insertCity(City* city) { 
    if (numCities == MAX_CITIES) { 
        cerr << "Overflow" << endl;
        return false; 
    }
    cities[numCities++] = city;
    return true; 
    }

bool CityDB::deleteCityByName(string cityName) { 
    if (numCities == 0) {
        cerr << "Underflow" << endl;
        return false; 
        }
    int cityPos = -1;
    for (int i = 0; i < numCities; i++) {
    if (cityName.compare(cities[i]->cityName) == 0) { 
        cityPos = i;
        break;
        } 
    }
//city to be deleted not found 
    if (cityPos == -1) {
        cout << "Does not exist." << endl;
        return false; } 
    else {
        for (int i = cityPos; i < numCities; i++) { 
            cities[i] = cities[i + 1];
            } 
        numCities--; 
        return true;
        } 
        }

bool CityDB::deleteCityByCoordinates(int X, int Y) { 
    if (numCities == 0) {
        cerr << "Underflow" << endl;
        return false; }
    int cityPos = -1;
    for (int i = 0; i < numCities; i++) {
    if (cities[i]->X == X && cities[i]->Y == Y) { 
        cityPos = i;
        break;
        } 
    }
//city to be deleted not found 
    if (cityPos == -1) {
        cout << "Does not exist." << endl;
        return false; } 
    else {
        for (int i = cityPos; i < numCities; i++) { 
            cities[i] = cities[i + 1];
            } 
        numCities--; 
        return true;
        } 
    }

bool CityDB::searchCityByName(string cityName) { 
    if (numCities == 0) {
        cerr << "Empty! Nothing to search!" << endl;
        return false; }
    int cityPos = -1;
    for (int i = 0; i < numCities; i++) {
        if (cityName.compare(cities[i]->cityName) == 0) { 
            cout << "City found:" << cityName << endl;
            return true; }
//city to be searched not found if (cityPos == -1) {
    cout << "City not found:" << cityName << endl;
    return false; 
    }
    return false; 
}

bool CityDB::searchCityByCoordinates(int X, int Y) {    
    if (numCities == 0) {
        cerr << "Empty! Nothing to search!" << endl;
        return false; }
    int cityPos = -1;
    for (int i = 0; i < numCities; i++) {
        if (cities[i]->X == X && cities[i]->Y == Y) { 
            cout << "City found!" << endl;
            return true;
            } 
    }
//city to be searched not found 
    if (cityPos == -1) {
    cout << "City not found!" << endl;
    return false; 
    }
    return false; 
    }

int main() { 
    //create city db 
    CityDB citydb;
//de!ne city 1
City* city1 = new City; 
city1->cityName = "NewYork"; 
city1->X = 20;
city1->Y = 30;
//insert city 1 
citydb.insertCity(city1); 
//de!ne city 2
City* city2 = new City; 
city1->cityName = "London"; 
city1->X = 120;
city1->Y = 130;
//insert city 2 
citydb.insertCity(city2);
//search city by name 
citydb.searchCityByName("London"); 
citydb.searchCityByName("Berlin"); 
return 0;
} 