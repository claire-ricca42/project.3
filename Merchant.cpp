#include<iostream>
#include<iomanip>
#include<fstream>
#include"Merchant.h"
#include"Start.h"


using namespace std;

// private:
//     int ingredients;
//     int armor;
//     string items[2];
//     string cookware[3];
//     string weapons[5];
//     int price_c[3];
//     int price_w[5];
//     int pob_c[3];
//     int pob_w[5];
/*NOTES
    *Most likely will be able to remove anything that deals with the items, cookware, and weapons array since we only need access to the amounts
        //this includes the mutators and accessors for names prices etc..
    *Creating objects in classes..will it overshadow the players actaul object of that class?
    *can you run a type /class/ as a parameter if its included? will this solve the problem above?
    *also just took the status update from INventory class and put it here, but it can be called inidiually
    *this measn we migh talso be able to make the inventory class just something else all together
*/

Merchant::Merchant()//contsuctor, setting everything(can just call this lmao)
{
    ingredients=0;
    armor =0;
    num_cookware=0;
    num_weapons=0; 
    num_treasures=0;

    //manually setting each arry (if no text file used)
    // items[0]="Cookware";
    // items[1]="Weapons";

    // cookware[0]="Ceramic Pot";
    // cookware[1]="Frying Pan";
    // cookware[2]="Cauldron";
    // //Ceramic Pot,Frying Pan,Cauldron
    // price_c[0]=2;
    // price_c[1]=10;
    // price_c[2]=20;
    // //prices of each cookware w corresponding idexes
    // weapons[0]="Stone Club";
    // weapons[1]="Iron Spear";
    // weapons[2]="Mytrhil Rapier";
    // weapons[3]="Flaming Battle-Axe";
    // weapons[4]="Vorpal Longsword";
    // //Stone Club,Iron Spear,Mythril Rapier,Flaming Battle-Axe,Vorpal Longsword
    
    // price_w[0]=2;
    // price_w[1]=2;
    // price_w[2]=5;
    // price_w[3]=15;
    // price_w[4]=50;
    // //prices of weapons

    // //pob and bonus
    //     //conver percent into decimal
    // pob_c[0]=.25;
    // pob_c[1]=.10;
    // pob_c[2]=.02;

    // bonus_w[0]=0;
    // bonus_w[1]=0;
    // bonus_w[2]=1;
    // bonus_w[3]=2;
    // bonus_w[4]=3;
    //access these vals in driver and subtract from party gold
        //access using getter fxn!
    for (int i = 0; i < 3; i++)//setting the amount of each items array to 0
    {
        amount_cookware[i]=0;
    }
    for (int i = 0; i < 5; i++)
    {
        amount_weapons[i]=0;
        amount_treasures[i]=0;
    }
    
}

//setter is just going to do the same as default constructor but with for loops and a filename!
//dont really know if we need this either!
// int Merchant::setArrays(string filename)
// {
//     // filename="mercahnt.txt";
//     string index[4];//temp for cookware
//     string temp[6];//temp for weapons
//     ifstream in_file(filename);
//     //file won't fail because we set the filename to something we already have
//     if (in_file.fail())
//     {
//         return -1;
//     }

//     string line;
//     while (getline(in_file, line))
//     {
//         int ret_val=split(line,',',index,6);
//         if (ret_val == 4)
//         //means it was cookware since theres on only 4 arrays
//         {
//             split(line, ',', index, 4);
//             //cookware
//             items[0]=index[0];
//             for (int i = 0; i < 3; i++)
//             {
//                 cookware[i]=index[i+1];
//                 //set price/pob manually?
//             }
            
//         }

//         if(ret_val == 6)
//         {
//             split(line, ',', index, 6);
//             items[1]=index[0];
//             for (int i = 0; i < 5; i++)
//             {
//                 weapons[i]=index[i+1];
//                 //set weapon price/bonus...manually?
                
//             }
            
//         }
        
        

        
//     }
    


    
// }

void Merchant::setArmor(int armor_ct)
{
    armor =armor_ct;
}

void Merchant::setIng(int ings_)
{
    ingredients +=ings_;
}

