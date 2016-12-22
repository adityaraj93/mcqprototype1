#include "serveripaddressdialog.h"
#include "ui_serveripaddressdialog.h"

ServerIpAddressDialog::ServerIpAddressDialog(QWidget *parent, QString *ip) :
    QDialog(parent),ip(ip),
    ui(new Ui::ServerIpAddressDialog)
{
    ui->setupUi(this);
    this->setModal(true);
    if(this->ip->length()!=0){
        ui->lineEdit->setText(*ip);
    }
}

ServerIpAddressDialog::~ServerIpAddressDialog()
{
    delete ui;
}

void ServerIpAddressDialog::on_commandLinkButton_clicked()
{
    if(ui->lineEdit->text().trimmed().length()!=0){
        *ip = ui->lineEdit->text().trimmed();
        this->close();
    }
    else
        QMessageBox::critical(this,"Error","Please enter correct IP address");
}
