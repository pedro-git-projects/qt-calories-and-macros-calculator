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
    emit calculatedBMR();
}

void User::calculateCalories()
{
    if(activityLevel_ == ActivityLevel::BMR) calories_ = BMR_;
    if(activityLevel_ == ActivityLevel::Sedentary) calories_ = BMR_ * 1.2;
    if(activityLevel_ == ActivityLevel::Light) calories_ = BMR_ * 1.375;
    if(activityLevel_ == ActivityLevel::Moderate) calories_ = BMR_ * 1.55;
    if(activityLevel_ == ActivityLevel::Active) calories_ = BMR_ * 1.75;
    if(activityLevel_ == ActivityLevel::VeryActive) calories_ = BMR_ * 1.9;

    emit calculatedCalories();
}

void User::calculateMacroSplit()
{
    Macro protein{ Macros::Protein };
    Macro carb { Macros::Carbohydrate };
    Macro fat { Macros::Fat};

    proteinIntake_ = (calories_ * 0.35)/protein.caloriesPerGram();
    fatIntake_ = (calories_ * 0.20)/fat.caloriesPerGram();
    carbohydrateIntake_ = (calories_ * 0.45)/carb.caloriesPerGram();

    emit calculatedMacroSplit();
}


unsigned int User::age()
{
    return age_;
}

float User::height()
{
    return height_;

}

float User::weight()
{
    return weight_;
}

float User::BMR()
{
    return BMR_;
}


Gender User::gender()
{
    return gender_;
}

ActivityLevel User::activityLevel()
{
    return activityLevel_;
}

float User::carbohydrateIntake()
{
    return carbohydrateIntake_;
}

float User::proteinIntake()
{
    return proteinIntake_;

}

float User::fatIntake()
{
    return fatIntake_;
}
