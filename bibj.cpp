#include <iostream>
using namespace std;

struct t_game{
    string title;
    int release_year;
    double memOccup;
};

struct t_gamePerso{
    int playtime;
    double trophies;
    t_game* game;
    bool isInstalled;
};

struct t_collection{


};