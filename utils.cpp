#include "utils.h"
#include <error.h>

Gender Utils::genderFromStringOrDie(QString gender)
{
    if(gender.toLower() == "male")
    {
        return Gender::Male;
    }

    else if(gender.toLower() == "female")
    {
        return Gender::Female;
    }

    else
    {
        throw std::runtime_error("Unknown gender");
    }
}
