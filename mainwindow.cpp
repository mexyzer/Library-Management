#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QStringList list=(QStringList()<<"Select"<<"ISBN"<<"Name"<<"Author"<<"Year");
    ui->comboBox->addItems(list);
    //ui->label_3->setText(5);

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
    connectDatabase search;
    search.openConnection();
    QSqlQueryModel* modal = new QSqlQueryModel;
    QSqlQuery *qry = new QSqlQuery(search.bookDB);
    qry->prepare("select *from CSBooks;");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    //ui->tableView->hideColumn();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
