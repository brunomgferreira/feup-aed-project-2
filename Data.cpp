#include <algorithm>
#include "Data.h"

// TODO

void Data::readFileAirlines() {
    ifstream file("../dataset/airlines.csv");

    if(!file.is_open()) {
        cout << "Error opening the file" << endl;
    } else {
        string line;
        getline(file,line);

        while(getline(file,line)) {
            string code, name, callsign, country;
            stringstream ss(line);
            getline(ss,code,',');
            getline(ss,name,',');
            getline(ss,callsign,',');
            getline(ss, country,',');

            Airline* airline = new Airline(code, name, callsign, country);
            this->airlines.insert({code, airline});
        }
    }
}

void Data::readFileAirports() {
    ifstream file("../dataset/airports.csv");

    if(!file.is_open()) {
        cout << "Error opening the file" << endl;
    } else {
        string line;
        getline(file,line);
        while(getline(file,line)) {
            string code, name, cityName, countryName, latitude, longitude;
            stringstream ss(line);
            getline(ss,code,',');
            getline(ss,name,',');
            getline(ss,cityName,',');
            getline(ss, countryName,',');
            getline(ss,latitude,',');
            getline(ss, longitude,',');

            Coordinate* coordinate = new Coordinate(stod(latitude), stod(longitude ));
            Airport* airport = new Airport(code, name, cityName+","+countryName, coordinate);

            if(g.addVertex(airport)) {

                this->airports.insert({code,airport});

                auto citiesIt = cities.find(cityName);
                if(citiesIt == cities.end()) {
                    City* city = new City(cityName+","+countryName, countryName, code);
                    cities.insert({cityName+","+countryName, city});
                } else citiesIt->second->addAirport(code);

                auto countriesIt = countries.find(countryName);
                if(countriesIt == countries.end()) {
                    Country* country = new Country(countryName, cityName+","+countryName);
                    countries.insert({countryName, country});
                } else countriesIt->second->addCity(cityName+","+countryName);
            }
        }
    }
}

void Data::readFileFlights() {
    ifstream file("../dataset/airlines.csv");

    if(!file.is_open()) {
        cout << "Error opening the file" << endl;
    } else {
        string line;
        getline(file,line);
        while(getline(file,line)){
            replace(line.begin(),line.end(),',',' ');

            stringstream ss(line);

            string origin, destination, airlineCode;
            ss >> origin >> destination >> airlineCode;
            g.addEdge(origin, destination, airlineCode);
        }
    }
}