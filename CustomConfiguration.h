#ifndef CUSTOMCONFIGURATION_H
#define CUSTOMCONFIGURATION_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QString>
#include "Configurations.h"

namespace Ui {
class CustomConfiguration;
}

class CustomConfiguration : public QWidget
{
    Q_OBJECT

public:
    explicit CustomConfiguration(Configurations &configurations, QWidget* parent = NULL);
    ~CustomConfiguration();

private:
    Ui::CustomConfiguration* ui;
    Configurations& _configurations;
    QTableWidgetItem* _currentItem;
    QString _prevLabel;
    int** _keyCodeArr;
    //variable for saving index of button. 0 to 9 - main buttons, 10 to 13 - left joystick, 14 to 17 right joystick
    int _buttonListening;
    void keyPressEvent(QKeyEvent* ev);
    void initKeyArray();
    void loadConfiguration();
private slots:
    void activateButtonListening(int row);
//    void activateLeftJoyButtonListening(int row);
//    void activateRightJoyButtonListening(int row);

    void changeLeftButtonsConfig();
//    void disableLeftButtonsConfig();
    void changeRightButtonsConfig();
//    void disableRightButtonsConfig();
signals:
    void buttonChangingDone();
};

#endif // CUSTOMCONFIGURATION_H
