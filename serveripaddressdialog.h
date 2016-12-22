#ifndef SERVERIPADDRESSDIALOG_H
#define SERVERIPADDRESSDIALOG_H

#include <QDialog>
#include<QMessageBox>

namespace Ui {
class ServerIpAddressDialog;
}

class ServerIpAddressDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ServerIpAddressDialog(QWidget *parent = 0,QString *ip=NULL);
    ~ServerIpAddressDialog();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::ServerIpAddressDialog *ui;
    QString *ip;
};

#endif // SERVERIPADDRESSDIALOG_H
