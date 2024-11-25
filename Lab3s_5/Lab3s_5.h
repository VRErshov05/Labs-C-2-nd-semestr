#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab3s_5.h"

class Lab3s_5 : public QMainWindow
{
    Q_OBJECT

public:
    Lab3s_5(QWidget *parent = nullptr);
    ~Lab3s_5();

private:
    Ui::Lab3s_5Class ui;
};
