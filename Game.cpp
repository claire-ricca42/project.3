#include<iostream>
#include<iomanip>
#include<fstream>
#ifndef MAP_H
#define MAP_H
#include <cstdlib>

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

class Map
{
private:
    const char UNEXPLORED = '-'; // marker for unexplored spaces
    const char EXPLORED = ' ';   // marker for explored spaces
    const char ROOM = 'R';       // marker for room locations
    const char NPC = 'N';        // marker for NPC locations
    const char PARTY = 'X';      // marker for party position
    const char EXIT = 'E';       // marker for dungeon exit

    static const int num_rows_ = 12; // number of rows in map
    static const int num_cols_ = 12; // number of columns in map
    static const int max_npcs_ = 5;  // max non-player characters
    static const int max_rooms_ = 5; // max number of rooms

    int player_position_[2];              // player position (row,col)
    int dungeon_exit_[2];                 // exit location of the dungeon
    int npc_positions_[max_npcs_][3];     // stores the (row,col) positions of NPCs present on map and if they have been found
    int room_positions_[max_rooms_][2];   // stores the (row,col) positions of rooms present on map
    char map_data_[num_rows_][num_cols_]; // stores the character that will be shown at a given (row,col)

    int npc_count_;  // stores number of misfortunes currently on map
    int room_count_; // stores number of sites currently on map
public:
    Map();

    void resetMap();

    // getters
    int getPlayerRow();
    int getPlayerCol();
    int getDungeonExitRow();
    int getDungeonExitCol();
    int getRoomCount();
    int getNPCCount();
    int getNumRows();
    int getNumCols();
    bool isOnMap(int row, int col);
    bool isNPCLocation(int row, int col);
    bool isRoomLocation(int row, int col);
    bool isExplored(int row, int col);
    bool isFreeSpace(int row, int col);
    bool isDungeonExit(int row, int col);

    // setters
    void setPlayerPosition(int row, int col);
    void setDungeonExit(int row, int col);

    // other
    void displayMap();
    bool move(char);
    bool addNPC(int row, int col);
    bool addRoom(int row, int col);
    bool removeNPC(int row, int col);
    bool removeRoom(int row, int col);
    void exploreSpace(int row, int col);

    //added stuff
    void printStatus();
    //used for status update in Mercahnt

};
#endif

#include "Map.h"

using namespace std;

Map::Map()
{
    resetMap();
}

/*
 * Algorithm: Resets positions of player, NPCs, and rooms and clears map_data_
 * Set Player position coordinates to 0
 * Set npc_count_ to false
 * Set room_count_ to 0
 * loop i from 0 to max_npcs_
 *      Set row and col of location to -1
 * loop i from 0 to max_rooms
 *      Set row and col of room location to -1
 * loop i from 0 to num_rows_
 *      loop j from 0 to num_cols_
 *          Set (i,j) location on map_data_ to '-'
 * Parameters: none
 * Return: nothing (void)
 */
void Map::resetMap()
{
    // resets player position, count values, and initializes values in position arrays to -1
    player_position_[0] = 0;
    player_position_[1] = 0;

    // set dungeon exit
    dungeon_exit_[0] = num_rows_ - 1;
    dungeon_exit_[1] = num_cols_ / 2;

    for (int i = 0; i < max_npcs_; i++)
    {
        npc_positions_[i][0] = -1;
        npc_positions_[i][1] = -1;
    }
    npc_count_ = 0;

    for (int i = 0; i < max_rooms_; i++)
    {
        room_positions_[i][0] = -1;
        room_positions_[i][1] = -1;
    }
    room_count_ = 0;

    for (int i = 0; i < num_rows_; i++)
    {
        for (int j = 0; j < num_cols_; j++)
        {
            map_data_[i][j] = UNEXPLORED;
        }
    }
    map_data_[dungeon_exit_[0]][dungeon_exit_[1]] = EXIT;
}

// return player's row position
int Map::getPlayerRow()
{
    return player_position_[0];
}

// return player's column position
int Map::getPlayerCol()
{
    return player_position_[1];
}

// return current room count
int Map::getRoomCount()
{
    return room_count_;
}

// return dungeon exit row
int Map::getDungeonExitRow()
{
    return dungeon_exit_[0];
}

// return dungeon exit col
int Map::getDungeonExitCol()
{
    return dungeon_exit_[1];
}

// set player position, if in range
void Map::setPlayerPosition(int row, int col)
{
    if (isOnMap(row, col))
    {
        player_position_[0] = row;
        player_position_[1] = col;
    }
}

// set dungeon exit position, if in range
void Map::setDungeonExit(int row, int col)
{
    if (isOnMap(row, col))
    {
        dungeon_exit_[0] = row;
        dungeon_exit_[1] = col;
    }
}

// returns member variable num_rows_
int Map::getNumRows()
{
    return num_rows_;
}

