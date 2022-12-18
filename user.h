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
    User(QObject* parent, unsigned int age, float height, float weight, Gender gender);
    unsigned int age();
    float height();
    float weight();
    float BMR();
    float calories();
    Gender gender();
    ActivityLevel activityLevel();
    float carbohydrateIntake();
    float proteinIntake();
    float fatIntake();

signals:
    void calculatedBMR();
    void calculatedCalories();
    void calculatedMacroSplit();

public slots:
    void calculateBMR();
    void calculateCalories();
    void calculateMacroSplit();

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
