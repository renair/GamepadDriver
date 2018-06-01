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
    explicit CustomConfiguration(QWidget *parent = 0);
    ~CustomConfiguration();

private:
    Ui::CustomConfiguration *ui;
    int buttonListening;
    QTableWidgetItem *currentItem;
    void keyPressEvent(QKeyEvent *ev);
    QString prevLabel;
private slots:
    void activateButtonListening(int row);
    void activateLeftJoyButtonListening(int row);
    void activateRightJoyButtonListening(int row);

    void enableLeftButtonsConfig();
    void disableLeftButtonsConfig();
    void enableRightButtonsConfig();
    void disableRightButtonsConfig();
};

#endif // CUSTOMCONFIGURATION_H
