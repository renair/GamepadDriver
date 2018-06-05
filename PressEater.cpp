#include "PressEater.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QString>


PressEater::PressEater(CustomConfiguration* parent):_parent(parent){}

bool PressEater::eventFilter(QObject *obj, QEvent *event)
{
    if(_parent->_currentItem != NULL){
        if (event->type() == QEvent::MouseButtonPress) {

            QMouseEvent *ev = static_cast<QMouseEvent *>(event);
            Qt::MouseButton mb = ev->button();

            if(mb!=Qt::NoButton){
                switch(mb)
                {
                    case 0x01:
                        _parent->_currentItem->setText("LMB");
                        *(_parent->_keyCodeArr[_parent->_buttonListening]) = mb;
                        break;
                    case 0x02:
                        _parent->_currentItem->setText("RMB");
                        *(_parent->_keyCodeArr[_parent->_buttonListening]) = mb;
                        break;
                    case 0x04:
                        _parent->_currentItem->setText("MMB");
                        *(_parent->_keyCodeArr[_parent->_buttonListening]) = mb;
                        break;
                    case 0x08:
                        _parent->_currentItem->setText("Fwd MB");
                        *(_parent->_keyCodeArr[_parent->_buttonListening]) = 0x05;
                        break;
                    case 0x10:
                        _parent->_currentItem->setText("Back MB");
                        *(_parent->_keyCodeArr[_parent->_buttonListening]) = 0x06;
                        break;
                    default:
                        _parent->_currentItem->setText("Key not supported!");
                }
                _parent->_buttonListening = -1;
                _parent->_currentItem = NULL;
                return true;
            }

        }
        if(event->type() == QEvent::KeyPress){
            QKeyEvent *ev = static_cast<QKeyEvent *>(event);
            switch(ev->nativeVirtualKey())
            {
                case 0x10:
                    _parent->_currentItem->setText("Shift");
                    break;
                case 0x11:
                    _parent->_currentItem->setText("Ctrl");
                    break;
                case 0x12:
                    _parent->_currentItem->setText("Alt");
                    break;
                default:
                    _parent->_currentItem->setText(QKeySequence(ev->key()).toString(QKeySequence::NativeText));
            }
            *(_parent->_keyCodeArr[_parent->_buttonListening]) = ev->nativeVirtualKey();
            _parent->_buttonListening = -1;
            _parent->_currentItem = NULL;
            return true;
        }
    }
    // standard event processing
    return QObject::eventFilter(obj, event);
}
