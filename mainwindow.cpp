#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "user.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->combo_box_imperial_activity->setPlaceholderText("(Select One)");
    ui->combo_box_imperial_activity->setCurrentIndex(-1);

    ui->combo_box_international_activity->setPlaceholderText("(Select One)");
    ui->combo_box_international_activity->setCurrentIndex(-1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_international_calculate_clicked()
{
    auto tempAge = ui->line_edt_international_age->text();
    unsigned int age = tempAge.toInt();

    auto tempHeight = ui->line_edt_international_height->text();
    float height = tempHeight.toFloat();

    auto tempWeight = ui->line_edt_international_weight->text();
    float weight = tempWeight.toFloat();

    Gender gender{};
    if(ui->radio_female_international->isChecked())
    {
        gender = Gender::Female;
    }
    if(ui->radio_male_international->isChecked())
    {
        gender = Gender::Male;
    }

    auto tempActivity { ui->combo_box_international_activity->currentIndex() };
    ActivityLevel activity{};
    if(tempActivity == 0)
    {
        activity = ActivityLevel::BMR;
    }
    else if(tempActivity == 1)
    {
        activity = ActivityLevel::Sedentary;
    }
    else if(tempActivity == 2)
    {
        activity = ActivityLevel::Light;
    }
    else if(tempActivity == 3)
    {
        activity = ActivityLevel::Moderate;
    }
    else if(tempActivity == 4)
    {
        activity = ActivityLevel::Active;
    }
    else if(tempActivity == 5)
    {
        activity = ActivityLevel::VeryActive;
    }

    User u{ this, age, height, weight, gender, activity };
    u.setup();

    qDebug() << u.calories() << " " << u.proteinIntake() << " " << u.carbohydrateIntake() << " " << u.fatIntake() << Qt::endl;
}
