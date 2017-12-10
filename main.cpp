//main.cpp
#include<string>
#include<vector>
#include<iostream>
#include"Room.h"
using namespace std;

//prototypes
vector < vector <bool> > createMapChecker(vector <vector <bool> > & mapChecker);
vector < vector <string> > createMap(vector <vector <string> > & map);
vector < vector <string> > setItems(vector <vector <string> > & items);
void game();
void search(int tempR, int tempC, vector <vector <string> > items, vector <vector <bool> > & mapChecker);
string changeRooms(string location, int & tempR, int & tempC, string command,vector <vector <bool> > mapChecker, vector <vector <string> > map);

int main()
{
    cout<<"Hello welcome to the keys of all keys game"<<endl; 
    cout<<"your goal is to find the keys of all keys"<<endl;
    cout<<"type 'search' to see if there are any keys inside the rooms. "<<endl;
    cout<<"type goNorth, goEast, goSouth, or goWest to enter the room in the direction demanded."<<endl;
    cout<<"If I were you, I would make a map ;)"<<endl;

    game();
    return 0;
}

void game()
{
     
    vector < vector <bool> > mapChecker;
    mapChecker = createMapChecker(mapChecker);

    vector < vector <string> > map;
    map = createMap(map);
   
    vector <vector <string> > items;
    items = setItems(items);

    Room quad(" quad ", true, "nothing");
    Room cafe(" cafe ", true, "nothing");
    Room studyLounge(" Study Lounge ", true, "nothing");
    Room computerLab(" computer lab ", true, "key to the Zen Den, which is south of the lab!");
    Room library(" library ", true,"nothing");
    Room lockerRoom(" locker room", true, "key of all keys!");
    Room office(" office",true, "nothing");
    Room gym(" gym ",true, "nothing");
    Room outside("outside ",true, "nothing" );
    Room lab(" lab", true, "nothing");
    Room weldingRoom(" welding Room",true, "nothing");
    Room zenDen(" Zen Den", true, "key to the locker room, which is north of the gym");
      
    items[0][0] = computerLab.getItem();
    items[4][2] = zenDen.getItem();
    items[0][3] = lockerRoom.getItem();
 
    map[0][3] = lockerRoom.getName();
    map[1][0] = studyLounge.getName();
    map[1][1] = cafe.getName();
    map[1][2] = office.getName();
    map[1][3] = gym.getName();
    map[2][1] = quad.getName();
    map[2][2] = library.getName();
    map[2][3] = outside.getName();
    map[3][2] = lab.getName();
    map[3][3] = weldingRoom.getName();
    map[4][2] = zenDen.getName(); 
    map[0][0] = computerLab.getName();

    int tempR = 2;//start coordinate 
    int tempC = 1;//star coordinate map[2][1]
    string location;
    location = quad.getName();
    cout<<"You are currently in the "<<location<<endl;
    
 
    bool game = true;
    while(game == true)
    {
        string command;
        cin>>command;
       
        if(command == "goNorth"||command == "goEast"||command == "goSouth"||command == "goWest")
        {
            location = changeRooms(location, tempR, tempC, command, mapChecker, map);
        }
        if(command == "search")
        {
            search(tempR, tempC, items, mapChecker);
        }
        if(command == "exit")
        {
            game = false;
        }
        command.clear();
    }
}

void search(int tempR, int tempC, vector <vector <string> > items, vector <vector <bool> > & mapChecker)
{
    int count = 0;
   if(items[tempR][tempC] == "null")
   {
        cout<<"There are no keys in this room. Keep searching!"<<endl;
   }
   else
   {    
        cout<<"you have found the "<< items[tempR][tempC]<<endl; 
        count++;
        if(count == 1)
        {
            mapChecker[4][2] = true;
        }
        if(count == 2)
        {
            mapChecker[0][3] = true;
        }
        if(count == 3)
        {
            cout<<"Thanks for playing! Good-bye!"<<endl;
        }
   }
}

string changeRooms(string location, int & tempR,int & tempC,string command, vector <vector <bool> > mapChecker, vector <vector <string> > map)
{  

    int north = tempR - 1;
    int east = tempC + 1;
    int south = tempR + 1;
    int west = tempC - 1;
    if(command == "goNorth")
    {
        if(north > -1 && north < 5)
        {
            if(mapChecker[north][tempC] == true)
            {
                location = map[north][tempC];
                cout<<"You are now in the "<<location<<endl;
                tempR--;
            }
        
            else if(mapChecker[north][tempC] == false)
            {
                cout<<"oops you hit a wall!"<<endl;
            }
        }
        else
        {
            cout<<"You can't go there. You are at the edge of the map"<<endl;
        }
    }

    if(command == "goEast")
    {
        if(east > -1 && east < 4)
        {
            if(mapChecker[tempR][east] == true)
            {
                location = map[tempR][east];
                cout<<"You are now in the "<<location<<endl;
                tempC++;
            }
            else if(mapChecker[tempR][east])
            {
                cout<<"oops you hit a wall!"<<endl;
            }
        }
        else
        {
            cout<< "You can't go there. You are at the edge of the map."<<endl;
        }
    }
    if(command == "goSouth")
    {
        if(south > -1 && south < 5)
        {
            if(mapChecker[south][tempC] == true)
            {
                location = map[south][tempC];
                cout<<"You are now in the "<<location<<endl;
                tempR++;
            }
            else if(mapChecker[south][tempC] == false)
            {
                cout<<"opps you hit a wall!"<<endl;
            }
        }
        else
        {
            cout<<"You can't go there. You are at the edge of the map."<<endl;
        }
    }
    if(command == "goWest")
    {
        if(west > -1 && west < 4)
        {
            if(mapChecker[tempR][west] == true)
            {
                location = map[tempR][west];
                cout<<"You are now in the "<<location<<endl;
                tempC--;
            }
            else if(mapChecker[tempR][west] == false)
            {
                cout<<"oops you hit a wall! "<<endl;
            }
        }
        else
        {
            cout<<"You can't go there. You are at the edge of the map."<<endl;
        }
    }
    return location;
}

vector <vector <bool> > createMapChecker(vector < vector <bool> > & mapChecker)
{
    
    int rows = 5;
    int columns = 4;
    mapChecker.resize(rows);//number of rows
    for(int i = 0; i < rows; i++)
    {
        mapChecker[i].resize(columns);
        for(int c = 0; c < columns; c++)
        {
            mapChecker[i][c] = false;
        }
    } 
    mapChecker[0][0] = true;
    mapChecker[0][3] = false;
    mapChecker[1][0] = true;
    mapChecker[1][1] = true;
    mapChecker[1][2] = true;
    mapChecker[1][3] = true;
    mapChecker[2][1] = true;
    mapChecker[2][2] = true;
    mapChecker[2][3] = true;
    mapChecker[3][2] = true;
    mapChecker[3][3] = true;
    mapChecker[4][2] = false;
    
    return mapChecker;
}


vector <vector <string> > createMap(vector< vector <string> > & map)
{
    int rows = 5;
    int columns = 4;
    map.resize(rows);
    for(int r = 0; r < rows; r++)
    {
        map[r].resize(columns);
        for(int c = 0; c < columns; c++)
        {
            map[r][c] = "null";
        }
    }
    return map;
}

vector <vector <string> > setItems(vector< vector <string> > & items)
{
    int rows = 5;
    int columns = 4;
    items.resize(rows);
    for(int r = 0; r < rows; r++)
    {
        items[r].resize(columns);
        for(int c = 0; c < columns; c++)
        {
            items[r][c] = "null";
        }
    }
    return items;
}





