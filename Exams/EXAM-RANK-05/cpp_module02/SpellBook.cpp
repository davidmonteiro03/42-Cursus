#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
    std::map<std::string, ASpell*>::iterator it = _spells.begin();
    while (it != _spells.end())
    {
        delete it->second;
        ++it;
    }
    _spells.clear();
}

void SpellBook::learnSpell(ASpell* spell)
{
    if (!spell)
        return ;
    if (_spells.find(spell->getName()) == _spells.end())
        _spells[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(const std::string& spell_name)
{
    std::map<std::string, ASpell*>::iterator it = _spells.find(spell_name);
    if (it != _spells.end())
    {
        delete it->second;
        _spells.erase(it);
    }
}

ASpell* SpellBook::createSpell(const std::string& spell_name)
{
    ASpell* tmp = NULL;
    if (_spells.find(spell_name) != _spells.end())
        tmp = _spells[spell_name];
    return (tmp);
}
