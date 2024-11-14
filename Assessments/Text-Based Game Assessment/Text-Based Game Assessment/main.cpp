#include "main.h"

int main()
{
    gameState = GameStates::INTRO;

    while (true)
    {
        switch (gameState)
        {
        case GameStates::UNDEFINED:
            Logging::LogWarning("Invalid GameState!");
            break;

        case GameStates::INTRO:
            intro.main();
            break;

        case GameStates::ENCOUNTER:
            encounter.main();
            break;

        case GameStates::CAMPFIRE:
            campfire.main();
            break;
        }
    }

    return gameState;
}