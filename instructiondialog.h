#ifndef INSTRUCTIONDIALOG_H
#define INSTRUCTIONDIALOG_H

#include <QDialog>
#include "model/team.h"
#include "model/question.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QNetworkRequest>
#include <QMessageBox>
#include <QXmlStreamReader>

namespace Ui {
class InstructionDialog;
}

class InstructionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InstructionDialog(QWidget *parent = 0,Team *team=new Team(),int response=0);
    ~InstructionDialog();

private slots:

    void on_commandLinkButton_clicked();
    void connectionFinished(QNetworkReply *reply);

private:
    Ui::InstructionDialog *ui;
    Team *team;
    QMessageBox *box;
    Question *questionArray;
    int response;
    qint8 type1n,type2n;
    void parseReply(QByteArray dataArray);
    void parseQuestion(QXmlStreamReader &xmlReader);
};

#endif // INSTRUCTIONDIALOG_H
