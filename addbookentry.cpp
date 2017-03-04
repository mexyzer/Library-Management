#include "addbookentry.h"
#include "ui_addbookentry.h"

addbookentry::addbookentry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addbookentry)
{
    ui->setupUi(this);
}

addbookentry::~addbookentry()
{
    delete ui;
}
