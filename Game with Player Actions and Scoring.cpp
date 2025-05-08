#include <iostream>
#include <string>
using namespace std;

class Game {
private:
    string playerName;
    int score;
    int health;

public:
    Game(const string& name) {
        playerName = name;
        score = 0;
        health = 100;
    }

    void attack() {
        cout << playerName << " attacks the enemy!" << endl;
        score += 10;
    }

    void defend() {
        cout << playerName << " defends against the attack!" << endl;
        score += 5;
    }

    void heal() {
        if (health < 100) {
            health += 10;
            if (health > 100) health = 100;
            cout << playerName << " heals. Health is now " << health << "." << endl;
            score += 2;
        } else {
            cout << "Health is already full.\n";
        }
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
        cout << playerName << " takes " << damage << " damage. Health is now " << health << "." << endl;
    }

    void displayStatus() const {
        cout << "Player: " << playerName << "\nScore: " << score << "\nHealth: " << health << "\n" << endl;
    }

    bool isAlive() const {
        return health > 0;
    }
};

// Example usage
int main() {
    Game player("Hero");

    player.displayStatus();

    player.attack();
    player.defend();
    player.takeDamage(20);
    player.heal();
    player.displayStatus();

    return 0;
}
