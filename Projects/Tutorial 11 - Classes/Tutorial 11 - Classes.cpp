#include <iostream>
#include "Enemy.h"

using namespace std;

int main()
{
    Enemy monster = Enemy{ "Monster", 5.0f };
    Enemy guard = Enemy{ "Guard", 6.5f };

    cout << monster.name << " : " << monster.damageAmount << " Damage" << endl;
    cout << guard.name << " : " << guard.damageAmount << " Damage" << endl;

    Enemy enemy;

    cout << enemy.name << " : " << enemy.damageAmount << " Damage" << endl;

    monster.RunDialogue();
    guard.RunDialogue();
    enemy.RunDialogue();
}