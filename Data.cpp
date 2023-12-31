#include <algorithm>
#include <limits>
#include <chrono>
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

bool Data::countryExists(const string& countryName) {
    auto it = countries.find(countryName);
    if (it != countries.end()) return true;
    return false;
}

bool Data::cityExists(const string& cityName) {
    auto it = cities.find(cityName);
    if (it != cities.end()) return true;
    return false;
}

bool Data::airportExists(const string& airportCode) {
    auto it = airports.find(airportCode);
    if (it != airports.end()) return true;
    return false;
}

bool Data::airlineExists(const string& airlineCode) {
    auto it = airlines.find(airlineCode);
    if (it != airlines.end()) return true;
    return false;
}



//Global

void Data::numberOfAirports() {
    cout << "\033[35m";
    cout << "----------------------------" << endl;
    cout << "\033[0m";
    cout << ">> There are " << airports.size() << " airports." << endl;
    cout << "\033[35m";
    cout << "----------------------------" << endl;
    cout << "\033[0m";
}

void Data::numberOfCities() {
    cout << "\033[35m";
    cout << "------------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> There are " << cities.size() << " cities with an airport." << endl;
    cout << "\033[35m";
    cout << "------------------------------------------" << endl;
    cout << "\033[0m";
}

void Data::numberOfCountries() {

    cout << "\033[35m";
    cout << "----------------------------" << endl;
    cout << "\033[0m";
    cout << ">> There are " << countries.size() << " countries." << endl;
    cout << "\033[35m";
    cout << "----------------------------" << endl;
    cout << "\033[0m";
}

void Data::numberOfAirlines() {
    cout << "\033[35m";
    cout << "----------------------------" << endl;
    cout << "\033[0m";
    cout << ">> There are " << airlines.size() << " airlines." << endl;
    cout << "\033[35m";
    cout << "----------------------------" << endl;
    cout << "\033[0m";
}

void Data::numberOfFlights() {
    size_t flights=0;
    for(auto& airport : g.getVertices()){
        for(auto& connection: airport.second->getAdj()){
            flights += connection.second.getAirlines().size();
        }
    }

    cout << "\033[35m";
    cout << "----------------------------" << endl;
    cout << "\033[0m";
    cout << ">> There are " << flights << " flights." << endl;
    cout << "\033[35m";
    cout << "----------------------------" << endl;
    cout << "\033[0m";
}



//Country

void Data::numberOfAirportsCountry(const string& countryName) {
    size_t nAirports=0;
    for(const auto& cityName : countries[countryName]->getCities()){
        nAirports += cities[cityName]->getAirports().size();
    }

    cout << "\033[35m";
    cout << "-------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> There are " << nAirports << " airports in " << countryName << "." << endl;
    cout << "\033[35m";
    cout << "-------------------------------------" << endl;
    cout << "\033[0m";
}

void Data::numberOfCitiesCountry(const string& countryName) {
    size_t nCities = countries[countryName]->getCities().size();
    cout << "\033[35m";
    cout << "------------------------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> There are " << nCities << " cities in " << countryName << " with an airport." << endl;
    cout << "\033[35m";
    cout << "------------------------------------------------------" << endl;
    cout << "\033[0m";


}

void Data::numberOfAirlinesCountry(const string& countryName) {
    unordered_set<string> difAirlines;
    for(const auto& cityName: countries[countryName]->getCities()) {
        for (const auto& airportCode: cities[cityName]->getAirports()) {
            for (auto &connection: g.findVertex(airportCode)->getAdj()) {
                for (auto &airlinesCode: connection.second.getAirlines()) {
                    difAirlines.insert(airlinesCode);
                }
            }
        }
    }

    cout << "\033[35m";
    cout << "--------------------------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> There are " << difAirlines.size() << " different airlines that fly from " << countryName << "." << endl;
    cout << "\033[35m";
    cout << "--------------------------------------------------------" << endl;
    cout << "\033[0m";

}

void Data::numberOfFlightsCountry(const string& countryName) {
    size_t flights = 0;
    for(auto &cityName : countries[countryName]->getCities()) {
        for (auto &airportCode: cities[cityName]->getAirports()) {
            for (auto &connection: g.findVertex(airportCode)->getAdj()) {
                flights += connection.second.getAirlines().size();
            }
        }
    }

    cout << "\033[35m";
    cout << "-----------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> There are " << flights <<" flights from " << countryName << "."<< endl;
    cout << "\033[35m";
    cout << "-----------------------------------------" << endl;
    cout << "\033[0m";

}

