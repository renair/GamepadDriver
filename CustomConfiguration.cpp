#include "CustomConfiguration.h"
#include "ui_CustomConfiguration.h"
#include <QKeyEvent>
#include <QKeySequence>
#include <QString>

CustomConfiguration::CustomConfiguration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomConfiguration),
    buttonListening(-1),
    currentItem(0)
{
    ui->setupUi(this);

    //Activating button config for joysticks on radio change
    connect(ui->isLeftKeyboardControl, SIGNAL(clicked(bool)), this, SLOT(enableLeftButtonsConfig()));
    connect(ui->isLeftMouseControl, SIGNAL(clicked(bool)), this, SLOT(disableLeftButtonsConfig()));
    connect(ui->isRightKeyboardControl, SIGNAL(clicked(bool)), this, SLOT(enableRightButtonsConfig()));
    connect(ui->isRightMouseControl, SIGNAL(clicked(bool)), this, SLOT(disableRightButtonsConfig()));

    //Button listening
    connect(ui->buttonTable->verticalHeader(), SIGNAL(sectionClicked(int)), this,
            SLOT(activateButtonListening(int)));
    connect(ui->leftButtonTable->verticalHeader(), SIGNAL(sectionClicked(int)), this,
            SLOT(activateLeftJoyButtonListening(int)));
    connect(ui->rightButtonTable->verticalHeader(), SIGNAL(sectionClicked(int)), this,
            SLOT(activateRightJoyButtonListening(int)));
}

CustomConfiguration::~CustomConfiguration()
{
    delete ui;
}

void CustomConfiguration::keyPressEvent(QKeyEvent *ev)
{
    if(currentItem!=0)
    {
        ui->testLabel->setText(QString("Setting %1 to %2").arg(QString::number(buttonListening),
                                                               QString::number(ev->nativeVirtualKey())));
        currentItem->setText(QKeySequence(ev->key()).toString());

        buttonListening=-1;
        currentItem = 0;
    }
}

void CustomConfiguration::activateButtonListening(int row)
{
    //In case new key was not set to selected button
    if(currentItem!=0){
        currentItem->setText(prevLabel);
    }
    currentItem = ui->buttonTable->item(row,0);
    prevLabel.clear();
    prevLabel.append(currentItem->text());
    currentItem -> setText("Press button now!");
    buttonListening = row;
    ui->buttonTable->clearSelection();
}

void CustomConfiguration::activateLeftJoyButtonListening(int row)
{
    //In case new key was not set to selected button
    if(currentItem!=0){
        currentItem->setText(prevLabel);
    }
    currentItem = ui->leftButtonTable->item(row,0);
    prevLabel.clear();
    prevLabel.append(currentItem->text());
    currentItem -> setText("Press button now!");
    buttonListening = row;
    ui->buttonTable->clearSelection();
}

void CustomConfiguration::activateRightJoyButtonListening(int row)
{
    //In case new key was not set to selected button
    if(currentItem!=0){
        currentItem->setText(prevLabel);
    }
    currentItem = ui->rightButtonTable->item(row,0);
    prevLabel.clear();
    prevLabel.append(currentItem->text());
    currentItem -> setText("Press button now!");
    buttonListening = row;
    ui->buttonTable->clearSelection();
}

void CustomConfiguration::enableLeftButtonsConfig()
{
    ui->leftButtonTable->setEnabled(true);
    ui->leftButtonTable->setVisible(true);
}

void CustomConfiguration::disableLeftButtonsConfig()
{
    ui->leftButtonTable->setEnabled(false);
    ui->leftButtonTable->setVisible(false);
}

void CustomConfiguration::enableRightButtonsConfig()
{
    ui->rightButtonTable->setEnabled(true);
    ui->rightButtonTable->setVisible(true);
}

void CustomConfiguration::disableRightButtonsConfig()
{
    ui->rightButtonTable->setEnabled(false);
    ui->rightButtonTable->setVisible(false);
}
