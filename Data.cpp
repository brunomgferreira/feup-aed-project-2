#include <algorithm>
#include <limits>
#include "Data.h"

Data::Data() {
    readFileAirlines();
    readFileAirports();
    readFileFlights();
}

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
            Airport* airport = new Airport(code, name, cityName+","+countryName, countryName, coordinate);

            if(g.addVertex(airport)) {

                this->airports.insert({code,airport});

                auto citiesIt = cities.find(cityName); //????
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
    ifstream file("../dataset/flights.csv");

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

// Confirm Existence

bool Data::countryExists(string countryName) {
    auto it = countries.find(countryName);
    if (it != countries.end()) return true;
    return false;
}

bool Data::cityExists(string cityName) {
    auto it = cities.find(cityName);
    if (it != cities.end()) return true;
    return false;
}

bool Data::airportExists(string airportCode) {
    auto it = airports.find(airportCode);
    if (it != airports.end()) return true;
    return false;
}

bool Data::airlineExists(string airlineCode) {
    auto it = airlines.find(airlineCode);
    if (it != airlines.end()) return true;
    return false;
}



//Global

void Data::numberOfAirports() {
    cout << "There is " << airports.size() << " airports." << endl;
}

void Data::numberOfCities() {
    cout << "There is " << cities.size() << " cities." << endl;
}

void Data::numberOfCountries() {
    cout << "There is " << countries.size() << " countries." << endl;
}

void Data::numberOfAirlines() {
    cout << "There is " << airlines.size() << " airlines." << endl;
}

void Data::numberOfFlights() {
    size_t flights=0;
    for(auto& airport : g.getVertices()){
        for(auto& connection: airport.second->getAdj()){
            flights += connection.second.getAirlines().size();
        }
    }
    cout << "There is " << flights <<" flights." << endl;
}



//Country

void Data::numberOfAirportsCountry(string countryname) {
    size_t nAirports=0;
    for(auto cityname : countries[countryname]->getCities()){
        nAirports += cities[cityname]->getAirports().size();
    }

    cout << "There is " << nAirports <<" airports in " << countryname << "." << endl;
}

void Data::numberOfCitiesCountry(string countryname) {
    size_t nCities =0;
    nCities = countries[countryname]->getCities().size();

    cout << "There is " << nCities <<" cities in " << countryname << "." << endl;

}


unordered_set<string> Data::airportsInCountry(const string& countryName) const {
    unordered_set<string> countryAirports;
    const unordered_set<string> countryCities= countries.at(countryName)->getCities();
    for (const string& city: countryCities){
        for (const string& airport : airportsInCity(city)){
            countryAirports.insert(airport);
        }
    }
}


//City

void Data::numberOfFlightsCity(string cityName) {
    size_t flights = 0;
    for(auto& airportCode : cities[cityName]->getAirports()){
        for(auto& connection: g.findVertex(airportCode)->getAdj()){
            flights += connection.second.getAirlines().size();
        }
        //chamar numberFlights Airport ?? mudar tipo...
    }
    cout << "There is " << flights <<" flights from " << cityName << "."<< endl;
}

void Data::numberOfCountriesCity(string cityName) {
    unordered_set<string> difCountries;
    for (auto &airportCode: cities[cityName]->getAirports()) {
        for (auto &connection: g.findVertex(airportCode)->getAdj()) {
            difCountries.insert(connection.second.getDest()->getAirport()->getCountry());
        }
    }
    cout << "There is " << difCountries.size() << " different countries that " << cityName << " flies to." << endl;
}



unordered_set<string> Data::airportsInCity(const string& cityName) const {
    return cities.at(cityName)->getAirports();
}

//Airline

void Data::numberOfFlightsAirline(string airlineCode) {
    size_t flights=0;
    for(auto& airport : g.getVertices()){
        for(auto& connection: airport.second->getAdj()){
            auto it = connection.second.getAirlines().find(airlineCode);
            if(it != connection.second.getAirlines().end()) flights++;
        }
    }
    cout << "There is " << flights <<" flights from airline " << airlineCode << "."<< endl;
}



//Airport

void Data::numberOfFlightsAirport(string airportCode) {
    size_t flights = 0;
    for(auto& connection: g.findVertex(airportCode)->getAdj()){
        flights += connection.second.getAirlines().size();
    }
    cout << "There is " << flights <<" flights out of " << airportCode << "."<< endl;
}

void Data::numberOfAirlinesAirport(string airportCode) {
    unordered_set<string> difAirlines;
    for(auto& connection: g.findVertex(airportCode)->getAdj()){
        for(auto& airlines : connection.second.getAirlines()){
            difAirlines.insert(airlines);
        }
    }
    cout << "There is " << difAirlines.size() << " different airlines that flies from " << airportCode << "." << endl;
}

void Data::numberOfCountriesAirport(string airportCode) {
    unordered_set<string> difCountries;
    for(auto& connection: g.findVertex(airportCode)->getAdj()){
        difCountries.insert(connection.second.getDest()->getAirport()->getCountry());
    }
    cout << "There is " << difCountries.size() <<" different countries that " << airportCode << " flies to."<< endl;
}

void Data::numberOfDestinationsAirport(string airportCode) {
    vector<int> destinations = g.bfs(airportCode);

    cout << "For the given airport there is, as destinations: " << endl;
    cout << destinations[0] << " airports" << endl;
    cout << destinations[1] << " cities" << endl;
    cout << destinations[2] << " countries" << endl;
}

void Data::numberOfDestinationsXStopsAirport(string airportCode, int stops) {
    vector<int> destinations = g.bfs(airportCode,stops);

    cout << "For the given airport there is, as destinations: " << endl;
    cout << destinations[0] << " airports" << endl;
    cout << destinations[1] << " cities" << endl;
    cout << destinations[2] << " countries" << endl;

}

void Data::maximumTrip() {
    vector<pair<string,string>> maxtripVec;
    int maxtrip = 0;
    for(auto &originAirport : g.getVertices()){
        for(auto v : g.getVertices()){
            v.second->setVisited(false);
        }
        queue<pair<Vertex*,int>> q;
        q.push({g.findVertex(originAirport.first),0});
        q.front().first->setVisited(true);
        while(!q.empty()){
            Vertex * r = q.front().first;
            int i = q.front().second;
            q.pop();
            for(auto &e : r->getAdj()){
                auto w = e.second.getDest();
                if(!w->isVisited()){
                    q.push({w,i+1});
                    w->setVisited(true);
                    if (maxtrip < i+1) maxtripVec.clear();
                    if (maxtrip <= i+1) maxtrip = i+1, maxtripVec.push_back({originAirport.first, w->getAirport()->getCode()});
                }
            }

        }
    }
    cout << "Max trip of " << maxtrip << " flights." << endl;
    cout << "Between airports: " << endl;
    for(auto &flight : maxtripVec){
        cout << flight.first << " --> " << flight.second << endl;
    }
}



void Data::topKAirports(int k) {
    vector<pair<string,int>> flights;
    for(auto &airportCode : g.getVertices()){
        int flightsAiport = 0;
        for(auto connection : airportCode.second->getAdj()){ //similar numberOfFlightsAirport()
            flightsAiport+= connection.second.getAirlines().size();
        }
        flights.push_back({airportCode.first,flightsAiport});
    }
    std::sort(flights.begin(), flights.end(),sortTopAirports);
    cout << "Top " << k << " airports:" << endl;
    for(int i =0; i<k; i++){
        cout << "Airport: "<< flights[i].first << " Flights: "<< flights[i].second << endl;
    }
}

bool Data::sortTopAirports(const pair<string, int>& a, const pair<string, int>& b){
    if(a.second > b.second) return true;
    else if (a.second == b.second){
        if(a.first < b.first) return true;
    }
    return false;
}


// Coordinates
string Data::airportNearCoordinate(Coordinate coordinate) const {
    double minDistance = std::numeric_limits<double>::max();
    string closerAirport;
    for (const auto& airport : airports){
        double distance = coordinate.distanceTo(*airport.second->getCoordinate());
        if (distance < minDistance){
            minDistance = distance;
            closerAirport = airport.first;
        }
    }
    return closerAirport;
}

unordered_set<string> Data::airportsInLocation(Coordinate coordinate, double radius) {
    unordered_set<string> inRadiusAirports;
    for (const auto& airport: airports){
        double distance = coordinate.distanceTo(*airport.second->getCoordinate());
        if (distance <= radius) inRadiusAirports.insert(airport.first);
    }
    return inRadiusAirports;
}
// Location

unordered_set<string> Data::convertLocation(const LocationInfo &location) {
    unordered_set<string> selectedAirports;
    int type = location.getType();

    switch (type) {
        case 1:
            selectedAirports.insert(location.getInfo());
            break;
        case 2:
            selectedAirports= airportsInCity(location.getInfo());
            break;
        case 3:
            selectedAirports= airportsInCountry(location.getInfo());
            break;
        case 4:
            selectedAirports.insert(airportNearCoordinate(location.getCoordinate()));
            break;
        case 5:
            selectedAirports = airportsInLocation(location.getCoordinate(), location.getRadius());
            break;
    }
    return selectedAirports;
}











