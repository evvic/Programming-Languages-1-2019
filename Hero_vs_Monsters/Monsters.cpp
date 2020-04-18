// -----------------------------------------------------------------------
// monsters.cpp
// -----------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int LINE_WIDTH = 50;

struct Weapon
{
    string name;
    int damageModifier;
};

struct Stats
{
   ///TODO (0): declare agility, toughness, hitpoints
   int agility;
   int toughness;
   int hitpoints;
};

struct Monster
{
   ///TODO(1): declare name, stats, and weapon
   string name;
   Stats stat;
   Weapon gat;
} ;

///TODO (2):  declare Hero struct
struct Hero {
    string name;
    Stats stat;
    Weapon gat;
};

//output agility, toughness, and hitpoints, NO newline
void displayStats(const Stats& s);

//output Weapon name and damageModifier, NO newline
void displayWeapon(const Weapon& w);

//output name, stats, and weapon
void displayMonster(const Monster& m);

//output name, stats, and weapon
void displayHero(const Hero& h);

//roll a d6 numDice times (nd6)
int d6Roll(int numDice);

//Hero attacks a Monster
void attackMonster(const Hero& h, Monster& m);

//Monster attacks the Hero
void attackHero(Hero& h, const Monster& m);

//Display each monster in the vector
void displayMonsters(const vector<Monster>& lair);

//Each Monster whose hitpoints > 0 attacks the Hero
//If the hero's hitpoints drop below zero, break
void monstersTurn(Hero& h, const vector<Monster>& lair);

//The Hero attacks each Monster whose hitpoints > 0
void heroTurn(const Hero& h, vector<Monster>& lair);

//returns true if there is no Monster whose hitpoints > 0
bool lairCleared(vector<Monster>& lair);

//begin an epic battle!  displayHero, displayMonsters
//loop as long as the hero is alive and the lair is not clear
void enterLair(Hero& h, vector<Monster>& lair);
//*******

int main()
{
    srand(1337);  //don't change me!

    Weapon teeth = {"teeth/claws", -6};
    Weapon axe = {"sharp axe", +1};
    Weapon dagger = {"steel dagger", +2};

    vector<Monster> lair;
    lair.push_back({"Rat", Stats{3, 4, 2}, teeth});
    lair.push_back({"Goblin", Stats{2, 7, 9}, axe});

    Hero hero = {"Darwin", Stats{5, 9, 20}, dagger};

    enterLair(hero, lair);

    if(lairCleared(lair)) cout << "You win!" << endl;
    else cout << "Game over" << endl;

    return 0;
}


///TODO (3):   displayStats, NO newline
void displayStats(const Stats& s) {
    cout << "[a:" << s.agility << ", t:" << s.toughness << ", hp:" << s.hitpoints << ']';
}
///TODO (4):   displayWeapon.  If damageModifier >= 0 prepend a "+". NO newline at the end.
void displayWeapon(const Weapon& w) {
     cout << '<' << w.name << "," << (w.damageModifier >= 0)? ' +' : ' ' << w.damageModifier << '>';
}
///TODO (5):   displayMonster
void displayMonster(const Monster& m) {
    cout << m.name << ' ';
    displayStats(m.stat);
    cout << ' ';
    displayWeapon(m.gat);
    cout << endl;
}
///TODO (6):   displayHero
void displayHero(const Hero& h) {
    cout << h.name << ' ';
    displayStats(h.stat);
    cout << ' ';
    displayWeapon(h.gat);
    cout << endl;
}
///TODO (7):   d6Roll.  Don't forget to add each roll if numDice is greater than 1.
int d6Roll(int numDice) {
    int sum = 0;
    for(int i = 0; i < numDice; i++) {
        sum += rand()%(6) + 1;
    }
    return sum;
}
///TODO (8):   attackMonster.  See rules above.
///            You will have to use multiple dots here to access members within members.
///            eg h.weapon.name, m.stats.agility, etc
void attackMonster(const Hero& h, Monster& m) {
    int damageRoll = 0;
    int hitRoll = d6Roll(1);
    cout << "Hit? " << hitRoll << " vs. " << m.stat.agility << " : " << ((hitRoll >= m.stat.agility) ? "yes" : "no") << endl;
    if(hitRoll >= m.stat.agility) {
        damageRoll = d6Roll(2);
        cout << h.name << " attacks " << m.name << " with " << h.gat.name << "..." << endl;
        cout << "inflict? " << damageRoll << " vs. " << m.stat.toughness << " : " << ((damageRoll > m.stat.toughness) ? "yes" : "no") << endl;
        if(damageRoll > m.stat.toughness) {
            m.stat.hitpoints -= (damageRoll + h.gat.damageModifier);
        }
        else {
            cout << m.name << "'s toughness prevents damage" << endl;
        }
    }
    else {
        cout << h.name << " misses." <<endl;
    }
}
///TODO (9):   attackHero.  Same rules.
void attackHero(Hero& h, const Monster& m) {
    int damageRoll = 0;

    if(d6Roll(1) >= h.stat.agility) {
        damageRoll = d6Roll(2);
        if(damageRoll > h.stat.toughness) {
            h.stat.hitpoints -= (damageRoll + m.gat.damageModifier);
        }
        else {
            cout << h.name << "'s toughness prevents damage" << endl;
        }
    }
    else {
        cout << m.name << " misses." <<endl;
    }

}
///TODO (10):  displayMonsters.  Loop through the vector and call displayMonster for each Monster
void displayMonsters(const vector<Monster>& lair) {
    for(int i = 0; i < lair.size(); i++) {
        cout << "--------" << endl;
        displayMonster(lair.at(0));
        cout << endl << "--------" << endl;
    }
}

///TODO (11):  monstersTurn.  Loop through the vector and call displayMonster and then attackHero for each Monster if their hitpoints > 0.  If the hero's hitpoints drop below zero, break
void monstersTurn(Hero& h, const vector<Monster>& lair) {
    for(int i = 0; i < lair.size(); i++) {
        if(lair.at(i).stat.hitpoints > 0) {
            displayMonster(lair.at(i));
            attackHero(h, lair.at(i));
        }
    }
}
///TODO (12):  heroTurn.  Loop through the vector and call attackMonster for each Monster whose hitpoints > 0
void heroTurn(const Hero& h, vector<Monster>& lair) {
    for(int i = 0; i < lair.size(); i++) {
        if(lair.at(i).stat.hitpoints > 0) {
                attackMonster(h, lair.at(i));
        }
    }
}
///TODO (13):  lairCleared.  Loop through the vector.  If there is a monster whose hitpoints > 0, return false.
///            if the loop completes then return true
bool lairCleared(vector<Monster>& lair) {
    for(int i = 0; i < lair.size(); i++) {
        if(lair.at(i).stat.hitpoints > 0) {
            return false;
        }
    }
    return true;
}
void enterLair(Hero& h, vector<Monster>& lair)
{
   ///TODO (14):  Call functions to display Hero and Monsters\
    Out
    cout << "Our hero..." << endl;
    displayHero(h);

    displayMonsters(lair);
    cout << "The battle begins..." << endl;
   ///TODO (15):  Loop while the hero is alive and the lair is not cleared
        ///call heroTurn
        ///if the lair is not cleared, call monstersTurn

    while(h.stat.hitpoints > 0 && !lairCleared(lair)) {
        heroTurn(h, lair);
        if(!lairCleared(lair)) {
            monstersTurn(h, lair);
        }
    }
}
