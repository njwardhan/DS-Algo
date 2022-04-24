// Daily Challenge: 24th April 2022
// Simple usage of 2 maps to get the work done, but not that good LC performance ..
// checkIn() and checkOut() function run in O(1) time and space
// getAverageTime() function runs in O(N) time, where N = number of distinct previous travel times between the pair of stations
// in question and constant time 

class UndergroundSystem {
public:
    map<pair<string, string>, vector<int>> Store;
    map<int, pair<string, int>> checkIN;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        pair<string, int> p = make_pair(stationName, t);
        checkIN[id] = p;
    }
    
    void checkOut(int id, string stationName, int t) {
        int time_diff = t - checkIN[id].second;
        pair<string, string> p = make_pair(checkIN[id].first, stationName);
        Store[p].push_back(time_diff);
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<string, string> temp = make_pair(startStation, endStation);
        double sum = 0;
        int n = Store[temp].size();
        for(int i = 0; i < n; i++)
            sum += Store[temp][i];
        
        return sum / n;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

