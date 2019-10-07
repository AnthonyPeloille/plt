#include <iostream>

// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>

void testSFML() {
    sf::Texture texture;
}

// Fin test SFML

#include <state.h>

using namespace std;
using namespace state;

int main(int argc,char* argv[])
{
    //Exemple exemple;
    //exemple.setX(53);
    state::Door door {};
    cout << door.getTypeId() << endl;
    
    if(argc > 1){
        if(argv[1] == std::string("hello")){	
            cout << "Bonjour le monde !" << endl;
        }
    }

    return 0;
}
