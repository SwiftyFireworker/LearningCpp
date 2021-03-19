//
//  Game.cpp
//  LearningCpp
//
//  Created by Egor Denisov on 19.03.2021.
//

#include <iostream>
#include <random>
#include <string>

int getRandomFloatingPointBetween_progressive(int min, int max) {
    std::random_device rd; // uniformly-distributed integer random number generator
    std::mt19937 gen(rd()); //инициализируем Вихрь Мерсенна случайным стартовым числом
    std::uniform_real_distribution<> dis(min, max);//uniform distribution between min and max
    return dis(gen);
}

class Hero {
private:
    std::string name;
    int health;
    int strength;
    
public:
    Hero(std::string name, int health, int strength) : name(name), health(health), strength(strength)
    { }
    
    int strike(Hero& targetHero) {
        if (health == 0) {
            return 0;
        }
        
        int strikesStrength = getRandomFloatingPointBetween_progressive(strength/2, strength);
        targetHero.health -= strikesStrength;
        std::cout << name << " strike " << targetHero.name << " for " << strikesStrength << std::endl;
        if (targetHero.health <= 0) {
            targetHero.health = 0;
            std::cout << "Hero " << targetHero.name << " dead" << std::endl;
        }
        return strikesStrength;
    }
    
    int getHealth() {
        return health;
    }
    
};

int main() {
    Hero elf = Hero("Elf", 43, 20);
    Hero orc = Hero("Orc", 100, 10);
    while (elf.getHealth() != 0 && orc.getHealth() != 0) {
        elf.strike(orc);
        orc.strike(elf);
    }
}
