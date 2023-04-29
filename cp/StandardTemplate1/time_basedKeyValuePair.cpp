#include <map>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
class Timebased {
    map<string,map<int,string>>mp;
    public:
        Timebased() {
            // Intialise your data structure here.
            ;
        }

    void setKey(string key, string val, int timestamp) {
        // Write your code here.
        mp[key][timestamp]=val;
    }

    string getValue(string targetKey, int targetTimestamp) {
        // Write your code here.
        if(!mp.count(targetKey)){
            return "-1";
        }
        auto it=mp[targetKey].upper_bound(targetTimestamp);
        if(it==mp[targetKey].begin()){
            return "-1";
        }
        --it;
        return it->second;
    }
};





class Runner {
    int t ;
    vector<vector<vector<string>>> brr;
    vector<vector<vector<string>>> crr;
    vector<vector<vector<int>>> drr;

public:
    void takeInput()
    {
        cin >> t;
        brr.resize(t);
        crr.resize(t);
        drr.resize(t);
        for (int i = 0; i < t; i++)
        {
            int n;
            cin >> n;
            brr[i].resize(n);
            crr[i].resize(n);
            drr[i].resize(n);
            for (int j = 0 ; j < n ; j++) {
                brr[i][j].resize(5);
                crr[i][j].resize(5);
                drr[i][j].resize(5);
                string id;
                cin >> id;
                if (id == "1") {
                    string key , val;
                    int time;
                    cin >> key;
                    cin >> val;
                    cin >> time;
                    brr[i][j][0] = id;
                    brr[i][j][1] = key;
                    crr[i][j][0] = val;
                    drr[i][j][0] = time;
                } else {
                    string key;
                    int time;
                    cin >> key;
                    cin >> time;
                    brr[i][j][0] = id;
                    brr[i][j][1] = key;
                    drr[i][j][0] = time;
                }
            }
        }
    }

    void execute()
    {
        vector<vector<vector<string>>>brrCopy = brr;
        vector<vector<vector<string>>>crrCopy = crr;
        vector<vector<vector<int>>>drrCopy = drr;
        for (int i = 0; i < t; i++)
        {
            Timebased *obj = new Timebased();
            for (int j = 0; j < brrCopy[i].size(); j++)
            {
                if (brrCopy[i][j][0] == "1") {
                    obj->setKey(brrCopy[i][j][1] , crrCopy[i][j][0] , drrCopy[i][j][0]);
                } else {
                    string ans = obj->getValue(brrCopy[i][j][1] , drrCopy[i][j][0]);
                }
            }
            delete obj;
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            Timebased *obj = new Timebased();
            for (int j = 0; j < brr[i].size(); j++)
            {
                if (brr[i][j][0] == "1") {
                    obj->setKey(brr[i][j][1] , crr[i][j][0] , drr[i][j][0]);
                } else {
                    string ans = obj->getValue(brr[i][j][1] , drr[i][j][0]);
                    cout << ans << " ";
                }
            }
            cout << endl;
            delete obj;
        }
    }
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}