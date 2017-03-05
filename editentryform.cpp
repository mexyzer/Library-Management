#include "editentryform.h"
#include "ui_editentryform.h"
#include "databaseconnection.h"

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

void editentryForm::on_pushButton_clicked()
{
    connectDatabase editDB;
    bool isCorrectEntry;

    editDB.openConnection();

    if(ui->lineEdit->text() == ""){
        QMessageBox::about(this,"No Key!","Please Enter ISBN of the record to be updated!");
    }
    else{
            QSqlQuery editQry;


            if(ui->lineEdit_2->text() == "" && ui->lineEdit_3->text() == "" && ui->lineEdit_4->text() == "" && ui->lineEdit_5->text() == ""){
                QMessageBox::about(this,"Empty values!","Please Enter Values to be Updated!");
            }


            if(ui->lineEdit_5->text()!=""){
              editQry.prepare("update CSBooks set Year = :newyear where ISBN = :isbn");
              editQry.bindValue(":newyear",ui->lineEdit_5->text());
              editQry.bindValue(":isbn",ui->lineEdit->text());
              isCorrectEntry = editQry.exec();
            }

            if(ui->lineEdit_4->text()!=""){
              editQry.prepare("update CSBooks set Author = :newauthor where ISBN = :isbn");
              editQry.bindValue(":newauthor",ui->lineEdit_4->text());
              editQry.bindValue(":isbn",ui->lineEdit->text());
              isCorrectEntry = editQry.exec();
            }

            if(ui->lineEdit_3->text()!=""){
              editQry.prepare("update CSBooks set Name = :newname where ISBN = :isbn");
              editQry.bindValue(":newname",ui->lineEdit_3->text());
              editQry.bindValue(":isbn",ui->lineEdit->text());
              isCorrectEntry = editQry.exec();
            }

            if(ui->lineEdit_2->text()!=""){                                                 //ISBN is updated at end to prevent the wrong referencing of ISBN in updting other entries.
              editQry.prepare("update CSBooks set ISBN = :newisbn where ISBN = :isbn");
              editQry.bindValue(":newisbn",ui->lineEdit_5->text());
              editQry.bindValue(":isbn",ui->lineEdit->text());
              isCorrectEntry = editQry.exec();
            }
    }

    editDB.closeConnection();

    if(isCorrectEntry){
        QMessageBox::about(this,"Upation Successful","Entry Updated Successfully!");
    }
    else if (ui->lineEdit->text() != ""){
        QMessageBox::about(this,"Failed!","Error in Value or Input type!");
    }

    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
}

void editentryForm::on_pushButton_2_clicked()
{
    this->close();
}
