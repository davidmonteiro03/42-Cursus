#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include "SpellBook.hpp"
# include "TargetGenerator.hpp"

class Warlock
{
    private:
        std::string _name;
        std::string _title;
        SpellBook _book;
    public:
        Warlock(const std::string& name, const std::string& title);
        ~Warlock();
        const std::string& getName(void) const;
        const std::string& getTitle(void) const;
        void setTitle(const std::string& title);
        void introduce() const;
        void learnSpell(ASpell* spell);
        void forgetSpell(std::string spell_name);
        void launchSpell(std::string spell_name, const ATarget& target);
};

#endif
