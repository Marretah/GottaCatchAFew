#include "Mons.h"

// MonStatStructure Implementation
MonStatStructure::MonStatStructure(int Hp, int Atk, int Def, int SpAtk, int SpDef, int Spe)
    : Hp(Hp), Atk(Atk), Def(Def), SpAtk(SpAtk), SpDef(SpDef), Spe(Spe) {}

// MonStats Implementation
MonStats::MonStats(int Hp, int Atk, int Def, int SpAtk, int SpDef, int Spe)
    : Base(Hp, Atk, Def, SpAtk, SpDef, Spe), IV(0, 0, 0, 0, 0, 0), EV(0, 0, 0, 0, 0, 0) {}

void MonStats::SetEv(int Hp, int Atk, int Def, int SpAtk, int SpDef, int Spe) {
    EV = MonStatStructure(Hp, Atk, Def, SpAtk, SpDef, Spe);
}

void MonStats::SetIv(int Hp, int Atk, int Def, int SpAtk, int SpDef, int Spe) {
    IV = MonStatStructure(Hp, Atk, Def, SpAtk, SpDef, Spe);
}

// Mon Implementation
Mon::Mon(std::string id,int level, const std::string& name, int Hp, int Atk, int Def, int SpAtk, int SpDef, int Spe, MonNature nature)
    : Id(id), Name(name), Stats(Hp, Atk, Def, SpAtk, SpDef, Spe), Nature(nature) {}

