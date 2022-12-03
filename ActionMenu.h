#include<iostream>
#include<iomanip>
#include"Map.h"

using namespace std;

class ActionMenu
{
    private:

        int action_option;

    public:
        //setters/getters
    void setActionOption(int);
    int getActionOption();
        //other
    int NormalSpace(int, int, Merchant, Start, Map);
    int NPCSpace(int,int, Merchant, Start, Map);
    int RoomSpace(int, int, Merchant, Start, Map);


};