void Data::numberOfDestinationsCountry(const string& countryName) {
    unordered_set<string> destinationAirports;
    unordered_set<string> destinationCities;
    unordered_set<string> destinationCountries;
    for(auto &cityName : countries[countryName]->getCities()) {
        for (auto &airportCode: cities[cityName]->getAirports()) {
            g.bfs(airportCode,destinationAirports,destinationCities,destinationCountries);
        }
    }
    cout << "\033[35m";
    cout << "-------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> From " << countryName << " it's possible to reach: " << endl;
    cout << "   " << destinationAirports.size() << " airports" << endl;
    cout << "   " <<  destinationCities.size() << " cities" << endl;
    cout << "   " <<  destinationCountries.size() << " countries" << endl;
    cout << "\033[35m";
    cout << "-------------------------------------" << endl;
    cout << "\033[0m";

}

void Data::numberOfDestinationsXStopsCountry(const string& countryName, int stops) {
    unordered_set<string> destinationAirports;
    unordered_set<string> destinationCities;
    unordered_set<string> destinationCountries;
    for(auto &cityName : countries[countryName]->getCities()) {
        for (auto &airportCode: cities[cityName]->getAirports()) {
            g.bfs(airportCode,stops,destinationAirports,destinationCities,destinationCountries);
        }
    }
    cout << "\033[35m";
    cout << "-----------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> From " << countryName << ", with " << stops << " stops it's possible to reach: " << endl;
    cout << "   " << destinationAirports.size() << " airports" << endl;
    cout << "   " <<  destinationCities.size() << " cities" << endl;
    cout << "   " <<  destinationCountries.size() << " countries" << endl;
    cout << "\033[35m";
    cout << "-----------------------------------------" << endl;
    cout << "\033[0m";
}


unordered_set<string> Data::airportsInCountry(const string& countryName) const {
    unordered_set<string> countryAirports;
    const unordered_set<string> countryCities= countries.at(countryName)->getCities();
    for (const string& city: countryCities){
        for (const string& airport : airportsInCity(city)){
            countryAirports.insert(airport);
        }
    }
    return countryAirports;
}


//City

void Data::numberOfAirportsCity(const string& cityName) {
    size_t n = 0;
    for(auto k : cities[cityName]->getAirports()){
        n++;
    }
    cout << "\033[35m";
    cout << "--------------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> There is " << n <<" airports in " << cityName << "."<< endl;
    cout << "\033[35m";
    cout << "--------------------------------------------" << endl;
    cout << "\033[0m";

}

void Data::numberOfCountriesCity(const string& cityName) {
    unordered_set<string> difCountries;
    for (auto& airportCode: cities[cityName]->getAirports()) {
        for (auto& connection: g.findVertex(airportCode)->getAdj()) {
            difCountries.insert(connection.second.getDest()->getAirport()->getCountry());
        }
    }
    cout << "\033[35m";
    cout << "----------------------------------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> There are " << difCountries.size() << " different countries that " << cityName << " flies to." << endl;
    cout << "\033[35m";
    cout << "----------------------------------------------------------------" << endl;
    cout << "\033[0m";

}

void Data::numberOfAirlinesCity(const string& cityName) {
    unordered_set<string> difAirlines;
    for (auto &airportCode: cities[cityName]->getAirports()) {
        for (auto &connection: g.findVertex(airportCode)->getAdj()) {
            for (auto &airlinesCode: connection.second.getAirlines()) {
                difAirlines.insert(airlinesCode);
            }
        }
    }

    cout << "\033[35m";
    cout << "---------------------------------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> There are " << difAirlines.size() << " different airlines that fly from " << cityName << "." << endl;
    cout << "\033[35m";
    cout << "---------------------------------------------------------------" << endl;
    cout << "\033[0m";

}

void Data::numberOfFlightsCity(const string& cityName) {
    size_t flights = 0;
    for(auto &airportCode : cities[cityName]->getAirports()){
        for(auto &connection: g.findVertex(airportCode)->getAdj()){
            flights += connection.second.getAirlines().size();
        }
    }
    cout << "\033[35m";
    cout << "-------------------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> There are " << flights <<" flights from " << cityName << "."<< endl;
    cout << "\033[35m";
    cout << "-------------------------------------------------" << endl;
    cout << "\033[0m";

}

void Data::numberOfDestinationsCity(const string& cityName) {
    unordered_set<string> destinationAirports;
    unordered_set<string> destinationCities;
    unordered_set<string> destinationCountries;
    for (auto &airportCode: cities[cityName]->getAirports()) {
        g.bfs(airportCode,destinationAirports,destinationCities,destinationCountries);
    }

    cout << "\033[35m";
    cout << "----------------------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> From " << cityName << " it's possible to reach: " << endl;
    cout << "   "<<destinationAirports.size() << " airports" << endl;
    cout << "   "<<destinationCities.size() << " cities" << endl;
    cout << "   "<<destinationCountries.size() << " countries" << endl;
    cout << "\033[35m";
    cout << "----------------------------------------------------" << endl;
    cout << "\033[0m";

}

