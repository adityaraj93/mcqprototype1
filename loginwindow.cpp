#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QEvent>
#include <QKeyEvent>
#include <QDebug>
#include <QScreen>
#include <QRect>
#include <QMessageBox>
#include <QPixmap>
#include <QImageReader>
#include <QImage>
#include <QString>
#include "instructiondialog.h"
#include "serveripaddressdialog.h"


LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow), clearFlag(false)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);                                      // Manager to connect to network.
    team = new Team();
    //initialize all the flags to 'false' as all the fields are initially empty
    for(int i=0;i<10;i++)
        lineedits[i]=false;

    //To disable both 'Submit' and 'Clear' button at the beginning
    ui->btnSubmit->setEnabled(false);
    ui->btnClear->setEnabled(false);

    ui->label_img->setBackgroundRole(QPalette::Base);
    ui->label_img->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);       // QSizePolicy::Ignored enables the image to be scaled to necessary size
    ui->label_img->setScaledContents(true);                                         // setScaledContent() will make the image to be zoomed along with the label_image

    QImageReader reader(":/img/dc_logo.png");                 // instantiate a reader
    reader.setAutoTransform(true);                                                  // enable automatic transformation
    const QImage image = reader.read();                                             // load the image
    ui->label_img->setPixmap(QPixmap::fromImage(image));                            // display the image using the label's pixmap

    // install the event filter (keyboard listener) fot all the fields
    ui->lineEdit_1->installEventFilter(this);
    ui->lineEdit_2->installEventFilter(this);
    ui->lineEdit_3->installEventFilter(this);
    ui->lineEdit_4->installEventFilter(this);
    ui->lineEdit_5->installEventFilter(this);
    ui->lineEdit_6->installEventFilter(this);
    ui->lineEdit_7->installEventFilter(this);
    ui->lineEdit_8->installEventFilter(this);
    ui->lineEdit_9->installEventFilter(this);
    ui->lineEdit_10->installEventFilter(this);
    this->setWindowState(Qt::WindowFullScreen);
}

LoginWindow::~LoginWindow()
{
    delete manager;
    delete ui;
}

bool LoginWindow::eventFilter(QObject *obj, QEvent *event)      //this is the Keyboard listener for all the fields
{
    if(event->type()==QEvent::KeyPress||event->type()==QEvent::KeyRelease){
        lineedit_helper();
        clearActivator();
        submitActivator();
    }
    if(event->type()==QEvent::WindowStateChange)
        QMessageBox::information(this, "event","State changed");

    return QWidget::eventFilter(obj,event);
}

void LoginWindow::on_radioButton_clicked()      // 2 members
{
    ui->student2Group->setEnabled(true);        // show the form for second member
    lineedit_helper();
    clearActivator();                           // check and (de)activate the 'Clear' Button
    submitActivator();                          // check and (de)activate the 'Submit' Button
}

void LoginWindow::on_radioButton_2_clicked()    // 1 member
{
    ui->student2Group->setEnabled(false);       // hide the form for second member
    lineedit_helper();
    clearActivator();                           // check and (de)activate the 'Clear' Button
    submitActivator();                          // check and (de)activate the 'Submit' Button
}

void LoginWindow::submitActivator()             // function to activate the 'Submit' button
{
    //
    bool x=lineedits[8]&&lineedits[9];          // for the team name and college name
    int y=ui->radioButton->isChecked()?8:4;     // If the team has only one member, then only first four
                                                // lineEdits need to be checked, else all of them need to be checked
    for(int i=0;i<y;i++)
        x=x&&lineedits[i];                      // check if all the Fields are filled.
    ui->btnSubmit->setEnabled(x);               // enable or disable on the Submit button
}

void LoginWindow::clearActivator()              // function to activate the 'Clear' button
{
    bool x=lineedits[8]||lineedits[9];          // for the Team name and college name
    int y=ui->radioButton->isChecked()?8:4;     // If the team has only one member, then only first four
                                                // lineEdits need to be checked, else all of them need to be checked
    for(int i=0;i<y;i++)
        x=x||lineedits[i];                      // check if all the Fields are filled.
    ui->btnClear->setEnabled(x);                // enable or disable on the Clear button
}

