#ifndef ADDBOOKENTRY_H
#define ADDBOOKENTRY_H

#include <QWidget>

namespace Ui {
class addbookentry;
}

class addbookentry : public QWidget
{
    Q_OBJECT

public:
    explicit addbookentry(QWidget *parent = 0);
    ~addbookentry();

private:
    Ui::addbookentry *ui;
};

#endif // ADDBOOKENTRY_H
