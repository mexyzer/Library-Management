#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addbookentry.h"
#include "editentryform.h"
#include "databaseconnection.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionNew_Entry_triggered();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    addbookentry addEntryForm;
    editentryForm editDBentry;
    connectDatabase openConn;
};

#endif // MAINWINDOW_H
