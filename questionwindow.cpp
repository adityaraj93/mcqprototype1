#include "questionwindow.h"
#include "ui_questionwindow.h"
#include <QScreen>
#include <QMessageBox>
#include <QDebug>
#include <QEvent>

int myrandom (int i) { return std::rand()%i;}

QuestionWindow::QuestionWindow(QWidget *parent, Team *team, int type1no, Question *questionList) :
    QMainWindow(parent),team(team),type1no(type1no),questionList(questionList),
    ui(new Ui::QuestionWindow)
{
    ui->setupUi(this);
    //ui->timerLabel->setFont(QFont("Courier New",25));
    std::srand ( unsigned ( std::time(0) ) );           // seed for rand() function

    timer_color_orange_flag=true;

    ui->pushButton_2->setStyleSheet("");
    ui->pushButton_3->setStyleSheet("");
    ui->pushButton_4->setStyleSheet("");

    currentQuestion = 0;
    totalTime = TOTAL_TIME;

    for(int i=0;i<type1no;i++){
        answerArray[i]=OPTION_NON;
        qV.push_back(questionList[i]);
    }
    std::random_shuffle(qV.begin(), qV.end(),myrandom); // shuffle the questions
    type1no=30;
    this->setWindowState(Qt::WindowMaximized);

    ui->optionA->setText(qV.at(0).getOpta());
    ui->optionB->setText(qV.at(0).getOptb());
    ui->optionC->setText(qV.at(0).getOptc());
    ui->optionD->setText(qV.at(0).getOptd());

    ui->questionLabel->setText(qV.at(0).getQues());
    ui->codeLabel->setText(qV.at(0).getCode());
    ui->qnoLabel->setText(QString::number(currentQuestion+1)+"/"+QString::number(type1no));

    ui->timeProgressBar->setRange(0,10000);


    this->setWindowState(Qt::WindowFullScreen);


    timer =new QTimer(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(showTime()));
    showTime();
    timer->start(1000);
}

QuestionWindow::~QuestionWindow()
{
    delete ui;
}


Team *QuestionWindow::getTeam() const
{
    return team;
}

void QuestionWindow::setTeam(Team *value)
{
    team = value;
}

void QuestionWindow::on_pushButton_2_clicked()      // next button
{
    storeAnswer(FORWARD_DIRECTION);

    if(currentQuestion<type1no-1)
        currentQuestion++;
    else
        return;

    updateQuestionView();
}

void QuestionWindow::on_pushButton_3_clicked()      // back button
{
    storeAnswer(BACK_DIRECTION);
    if(currentQuestion!=0)
        currentQuestion--;
    else
        return;

    updateQuestionView();
}

void QuestionWindow::on_pushButton_4_clicked()      // unanswer button
{
    clearSelection();
    answerArray[currentQuestion] = OPTION_NON;
}

void QuestionWindow::showTime()                     // called each second
{
    register int minute=(totalTime-2)/60;
    register int sec = (totalTime-2)%60;
    sprintf(displayTime,"%02d : %02d",minute,sec);
    /*if(sec%2==0)
       {
           displayTime[3]=' ';
       }*/
    --totalTime;
    if(totalTime!=0){
        //ui->timerLabel->setText(QString(displayTime));

        //qDebug()<< (int)100-100*(totalTime-2)/(TOTAL_TIME-2);
        ui->timeProgressBar->setValue((int)10000-10000*(totalTime-2)/(TOTAL_TIME-2));
        ui->timeProgressBar->setFormat("Time Left : "+ QString(displayTime));
        if(timer_color_orange_flag && totalTime < WARNING_TIME){
            ui->timeProgressBar->setStyleSheet("QProgressBar {\
                                               font: bold 14pt; color: white;\
                                                   border: 2px solid grey;\
                                                   border-radius: 5px;\
                                                   text-align: center;\
                                               }\
                                               \
                                               QProgressBar::chunk {\
                                                   background-color: rgb(222, 0, 0);\
                                               }");
            timer_color_orange_flag=false;
        }
    }
    else{
        submitResult();
    }
}

