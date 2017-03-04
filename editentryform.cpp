#include "editentryform.h"
#include "ui_editentryform.h"

editentryForm::editentryForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editentryForm)
{
    ui->setupUi(this);
}

editentryForm::~editentryForm()
{
    delete ui;
}
