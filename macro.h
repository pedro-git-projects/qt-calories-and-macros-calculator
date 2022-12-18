#ifndef MACRO_H
#define MACRO_H

#include<QString>

enum class Macros
{
    Carbohydrate,
    Protein,
    Fat
};


class Macro
{
public:
    Macro(Macros type);
    Macro() = delete;
    ~Macro() = default;

    unsigned int caloriesPerGram() const;
    QString name() const;

private:
    const unsigned int carbohydrateCalories_ = 4;
    const unsigned int proteinCalories_ = 4;
    const unsigned int fatCalories_ = 9;
    QString name_;
    unsigned int caloriesPerGram_;
    Macros type_;
};

#endif // MACRO_H
