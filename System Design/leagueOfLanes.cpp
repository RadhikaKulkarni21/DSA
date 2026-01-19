/*
Currently processing stove league, lets design a league inheritence cpp program 
This has each lane - Top, Mid, Bot
Each role for each lane - TOP, Jungle, mid, adc, support
Each role has top three prefered champs out of 172
Each role has a player assigned
*/
#include "R:\C++\Project1\lcHeader.h"


class LeagueLane{
    public:
    string lane;//all lanes
    string role;
    string player;
    vector<string> champs;

    //LeagueLane(string l,string r, string p): lane(l), role(r), player(p){};

    LeagueLane(string l,string r, string p){
        lane = l;
        role = r;
        player = p;
    }

    void addChamp(string champ){
        champs.push_back(champ);
    }

    virtual void display(){
        cout<< "Lane: "<< lane << " Role: " << role <<endl;
        for(string c : champs){
            cout<< "Pref Champ - " << c << endl;  
        }
        cout<< "See player - " << player << endl;
    }
};

//lets make some roles
class TopLane : public LeagueLane{
    public:
    TopLane(string l, string r, string p) : LeagueLane(l,r,p) {};
};

class MidLane : public LeagueLane{
    public:

    MidLane(string l, string r, string p) : LeagueLane(l,r,p) {};
};

class BotLane : public LeagueLane{
    public:

    BotLane(string l, string r, string p) : LeagueLane(l,r,p) {};
};


int main(){
    TopLane tl("Top Lane", "Top Liner", "Doran/Zeus");
    tl.addChamp("Ambessa");
    tl.addChamp("Camille");
    tl.addChamp("Gragas");

    TopLane jl("Jungle", "Jungler", "Oner");
    jl.addChamp("LeeShin");
    jl.addChamp("Nocturn");
    jl.addChamp("Xin Zhao");

    MidLane ml("Mid Lane", "Mid Liner", "Faker");
    ml.addChamp("Ahri");
    ml.addChamp("Galio");
    ml.addChamp("Azir");

    BotLane bl("Bot Lane", "ADC", "Gumayusi");
    bl.addChamp("Lucian");
    bl.addChamp("Kaisa");
    bl.addChamp("Miss Fortune");

    BotLane sl("Bot Lane", "Support", "Keria");
    sl.addChamp("Neeko");
    sl.addChamp("Poppy");
    sl.addChamp("Leona");
    
    tl.display();
    jl.display();
    ml.display();
    bl.display();
    sl.display();
}