void Data::numberOfDestinationsXStopsCity(const string& cityName, int stops) {
    unordered_set<string> destinationAirports;
    unordered_set<string> destinationCities;
    unordered_set<string> destinationCountries;
    for (auto &airportCode: cities[cityName]->getAirports()) {
        g.bfs(airportCode,stops,destinationAirports,destinationCities,destinationCountries);
    }
    cout << "\033[35m";
    cout << "--------------------------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> From " << cityName << ", with " << stops << " stops it's possible to reach: " << endl;
    cout << "   "<<destinationAirports.size() << " airports" << endl;
    cout << "   "<<destinationCities.size() << " cities" << endl;
    cout << "   "<<destinationCountries.size() << " countries" << endl;
    cout << "\033[35m";
    cout << "--------------------------------------------------------" << endl;
    cout << "\033[0m";
}



unordered_set<string> Data::airportsInCity(const string& cityName) const {
    return cities.at(cityName)->getAirports();
}

//Airline

void Data::numberOfFlightsAirline(const string& airlineCode) {
    size_t flights=0;
    for(auto &airport : g.getVertices()){
        for(auto &connection: airport.second->getAdj()){
            auto airlinesSet = connection.second.getAirlines();
            auto it = airlinesSet.find(airlineCode);
            if(it != airlinesSet.end()) flights++;
        }
    }
    cout << "\033[35m";
    cout << "---------------------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> There are " << flights <<" flights from airline " << airlineCode << "."<< endl;
    cout << "\033[35m";
    cout << "---------------------------------------------------" << endl;
    cout << "\033[0m";
}

void Data::numberOfDestinationsAirline(const string& airlineCode) {
    unordered_set<string> destinationAirports;
    unordered_set<string> destinationCities;
    unordered_set<string> destinationCountries;
    for(const auto& airportCode : g.getVertices()) {
        for(const auto& connection : g.findVertex(airportCode.first)->getAdj()){
            auto airlinesC = connection.second.getAirlines();
            auto it = airlinesC.find(airlineCode);
            if (it != airlinesC.end()){
                Airport* dest = connection.second.getDest()->getAirport();
                destinationAirports.insert(dest->getCode());
                destinationCities.insert(dest->getCity());
                destinationCountries.insert(dest->getCountry());
            }
        }
    }
    cout << "\033[35m";
    cout << "----------------------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> From airline " << airlineCode << " it's possible to reach: " << endl;
    cout << "   "<<destinationAirports.size() << " airports" << endl;
    cout << "   "<<destinationCities.size() << " cities" << endl;
    cout << "   "<<destinationCountries.size() << " countries" << endl;
    cout << "\033[35m";
    cout << "----------------------------------------------------" << endl;
    cout << "\033[0m";

}



//Airport

void Data::numberOfFlightsAirport(const string& airportCode) {
    size_t flights = 0;
    for(auto &connection: g.findVertex(airportCode)->getAdj()){
        flights += connection.second.getAirlines().size();
    }
    cout << "\033[35m";
    cout << "-------------------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> There are " << flights <<" flights out of " << airportCode << "."<< endl;
    cout << "\033[35m";
    cout << "-------------------------------------------------" << endl;
    cout << "\033[0m";

}

void Data::numberOfAirlinesAirport(const string& airportCode) {
    unordered_set<string> difAirlines;
    for(auto &connection: g.findVertex(airportCode)->getAdj()){
        for(auto &airlinesCode : connection.second.getAirlines()){
            difAirlines.insert(airlinesCode);
        }
    }
    cout << "\033[35m";
    cout << "-------------------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> There are " << difAirlines.size() << " different airlines that fly from " << airportCode << "." << endl;
    cout << "\033[35m";
    cout << "-------------------------------------------------" << endl;
    cout << "\033[0m";

}

void Data::numberOfCountriesAirport(const string& airportCode) {
    unordered_set<string> difCountries;
    for(auto &connection: g.findVertex(airportCode)->getAdj()){
        difCountries.insert(connection.second.getDest()->getAirport()->getCountry());
    }
    cout << "\033[35m";
    cout << "-------------------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> There are " << difCountries.size() <<" different countries that " << airportCode << " flies to."<< endl;
    cout << "\033[35m";
    cout << "-------------------------------------------------" << endl;
    cout << "\033[0m";

}