void Merchant::setAmountofCookware(int index, int amount)
{
    num_cookware = amount;
    amount_cookware[index]=num_cookware;

}

void Merchant::setAmountofWeapons(int index, int amount)
{
    num_weapons =amount;
    amount_weapons[index]=num_weapons;
}

void Merchant::setAmountofTreasures(int index, int amount)
{
    num_treasures += amount;
    amount_treasures[index]=num_treasures;
}

void Merchant::setAmountofKeys(int num_key)
{
    num_keys =num_key;
}

string Merchant::getItemName(string item_name)
{
    //return //index of items array depending on...if it matches item name in param
    //think like the findAuthor function
    //so like if item_name==cookware[i] return cookware[i]
        //if not, if weapons[i]== item_name return weapons[i]
        //if not return DNE;
    for (int i = 0; i < 4; i++)//cookware first
    {
        if (cookware[i] == item_name)
        {
            return cookware[i];
        }
        else
        {
            return "DNE";
        }
    }
    for (int i = 0; i < 6; i++)
    {
        if(weapons[i]==item_name)
        {
            return weapons[i];
        }
        else
        {
            return "DNE";
        }
    }
    
    //two arrays of cookware and weapons
    //cookware is 4, weapons is 6


}

int Merchant::getItemPrice(string item_name)
{
    //return index of cookware or weapons w corresponding index as item name
    //same code as get Item name but going to be returning index from price array
     for (int i = 0; i < 4; i++)//cookware first
    {
        if (cookware[i] == item_name)
        {
            return price_c[i];
        }
        else
        {
            return -1;
        }
    }
    for (int i = 0; i < 6; i++)
    {
        if(weapons[i]==item_name)
        {
            return price_w[i];
        }
        else
        {
            return -1;
        }
    }
}

int Merchant::getItemPoB()
{
    //return index of cook/weap same as price index
    //dont really know if we need this....

}

//get bonus?
int Merchant::getBonus()
{

}

int Merchant::getArmor()
{
    //armor is just incremented by 1 when purchased btw
    return armor;
}

int Merchant::getIng()
{
    return ingredients;
}

int Merchant::getAmountofCookware(int index)
{
    return amount_cookware[index];

}

int Merchant::getAmountofWeapons(int index)
{
    return amount_weapons[index];
}

int Merchant::getAmountofTreasures(int index)
{
    return amount_treasures[index];
}

int Merchant::getAmountofKeys()
{
    return num_keys;
}
//print
void Merchant::statusUpdate(Start g, Merchant m, Map temp)
{
    //why wont it include the classes/member fucntioins?
    // ingredients_.getIng();
    //use getters for all cookware, weaponry, and treasures
    // Start g;
    // Merchant m;
    //creatign objects to use getter functions
    //TEST CASES IN DRIVER:
        //see if this overhsadows the object created in the main
        //dont want the amounts to be completely unrelated to the party's actual amount
    cout<<"+-------------+"<<endl;
    cout<<"| ROOMS       |"<<endl;
    cout<<"+-------------+"<<endl;
    cout<<"|Rooms Cleared: "<<temp.getRoomCount()<<" | Keys: "<< m.getAmountofKeys()<<"| Anger Level: "<<g.getSorcererAnger(); 
    cout<<"+-------------+"<<endl;
    cout<<"| INVENTORY   |"<<endl;
    cout<<"+-------------+"<<endl;
    cout<<"| Gold        |"<<g.getGold()<<endl;
    cout<<"| Ingredients |"<< m.getIng()<< "kg"<<endl;
    cout<<"| Cookware    | P:" <<m.getAmountofCookware(0) <<"| F:"<< m.getAmountofCookware(1) <<"|C:"<< m.getAmountofCookware(2)<<endl;
    cout<<"| Weapons     | C:"<<m.getAmountofWeapons(0)<<"| S:"<< m.getAmountofWeapons(1)<< "| R:"<< m.getAmountofWeapons(2) <<"| B:" <<m.getAmountofWeapons(3) <<"| L:"<< m.getAmountofWeapons(4)<<endl;
    cout<<"| Armor       |"<< m.getArmor()<<endl;
    cout<<"| Treasures   | R:"<< m.getAmountofTreasures(0)<< "| N:"<< m.getAmountofTreasures(1) <<"| B:" <<m.getAmountofTreasures(2) <<"| C:"<< m.getAmountofTreasures(3) <<"| G:"<< m.getAmountofTreasures(4)<<endl;
    
}

