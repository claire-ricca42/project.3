#include<iostream>
#include<iomanip>
#include<vector>
#include"Start.h"


using namespace std;

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

void Start::setPartyFullness(int index, int fullness)
{
    fullness_[index]=fullness;

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