void Data::numberOfDestinationsAirport(const string& airportCode) {
    unordered_set<string> destinationAirports;
    unordered_set<string> destinationCities;
    unordered_set<string> destinationCountries;
    g.bfs(airportCode,destinationAirports,destinationCities,destinationCountries);

    cout << "\033[35m";
    cout << "-------------------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> From " << airportCode << " it's possible to reach: " << endl;
    cout << "   "<<destinationAirports.size() << " airports" << endl;
    cout << "   "<<destinationCities.size() << " cities" << endl;
    cout << "   "<<destinationCountries.size() << " countries" << endl;
    cout << "\033[35m";
    cout << "-------------------------------------------------" << endl;
    cout << "\033[0m";

}

void Data::numberOfDestinationsXStopsAirport(const string& airportCode, int stops) {
    unordered_set<string> destinationAirports;
    unordered_set<string> destinationCities;
    unordered_set<string> destinationCountries;
    g.bfs(airportCode, stops,destinationAirports,destinationCities,destinationCountries);

    cout << "\033[35m";
    cout << "-------------------------------------------------" << endl;
    cout << "\033[0m";
    cout << ">> From " << airportCode << ", with " << stops << " stops it's possible to reach: " << endl;
    cout << "   "<<destinationAirports.size() << " airports" << endl;
    cout << "   "<<destinationCities.size() << " cities" << endl;
    cout << "   "<<destinationCountries.size() << " countries" << endl;
    cout << "\033[35m";
    cout << "-------------------------------------------------" << endl;
    cout << "\033[0m";


}



void Data::maximumTrip() {
    vector<pair<string,string>> maxTripVec;
    int maxTrip = 0;
    g.bfsmaxtrip(maxTripVec,maxTrip);

    cout << "Max trip of " << maxTrip << " flights." << endl;
    cout << "Between " << maxTripVec.size() << " airports:" << endl;
    for(auto &flight : maxTripVec){
        cout << flight.first << " --> " << flight.second << endl;
    }
}


void Data::topKAirports(int k) {
    vector<pair<string,int>> flights;
    for(auto &airportCode : g.getVertices()){
        size_t flightsAirport = 0;
        for(const auto& connection : airportCode.second->getAdj()){
            flightsAirport+= connection.second.getAirlines().size();
        }
        flights.push_back({airportCode.first,flightsAirport});
    }
    std::sort(flights.begin(), flights.end(),sortTopAirports);
    cout << "Top " << k << " airports:" << endl;
    for(int i =0; i<k; i++){
        cout << "Airport: "<< flights[i].first << "  |  Flights: "<< flights[i].second << endl;
    }
}