void QuestionWindow::connectionFinished(QNetworkReply *reply)
{
    if(reply->error()!=QNetworkReply::NoError){
        //qDebug()<<"error: "<<reply->errorString();
        QMessageBox::critical(this,"Connection Error",reply->errorString());
        return;
    }

    QByteArray c = reply->readAll();

    box->setText("Your score has been submitted...Please do not close anything...\n Thank you");

}

void QuestionWindow::updateQuestionView()
{
    type1no = 30;
    ui->questionLabel->setText(qV.at(currentQuestion).getQues());
    ui->codeLabel->setText(qV.at(currentQuestion).getCode());
    ui->optionA->setText(qV.at(currentQuestion).getOpta());
    ui->optionB->setText(qV.at(currentQuestion).getOptb());
    ui->optionC->setText(qV.at(currentQuestion).getOptc());
    ui->optionD->setText(qV.at(currentQuestion).getOptd());
    ui->qnoLabel->setText(QString::number(currentQuestion+1)+"/"+QString::number(type1no));

    if(answerArray[currentQuestion]!=OPTION_NON){
        switch(answerArray[currentQuestion]){
        case OPTION_A: ui->optionA->setChecked(true);
            break;
        case OPTION_B: ui->optionB->setChecked(true);
            break;
        case OPTION_C: ui->optionC->setChecked(true);
            break;
        case OPTION_D: ui->optionD->setChecked(true);
            break;
        default:
                break;
        }
    }
}

void QuestionWindow::storeAnswer(int direction)
{
    if(ui->optionA->isChecked()){
        answerArray[currentQuestion]=OPTION_A;
    }
    else if(ui->optionB->isChecked()){
        answerArray[currentQuestion]=OPTION_B;
    }
    else if(ui->optionC->isChecked()){
        answerArray[currentQuestion]=OPTION_C;
    }
    else if(ui->optionD->isChecked()){
        answerArray[currentQuestion]=OPTION_D;
    }
    else answerArray[currentQuestion]=OPTION_NON;

    if((currentQuestion==0&&direction == BACK_DIRECTION)||(currentQuestion==type1no-1 && direction == FORWARD_DIRECTION))
        return;
    else
        clearSelection();
}

float QuestionWindow::calcualteScore()
{
    float score=0.0;
    float posMarks=1;
    float negMarks=-0.33f;
    for(int i=0;i<type1no;i++){
        int ans=qV.at(i).getAns();
        if(answerArray[i]!=OPTION_NON){
            if(answerArray[i]==ans)
                score+=posMarks;
            else
                score+=negMarks;
        }
    }
    return score;
}

void QuestionWindow::clearSelection()
{
    if(ui->optionA->isChecked()){
        ui->optionA->setAutoExclusive(false);
        ui->optionA->setChecked(false);
        ui->optionA->setAutoExclusive(true);
    }
    else if(ui->optionB->isChecked()){
        ui->optionB->setAutoExclusive(false);
        ui->optionB->setChecked(false);
        ui->optionC->setAutoExclusive(true);
    }
    else if(ui->optionC->isChecked()){
        ui->optionC->setAutoExclusive(false);
        ui->optionC->setChecked(false);
        ui->optionC->setAutoExclusive(true);
    }
    else if(ui->optionD->isChecked()){
        ui->optionD->setAutoExclusive(false);
        ui->optionD->setChecked(false);
        ui->optionD->setAutoExclusive(true);
    }
}

