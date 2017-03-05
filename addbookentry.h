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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addbookentry *ui;
};

#endif // ADDBOOKENTRY_H
