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

void display_collection_stats(t_collection & tcoll){
    char yesNo;
    cout<<"Memoire maximale: "<<tcoll.maxMem<<" Go"<<endl;
    cout<<"Nombre de jeux: "<<tcoll.nbGames<<endl;
    cout<<"Nombre de jeux eux installe: "<<tcoll.maxMem<<endl;
    cout<<"Afficher les jeux ? Y/N :"<<endl;
    cin>>yesNo;
    if(yesNo == 'Y' || yesNo == 'y'){
        for(int i = 0; i < tcoll.nbGames; i++){
            cout<<tcoll.collection[i]->game->title;
        }
    }
}

double total_memOccup(t_collection & tcoll){
    double tot;

    for(int i = 0; i < tcoll.nbGames; i++){
        tot+= tcoll.collection[i]->game->memOccup;
    }
    
    return tot;
}

void add_game(t_collection & tcoll, t_game newGame){
    if((tcoll.maxMem - total_memOccup(tcoll)) >= newGame.memOccup){
        tcoll.collection[tcoll.nbGames]->game = &newGame;
        tcoll.nbGames=+1;
    }else{
        cout<<"pas assez d'espace de stockage"<<endl;
    }
}

void delete_game(t_collection & tcoll, string gameTitle){
    int i = 0;
    while(tcoll.collection[i]->game->title != gameTitle){
        
    }
}