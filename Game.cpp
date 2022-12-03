#include<iostream>
#include<iomanip>
// #include"Start.h"
// #include"Merchant.h"
// #include"Map.h"

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
    void setPartyFullness(int,int,int,int);
    string getPartyMemberArray(int index);
    //filling an array for party members fullness
    void setScorcererAnger(int);
    void setGold(int);

    //print party fullness
    void printParty();
    
};

Start::Start()
{
    player_name="";
    fullness=50;
    for (int i = 0; i < 4; i++)
    {
        party_names[i]="";
        fullness_[i]=50;
    }//setting party names to empty, fullness to 50
    sorcerer_anger=0;
    gold=100;
}

Start::Start(string playername, string partymembers[], int size)
{
    player_name=playername;
    fullness=50;
    // int size=4;
    for (int i = 0; i < size; i++)
    {
        party_names[i]=partymembers[i];
        fullness_[i]=50;
    }
    sorcerer_anger=0;
    gold=100;
}

//getters
string Start::getPlayerName()
{
    return player_name;
}

int Start::getPlayerFullness()
{
    return fullness;
}

string Start::getPartyMemberName(string partymembername)
{
    for (int i = 0; i < 4; i++)
    {
        if (party_names[i] == partymembername)
        {
            return party_names[i];
        }
        
    }
    
}

int Start::getPartyMemberFullness(int index )
{
    if (index > 4)
    {
        return -1;
    }

    return fullness_[index];
    
}

string Start::getPartyMemberArray(int index)
{
    if (index > 5)
    {
        return "Invalid index";
    }

    return party_names[index];
    
}

int Start::getSorcererAnger()
{
    return sorcerer_anger;
}

int Start::getGold()
{
    if (gold == 0)
    {
        return -1;
    }
    return gold;
}
//
void Start::setPlayername(string playername)
{
    player_name=playername;
}

void Start::setPartyNames(string member1, string member2, string member3, string member4)
{
    party_names[0]=member1;
    party_names[1]=member2;
    party_names[2]=member3;
    party_names[3]=member4;
}

void Start::setPlayerFullness(int fullness_player)
{
    fullness=fullness_player;
}

void Start::setPartyFullness(int mem_full1, int mem_full2, int mem_full3, int mem_full4)
{
    fullness_[0]=mem_full1;
    fullness_[1]=mem_full2;
    fullness_[2]=mem_full3;
    fullness_[3]=mem_full4;

}

void Start:: setScorcererAnger(int anger)
{
    sorcerer_anger=anger;
}

void Start::setGold(int golds)
{
    gold +=golds;
}

//print party fullness and names
void Start::printParty()
{
    cout<<"+-------------+"<<endl;
    cout<<"| PARTY       |"<<endl;
    cout<<"+-------------+"<<endl;
    cout<<"| "<< getPlayerName() << " |  Fullness: " <<getPlayerFullness()<<endl;
    cout<<"| "<<getPartyMemberArray(0)<< " |  Fullness: "<< getPartyMemberFullness(0)<<endl;
    cout<<"| "<<getPartyMemberArray(1)<<" |  Fullness: "<< getPartyMemberFullness(1)<<endl;
    cout<<"| "<<getPartyMemberArray(2)<<" |  Fullness: "<<getPartyMemberFullness(2)<<endl;
    cout<<"| "<<getPartyMemberArray(3)<<" |  Fullness: "<<getPartyMemberFullness(3)<<endl;
    cout<<"+-------------+"<<endl;

}

int main()
{
    string username;
    string member_name;
    string party[4];

    //ask user for username
    //ask user for party names
    cout<<"Username: "<<endl;
    getline (cin, username);
    cout<<"Party member names (4): ";
    for (int i=0; i < 4; i++)
    {
        getline (cin, party[i]);
    }
    //run this array thru a parameterized constructr
    Start start_object= Start(username, party, 4);
    
    //if ActionMenu::NormalSpace, NPC or Room == -1, GAME OVER




    return 0;
}
