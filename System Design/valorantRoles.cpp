/*
Lets make a valorant one as well
Roles - Initiator,Duelist, Controller and Sentinel
Type - Entry, Scan, lurk, Smoker
Agents each role
Best player each role
*/
#include "R:\C++\Project1\lcHeader.h"

class Valorant
{
    public:
    string role;
    string type;
    string player;
    vector<string> agents;

    Valorant(string r, string t,string p): role(r), type(t), player(p){};

    void addAgent(string agent){
        agents.push_back(agent);
    }

    void display(){
        cout<<"Role - " << role << " Type - " << type << endl;
        for(string a : agents){
            cout<<"-"<< a << endl;
        }
        cout<<"Player to watch - " << player <<  endl;
    }
};

class Initiatior : public Valorant{
    public:
    Initiatior(string r, string t,string p) : Valorant(r,t,p){}
};

class Duelist : public Valorant{
    public:
    Duelist(string r, string t,string p) : Valorant(r,t,p){}
};

class Controller : public Valorant{
    public:
    Controller(string r, string t,string p) : Valorant(r,t,p){}
};

class Sentinel : public Valorant{
    public:
    Sentinel(string r, string t,string p) : Valorant(r,t,p){}
};

int main(){
    Initiatior ini("Initiator", "Scanner", "Lakia");
    ini.addAgent("Sova");
    ini.addAgent("Fade");
    ini.addAgent("Skye");

    Duelist duel("Duelist", "Entry", "T3xture");
    duel.addAgent("Jett");
    duel.addAgent("Neon");
    duel.addAgent("Yoru");

    Controller cont("Controller", "Smoker", "Mako");
    cont.addAgent("Omen");
    cont.addAgent("Brimstone");
    cont.addAgent("Viper");

    Sentinel sen("Sentinel", "Lurker", "Nats");
    sen.addAgent("Killjoy");
    sen.addAgent("Cypher");
    sen.addAgent("Chamber");

    ini.display();
    duel.display();
    cont.display();
    sen.display();
}