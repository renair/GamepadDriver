#include "MouserPressEater.h"
#include <QMouseEvent>
#include <QString>


MousePressEater::MousePressEater(CustomConfiguration* parent):_parent(parent){}

bool MousePressEater::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress && _parent->_currentItem != NULL) {

        QMouseEvent *ev = static_cast<QMouseEvent *>(event);
        Qt::MouseButton mb = ev->button();

        if(mb!=Qt::NoButton){
            _parent->_currentItem->setText(QKeySequence(mb).toString());
            *(_parent->_keyCodeArr[_parent->_buttonListening]) = mb;
            _parent->_buttonListening = -1;
            _parent->_currentItem = NULL;
            return true;
        }
        // standard event processing
        return QObject::eventFilter(obj, event);
    }
    // standard event processing
    return QObject::eventFilter(obj, event);
}
