#include<iostream>
#include<iomanip>
#include"ActionMenu.h"
#include"Merchant.h"
#include"Map.h"

using namespace std;

ActionMenu::ActionMenu()
{
    action_option=0;
}

void ActionMenu::setActionOption(int option)
{
    action_option = option;
}

int ActionMenu::getActionOption()
{
    return action_option;
}
int ActionMenu::NormalSpace(int row, int col, Merchant temp, Start temp2, Map temp3)
{
    char movement;
    int cookware;
    //getActionOption();
    if (temp2.getPlayerFullness() == 0 || temp2.getSorcererAnger()==100 )
        {
            /* code */
            for (int i = 0; i < 4; i++)
            {
                if (temp2.getPartyMemberFullness(i)==0)
                {
                    return -1;
                }
                
            }
            return -1;
        }
    while (action_option !=5)
    {
        
        
    cout<<"You've landed on a Normal Space, what would you like to do?"<<endl;
    cout<<"1. Move"<<endl;
    cout<<"2. Investigate"<<endl;
    cout<<"3. Pick a Fight"<<endl;
    cout<<"4. Cook and Eat"<<endl;
    cout<<"5. Give Up"<<endl;
    cin>>action_option;
    switch (action_option)
    {
    case 1://move
        cout<<"Which direction would you like to move? (w,a,s,d)"<<endl;
        cin>>movement;
        move(movement);
        //20% of hunger dropping or each memeber
        int random= rand()%10;
        if (random == (rand()%10) || random == (rand()%10))
        {
            //reduce hunger by 1
            for (int i = 0; i < 4; i++)
            {
                int party_fullness= temp2.getPartyMemberFullness(i) ;
                party_fullness -= 1;
                temp2.setPartyFullness(i, party_fullness);
            }

            int player_fullness = temp2.getPlayerFullness();
            player_fullness --;
            temp2.setPlayerFullness(player_fullness);
            
        }
        

        break;
    case 2://investigate
        //if not marked as explored, player investigates...mark as explored
        if (temp3.isExplored(temp3.getPlayerRow(), temp3.getPlayerCol()))
        {
            cout<<"You've already explored this space. "<<endl;
            break;
        }
        else
        {
            temp3.isExplored(temp3.getPlayerRow(), temp3.getPlayerCol())== true;

        
        //10% chance player finds a key 
        int random = rand()%10;
        if (random == rand()%10)
        {
            cout<<"You found a key! You can use these to open Rooms"<<endl;
            int num_of_keys = temp.getAmountofKeys();
            num_of_keys ++;
            temp.setAmountofKeys(num_of_keys);
        }

        //20% chance player finds treauser (kind of treasure is determind by room count)
        int rand2= rand()%10;
        if (rand2 ==(rand()%10) || rand2 == (rand()%10) )
        {
            cout<<"You've found a Treasure! You can sell these to a merchant for Gold"<<endl;
            if (temp3.getRoomCount() == 0)
            {
                cout<<"You haven't entered any rooms yet! Move around the map to find a room, and possibly find a treasure!"<<endl;

            }
            else if (temp3.getRoomCount() == 1)
            {
                cout<<"You found a Silver Ring!"<<endl;
                temp.setAmountofTreasures(0, 1);
            }
            else if (temp3.getRoomCount() == 2)
            {
                cout<<"YOu found a Ruby Necklace"<<endl;
                temp.setAmountofTreasures(1, 1);

            }
            else if (temp3.getRoomCount() == 3)
            {
                cout<<"You found an Emerald Bracelet!"<<endl;
                temp.setAmountofTreasures(2, 1);
            }
            else if (temp3.getRoomCount() == 4)
            {
                cout<<"You found a Diamond circlet"<<endl;
                temp.setAmountofTreasures(3, 1);
            }
            else if (temp3.getRoomCount() == 5)
            {
                cout<<"You found a Gem-encrusted Goblet!"<<endl;
                temp.setAmountofTreasures(4, 1);
            }
            
            
        }
        //20% chance player fights rand monster... monster.h

        //after investigating, pevery party members fullness has a 50% chance in dropping by 1
        int rand3=rand()%10;
        if (rand3 == (rand()%10) || rand3 == (rand()%10) || rand3 == (rand()%10) || rand3 == (rand()%10) || rand3 == (rand()%10))
        {
            //reduce hunger by 1
            for (int i = 0; i < 4; i++)
            {
                int party_fullness= temp2.getPartyMemberFullness(i) ;
                party_fullness -= 1;
                temp2.setPartyFullness(i, party_fullness);
            }

            int player_fullness = temp2.getPlayerFullness();
            player_fullness --;
            temp2.setPlayerFullness(player_fullness);
            
            //if player fought monster, chance is not applied twice

        }
        
        
        }
        break;
    case 3://pick a fight
        break;
    case 4://cook and eat
        cout<<"Which cookware would you like to use?"<<endl;
        cout<<"1. Ceramic pot"<<endl;
        cout<<"2. Frying pan"<<endl;
        cout<<"3. Cauldron"<<endl;
        cin>>cookware;
        if (cookware == 1)
        {
            //remove 1 from ceramic pot index
            //reomve 5 kg from ing
            
            int amount_ceram=temp.getAmountofCookware(0);
            amount_ceram --;
            temp.setAmountofCookware(0, amount_ceram);
            temp.setIng(-5);
            //setIng definition for reference as to why -5 is the int parameter
            // void Merchant::setIng(int ings_)
            // {
            //     ingredients +=ings_;
            // }
            //this will add negative 5 from the amount of ing (subrtract 5)

            //inc fullness
            for (int i = 0; i < 4; i++)
            {
                int party_fullness= temp2.getPartyMemberFullness(i) ;
                party_fullness += 1;
                temp2.setPartyFullness(i, party_fullness);
            }

            int player_fullness = temp2.getPlayerFullness();
            player_fullness ++;
            temp2.setPlayerFullness(player_fullness);


            //if it breaks...
                //remove coookware form inventory, dont inc, ing lost
                //let party know
            
        }
        if ( cookware == 2)
        {
            //remove one from frying pan index
            //remove 5 kg
            int amount_pan=temp.getAmountofCookware(1);
            amount_pan --;
            temp.setAmountofCookware(0, amount_pan);
            temp.setIng(-5);
            //setIng definition for reference as to why -5 is the int parameter
            // void Merchant::setIng(int ings_)
            // {
            //     ingredients +=ings_;
            // }
            //this will add negative 5 from the amount of ing (subrtract 5)

            //inc fullness
            for (int i = 0; i < 4; i++)
            {
                int party_fullness= temp2.getPartyMemberFullness(i) ;
                party_fullness += 1;
                temp2.setPartyFullness(i, party_fullness);
            }

            int player_fullness = temp2.getPlayerFullness();
            player_fullness ++;
            temp2.setPlayerFullness(player_fullness);

        }
        if (cookware == 3)
        {
            //remove one from cauldron index
            //remove 5 kg from ingredients
            int amount_caul=temp.getAmountofCookware(1);
            amount_caul --;
            temp.setAmountofCookware(0, amount_caul);
            temp.setIng(-5);
            //setIng definition for reference as to why -5 is the int parameter
            // void Merchant::setIng(int ings_)
            // {
            //     ingredients +=ings_;
            // }
            //this will add negative 5 from the amount of ing (subrtract 5)

            //inc fullness
            for (int i = 0; i < 4; i++)
            {
                int party_fullness= temp2.getPartyMemberFullness(i) ;
                party_fullness += 1;
                temp2.setPartyFullness(i, party_fullness);
            }

            int player_fullness = temp2.getPlayerFullness();
            player_fullness ++;
            temp2.setPlayerFullness(player_fullness);

        }
    }
    }
    if (action_option == 5)
    {
        return -1;
    }
    
    
}

int ActionMenu::NPCSpace(int row, int col, Merchant temp, Start temp2, Map temp3)
{
    //reveal space, let player know they met an NPC
    
    switch (getActionOption())
    {
    case 1://move
        
        break;
    case 2://speak to npc
        break;
    case 3://end game
        
        break;
    default:
        break;
    }
}

int ActionMenu::RoomSpace(int row, int col, Merchant temp, Start temp2, Map temp3)
{

}