void Merchant :: printMerchantMenu(int option, Merchant temp, Start tempo, Map temp2)
{
    string response = "";
    int choice = 0;
    int ing_purchased = 0;
    int cookware_choice = 0;
    int pots_bought = 0;
    int pans_bought = 0;
    int cauldron_bought = 0;
    int weapon_choice=0;
    int clubs_bought=0;
    int spears_bought=0;
    int raps_bought;
    int axes_bought=0;
    int swords_bought=0;
    int armor_bought;
    int treasures_sold=0;
    int amt_rings, amt_bracs, amt_circlets, amt_necklace, amt_goblet = 0;
    int price = 0;
    //use if statemnets to alter the price depending on what room the party is in

    // Merchant temp;

    // Start tempo;
    //will this be completely unrelated to parties actual amounts?
    //can i run type Inventory object through as a parameter?
    

    while (option !=6)
    {  
        tempo.printParty();
        temp.statusUpdate(tempo, temp, temp2);

        if (tempo.getGold() == -1)
        {
            cout<<"You don't have enough gold to purchase from me!"<<endl;
            cout<<"You have "<<tempo.getGold()<<" gold between your party, maybe try trading a treasure!"<<endl;
        }

        cout << "Choose one of the following:" << endl;
        cout << "1. Ingredients: To make food, you have to cook raw ingredients." << endl;
        cout << "2. Cookware: You will need something to cook those ingredients." << endl;
        cout << "3. Weapons: It's dangerous to go alone, take this!" << endl;
        cout << "4. Armor: If you want to survive monster attacks, you will need some armor." << endl;
        cout << "5. Sell treasures: If you find anything shiny, I would be happy to take it off your hands." << endl;
        cout << "6. Leave: Make sure you get everything you need, I'm leaving after this sale!" << endl;
        cin >> option;
        switch (option)
        {
        case 1://ingredetns
        // The merchant recommends the player(s) should purchase at least 10 kg of ingredients per person, at 1 gold piece per kilogram of food.
        // Ask the player how many kilograms of ingredients they wish to purchase.
        // Compute and print the current total cost so far.
            cout << "How many kilograms of ingredients do you wish to purchase? You should have at least 10 kg per person" << endl;
            cin >> ing_purchased;

            temp.setIng(ing_purchased);
            /*if <mapobject.getplayerPosition == room 1, 2, 3 etc...*/
            price = ing_purchased; //number of kg purchased * 1
            tempo.setGold(price * -1);//want to subtract from gold so multiply by -1
            break;

        case 2://cookware
            // Ask the player which cookware they would like to buy. They can buy different types, and more than one.
            // Compute and print the current total cost so far. 
            cout << "Choose one of the following:" << endl;
            cout << "1. (25%) Ceramic Pot [2 Gold]" << endl;
            cout << "2. (10%) Frying Pan [10 Gold]" << endl;
            cout << "3. ( 2%) Cauldron [20 Gold]" << endl;
            cout << "4. Cancel" << endl;
            cin >> cookware_choice;

            if(cookware_choice == 1)
            {
                cout << "How many Ceramic Pots would you like to purchase?" << endl;
                cin >> pots_bought;
                price =pots_bought * 2;
                cout<<"You want to purchase "<<pots_bought<<" Ceramic Pot(s) for"<<price<<" gold? (y/n)"<<endl;
                cin>> response;
                if (response == "n")
                {
                    break;
                }
                else
                {
                    cout<<"Alright, here you go! "<<pots_bought<<" pot(s)."<<endl;
                    tempo.setGold(price*-1);
                    //set amount in array 
                    temp.setAmountofCookware(0, pots_bought);
                    //0 index = pots, pots_bought= amount
                }
                
            }
            if(cookware_choice == 2)
            {
                cout << "How many Frying Pans would you like to purchase?" << endl;
                cin >> pans_bought;
                price = pans_bought * 10;
                cout<<"You want to buy "<<pans_bought<<" Frying Pan(s) for"<< price<<" gold? (y/n)"<<endl;
                cin>>response;
                if (response == "n")
                {
                    break;
                }
                else
                {
                    cout<<"Great! Here's "<<pans_bought<<" pan(s)"<<endl;
                    tempo.setGold(price*-1);
                    //set amount in array
                    temp.setAmountofWeapons(1, pans_bought);
                }
                
            }
            if(cookware_choice == 3)
            {
                cout << "How many Cauldrons would you like to purchase?" << endl;
                cin >> cauldron_bought;
                price = cauldron_bought * 20;
                cout<<"You would like to purchase "<< cauldron_bought<< " Cauldron(s) for"<<price<<" gold? (y/n)"<<endl;
                cin>>response;
                if (response == "n")
                {
                    break;
                }
                else
                {
                    cout<<"Great! I'll give you"<< cauldron_bought<<" cauldron(s)."<<endl;
                    tempo.setGold(price*-1);
                    //set amount in array 
                    temp.setAmountofCookware(2, cauldron_bought);
                }
                
            }
            if (cookware_choice == 4)
            {
                break;
            }
        break;

        case 3://weapons, same as cookware just more 
            //You need weapons to be able to fend off monsters, otherwise, you can only run! Equipping your team with the maximum number of weapons (1 weapon per person) and buying upgraded weapons that are worth 5 gold pieces will maximize your chances of survival during an attack. You can have a maximum of 5 weapons. These are the different types of weapons:
            // A club (C) costs 2 gold pieces.
            // A spear (S) costs 2 gold pieces.
            // A +1 rapier (R) costs 5 gold pieces.
            // A +2 battle-axe (B) costs 15 gold pieces.
            // A +3 longsword (L) costs 50 gold pieces.
            // Ask the player which weapons they would like to purchase.
            // Compute and print the current total cost so far. 
            cout<<"Choose one of the following:"<<endl;
            cout<<"1. Stone Club (2 Gold)"<<endl;
            cout<<"2. Iron Spear (2 Gold)"<<endl;
            cout<<"3. Mythril Rapier (5 Gold)"<<endl;
            cout<<"4. Flaming Battle-Axe (15 Gold)"<<endl;
            cout<<"5.Vorpal Longsword (50 Gold)"<<endl;
            cout<<"6. Cancel"<<endl;
            cin >> weapon_choice;
            if (weapon_choice == 1)
            {
                cout<<"How many Stone Clubs would you like to purchase?"<<endl;
                cin >> clubs_bought;
                price= clubs_bought * 2;
                cout<<"You want to buy "<<clubs_bought<<" Stone Club(s) for "<<price<<" gold? (y/n)"<<endl;
                cin >> response;
                if (response == "n")
                {
                    break;
                }
                else
                {
                    cout<<"Great! Here's "<<clubs_bought<<" Stone club(s)"<<endl;
                    tempo.setGold(price * -1);
                    //set amount 
                    temp.setAmountofWeapons(0, clubs_bought);
                }
                
            }
            if (weapon_choice == 2)
            {
                cout<<"How many Iron Spears would you like to purchase?"<<endl;
                cin >> spears_bought;
                price= spears_bought * 2;
                cout<<"You want to buy "<<spears_bought<<" Iron Spear(s) for "<<price<<" gold? (y/n)"<<endl;
                cin >> response;
                if (response == "n")
                {
                    break;
                }
                else
                {
                    cout<<"Great! Here's "<<spears_bought<<" Iron Spear(s)"<<endl;
                    tempo.setGold(price * -1);
                    //set amount 
                    temp.setAmountofWeapons(1, spears_bought);
                }
                
            }
            if (weapon_choice == 3)
            {
                cout<<"How many Mythril Rapiers would you like to purchase?"<<endl;
                cin >> raps_bought;
                price= raps_bought * 5;
                cout<<"You want to buy "<<raps_bought<<" Mythril Rapier(s) for "<<price<<" gold? (y/n)"<<endl;
                cin >> response;
                if (response == "n")
                {
                    break;
                }
                else
                {
                    cout<<"Great! Here's "<<raps_bought<<" Stone club(s)"<<endl;
                    tempo.setGold(price * -1);
                    //set amount 
                    temp.setAmountofWeapons(2, raps_bought);
                }
                
            }
            if (weapon_choice == 4)
            {
                cout<<"How many Flaming Battle-Axes would you like to purchase?"<<endl;
                cin >> axes_bought;
                price= axes_bought * 15;
                cout<<"You want to buy "<<axes_bought<<" Flmaing Battle-Axe(s) for "<<price<<" gold? (y/n)"<<endl;
                cin >> response;
                if (response == "n")
                {
                    break;
                }
                else
                {
                    cout<<"Great! Here's "<<axes_bought<<" Stone club(s)"<<endl;
                    tempo.setGold(price * -1);
                    //set amount 
                    temp.setAmountofWeapons(0, axes_bought);
                }
                
            }
            if (weapon_choice == 5)
            {
                cout<<"How many Vorpal Longswords would you like to purchase?"<<endl;
                cin >> swords_bought;
                price= swords_bought * 50;
                cout<<"You want to buy "<<swords_bought<<" Vorpal Longsword(s) for "<<price<<" gold? (y/n)"<<endl;
                cin >> response;
                if (response == "n")
                {
                    break;
                }
                else
                {
                    cout<<"Great! Here's "<<swords_bought<<" Vorpal Longsword(s)"<<endl;
                    tempo.setGold(price * -1);
                    //set amount 
                    temp.setAmountofWeapons(0, swords_bought);
                }
                
            }
            if (weapon_choice == 6)
            {
                break;
            }
            
            
            
            break;

        case 4://armor
            cout<<"How many suits of armor can I get you? (enter 0 to return to menu)"<<endl;
            cin>>armor_bought;
            if (armor_bought == 0)
            {
                break;
            }
            price = armor_bought * 5;
            cout<<"You want to buy "<< armor_bought<<" suits of armor for"<<price<<" gold? (y/n)"<<endl;
            cin>>response;
            if (response == "n")
            {
                break;
            }
            else
            {
                cout<<"Thank you for your purchase, the armor should protect you well!"<<endl;
                tempo.setGold(price * -1);
                //set amount of armor
                temp.setArmor(armor_bought);
            }
            
            break;
        case 5://sell treasures
            cout<<"Let's see what treasures you have."<<endl;
            for (int i = 0; i < 5; i++)
            {
                int ret_val=0;
                ret_val += temp.getAmountofTreasures(i); 
                if ( ret_val== 0)//never incremented
                {
                    cout<<"Looks like you don't have anything for a fair trade! Maybe next time..."<<endl;
                    break;
                }
                
            }
            //print inventory of just treasures
            cout<<"Silver Ring(s): "<<temp.getAmountofTreasures(0);
            cout<<"Ruby necklace(s): "<<temp.getAmountofTreasures(1);
            cout<<"Emerald Bracelet(s): "<<temp.getAmountofTreasures(2);
            cout<<"Diamond circlet(s): "<<temp.getAmountofTreasures(3);
            cout<<"Gem-encrusted goblet(s): "<<temp.getAmountofTreasures(4);
            
            cout<<"And which of those would you like to sell?"<<endl;
            cout<<"1. Silver Ring"<<endl;
            cout<<"2. Ruby Necklace"<<endl;
            cout<<"3. Emerald Bracelet"<<endl;
            cout<<"4. Diamond ciclet"<<endl;
            cout<<"5. Gem-encrusted goblet"<<endl;
            cout<<"6. Cancel"<<endl;
            cin>>treasures_sold;

            if (treasures_sold == 1)
            {
                cout<<"How many of your Silver Rings would you like to sell?"<<endl;
                cin>>amt_rings;
                price = amt_rings * 10;
                if (amt_rings > temp.getAmountofTreasures(0))
                {
                    cout<<"You don't have that many!"<<endl;
                    cout<<"How many would you like to sell?"<<endl;
                    cin>>amt_rings;
                }
                cout<<"You would like to sell"<< amt_rings<<" rings for"<<price<<" gold? (y/n)"<<endl;
                cin>>response;
                if (response == "y")
                {
                    cout<<"Great! Here's "<<price<<" gold"<<endl;
                    tempo.setGold(price);
                }
                
                
            }
            if (treasures_sold == 2)
            {
                cout<<"How many of your Ruby Necklaces would you like to sell?"<<endl;
                cin>>amt_necklace;
                price = amt_necklace * 20;
                if (amt_necklace > temp.getAmountofTreasures(1))
                {
                    cout<<"You don't have that many!"<<endl;
                    cout<<"How many would you like to sell?"<<endl;
                    cin>>amt_necklace;
                }
                cout<<"You would like to sell"<< amt_necklace<<" necklace(s) for"<<price<<" gold? (y/n)"<<endl;
                cin>>response;
                if (response == "y")
                {
                    cout<<"Great! Here's "<<price<<" gold"<<endl;
                    tempo.setGold(price);
                }
            }
            if (treasures_sold == 3)
            {
                cout<<"How many of your Emerald Bracelets would you like to sell?"<<endl;
                cin>>amt_bracs;
                price = amt_bracs * 30;
                if (amt_bracs> temp.getAmountofTreasures(2))
                {
                    cout<<"You don't have that many!"<<endl;
                    cout<<"How many would you like to sell?"<<endl;
                    cin>>amt_bracs;
                }
                cout<<"You would like to sell"<< amt_bracs<<" braclet(s) for"<<price<<" gold? (y/n)"<<endl;
                cin>>response;
                if (response == "y")
                {
                    cout<<"Great! Here's "<<price<<" gold"<<endl;
                    tempo.setGold(price);
                }
            }
            if (treasures_sold == 4)
            {
                cout<<"How many of your Diamond Circlets would you like to sell?"<<endl;
                cin>>amt_circlets;
                price = amt_circlets * 40;
                if (amt_circlets > temp.getAmountofTreasures(3))
                {
                    cout<<"You don't have that many!"<<endl;
                    cout<<"How many would you like to sell?"<<endl;
                    cin>>amt_circlets;
                }
                cout<<"You would like to sell"<< amt_circlets<<" circlet(s) for"<<price<<" gold? (y/n)"<<endl;
                cin>>response;
                if (response == "y")
                {
                    cout<<"Great! Here's "<<price<<" gold"<<endl;
                    tempo.setGold(price);
                }
            }
            if (treasures_sold == 5)
            {
                cout<<"How many of your Gem-encrusted Goblets would you like to sell?"<<endl;
                cin>>amt_goblet;
                price = amt_goblet * 50;
                if (amt_rings > temp.getAmountofTreasures(4))
                {
                    cout<<"You don't have that many!"<<endl;
                    cout<<"How many would you like to sell?"<<endl;
                    cin>>amt_goblet;
                }
                cout<<"You would like to sell"<< amt_goblet<<" goblet(s) for"<<price<<" gold? (y/n)"<<endl;
                cin>>response;
                if (response == "y")
                {
                    cout<<"Great! Here's "<<price<<" gold"<<endl;
                    tempo.setGold(price);
                }
            }
            if (treasures_sold == 6)
            {
                break;
            }
            // 1 Room: Silver ring (R) - 10 gold pieces each
            // 2 Rooms: Ruby necklace (N) - 20 gold pieces each
            // 3 Rooms: Emerald bracelet (B) - 30 gold pieces each
            // 4 Rooms: Diamond circlet (C) - 40 gold pieces each
            // 5 Rooms: Gem-encrusted goblet (G) - 50 gold pieces each
            break;

        default:
            break;
        }
    }
    
    if(option ==6)
    {
        cout << "Are you sure you're finished? You won't be able to buy anything else from me! (y/n)" << endl;
        cin >> response;
        if(response == "y")
        {
          cout <<  "Stay safe out there! Goodbye!" << endl;
          return;
        }
        
    }

}
