#include "ASpell.hpp"

ASpell::ASpell(std::string name, std::string effects) : \
    _name(name), _effects(effects)
{
}

ASpell::~ASpell()
{
}

std::string ASpell::getName(void) const
{
    return (_name);
}

std::string ASpell::getEffects(void) const
{
    return (_effects);
}

void ASpell::launch(const ATarget& target) const
{
    target.getHitBySpell(*this);
}
