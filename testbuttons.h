        #ifndef TESTBUTTONS_H
    #define TESTBUTTONS_H

    #include <QWidget>

    namespace Ui {
    class TestButtons;
    }

    class TestButtons : public QWidget
    {
        Q_OBJECT

    public:
        explicit TestButtons(QWidget *parent = 0);
        ~TestButtons();

    protected:
        void keyPressEvent(QKeyEvent *event);
    private:
        Ui::TestButtons *ui;
    };

    #endif // TESTBUTTONS_H
