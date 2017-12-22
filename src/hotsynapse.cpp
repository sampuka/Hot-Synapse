#include <SFML/Graphics.hpp>
#include <iostream>

#include "HotSynapseGame.hpp"

using namespace std;

int main()
{
    HotSynapseGame *game = new HotSynapseGame;

    while(!game->isGameClosed())
	;
    
    cout << "Reached end of main()" << endl;
    return 0;
}
