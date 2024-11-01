#ifndef ROUTER_H
#define ROUTER_H

#include <iostream>
#include <map>
using namespace std;

using namespace std;

class Router
{
    private:
        string id;
        unsigned short cost;
        map<string, map< string, int, greater<string>>, greater<string>> data;
        void searchLinkBTRoutes(string key, string ignore, string &keyEnd);



    public:
        Router();

        void formatDataInit(string unformattedData);
        void addRouter();
        void removeRouter();
        bool verifyIFexistRouter(string key);
        void showRouters();
        void showTableOfRouters();
        bool addCostBetween(string key_1, string key_2);
        int costBetwennToRouters(string key_1, string key_2);

        void setId(string key);
        void setCost(int cost);

        string getKey() const;
        int getCost() const;


};

#endif // ROUTER_H
