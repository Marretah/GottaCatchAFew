#ifndef MONS_H
#define MONS_H

#include <string>

enum MonNature {
    Bold
};

class MonStatStructure {
private:
    int Hp, Atk, Def, SpAtk, SpDef, Spe;

public:
    MonStatStructure(int Hp, int Atk, int Def, int SpAtk, int SpDef, int Spe);
};

class MonStats {
private:
    MonStatStructure Base, IV, EV;

public:
    MonStats(int Hp, int Atk, int Def, int SpAtk, int SpDef, int Spe);
    void SetEv(int Hp, int Atk, int Def, int SpAtk, int SpDef, int Spe);
    void SetIv(int Hp, int Atk, int Def, int SpAtk, int SpDef, int Spe);
};

class Mon {
private:
    std::string Id;
    int level;
    std::string Name;   
    MonStats Stats;
    MonNature Nature;

public:
    Mon(std::string Id,int Level, const std::string& Name, int Hp, int Atk, int Def, int SpAtk, int SpDef, int Spe, MonNature Nature);
};

#endif // MONS_H