// returns member variable num_cols_
int Map::getNumCols()
{
    return num_cols_;
}

/*
 * @brief Checks if the given (row, col) position is on the map
 *
 * Algorithm:
 *  if 0 <= row < num_rows_ and 0 <= col < num_cols_:
 *      return true
 *  else:
 *      return false
 *
 * Parameters: row (int), col (int)
 * Returns: bool
 */
bool Map::isOnMap(int row, int col)
{
    if (0 <= row && row < num_rows_ && 0 <= col && col < num_cols_)
    {
        return true;
    }
    return false;
}

/*
 * Algorithm: Checks if the location is an NPC location
 * if (row, col) is not within the map boundaries
 *      return false
 * loop i from 0 to npc_count_
 *      if (row,col) is a npc location
 *          return true
 * return true
 * Parameters: row (int), col (int)
 * return false
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isNPCLocation(int row, int col)
{
    if (!isOnMap(row, col))
    {
        return false;
    }
    for (int i = 0; i < npc_count_; i++)
    {
        if (row == npc_positions_[i][0] && col == npc_positions_[i][1])
        {
            return true;
        }
    }
    return false;
}

/*
 * Algorithm: Checks if the location is an room location
 * if (row, col) is not within the map boundaries
 *      return false
 * loop i from 0 to room_count_
 *      if (row,col) is a room location
 *          return true
 * return true
 * Parameters: row (int), col (int)
 * return false
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isRoomLocation(int row, int col)
{
    if (!isOnMap(row, col))
    {
        return false;
    }
    for (int i = 0; i < room_count_; i++)
    {
        if (row == room_positions_[i][0] && col == room_positions_[i][1])
        {
            return true;
        }
    }
    return false;
}

/*
 * Algorithm: Checks if the given row and column is an explored space
 * if (row, col) is not on the map:
 *     return false
 * if map_data_[row][col] is ' ':
 *     return true
 * if (row, col) is npc location and has been found:
 *     return true
 * else:
 *     return false
 */
bool Map::isExplored(int row, int col)
{
    if (!isOnMap(row, col))
    {
        return false;
    }
    if (map_data_[row][col] == EXPLORED)
    {
        return true;
    }
    for (int i = 0; i < npc_count_; i++)
    {
        if (npc_positions_[i][0] == row && npc_positions_[i][1] == col)
        {
            if (npc_positions_[i][2] == true)
            {
                return true;
            }
            break;
        }
    }
    return false;
}

/*
 * Algorithm: checks if (row, col) is dungeon_exit_
 *
 */
bool Map::isDungeonExit(int row, int col)
{
    if (row == dungeon_exit_[0] && col == dungeon_exit_[1])
    {
        return true;
    }
    return false;
}