void Data::essentialAirports() {
    Graph f = g;
    for(const auto& airportCode : g.getVertices()){
        for(const auto& connection : g.findVertex(airportCode.first)->getAdj()){
            f.addEdge(connection.first,airportCode.first,"");
        }
    }
    unordered_set<string> res;
    for(auto airportCode : f.getVertices()) airportCode.second->setVisited(false);
    stack<string> s;
    int i =1;
    for(const auto& airportCode : f.getVertices()){
        if(!airportCode.second->isVisited()) f.dfsart(airportCode.second, s, res, i, airportCode.first);
    }
    cout << "There is " << res.size() << " essential airports." << endl;

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
// Flights

void Data::getFlights(const LocationInfo &originLocation, const LocationInfo &destinyLocation,
                       unordered_set<std::string> airlineSet, bool unwantedAirlines, bool minimizeAirlines) {

    cout << "Processing the flights... \n\n";
    // Create set of airports to consider as start and end
    unordered_set<string> originAirports = convertLocation(originLocation);
    unordered_set<string> destinyAirports = convertLocation(destinyLocation);

    list<list<string>> bestFlights;
    int minSizeFlight = numeric_limits<int>::max();

    for (const string &airport: originAirports) {

        // Set all airports to unvisited
        for (const auto &vertex: g.getVertices()) {
            vertex.second->setVisited(false);
        }

        // Control flights
        unordered_map<string, pair<list<string>, int>> airportTrack;
        bool foundFlight = false;
        int flightSize = numeric_limits<int>::max();
        unordered_set<string> reachedDestiny;

        // BFS
        Vertex *beggining = g.findVertex(airport);
        queue<Vertex *> q;
        q.push(beggining);
        beggining->setVisited(true);
        airportTrack[airport] = {{}, 0};
        while (!q.empty()) {
            Vertex *origin = q.front();
            string originCode = origin->getAirport()->getCode();
            q.pop();

            // Airport is a destiny airport
            if (destinyAirports.find(originCode) != destinyAirports.end()) {
                // Check if that level Airports are already all checked
                if (airportTrack[originCode].second > flightSize) {
                    q.empty();
                } else {
                    foundFlight = true;
                    flightSize = airportTrack[originCode].second;
                    reachedDestiny.insert(originCode);
                }
            } else {
                // Consider more distant airports only if flight is not found yet
                if (!foundFlight) {
                    for (const auto &edge: origin->getAdj()) {
                        // Check if it is possible to use the connection
                        bool canUseEdge = false;
                        unordered_set<string> availableAirlines = edge.second.getAirlines();
                        if (unwantedAirlines) {
                            for (const string &airline: availableAirlines) {
                                if (airlineSet.find(airline) == airlineSet.end()) {
                                    canUseEdge = true;
                                    break;
                                }
                            }
                        } else {
                            for (const string &airline: airlineSet) {
                                if (availableAirlines.find(airline) != availableAirlines.end()) {
                                    canUseEdge = true;
                                    break;
                                }
                            }
                        }
                        if (canUseEdge) {
                            string destinyCode = edge.first;
                            Vertex *destiny = edge.second.getDest();
                            if (destiny->isVisited()) {
                                // Check if distance via current node is the same as already set distance
                                if (airportTrack[destinyCode].second == airportTrack[originCode].second + 1) {
                                    // If so, add it as an origin for that airport as well
                                    airportTrack[destinyCode].first.push_back(originCode);
                                }
                                } else {
                                    destiny->setVisited(true);
                                    airportTrack[destinyCode] = {{originCode}, airportTrack[originCode].second + 1};
                                    q.push(destiny);
                                }

                        }
                    }

                }
            }
        }
        // Check if Flight from current airport is better than flights from others
        if (flightSize <= minSizeFlight){

            if (flightSize < minSizeFlight){
                bestFlights.clear();
            }
            minSizeFlight = flightSize;
            // Process the actual flight path
            for (const string& destiny : reachedDestiny){
                for (const list<string>& flight : processFlights(destiny, airportTrack)){
                    bestFlights.push_back(flight);
                }
            }
        }
    }

    if (bestFlights.empty()){
        cout << "Not able to find any flights..." << endl;
        return;
    }

    if (minimizeAirlines) {
        pair<list<list<string>>, int> minimizedAirlines = minimalAirlines(bestFlights);
        bestFlights = minimizedAirlines.first;
        int minNumberAirlines = minimizedAirlines.second;
        cout << "A possible flight was found with the minimal number of " << minNumberAirlines << " different airlines:" << endl;
    }


    for (const auto & flight : bestFlights){
        cout << endl;
        for (const string& airport : flight){
            cout << airport  << "-";
        }
    }

}

pair<list<list<string>>, int> Data::minimalAirlines(const list<list<string>> &flights) const {

    int minAirlines = numeric_limits<int>::max();
    list<list<string>> bestFlights;

    for (const list<string>& flight : flights){
        unordered_set<string> usedAirlines;
        int numberAirlines = 0;

        auto airport = flight.begin();
        while (next(airport, 1)!=flight.end()){
            string origin = *airport;
            string destiny = *(++airport);

            unordered_set<string> availableAirlines = g.findVertex(origin)->getAdj().at(destiny).getAirlines();
            unordered_set<string> bestAirlines = usedAirlines;
            for (const string& airline : bestAirlines){
                if (availableAirlines.find(airline) != availableAirlines.end()){
                    bestAirlines.insert(airline);
                }
            }
            if (bestAirlines.empty()){
                numberAirlines++;
                for (const string& airline : availableAirlines){
                    usedAirlines.insert(airline);
                }
            }else{
                usedAirlines = bestAirlines;
            }


        }
        if (numberAirlines <= minAirlines){
            if (numberAirlines < minAirlines){
                bestFlights.clear();
            }
            minAirlines = numberAirlines;
            bestFlights.push_back(flight);
        }
    }
    return {bestFlights, minAirlines};
}

list<list<string>> Data::processFlights(const string& destiny, const unordered_map<string, pair<list<string>, int>>& airportTrack) const{
    list<string> originList = airportTrack.at(destiny).first;
    if (originList.empty()){
        return {{destiny}};
    }
    list<list<string>> flights;
    for (const string& origin : originList){
        for (const list<string>& flight : processFlights(origin, airportTrack)){
            flights.push_back(flight);
        }
    }
    for (list<string>& flight : flights){
        flight.push_back(destiny);
    }
    return flights;
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


