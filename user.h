#ifndef USER_H
#define USER_H

#include <QObject>


enum class Gender
{
    Male,
    Female
};

enum class ActivityLevel
{
    BMR,
    Sedentary,
    Light,
    Moderate,
    Active,
    VeryActive
};

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);
    User(QObject* parent, unsigned int age, float height, float weight, Gender gender, ActivityLevel activityLevel);
    unsigned int age() const;
    float height() const;
    float weight() const;
    float BMR() const;
    float calories() const;
    Gender gender() const;
    ActivityLevel activityLevel() const;
    float carbohydrateIntake() const;
    float proteinIntake() const;
    float fatIntake() const;
    void calculateBMR();
    void calculateCalories();
    void calculateMacroSplit();
    void setup();

private:
    unsigned int age_;
    float height_;
    float weight_;
    float BMR_;
    float calories_;
    Gender gender_;
    ActivityLevel activityLevel_;
    float carbohydrateIntake_;
    float proteinIntake_;
    float fatIntake_;
};

#endif // USER_H
