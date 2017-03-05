#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSql>
#include <QSqlQueryModel>
#include <string>
#include <QString>
#include <QComboBox>

class connectDatabase
{
public:
    connectDatabase() {}
    QSqlDatabase bookDB = QSqlDatabase::addDatabase("QSQLITE");
    bool openConnection(){
        bookDB.setDatabaseName("/home/gajesh/QtProjects/LibraryManagement/LibManagementResourceFiles/Database/Books.db");
        return bookDB.open();
    }

    void closeConnection(){
        bookDB.close();
     }
  };

#endif // DATABASECONNECTION_H
