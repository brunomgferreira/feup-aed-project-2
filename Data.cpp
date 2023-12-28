#include <algorithm>
#include "Data.h"

// TODO

void Data::readFileAirlines() {
    ifstream file("../dataset/airlines.csv");
    if(!file.is_open()){
        cout << "Error opening the file" << endl;
    }
    else{
        string line;
        getline(file,line);
        while(getline(file,line)){
            string code, name, callsign, country;
            stringstream ss(line);
            getline(ss,code,',');
            getline(ss,name,',');
            getline(ss,callsign,',');
            getline(ss, country,',');

            Airline* airline = new Airline(code,name,callsign,country);
            this->airlines.insert({code,airline});
        }

    }
}

void Data::readFileAirports() {
    ifstream file("../dataset/airports.csv");
    if(!file.is_open()){
        cout << "Error opening the file" << endl;
    }
    else{
        string line;
        getline(file,line);
        while(getline(file,line)){
            string code, name, city, country, latitude, longitude;
            stringstream ss(line);
            getline(ss,code,',');
            getline(ss,name,',');
            getline(ss,city,',');
            getline(ss, country,',');
            getline(ss,latitude,',');
            getline(ss, longitude,',');

            Coordinate* coordinate = new Coordinate(stod(latitude), stod(longitude ));
            Airport* airport = new Airport(code, name, city, coordinate);
           // if(g.addVertex( airport->getCode())) this->airports.insert({code,airport});
        }

    }
}

void Data::readFileFlights() {
    ifstream file("../dataset/airlines.csv");
    if(!file.is_open()){
        cout << "Error opening the file" << endl;
    }
    else{
        Graph g;
        string line;
        getline(file,line);
        while(getline(file,line)){
            replace(line.begin(),line.end(),',',' ');

            stringstream ss(line);

            string source, target, flightairline;
            ss >> source >> target >> flightairline;
            //addEdge

        }

    }

}