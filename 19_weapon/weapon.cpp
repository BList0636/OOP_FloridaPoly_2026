#include <iostream>

class Weapon {
public:
    virtual void use() = 0;
};

class Knife : public Weapon {
public:
    Knife(bool isStainless = false) : is_stainless(isStainless) {}
    void use() override {
        std::cout << "Slash!" << std::endl;
    }

    bool isStainless(){
        return is_stainless;
    }
private:
    bool is_stainless;
};

class Gun : public Weapon{
public:
    int bullets;
    int magazine;
    Gun(int magazine = 10) : magazine(magazine), bullets(magazine) {}

    void use() override {
        if (bullets > 0) {
            std::cout << "BANG!" << std::endl;
            bullets--;
        }
        else {
            std::cout << "CLICK!" << std::endl;
        }
    }

    void reload(int amount) {
        if (amount <= 0) return;

        if (amount > magazine - bullets)
            bullets = magazine;
        else
            bullets += amount;
    }
};

class MachineGun : public Gun {
public:
    MachineGun(int magazine = 20) : Gun(magazine) {}

    void use() override {
        if (bullets == 0) {
            std::cout << "CLICK!" << std::endl;
            return;
        }
        while (bullets > 0) {
            std::cout << "BANG! ";
            bullets--;
        }
        std::cout << "\n";
    }
};

class Player {
    public:
    void useWeapon(Weapon& weapon) {
        Knife* knife = dynamic_cast<Knife*>(&weapon);
        if (knife != nullptr && !knife->isStainless()){
            std::cout << "Cannot use this knife";
            return;
        }
        weapon.use();
    }
    void reload(Gun& gun, int bullets) {
        gun.reload(bullets);
    }
};

int main(void) {
    Gun revolver;
    MachineGun machineGun;
    Knife dagger;
    Player player;
    player.useWeapon(revolver);
    player.useWeapon(machineGun);
    player.useWeapon(machineGun);
    player.reload(machineGun, 5);
    player.useWeapon(machineGun);

    player.useWeapon(dagger);
    return 0;
}