void LoginWindow::lineedit_helper()             // set or reset flags for corresponding flags for all the fields
{
    if(ui->lineEdit_1->text().trimmed().length()==0)
        lineedits[0]=false;
    else    lineedits[0]=true;

    if(ui->lineEdit_2->text().trimmed().length()==0)
        lineedits[1]=false;
    else    lineedits[1]=true;

    if(ui->lineEdit_3->text().trimmed().length()==0)
        lineedits[2]=false;
    else    lineedits[2]=true;

    if(ui->lineEdit_4->text().trimmed().length()==0)
        lineedits[3]=false;
    else    lineedits[3]=true;

    if(ui->lineEdit_5->text().trimmed().length()==0)
        lineedits[4]=false;
    else    lineedits[4]=true;

    if(ui->lineEdit_6->text().trimmed().length()==0)
        lineedits[5]=false;
    else    lineedits[5]=true;

    if(ui->lineEdit_7->text().trimmed().length()==0)
        lineedits[6]=false;
    else    lineedits[6]=true;

    if(ui->lineEdit_8->text().trimmed().length()==0)
        lineedits[7]=false;
    else    lineedits[7]=true;

    if(ui->lineEdit_9->text().trimmed().length()==0)
        lineedits[8]=false;
    else    lineedits[8]=true;


    if(ui->lineEdit_10->text().trimmed().length()==0)
        lineedits[9]=false;
    else    lineedits[9]=true;
}

void LoginWindow::errorCleaner()
{
    ui->lineEdit_1->setStyleSheet("");
    ui->lineEdit_2->setStyleSheet("");
    ui->lineEdit_3->setStyleSheet("");
    ui->lineEdit_4->setStyleSheet("");
    ui->lineEdit_5->setStyleSheet("");
    ui->lineEdit_6->setStyleSheet("");
    ui->lineEdit_7->setStyleSheet("");
    ui->lineEdit_8->setStyleSheet("");
    ui->lineEdit_9->setStyleSheet("");
    ui->lineEdit_10->setStyleSheet("");
}

void LoginWindow::on_btnClear_clicked()         // Clear all the fields
{
    ui->lineEdit_1->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_9->setText("");
    ui->lineEdit_10->setText("");
    ui->btnClear->setEnabled(false);
    ui->btnSubmit->setEnabled(false);
    errorCleaner();
}

void LoginWindow::on_btnSubmit_clicked()        // Validate the data and submit the details then go to the Instructions Page
{
    if(!checkData())
        return;
    /**
      * Insert code to send the details to the server
      */

    team->setTeamName(ui->lineEdit_9->text());
    team->setCollegeName(ui->lineEdit_10->text());
    if(ui->radioButton->isChecked()){           // if there are two members then get information from both
        team->setNs(TWOSTUDENT);
        team->setName2(ui->lineEdit_5->text());
        team->setUsn2(ui->lineEdit_6->text());
        team->setEmail2(ui->lineEdit_7->text());
        team->setPhone2(ui->lineEdit_8->text());
    }
    else
        team->setNs(ONESTUDENT);        // if there is only one member then get info of that member

    team->setName1(ui->lineEdit_1->text());
    team->setUsn1(ui->lineEdit_2->text());
    team->setEmail1(ui->lineEdit_3->text());
    team->setPhone1(ui->lineEdit_4->text());

    connectToNetwork();
}

void LoginWindow::connectionFinished(QNetworkReply *reply)
{
    if(reply->error()!=QNetworkReply::NoError){
        //qDebug()<<"error: "<<reply->errorString();
        QMessageBox::critical(this,"Connection Error",reply->errorString());
        return;
    }

    QByteArray c = reply->readAll();

    //qDebug()<< "Reply = " + c + "\n";

    int x=0;

    QString s(c);

    if(s=="0"){
        QMessageBox::critical(this,"Error","Error Code: REPEAT_TN_ST1");
        return;
    }
    if(s=="2"){
        QMessageBox::critical(this,"Error","Error Code: REPEAT_ST2");
        return;
    }
    if(s=="1"){
        x=1;
        reply->deleteLater();
        InstructionDialog *id =  new InstructionDialog(this,team,x);
        this->hide();
        id->show();
    }
}

