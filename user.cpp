#include "user.h"
#include "macro.h"

User::User(QObject *parent)
    : QObject{parent}
{

}

User::User(QObject* parent, unsigned int age, float height, float weight, Gender gender, ActivityLevel activityLevel)
    : QObject{parent},
      age_{age},
      height_{height},
      weight_{weight},
      gender_{gender},
      activityLevel_{activityLevel}
{
}

void User::calculateBMR()
{
    if(gender_ == Gender::Male)
    {
        double bmrResult { 66.5 + (13.75 * weight_) + (5.003 * height_) - (6.75 * age_) };
        BMR_ = bmrResult;
    }
    if(gender_ == Gender::Female)
    {
        double bmrResult { 655.1 + (9.563 * weight_) + (1.850 * height_) - (4.676 * age_) };
        BMR_ = bmrResult;
    }
}

void User::calculateCalories()
{
    if(activityLevel_ == ActivityLevel::BMR) calories_ = BMR_;
    if(activityLevel_ == ActivityLevel::Sedentary) calories_ = BMR_ * 1.2;
    if(activityLevel_ == ActivityLevel::Light) calories_ = BMR_ * 1.375;
    if(activityLevel_ == ActivityLevel::Moderate) calories_ = BMR_ * 1.55;
    if(activityLevel_ == ActivityLevel::Active) calories_ = BMR_ * 1.75;
    if(activityLevel_ == ActivityLevel::VeryActive) calories_ = BMR_ * 1.9;
}

void User::calculateMacroSplit()
{
    Macro protein{ Macros::Protein };
    Macro carb { Macros::Carbohydrate };
    Macro fat { Macros::Fat};

    proteinIntake_ = (calories_ * 0.35)/protein.caloriesPerGram();
    fatIntake_ = (calories_ * 0.20)/fat.caloriesPerGram();
    carbohydrateIntake_ = (calories_ * 0.45)/carb.caloriesPerGram();
}

void User::setup()
{
    calculateBMR();
    calculateCalories();
    calculateMacroSplit();
}

unsigned int User::age() const
{
    return age_;
}

float User::height() const
{
    return height_;

}

float User::weight() const
{
    return weight_;
}

float User::BMR() const
{
    return BMR_;
}


Gender User::gender() const
{
    return gender_;
}

ActivityLevel User::activityLevel() const
{
    return activityLevel_;
}

float User::calories() const
{
    return calories_;
}

float User::carbohydrateIntake() const
{
    return carbohydrateIntake_;
}

float User::proteinIntake() const
{
    return proteinIntake_;

}

float User::fatIntake() const
{
    return fatIntake_;
}
