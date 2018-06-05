#ifndef CUSTOMCONFIGURATION_H
#define CUSTOMCONFIGURATION_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QString>
#include <QEvent>
#include "Configurations.h"

namespace Ui {
class CustomConfiguration;
}

class CustomConfiguration : public QWidget
{
    Q_OBJECT

public:
    QTableWidgetItem* _currentItem;
    QString _prevLabel;
    int** _keyCodeArr;
    //variable for saving index of button. 0 to 9 - main buttons, 10 to 13 - left joystick, 14 to 17 right joystick
    int _buttonListening;
    explicit CustomConfiguration(Configurations &configurations,
                                 QWidget* parent = NULL);
    ~CustomConfiguration();

private:
    Ui::CustomConfiguration* ui;
    Configurations& _configurations;
    void initKeyArray();
    void loadConfiguration();
private slots:
    void activateButtonListening(int row);
    void saveChanges();
    void changeLeftButtonsConfig();
    void changeRightButtonsConfig();
signals:
    void buttonChangingDone();

};

#endif // CUSTOMCONFIGURATION_H
