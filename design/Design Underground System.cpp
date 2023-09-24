class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> check_in_time;
    unordered_map<string,pair<int,int>> path;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        check_in_time[id] = {stationName , t};
    }
    
    void checkOut(int id, string stationName, int t) {
        // while check out store the time taken from one station to another
        auto checkIn = check_in_time[id];
        check_in_time.erase(id);

        string path_name = checkIn.first + "_" +stationName;
        path[path_name].first += t - checkIn.second;
        path[path_name].second += 1;
        
    }
    
    double getAverageTime(string startStation, string endStation) {
        string routeName = startStation + "_" + endStation;
        auto& route = path[routeName];
        return (double) route.first / route.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */