//Room.cpp
#include"Room.h"
#include<string>
using namespace std;

Room::Room(string nm, bool is,string itm)
{
    name = nm;
    room = is;
    item = itm;
}
bool Room::isRoom()
{
    return room;
}
string Room::getName()
{
    
    return name;
}
string Room::getItem()
{
    return item;
   
}



