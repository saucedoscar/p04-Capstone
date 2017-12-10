//Room. h file
#ifndef _ICECREAM_H_
#define _ICEREAM_H_
#include<string>
using namespace std;
class Room
{
    private:
    string name;
    bool room;
    string item;
    public:
    Room(string nm, bool is, string itm); 
    bool isRoom();
    string getName();
    string getItem();
};

#endif
