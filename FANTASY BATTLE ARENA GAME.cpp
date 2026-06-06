#include <iostream>
#include <string>
using namespace std;

class Hero
{
private:
    string name;
    int health;
    int attackPower;
    int level;
    string type;

public:
    Hero(string n, int h, int ap, int lv, string t)
    {
        name = n;
        health = h;
        attackPower = ap;
        level = lv;
        type = t;
    }

    string getName() { return name; }
    int getHealth() { return health; }
    int getAttackPower() { return attackPower; }
    int getLevel() { return level; }
    string getType() { return type; }

    void displayHero()
    {
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Health: " << health << endl;
        cout << "Attack Power: " << attackPower << endl;
        cout << "Level: " << level << endl;
    }


    void attack()
    {
        cout << name << " performs a normal attack." << endl;
    }

    void attack(int bonusDamage)
    {
        cout << name << " attacks with +" << bonusDamage << " bonus damage." << endl;
    }

    void attack(string specialSkill)
    {
        cout << name << " uses special skill: " << specialSkill << endl;
    }

    void attack(int bonusDamage, string specialSkill)
    {
        cout << name << " uses " << specialSkill
             << " with +" << bonusDamage << " bonus damage." << endl;
    }
};

int main()
{

    Hero h1("ELSY", 150, 60, 5, "Warrior");
    Hero h2("ROCIAN", 110, 50, 4, "Archer");
    Hero h3("CORNELL", 90, 70, 6, "Mage");

    Hero heroes[3] = {h1, h2, h3};

    cout << "\n===== ALL HEROES =====\n";

    for (int i = 0; i < 3; i++)
    {
        heroes[i].displayHero();
        cout << "------------------\n";
    }

    cout << "\n===== ATTACK DEMONSTRATION =====\n";

    for (int i = 0; i < 3; i++){
    heroes[i].attack();
    heroes[i].attack(15);
    heroes[i].attack("Iron Blast");
    heroes[i].attack(25, "Fire Slash");
    }

    int maxIndex = 0;

    for (int i = 1; i < 3; i++)
    {
        if (heroes[i].getAttackPower() > heroes[maxIndex].getAttackPower())
        {
            maxIndex = i;
        }
    }

    cout << "\n===== STRONGEST HERO =====\n";
    cout << heroes[maxIndex].getName()
         << " with Attack Power "
         << heroes[maxIndex].getAttackPower() << endl;

    cout << "\n===== TEAM BATTLE MANAGEMENT =====\n";
    cout << "Total Number of Heroes: 3" << endl;
    cout << "Hero with Highest Attack Power: "
         << heroes[maxIndex].getName()
         << " (" << heroes[maxIndex].getAttackPower() << ")" << endl;
    int totalAttack = 0;
    for (int i = 0; i < 3; i++)
    {
        totalAttack += heroes[i].getAttackPower();
    }

    cout << "Average Attack Power: "
         << totalAttack / 3.0 << endl;

    return 0;
}
