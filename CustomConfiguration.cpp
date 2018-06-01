#include "CustomConfiguration.h"
#include "ui_CustomConfiguration.h"
#include <QKeyEvent>
#include <QKeySequence>
#include <QString>

CustomConfiguration::CustomConfiguration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomConfiguration),
    _currentItem(NULL),
    _buttonListening(-1)
{
    ui->setupUi(this);

    //Activating button config for joysticks on radio change
    connect(ui->isLeftKeyboardControl, SIGNAL(clicked(bool)), this, SLOT(changeLeftButtonsConfig()));
    connect(ui->isLeftMouseControl, SIGNAL(clicked(bool)), this, SLOT(changeLeftButtonsConfig()));
    connect(ui->isRightKeyboardControl, SIGNAL(clicked(bool)), this, SLOT(changeRightButtonsConfig()));
    connect(ui->isRightMouseControl, SIGNAL(clicked(bool)), this, SLOT(changeRightButtonsConfig()));

    //Button listening
    connect(ui->buttonTable->verticalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(activateButtonListening(int)));
    connect(ui->leftButtonTable->verticalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(activateButtonListening(int)));
    connect(ui->rightButtonTable->verticalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(activateButtonListening(int)));
//    connect(ui->leftButtonTable->verticalHeader(), SIGNAL(sectionClicked(int)), this,
//            SLOT(activateLeftJoyButtonListening(int)));
//    connect(ui->rightButtonTable->verticalHeader(), SIGNAL(sectionClicked(int)), this,
//            SLOT(activateRightJoyButtonListening(int)));
}

CustomConfiguration::~CustomConfiguration()
{
    delete ui;
}

void CustomConfiguration::keyPressEvent(QKeyEvent *ev)
{
    if(_currentItem != NULL)
    {
        ui->testLabel->setText(QString("Setting %1 to %2").arg(QString::number(_buttonListening),
                                                               QString::number(ev->nativeVirtualKey())));
        _currentItem->setText(QKeySequence(ev->key()).toString());

        _buttonListening = -1;
        _currentItem = NULL;
    }
}

void CustomConfiguration::activateButtonListening(int row)
{
    //In case new key was not set to selected button
    if(_currentItem != NULL)
    {
        _currentItem->setText(_prevLabel);
    }
    QTableWidget* table = static_cast<QTableWidget*>(sender());
    _currentItem = table->item(row,0);
    _prevLabel = _currentItem->text();
    _currentItem -> setText("Press button now!");
    _buttonListening = row;
    table->clearSelection();
    emit buttonChangingDone();
}

//void CustomConfiguration::activateLeftJoyButtonListening(int row)
//{
//    //In case new key was not set to selected button
//    if(_currentItem != NULL)
//    {
//        _currentItem->setText(_prevLabel);
//    }
//    _currentItem = ui->leftButtonTable->item(row,0);
//    _prevLabel = _currentItem->text();
//    _currentItem -> setText("Press button now!");
//    _buttonListening = row;
//    ui->buttonTable->clearSelection();
//    emit buttonChangingDone();
//}

//void CustomConfiguration::activateRightJoyButtonListening(int row)
//{
//    //In case new key was not set to selected button
//    if(_currentItem != NULL)
//    {
//        _currentItem->setText(_prevLabel);
//    }
//    _currentItem = ui->rightButtonTable->item(row,0);
//    _prevLabel = _currentItem->text();
//    _currentItem -> setText("Press button now!");
//    _buttonListening = row;
//    ui->buttonTable->clearSelection();
//    emit buttonChangingDone();
//}

void CustomConfiguration::changeLeftButtonsConfig()
{
    bool enabled = ui->isLeftKeyboardControl->isChecked();
    ui->leftButtonTable->setEnabled(enabled);
    ui->leftButtonTable->setVisible(enabled);
}

//void CustomConfiguration::disableLeftButtonsConfig()
//{
//    ui->leftButtonTable->setEnabled(false);
//    ui->leftButtonTable->setVisible(false);
//}

void CustomConfiguration::changeRightButtonsConfig()
{
    bool enabled = ui->isRightKeyboardControl->isChecked();
    ui->rightButtonTable->setEnabled(enabled);
    ui->rightButtonTable->setVisible(enabled);
}

//void CustomConfiguration::disableRightButtonsConfig()
//{
//    ui->rightButtonTable->setEnabled(false);
//    ui->rightButtonTable->setVisible(false);
//}
