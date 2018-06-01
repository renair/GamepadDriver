#ifndef CUSTOMCONFIGURATION_H
#define CUSTOMCONFIGURATION_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QString>

namespace Ui {
class CustomConfiguration;
}

class CustomConfiguration : public QWidget
{
    Q_OBJECT

public:
    explicit CustomConfiguration(QWidget* parent = NULL);
    ~CustomConfiguration();

private:
    Ui::CustomConfiguration* ui;
    QTableWidgetItem* _currentItem;
    QString _prevLabel;
    int _buttonListening;
    void keyPressEvent(QKeyEvent* ev);
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
