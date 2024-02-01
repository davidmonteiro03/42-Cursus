#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include "ATarget.hpp"
# include <map>

class TargetGenerator
{
    private:
        std::map<std::string, ATarget*> _targets;
    public:
        TargetGenerator();
        ~TargetGenerator();
        void learnTargetType(ATarget* target);
        void forgetTargetType(const std::string& target_type);
        ATarget* createTarget(const std::string& target_type);
};

#endif
