#ifndef MOUSERPRESSEATER_H
#define MOUSERPRESSEATER_H
#include <QObject>
#include "CustomConfiguration.h"

class MousePressEater : public QObject{
    Q_OBJECT
public:
    MousePressEater(CustomConfiguration* parent);
private:
    CustomConfiguration* _parent;
protected:
    bool eventFilter(QObject *obj, QEvent *event);
};
#endif // MOUSERPRESSEATER_H
