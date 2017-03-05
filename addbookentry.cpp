#include "addbookentry.h"
#include "ui_addbookentry.h"
#include "mainwindow.h"

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

void addbookentry::on_pushButton_clicked()
{
    connectDatabase addEntry;
    addEntry.openConnection();

    if(ui->lineEdit->text()=="" || ui->lineEdit_2->text()=="" || ui->lineEdit_3->text()=="" || ui->lineEdit->text()==""){

            //Empty Feild throw error.
            QMessageBox::about(this,"Incomplete Entries!","Please Enter all the values to make an entry.");
    }
    else{

        //Write Query to database.
        QSqlQuery writeQry;

        writeQry.prepare("insert into CSBooks values(:isbn,:name,:author,:year);");
        writeQry.bindValue(":isbn",ui->lineEdit->text());
        writeQry.bindValue(":name",ui->lineEdit_2->text());
        writeQry.bindValue(":author",ui->lineEdit_3->text());
        writeQry.bindValue(":year",ui->lineEdit_4->text());

        bool written = writeQry.exec();

        if(written){
            QMessageBox::about(this,"Entry Updated!","Entry Updated to Database.");
        }
        else{
            QMessageBox::about(this,"Error Updating.","Error Updating Database! Check Connection or values!");
        }
        addEntry.closeConnection();

        ui->lineEdit->setText("");      //Set the Lineedit to null to allow entry of new values.
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        ui->lineEdit_4->setText("");
    }
}

void addbookentry::on_pushButton_2_clicked()
{
    this->close();
}
