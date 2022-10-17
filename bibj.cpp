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
    double maxMem;
    int nbGames;
    t_gamePerso** collection;
    int capaTab;
    int installGames;
};

void create_collection(t_collection & tcoll){
    cout<<"Memoire maximale de la collection ?"<<endl;
    cin>>tcoll.maxMem;
    tcoll.installGames = 0;
    tcoll.nbGames = 0;
    tcoll.capaTab = (tcoll.maxMem)/20; // pour 500Go on aura au plus 25 jeux ?

    //allocation
    tcoll.collection = new t_gamePerso*[tcoll.capaTab];
    for(int i = 0; i < tcoll.capaTab; i++){
        tcoll.collection[i] = new t_gamePerso[tcoll.capaTab];
    }

}

void delete_collection(t_collection & tcoll){
    for(int i = 0; i < tcoll.capaTab; i++){
        delete[] tcoll.collection[i];
    }
    
    delete[] tcoll.collection;
    tcoll.capaTab = 0;
}

