#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dishmanager.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::vector<Dish> dishes = DishManager::getInstance()->getAll();
    for(size_t i = 0; i< dishes.size();i++)
        dishes[i].print();
}

MainWindow::~MainWindow()
{
    delete ui;
}

