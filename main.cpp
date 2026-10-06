#include <iostream>
#include <string>

struct Hero {
    std::string name;
    int hp;
    int maxHp;
    int attack;
    bool hasKey;
    int currentRoom; // 0 = Entrance, 1 = Armory, 2 = Boss Chamber
};

void inspectRoom(const Hero& hero) {
    if (hero.currentRoom == 0) {
        std::cout << "\n[ENTRANCE] Heavy stone walls surround you. A locked door stands to the North.\n";
        std::cout << "There is a path leading East to the Armory.\n";
    } else if (hero.currentRoom == 1) {
        std::cout << "\n[ARMORY] Racks of rusty weapons line the room. Something shiny rests on a table.\n";
        std::cout << "The Entrance is back to the West.\n";
    } else if (hero.currentRoom == 2) {
        std::cout << "\n[BOSS CHAMBER] A giant skeleton monster guards the exit portal!\n";
    }
}

void processRoomAction(Hero& hero) {
    char choice;
    if (hero.currentRoom == 0) {
        std::cout << "Actions: [1] Go East to Armory | [2] Open North Door: ";
        std::cin >> choice;
        if (choice == '1') hero.currentRoom = 1;
        else if (choice == '2') {
            if (hero.hasKey) {
                std::cout << "You unlocked the door with the Rusty Key!\n";
                hero.currentRoom = 2;
            } else {
                std::cout << "The door is locked solid! You need a key, dweeb.\n";
            }
        }
    } 
    else if (hero.currentRoom == 1) {
        std::cout << "Actions: [1] Search Room | [2] Go West to Entrance: ";
        std::cin >> choice;
        if (choice == '1') {
            if (!hero.hasKey) {
                std::cout << "You found a Rusty Key among the old shields!\n";
                hero.hasKey = true;
            } else {
                std::cout << "Nothing else useful here.\n";
            }
        } else if (choice == '2') {
            hero.currentRoom = 0;
        }
    }
}

int main() {
    Hero hero = {"Andrew", 50, 50, 15, false, 0};
    std::cout << "=== TEXT DUNGEON ENGINE ===\n";

    while (hero.hp > 0 && hero.currentRoom != 2) {
        inspectRoom(hero);
        processRoomAction(hero);
    }

    if (hero.currentRoom == 2) {
        inspectRoom(hero);
        std::cout << "\nBoss fight triggered! You escaped the dungeon maze!\n";
        std::cout << "=== VICTORY! ===\n";
    }

    return 0;
}