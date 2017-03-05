#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList list=(QStringList()<<"Select"<<"ISBN"<<"Name"<<"Author"<<"Year");
    ui->comboBox->addItems(list);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Entry_triggered()
{
    connectDatabase openConn;

 if(!openConn.openConnection()){
    QMessageBox::about(this,"Connection Status","Failed!");
 }
 else{
    addEntryForm.show();

 }
}

void MainWindow::on_pushButton_clicked()
{
    connectDatabase searchDB;
    searchDB.openConnection();

    if(!searchDB.openConnection()){
        QMessageBox::critical(this,"Database Error!","Error Connecting to Database! Please try again or Check Database.");
    }

    //Modeling for Table View.

    QSqlQueryModel* databaseModel = new QSqlQueryModel;

    //Sql Query Prepration

    QSqlQuery* databaseQuery = new QSqlQuery(searchDB.bookDB);

    //Search based on option

    if(ui->comboBox->currentText() == "ISBN"){

        databaseQuery->prepare("select *from CSBooks where ISBN = :isbn;");
        databaseQuery->bindValue(":isbn",ui->lineEdit->text());
        databaseQuery->exec();
    }


    else if(ui->comboBox->currentText() == "Name"){

        databaseQuery->prepare("select *from CSBooks where Name = :name;");
        databaseQuery->bindValue(":name",ui->lineEdit->text());
        databaseQuery->exec();
    }


    else if(ui->comboBox->currentText() == "Author"){

        databaseQuery->prepare("select *from CSBooks where Author = :author;");
        databaseQuery->bindValue(":author",ui->lineEdit->text());
        databaseQuery->exec();
    }


    else if(ui->comboBox->currentText() == "Year"){

        databaseQuery->prepare("select *from CSBooks where Year = :year ");
        databaseQuery->bindValue(":year",ui->lineEdit->text());
        databaseQuery->exec();
    }


    else if(ui->comboBox->currentText() == "Select"){

        databaseQuery->exec("select *from CSBooks");
    }


    databaseModel->setQuery(*databaseQuery);
    ui->tableView->setModel(databaseModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    searchDB.closeConnection();
}

void MainWindow::on_actionEdit_Entry_triggered()
{
    editDBentry.show();
}

void MainWindow::on_actionRemove_Entry_triggered()
{
    removeEntry.show();
}

void MainWindow::on_actionAbout_Developer_triggered()
{
    QMessageBox::about(this,"Library Management Software","Created by Gajesh Bhat");
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this,"About Qt");
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
