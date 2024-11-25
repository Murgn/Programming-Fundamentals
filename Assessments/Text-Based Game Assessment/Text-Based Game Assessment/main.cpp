#include "main.h"

int main()
{
    Utilities::clear();
    Utilities::initRand();
    Game::gameState = Game::GameStates::INTRO;
    //Game::settings.encounter = 19; // REMOVE AFTER

    while (true)
    {
        switch (Game::gameState)
        {
        case Game::GameStates::UNDEFINED:
            Logging::LogWarning("Invalid GameState!");
            break;

        case Game::GameStates::INTRO:
            intro.main();
            break;

        case Game::GameStates::ENCOUNTER:
            encounter.main();
            break;

        case Game::GameStates::CAMPFIRE:
            campfire.main();
            break;
        }
    }

    return Game::gameState;
}