void QuestionWindow::submitResult()
{

    float score = calcualteScore();
    QFile resFile("Res_"+team->getTeamName()+"_USN1_"+team->getUsn1()+".txt");
    resFile.open(QIODevice::WriteOnly | QIODevice::Text);

    QTextStream out(&resFile);
    out<<"Team Name : "<<team->getTeamName()<<endl;
    out<<"USN1 : "<<team->getUsn1()<<endl;
    out<<"Phone 1 : "<<team->getPhone1();
    out<<endl<<"USN2 : "<<team->getUsn2();
    out<<endl<<"Phone 2 : "<<team->getPhone2();
    out<<endl<<"Score : " <<QString::number(score);



    disconnect(timer,SIGNAL(timeout()),this, SLOT(showTime()));


    out<<endl<<"Time taken: "<<QString::number(TOTAL_TIME-totalTime);
    out.flush();

    resFile.close();

    box = new QMessageBox(this);
    box->setWindowTitle("Finished...");
    box->setText("Please wait while we submit the results...Please do not press Ok");
    box->setModal(true);
    box->show();

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(connectionFinished(QNetworkReply*)));
    QString qry = "http://"+team->server_ip_address+"/update_result.php?";
    qry = qry+"name="+team->getTeamName();
    qry = qry+"&score="+QString::number(score);
    qry = qry+"&time="+QString::number(TOTAL_TIME-totalTime);

    qDebug()<<"reply: "<<qry<<endl;

    manager->get(QNetworkRequest(QUrl(qry)));
    this->hide();
}

void QuestionWindow::on_commandLinkButton_clicked()
{
    if(QMessageBox::question(this,"Submit pressed","Are you sure you want to submit and finish the test?",QMessageBox::Yes,QMessageBox::No)==QMessageBox::Yes)
        submitResult();
}

void QuestionWindow::on_optionA_clicked()
{
    answerArray[currentQuestion]=1;
    // to make sure that no other option is selected
    if(ui->optionB->isChecked()){
        ui->optionB->setAutoExclusive(false);
        ui->optionB->setChecked(false);
        ui->optionC->setAutoExclusive(true);
    }
    else if(ui->optionC->isChecked()){
        ui->optionC->setAutoExclusive(false);
        ui->optionC->setChecked(false);
        ui->optionC->setAutoExclusive(true);
    }
    else if(ui->optionD->isChecked()){
        ui->optionD->setAutoExclusive(false);
        ui->optionD->setChecked(false);
        ui->optionD->setAutoExclusive(true);
    }

}

void QuestionWindow::on_optionB_clicked()
{
    answerArray[currentQuestion]=2;
    // to make sure that no other option is selected
    if(ui->optionA->isChecked()){
        ui->optionA->setAutoExclusive(false);
        ui->optionA->setChecked(false);
        ui->optionA->setAutoExclusive(true);
    }
    else if(ui->optionC->isChecked()){
        ui->optionC->setAutoExclusive(false);
        ui->optionC->setChecked(false);
        ui->optionC->setAutoExclusive(true);
    }
    else if(ui->optionD->isChecked()){
        ui->optionD->setAutoExclusive(false);
        ui->optionD->setChecked(false);
        ui->optionD->setAutoExclusive(true);
    }
}

void QuestionWindow::on_optionC_clicked()
{
    answerArray[currentQuestion]=3;
    // to make sure that no other option is selected
    if(ui->optionA->isChecked()){
        ui->optionA->setAutoExclusive(false);
        ui->optionA->setChecked(false);
        ui->optionA->setAutoExclusive(true);
    }
    else if(ui->optionB->isChecked()){
        ui->optionB->setAutoExclusive(false);
        ui->optionB->setChecked(false);
        ui->optionC->setAutoExclusive(true);
    }
    else if(ui->optionD->isChecked()){
        ui->optionD->setAutoExclusive(false);
        ui->optionD->setChecked(false);
        ui->optionD->setAutoExclusive(true);
    }
}

void QuestionWindow::on_optionD_clicked()
{
    answerArray[currentQuestion]=4;
    // to make sure that no other option is selected
    if(ui->optionA->isChecked()){
        ui->optionA->setAutoExclusive(false);
        ui->optionA->setChecked(false);
        ui->optionA->setAutoExclusive(true);
    }
    else if(ui->optionB->isChecked()){
        ui->optionB->setAutoExclusive(false);
        ui->optionB->setChecked(false);
        ui->optionC->setAutoExclusive(true);
    }
    else if(ui->optionC->isChecked()){
        ui->optionC->setAutoExclusive(false);
        ui->optionC->setChecked(false);
        ui->optionC->setAutoExclusive(true);
    }
}
