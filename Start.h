#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

class Start
{
    private:
    int size_=4;
    int fullness;
    int sorcerer_anger;
    int gold;
    string player_name;
    string party_names[4];
    int fullness_[4];

    public:
    Start();
    Start(string, string[], int);

    //getters
    string getPlayerName();
    int getPlayerFullness();
    string getPartyMemberName(string);//find member name in array, return that
    int getPartyMemberFullness(int);//find member name in array, 
    //that index will be the same for fullness array
    //return index from fullness array
    int getSorcererAnger();
    int getGold();

    //setters
    void setPlayername(string);
    void setPartyNames(string,string,string,string);//names into an array
    void setPlayerFullness(int);
    void setPartyFullness(int,int);
    string getPartyMemberArray(int index);
    //filling an array for party members fullness
    void setScorcererAnger(int);
    void setGold(int);

    //print party fullness
    void printParty();
    
};