bool LoginWindow::checkData()                   // Validate the data provided in the fields of the Login Page
{
    bool ret=true;

    //Team Name
    vState = v.validateTeamName(ui->lineEdit_9->text().trimmed());
    if(vState!=QValidator::Acceptable)
        ui->lineEdit_9->setStyleSheet(validationError),ret=false;
    else
        ui->lineEdit_9->setStyleSheet("");

    //College Name
    vState = v.validateCollegeName(ui->lineEdit_10->text().trimmed());
    if(vState!=QValidator::Acceptable)
        ui->lineEdit_10->setStyleSheet(validationError),ret=false;
    else
        ui->lineEdit_10->setStyleSheet("");


    //Name
    vState = v.validateName(ui->lineEdit_1->text().trimmed());
    if(vState!=QValidator::Acceptable)
        ui->lineEdit_1->setStyleSheet(validationError),ret=false;
    else
        ui->lineEdit_1->setStyleSheet("");

    //USN
    vState = v.validateUSN(ui->lineEdit_2->text().trimmed());
    if(vState!=QValidator::Acceptable)
        ui->lineEdit_2->setStyleSheet(validationError),ret=false;
    else
        ui->lineEdit_2->setStyleSheet("");

    //Email
    vState = v.validateEmail(ui->lineEdit_3->text().trimmed());
    if(vState!=QValidator::Acceptable)
        ui->lineEdit_3->setStyleSheet(validationError),ret=false;
    else
        ui->lineEdit_3->setStyleSheet("");

    //Mobile
    vState = v.validateMobile(ui->lineEdit_4->text().trimmed());
    if(vState!=QValidator::Acceptable)
        ui->lineEdit_4->setStyleSheet(validationError),ret=false;
    else
        ui->lineEdit_4->setStyleSheet("");



    if(ui->radioButton->isChecked()){           // if there are two members then validation for the second member
        //Name
        vState = v.validateName(ui->lineEdit_1->text().trimmed());
        if(vState!=QValidator::Acceptable)
            ui->lineEdit_5->setStyleSheet(validationError),ret=false;
        else
            ui->lineEdit_5->setStyleSheet("");

        //USN
        vState=v.validateUSN(ui->lineEdit_6->text().trimmed());
        if(vState!=QValidator::Acceptable)
            ui->lineEdit_6->setStyleSheet(validationError),ret=false;
        else
            ui->lineEdit_6->setStyleSheet("");

        //Email
        vState = v.validateEmail(ui->lineEdit_7->text().trimmed());
        if(vState!=QValidator::Acceptable)
            ui->lineEdit_7->setStyleSheet(validationError),ret=false;
        else
            ui->lineEdit_7->setStyleSheet("");

        //Mobile
        vState = v.validateMobile(ui->lineEdit_8->text().trimmed());
        if(vState!=QValidator::Acceptable)
            ui->lineEdit_8->setStyleSheet(validationError),ret=false;
        else
            ui->lineEdit_8->setStyleSheet("");
     }
    return ret;
}

void LoginWindow::connectToNetwork()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(connectionFinished(QNetworkReply*)));
    qDebug()<<"IP Address server: "<<team->server_ip_address;
    QString qry = "http://"+team->server_ip_address+"/sendtest.php?";
    qry = qry + "team=" ;
    qry = (qry+team->getTeamName());
    qry = qry+"&college=";
    qry = (qry+team->getCollegeName());

    qry = qry+"&ns=";
    qry = (qry+QString::number(team->getNs()));

    qry = qry+"&name1="+team->getName1();
    qry = qry+"&usn1="+team->getUsn1();
    qry = qry+"&email1="+team->getEmail1();
    qry = qry+"&phone1="+team->getPhone1();

    if(team->getNs()==TWOSTUDENT){
        qry = qry+"&name2="+team->getName2();
        qry = qry+"&usn2="+team->getUsn2();
        qry = qry+"&email2="+team->getEmail2();
        qry = qry+"&phone2="+team->getPhone2();
    }

 //   qDebug()<< qry << endl;
    manager->get(QNetworkRequest(QUrl(qry)));
}

void LoginWindow::on_toolButton_clicked()
{
    ServerIpAddressDialog *servIP = new ServerIpAddressDialog(this,&(team->server_ip_address));
    servIP->show();
    ui->toolButton->setEnabled(false);
}