/*
 * Algorithm: Checks if the given row and column on map is a free space
 * if row and column is not within the map boundaries
 *      return false
 * if row and column is a npc location
 *      return false
 * if row and column is a room location
 *      return false
 * if row and column is the dungeon exit
 *      return false
 * return true
 *
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
bool Map::isFreeSpace(int row, int col)
{
    if (!isOnMap(row, col))
    {
        return false;
    }
    if (isNPCLocation(row, col))
    {
        return false;
    }
    if (isRoomLocation(row, col))
    {
        return false;
    }
    if (isDungeonExit(row, col))
    {
        return false;
    }
    return true;
}

/*
 * Algorithm: Create an NPC on the map
 * if npc is present on map
 *      return false
 * if (row,col) is not a free space
 *      return false
 * store row and col values in npcPosition array
 * mark NPC as hidden
 * set (row,col) value in map_data_ to 'N'
 * increment npc_count_
 * return true
 *
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
bool Map::addNPC(int row, int col)
{
    if (npc_count_ >= max_npcs_)
    {
        return false;
    }
    if (!isFreeSpace(row, col))
    {
        return false;
    }

    npc_positions_[npc_count_][0] = row;
    npc_positions_[npc_count_][1] = col;
    npc_positions_[npc_count_][2] = false;
    map_data_[row][col] = NPC;
    npc_count_++;
    return true;
}

/*
 * Algorithm: Create a room on the map
 * if room_count_ is more than or equal to number of rooms
 *      return false
 * if (row,col) is not a free space
 *      return false
 * if next row in room_positions_ matrix is -1 -1
 *      store row, col and type values in the current row of room_positions_ matrix
 *      increment room_count_
 *      Set (row,col) value in map_data_ to 'R'
 *      return true
 *
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
bool Map::addRoom(int row, int col)
{

    if (room_count_ >= max_rooms_)
    {
        return false;
    }

    // location must be blank to spawn
    if (!isFreeSpace(row, col))
    {
        return false;
    }

    room_positions_[room_count_][0] = row;
    room_positions_[room_count_][1] = col;
    room_count_++;
    map_data_[row][col] = ROOM;
    return true;
}

/*
 * Algorithm: Removes the NPC at (row, col) from the map
 * loop i from 0 to npc_count_
 *      if npc_position[i] is (row, col)
 *          swap npc_position[npc_count_-1] with npc_position[i]
 *          reset npc_position[npc_count_-1][0] and npc_position[npc_count_-1][1] to -1
 *          reset npc_position[npc_count_-1][2] to 0
 *          decrement npc_count_
 *          set map data at (row, col) to explored
 *          return true
 * return false
 *
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
bool Map::removeNPC(int row, int col)
{
    for (int i = 0; i < npc_count_; i++)
    {
        if (npc_positions_[i][0] == row && npc_positions_[i][1] == col)
        {
            // swap i'th npc with last npc
            npc_positions_[i][0] = npc_positions_[npc_count_ - 1][0];
            npc_positions_[i][1] = npc_positions_[npc_count_ - 1][1];
            npc_positions_[i][2] = npc_positions_[npc_count_ - 1][2];
            // reset last npc
            npc_positions_[npc_count_ - 1][0] = -1;
            npc_positions_[npc_count_ - 1][1] = -1;
            npc_positions_[npc_count_ - 1][2] = false;
            // decrement npc_count_
            npc_count_--;
            // set map data to explored
            map_data_[row][col] = EXPLORED;
            return true;
        }
    }
    return false;
}

/*
 * Algorithm: Removes the room at (row, col) from the map
 * loop i from 0 to room_count_
 *      if room_position[i] is (row, col)
 *          swap room_position[room_count_-1] with room_position[i]
 *          reset room_position[room_count_-1][0] and room_position[room_count_-1][1] to -1
 *          decrement room_count_
 *          set map data at (row, col) to explored
 *          return true
 * return false
 *
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
bool Map::removeRoom(int row, int col)
{
    for (int i = 0; i < room_count_; i++)
    {
        if (room_positions_[i][0] == row && room_positions_[i][1] == col)
        {
            // swap i'th room with last room
            room_positions_[i][0] = room_positions_[room_count_ - 1][0];
            room_positions_[i][1] = room_positions_[room_count_ - 1][1];
            // reset last room
            room_positions_[room_count_ - 1][0] = -1;
            room_positions_[room_count_ - 1][1] = -1;
            // decrement room_count_
            room_count_--;
            // set map data to explored
            map_data_[row][col] = EXPLORED;
            return true;
        }
    }
    return false;
}

/*
 * Algorithm: Mark (row, col) as explored, either revealing NPC or empty space
 * if (row, col) is NPC location
 *      mark npc at player_position_ as found
 * else if (row, col) is a free space
 *      mark space as explored in map data
 *
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
void Map::exploreSpace(int row, int col)
{
    for (int i = 0; i < npc_count_; i++)
    {
        if (row == npc_positions_[i][0] && col == npc_positions_[i][1])
        {
            // mark NPC as found
            npc_positions_[i][2] = 1;
            return;
        }
    }
    if (isFreeSpace(row, col))
    {
        map_data_[player_position_[0]][player_position_[1]] = EXPLORED;
    }
}

/*
 * Algorithm: Make the player move based on the given command
 * if user inputs w and if its not the top row of the map
 *      Move the player up by one row
 * if user inputs s and if its not the bottom row of the map
 *      Move the player down by one row
 * if user inputs a and if its not the leftmost column
 *      Move the player left by one column
 * if user inputs d and if its not the rightmost column
 *      Move the player right by one column
 * if player moved
 *      if new location is an NPC location
 *          mark new location as explored
 *      return true
 * else
 *      return false
 *
 * Parameters: direction (char)
 * Return: boolean (bool)
 */
bool Map::move(char direction)
{
    // check input char and move accordingly
    switch (tolower(direction))
    {
    case 'w': // if user inputs w, move up if it is an allowed move
        if (player_position_[0] > 0)
        {
            player_position_[0] -= 1;
        }
        else
        {
            return false;
        }
        break;
    case 's': // if user inputs s, move down if it is an allowed move
        if (player_position_[0] < num_rows_ - 1)
        {
            player_position_[0] += 1;
        }
        else
        {
            return false;
        }
        break;
    case 'a': // if user inputs a, move left if it is an allowed move
        if (player_position_[1] > 0)
        {
            player_position_[1] -= 1;
        }
        else
        {
            return false;
        }
        break;
    case 'd': // if user inputs d, move right if it is an allowed move
        if (player_position_[1] < num_cols_ - 1)
        {
            player_position_[1] += 1;
        }
        else
        {
            return false;
        }
        break;
    default:
        return false;
    }
    // if new location is an NPC location, mark as explored
    if (isNPCLocation(player_position_[0], player_position_[1]))
    {
        exploreSpace(player_position_[0], player_position_[1]);
    }
    return true;
}

