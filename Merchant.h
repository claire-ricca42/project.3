#include<iostream>
#include<iomanip>
#include<fstream>
#include"Start.h"
#include"Map.h"
// #include"Inventory.h"

using namespace std;
//split
// int split(string input_string, char separator, string arr[], int arr_size)
// {
//     int m = 0;
//     int start=0;
//     int end=0;

//     if(input_string.length() == 0 || arr_size == 0)
//     {
//       return 0;  
//     }

//     while(end < input_string.length())
//     {
//         if(input_string[end]==separator)
//         {
//             if(m == arr_size)

//             {
//                 return -1;
//             }
//             arr[m++] = input_string.substr(start,(end-start));

//             end++;
//             start=end;
//         }
//         else 
//         {
//             end++;
//         }
//     }

//     if(m == arr_size)
//     {
//         return -1;
//     }
//     arr[m++] = input_string.substr(start,(end-start));
//     return m;
// }

class Merchant
{
    private:
    int ingredients;
    int ing_price;
    int armor;
    int armor_price;
    string items[2];
    string cookware[3];
    string weapons[5];
    int price_c[3];
    int price_w[5];
    double pob_c[3];
    int bonus_w[5];

    //pob = probability of breaking for cookware
    //bonus = bonus from weapons
    //don't really know if we need arrays for item names/price/etc but well keep them for now

    //need (an) array(s) to keep track of the party's AMOUNT of each thing
    int amount_cookware[3];
    int amount_weapons[5];
    int amount_treasures[5];
    int num_cookware;
    int num_weapons;
    int num_treasures;
    int num_keys;
    //all initialized to 0

    public:
    //consuctors?
    //default
    Merchant();
    //paramterize....
    
    //setts?
    int setArrays(string);

    void setArmor(int);

    void setIng(int);

    void setAmountofCookware(int, int);

    void setAmountofWeapons(int, int);

    void setAmountofTreasures(int, int);

    void setAmountofKeys(int);


    //getts?
    string getItemName(string);

    int getItemPrice(string);

    int getItemPoB();

    int getBonus();

    int getIngredients();

    int getArmor();

    int getIng();

    int getAmountofCookware(int);

    int getAmountofWeapons(int);

    int getAmountofTreasures(int);

    int getAmountofKeys();


    //other
    void statusUpdate(Start, Merchant, Map);

    void printMerchantMenu(int, Merchant, Start, Map);
    //just type menu from github, so we can call several times


};
