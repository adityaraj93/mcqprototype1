#include "instructiondialog.h"
#include "ui_instructiondialog.h"
#include "questionwindow.h"
#include <QDebug>
InstructionDialog::InstructionDialog(QWidget *parent, Team *team, int response) :
    QDialog(parent),
    ui(new Ui::InstructionDialog),
    response(response),
    team(team)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);

    //ui->label_2->setText(ui->label_2->text()+" " + QString::number(this->response)+ " team name: "+ team->getTeamName());

}

InstructionDialog::~InstructionDialog()
{
    delete ui;
}

void InstructionDialog::on_commandLinkButton_clicked()
{
    box = new QMessageBox(this);
    //box->information()
    box->setText("Please wait while we retrieve questions");
    box->setModal(true);
    box->setWindowTitle("Connecting...");
    box->show();
    qDebug()<<"Break 1"<<endl;
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(connectionFinished(QNetworkReply*)));
    manager->get(QNetworkRequest(QUrl("http://"+team->server_ip_address+"/quest_retrieve.php")));
    qDebug()<<"Break 2"<<endl;
}

void InstructionDialog::connectionFinished(QNetworkReply *reply)
{
    qDebug()<<"conn finished, break 3"<<endl;
    if(reply->error()!=QNetworkReply::NoError){
        box->close();
        //qDebug()<<"error: "<<reply->errorString();
        QMessageBox::critical(this,"Connection Error",reply->errorString());
        return;
    }
    QByteArray replyData = reply->readAll();
    qDebug()<<"start parse Break 4"<<endl;
    parseReply(replyData);
    qDebug()<<"stop parse, break5"<<endl;
    box->close();
    QuestionWindow *q = new QuestionWindow(this,team,type1n,questionArray);
    q->show();
    this->hide();
}
void InstructionDialog::parseReply(QByteArray dataArray)
{
    QXmlStreamReader xmlReader(dataArray);

    while(!xmlReader.atEnd() && !xmlReader.hasError())
    {
        QXmlStreamReader::TokenType token = xmlReader.readNext();
        if(token == QXmlStreamReader::StartDocument)
            continue;
        if(token == QXmlStreamReader::StartElement)
        {
            if(xmlReader.name()=="qtype1"){
                type1n=xmlReader.attributes().value("total").toString().toInt();
                questionArray = new Question[type1n];
                continue;
            }
            if(xmlReader.name()=="question")
                this->parseQuestion(xmlReader);
        }
    }
}

void InstructionDialog::parseQuestion(QXmlStreamReader &xmlReader)
{
       if(xmlReader.tokenType()!=QXmlStreamReader::StartElement && xmlReader.name()!="question")
       {
           qDebug()<<"error in calling";
           return;
       }
       int qno = (xmlReader.attributes().value("number").toString().toInt())-1;
       questionArray[qno].setQno(qno);
       xmlReader.readNext();
       while(!(xmlReader.tokenType() == QXmlStreamReader::EndElement && xmlReader.name()=="question"))
       {
           if(xmlReader.tokenType()==QXmlStreamReader::StartElement)
           {
                if(xmlReader.name()=="ques")
                {
                    xmlReader.readNext();
                    questionArray[qno].setQues(xmlReader.text().toString());
                }
                else if(xmlReader.name()=="code")
                {
                    xmlReader.readNext();
                    questionArray[qno].setCode(xmlReader.text().toString());
                }
                else if(xmlReader.name()=="opta")
                {
                    xmlReader.readNext();
                    questionArray[qno].setOpta(xmlReader.text().toString());
                }
                else if(xmlReader.name()=="optb")
                {
                    xmlReader.readNext();
                    questionArray[qno].setOptb(xmlReader.text().toString());
                }
                else if(xmlReader.name()=="optc")
                {
                    xmlReader.readNext();
                    questionArray[qno].setOptc(xmlReader.text().toString());
                }
                else if(xmlReader.name()=="optd")
                {
                    xmlReader.readNext();
                    questionArray[qno].setOptd(xmlReader.text().toString());
                }
                else if(xmlReader.name()=="optright")
                {
                    xmlReader.readNext();
                    if(!QString::compare(xmlReader.text().toString(),QString("a")))
                        questionArray[qno].setAns(1);
                    else if(!QString::compare(xmlReader.text().toString(),QString("b")))
                        questionArray[qno].setAns(2);
                    else if(!QString::compare(xmlReader.text().toString(),QString("c")))
                        questionArray[qno].setAns(3);
                    else if(!QString::compare(xmlReader.text().toString(),QString("d")))
                        questionArray[qno].setAns(4);

                }
           }
           xmlReader.readNext();
       }
}