/*
 * Algorithm: This function prints a 2D map in the terminal.
 * Loop i from 0 to number of rows
 *      Loop j from 0 to number of columns
 *          if player position is at (i,j)
 *              print 'X'
 *          else if npc is at (i,j)
 *              if npc has been found:
 *                  print 'N'
 *              else
 *                  print '-'
 *          else
 *              print the value of (i,j) in map_data_
 *
 * Parameters: none
 * Return: nothing (void)
 */
void Map::displayMap()
{
    for (int i = 0; i < num_rows_; i++)
    {
        for (int j = 0; j < num_cols_; j++)
        {
            if (player_position_[0] == i && player_position_[1] == j)
            {
                cout << PARTY;
            }
            else if (map_data_[i][j] == 'N')
            { // NPC location, have to check if they were found yet
                for (int k = 0; k < npc_count_; k++)
                {
                    if (npc_positions_[k][0] == i && npc_positions_[k][1] == j)
                    {
                        if (npc_positions_[k][2] == true)
                        {
                            cout << NPC;
                        }
                        else
                        {
                            cout << UNEXPLORED;
                        }
                    }
                }
            }
            else
            {
                cout << map_data_[i][j];
            }
        }
        cout << endl;
    }
}

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

Merchant::Merchant()//contsuctor, setting everything(can just call this lmao)
{
    ingredients=0;
    armor =0;
    num_cookware=0;
    num_weapons=0; 
    num_treasures=0;

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



int main()
{
    string username;
    string member_name;
    string party[4];
    int am_ret_val;
    char direction;
    
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
    Map map;
    for (int i = 0; i < 4; i++)
    {
        map.addRoom((rand()%10), (rand()%10));
        map.addNPC((rand()%10), (rand()%10));
    }
    cout<<"Here is your map, R indicates a Room. You will need a Key to enter them, but be careful, there may be a monster lurking inside!"<<endl;
    cout<<"E indicates the exit to the dungeon, if you make it to the exit, you may have to defeat the Sorcerer to leave!"<<endl;
    cout<<"Not all spaces that aren't labeled are normal...some might have a hidden character, they may ask you questions and you may answer!"<<endl;
    cout<<"Good luck on your journey!"<<endl;
    cout<<"To move, use 'a' to go left, 'd' to go right, 'w' to go up, and 's' to go down"<<endl;
    map.displayMap();
    while (am_ret_val !=-1)
    {
        cout<<"Let's begin! whcih way would you like to move fisrt?"<<endl;
        cin>>direction;
        map.move(direction);
        map.displayMap();
        while (!map.isDungeonExit(map.getPlayerRow(), map.getPlayerCol()))
    {
        if (!(map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())) && !(map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol())))
        {
            cout<<"Normal"<<endl;
            //this is where we would call action_object.NormalSpace(params);
        }
        if (map.isNPCLocation(map.getPlayerRow(), map.getPlayerCol()))
        {
            cout<<"NPC"<<endl;
            //this is where we would call action_object.NPCSpace(params);
        }
        if (map.isRoomLocation(map.getPlayerRow(), map.getPlayerCol()))
        {
            cout<<"Room"<<endl;
            //this is where we would call action_object.RoomSpace(params);
        }
        cout<<"Which way would you like to go?"<<endl;
        cin >> direction;
        map.move(direction);
        map.displayMap();
    }
        
    }

    if (am_ret_val == -1)
    {
        ofstream final_stats ("finalstats.txt");
        if (final_stats.is_open())
        {
            // final_stats << <Merchant>.statusUpdate();
            final_stats << "Sorcerer's Anger: " <<start_object.getSorcererAnger()<<endl;
            final_stats <<"+-------------+"<<endl;
            final_stats<<"| PARTY       |"<<endl;
            final_stats<<"+-------------+"<<endl;
            final_stats<<"| "<< start_object.getPlayerName() << " |  Fullness: " <<start_object.getPlayerFullness()<<endl;
            final_stats<<"| "<<start_object.getPartyMemberArray(0)<< " |  Fullness: "<< start_object.getPartyMemberFullness(0)<<endl;
            final_stats<<"| "<<start_object.getPartyMemberArray(1)<<" |  Fullness: "<< start_object.getPartyMemberFullness(1)<<endl;
            final_stats<<"| "<<start_object.getPartyMemberArray(2)<<" |  Fullness: "<<start_object.getPartyMemberFullness(2)<<endl;
            final_stats<<"| "<<start_object.getPartyMemberArray(3)<<" |  Fullness: "<<start_object.getPartyMemberFullness(3)<<endl;
            final_stats<<"+-------------+"<<endl;
           

        }

        
        return 0;
    }

    return 0;
}
