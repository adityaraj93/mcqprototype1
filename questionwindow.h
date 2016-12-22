#ifndef QUESTIONWINDOW_H
#define QUESTIONWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <vector>
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include <algorithm>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QNetworkRequest>
#include <QFile>
#include "model/team.h"
#include "model/question.h"

namespace Ui {
class QuestionWindow;
}

class QuestionWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuestionWindow(QWidget *parent = 0, Team *team=NULL, int type1no=0, Question *questionList=NULL);
    ~QuestionWindow();

    Team *getTeam() const;
    void setTeam(Team *value);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void showTime();

    void connectionFinished(QNetworkReply *reply);

    void on_commandLinkButton_clicked();

    void on_optionA_clicked();

    void on_optionB_clicked();

    void on_optionC_clicked();

    void on_optionD_clicked();

private:
#define OPTION_A 1
#define OPTION_B 2
#define OPTION_C 3
#define OPTION_D 4
#define OPTION_NON -1
#define BACK_DIRECTION -1
#define FORWARD_DIRECTION 1
#define TOTAL_TIME 1802
#define WARNING_TIME 302
    Ui::QuestionWindow *ui;
    Team *team;
    int type1no;
    Question *questionList;
    int answerArray[50];
    std::vector<Question> qV;
    int currentQuestion;
    int totalTime;
    QTimer *timer;
    char displayTime[7];
    QMessageBox *box;
    QMessageBox askSubmit;
    bool timer_color_orange_flag;

    void updateQuestionView();
    void storeAnswer(int direction);
    float calcualteScore();
    void clearSelection();
    void submitResult();
};
#endif // QUESTIONWINDOW_H
