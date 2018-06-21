#include "CustomConfiguration.h"
#include "ui_CustomConfiguration.h"
#include <QKeyEvent>
#include <QMouseEvent>
#include <QKeySequence>
#include <QString>
#include <QMessageBox>
#include <windows.h>
#include "Constants.h"

CustomConfiguration::CustomConfiguration(Configurations& configurations, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomConfiguration),
    _configurations(configurations),
    _currentItem(NULL),
    _keyCodeArr(new int*[18]),
    _buttonListening(-1)
{
    ui->setupUi(this);
    initKeyArray();
    loadConfiguration();
    //Activating button config for joysticks on radio change
    connect(ui->isLeftKeyboardControl, SIGNAL(clicked(bool)), this, SLOT(changeLeftButtonsConfig()));
    connect(ui->isLeftMouseControl, SIGNAL(clicked(bool)), this, SLOT(changeLeftButtonsConfig()));
    connect(ui->isRightKeyboardControl, SIGNAL(clicked(bool)), this, SLOT(changeRightButtonsConfig()));
    connect(ui->isRightMouseControl, SIGNAL(clicked(bool)), this, SLOT(changeRightButtonsConfig()));

    //Button listening
    connect(ui->buttonTable->verticalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(activateButtonListening(int)));
    connect(ui->leftButtonTable->verticalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(activateButtonListening(int)));
    connect(ui->rightButtonTable->verticalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(activateButtonListening(int)));

    //Save configuration
    connect(ui->saveButton, SIGNAL(clicked(bool)), this, SLOT(saveChanges()));
}

CustomConfiguration::~CustomConfiguration()
{
    delete ui;
    delete[] _keyCodeArr;
}

void CustomConfiguration::initKeyArray()
{
    _keyCodeArr[0] = &_configurations.getPreferences()._leftTrigger;
    _keyCodeArr[1] = &_configurations.getPreferences()._rightTrigger;
    _keyCodeArr[2] = &_configurations.getPreferences()._xButton;
    _keyCodeArr[3] = &_configurations.getPreferences()._aButton;
    _keyCodeArr[4] = &_configurations.getPreferences()._bButton;
    _keyCodeArr[5] = &_configurations.getPreferences()._yButton;
    _keyCodeArr[6] = &_configurations.getPreferences()._leftFunctionButton;
    _keyCodeArr[7] = &_configurations.getPreferences()._rightFunctionButton;
    _keyCodeArr[8] = &_configurations.getPreferences()._leftJoystickButton;
    _keyCodeArr[9] = &_configurations.getPreferences()._rightJoystickButton;
    _keyCodeArr[10] = &_configurations.getPreferences()._leftJoystick._up;
    _keyCodeArr[11] = &_configurations.getPreferences()._leftJoystick._down;
    _keyCodeArr[12] = &_configurations.getPreferences()._leftJoystick._left;
    _keyCodeArr[13] = &_configurations.getPreferences()._leftJoystick._right;
    _keyCodeArr[14] = &_configurations.getPreferences()._rightJoystick._up;
    _keyCodeArr[15] = &_configurations.getPreferences()._rightJoystick._down;
    _keyCodeArr[16] = &_configurations.getPreferences()._rightJoystick._left;
    _keyCodeArr[17] = &_configurations.getPreferences()._rightJoystick._right;
}

void CustomConfiguration::loadConfiguration()
{
    QTableWidget* buttonTable = ui->buttonTable;
    QTableWidget* leftJoyTable = ui->leftButtonTable;
    QTableWidget* rightJoyTable = ui->rightButtonTable;
    unsigned int i;
    for(i = 0; i<=9; ++i){
        int currentKey = *(_keyCodeArr[i]);
        if(currentKey != 0)
            buttonTable->item(i,0)->setText(getKeyName(currentKey));
    }
    for(; i<=13; ++i){
        int currentKey = *(_keyCodeArr[i]);
        if(currentKey != 0)
            leftJoyTable->item(i - 10,0)->setText(getKeyName(currentKey));
    }
    for(; i<=17; ++i){
        int currentKey = *(_keyCodeArr[i]);
        if(currentKey != 0)
            rightJoyTable->item(i - 14,0)->setText(getKeyName(currentKey));
    }

    //Set checked radio and tables for joysticks
    if(_configurations.getPreferences()._leftJoystick._type == JOYSTICK_MOUSE){
        ui->leftButtonTable->setEnabled(false);
        ui->leftButtonTable->setVisible(false);
        ui->isLeftMouseControl->setChecked(true);
    }else{
        ui->leftButtonTable->setEnabled(true);
        ui->leftButtonTable->setVisible(true);
        ui->isLeftKeyboardControl->setChecked(true);
    }
    if(_configurations.getPreferences()._rightJoystick._type == JOYSTICK_MOUSE){
        ui->rightButtonTable->setEnabled(false);
        ui->rightButtonTable->setVisible(false);
        ui->isRightMouseControl->setChecked(true);
    }else{
        ui->rightButtonTable->setEnabled(true);
        ui->rightButtonTable->setVisible(true);
        ui->isRightKeyboardControl->setChecked(true);
    }
}

QString CustomConfiguration::getKeyName(int code)
{
    switch(code){
        case 0x01:
            return QString("LMB");
        case 0x02:
            return QString("RMB");
        case 0x04:
            return QString("MMB");
        case 0x05:
            return QString("Fwd MB");
        case 0x06:
            return QString("Back MB");

    }
    const int size = 30;
    wchar_t name[size];
    unsigned int scanCode = MapVirtualKeyW(code, MAPVK_VK_TO_VSC);
    long lParamValue = (scanCode << 16);
    int result = GetKeyNameText(lParamValue, name, size);
    if (result > 0)
    {
        return QString::fromWCharArray(name,result);
    }
    return QString("ERRORERRORERRORERRORERRORERRORERRORERRORERROR");
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
    table->clearSelection();
    QString tname = table->parent()->objectName();
    if(tname.compare(ui->buttonTable->objectName()) == 0){
        _buttonListening = row;
        return;
    }
    if(tname.compare(ui->leftButtonTable->objectName()) == 0){
        _buttonListening = row+10;
        return;
    }
    if(tname.compare(ui->rightButtonTable->objectName()) == 0){
        _buttonListening = row+14;
        return;
    }
}

void CustomConfiguration::saveChanges()
{
    if(!_configurations.savePreferences())
    {
        QMessageBox::warning(this, "File not saved" ,"Can't save file. If it open with some other program, please close it.");
    }
    emit buttonChangingDone();
}

void CustomConfiguration::changeLeftButtonsConfig()
{
    bool keyboardEnabled = ui->isLeftKeyboardControl->isChecked();
    ui->leftButtonTable->setEnabled(keyboardEnabled);
    ui->leftButtonTable->setVisible(keyboardEnabled);

    _configurations.getPreferences()._leftJoystick._type = keyboardEnabled;
}

void CustomConfiguration::changeRightButtonsConfig()
{
    bool keyboardEnabled = ui->isRightKeyboardControl->isChecked();
    ui->rightButtonTable->setEnabled(keyboardEnabled);
    ui->rightButtonTable->setVisible(keyboardEnabled);

    _configurations.getPreferences()._rightJoystick._type = keyboardEnabled;
}

