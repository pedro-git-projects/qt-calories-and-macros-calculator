#include "macro.h"

Macro::Macro(Macros type) :
    type_{type}
{
    if(type == Macros::Carbohydrate)
    {
        caloriesPerGram_ = carbohydrateCalories_;
        name_ = QString{"carbohydrate"};
    }
    if(type == Macros::Protein)
    {
        caloriesPerGram_ = proteinCalories_;
        name_ = QString{"protein"};
    }
    if(type == Macros::Fat)
    {
        caloriesPerGram_ = fatCalories_;
        name_ = QString{"fat"};
    }
}

unsigned int Macro::caloriesPerGram() const
{
   return caloriesPerGram_;
}


QString Macro::name() const
{
    return name_;
}
