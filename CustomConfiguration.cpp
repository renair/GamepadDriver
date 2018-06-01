#include "CustomConfiguration.h"
#include "ui_CustomConfiguration.h"
#include <QKeyEvent>
#include <QString>

CustomConfiguration::CustomConfiguration(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomConfiguration),
    buttonListening(-1),
    currentItem(0)
{
    ui->setupUi(this);
    connect(ui->buttonTable->verticalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(activateButtonListening(int)));
}

CustomConfiguration::~CustomConfiguration()
{
    delete ui;
}

void CustomConfiguration::keyPressEvent(QKeyEvent *ev)
{
    if(currentItem!=0)
    {
        ui->testLabel->setText(QString("Setting %1 to %2").arg(QString::number(buttonListening),
                                                               QString::number(ev->key())));
        currentItem->setText(QString::number(ev->key()));

        buttonListening=-1;
        currentItem = 0;
    }
}

void CustomConfiguration::activateButtonListening(int row)
{
    //In case new key was not set to selected button
    if(currentItem!=0){
        currentItem->setText(prevLabel);
    }
    currentItem = ui->buttonTable->item(row,0);
    prevLabel.clear();
    prevLabel.append(currentItem->text());
    currentItem -> setText("Press button now!");
    buttonListening = row;
    ui->buttonTable->clearSelection();
}
