#include <iostream>
using namespace std;

//structure of a city in list 
struct City {
    string cityName; //name of city 
    int X; //X coordinate of city
    int Y; //y coordinate of city
};

//structure of a city node in list 
struct CityNode {
    City *city;
    CityNode *nextCity; 
    };

//class de!nition of city database 
class CityDB {
    private:
    CityNode *headCity;//pointer 
    public:
    CityDB(); //constructor
    bool insertCity(City* city); //inserts city
    bool searchCityByName(string cityName); //searches by name 
    bool searchCityByCoordinates(int X, int Y); //searches by coordinates
    bool deleteCityByName(string cityName); //deletes by name
    bool deleteCityByCoordinates(int X, int Y); //deletes by coordinates 
    
};

//implementation of functions 
CityDB::CityDB() {
    headCity = NULL;
    }

bool CityDB::insertCity(City* city) { 
    //if list empty
    if (headCity == NULL) {
        headCity->city = city; } 
    else {
        headCity->nextCity = headCity;
        headCity->city = city; }
        return true; 
        }

bool CityDB::deleteCityByName(string cityName) { 
    if (headCity == NULL) {
        cerr << "Underflow" << endl;
        return false; }

    CityNode *currCity, *prevCity; 
    currCity = headCity;
    prevCity = NULL;
    while (currCity != NULL) {
        if (cityName.compare(currCity->city->cityName) == 0) { 
            break;
        }
    prevCity = currCity;
    currCity = currCity->nextCity;
}

//city to be deleted not found 
    if (currCity == NULL) {
        cout << "Does not exist." << endl;
        return false; } 
    else {
        prevCity->nextCity = currCity->nextCity;
        delete currCity; }
        return true; }

bool CityDB::deleteCityByCoordinates(int X, int Y) { 
    if (headCity == NULL) {
        cerr << "Underflow" << endl;
        return false; }
    CityNode *currCity, *prevCity; 
    currCity = headCity;
    prevCity = NULL;
    while (currCity != NULL) {
        if (currCity->city->X == X && currCity->city->Y == Y) { 
            break;
        }
    prevCity = currCity;
    currCity = currCity->nextCity; 
}

//city to be deleted not found 
    if (currCity == NULL) {
        cout << "Does not exist." << endl;
            return false; 
    } 
    else {
        prevCity->nextCity = currCity->nextCity;
        delete currCity; 
    }
    return true;
}

bool CityDB::searchCityByName(string cityName) { 
    if (headCity == NULL) {
        cerr << "Empty! Nothing to search!" << endl;
        return false; }
    CityNode *currCity; currCity = headCity; 
    while (currCity != NULL) {
        if (cityName.compare(currCity->city->cityName) == 0) { 
            cout << "City found:" << cityName << endl;
            return true;
        }
        currCity = currCity->nextCity; 
        }

//city to be deleted not found 
    if (currCity == NULL) {
        cout << "City not found:" << cityName << endl;
        return false; 
        }
    return false; 
}

bool CityDB::searchCityByCoordinates(int X, int Y) { 
    if (headCity == NULL) {
        cerr << "Empty! Nothing to search!" << endl;
        return false; 
        }
    CityNode *currCity; currCity = headCity; 
    while (currCity != NULL) {
    if (currCity->city->X == X && currCity->city->Y == Y) 
    { cout << "City found:" << endl;
    return true;
    }
    currCity = currCity->nextCity; 
}

//city to be deleted not found 
    if (currCity == NULL) {
        cout << "City not found:" << endl;
        return false; 
    }
    return false; }

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