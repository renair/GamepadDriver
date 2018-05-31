#include "testbuttons.h"
#include "ui_testbuttons.h"
#include <QKeyEvent>

TestButtons::TestButtons(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestButtons)
{
    ui->setupUi(this);
}

void TestButtons::keyPressEvent(QKeyEvent *ev)
{
    ui->myLabel->setText("You Pressed Key " + ev->text());
}

TestButtons::~TestButtons()
{
    delete ui;
}
