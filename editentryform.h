#ifndef EDITENTRYFORM_H
#define EDITENTRYFORM_H

#include <QWidget>


namespace Ui {
class editentryForm;
}

class editentryForm : public QWidget
{
    Q_OBJECT

public:
    explicit editentryForm(QWidget *parent = 0);
    ~editentryForm();

private:
    Ui::editentryForm *ui;
};

#endif // EDITENTRYFORM_H
