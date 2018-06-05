#ifndef MOUSERPRESSEATER_H
#define MOUSERPRESSEATER_H
#include <QObject>
#include "CustomConfiguration.h"

class PressEater : public QObject{
    Q_OBJECT
public:
    PressEater(CustomConfiguration* parent);
private:
    CustomConfiguration* _parent;
protected:
    bool eventFilter(QObject *obj, QEvent *event);
};
#endif // MOUSERPRESSEATER_H
