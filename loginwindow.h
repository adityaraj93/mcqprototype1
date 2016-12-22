#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "validators/loginvalidator.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>
#include <QNetworkRequest>
#include "model/team.h"


namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();
    bool eventFilter(QObject *, QEvent *);



private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_btnClear_clicked();

    void on_btnSubmit_clicked();

    void connectionFinished(QNetworkReply *reply);

    void on_toolButton_clicked();

private:
    Ui::LoginWindow *ui;
    bool clearFlag=false;
    bool lineedits[10];
    void submitActivator();
    void clearActivator();
    void lineedit_helper();
    void errorCleaner();
    int num=0;
    QString validationError = "border: 1px solid red";
    LoginValidator v;
    QValidator::State vState;
    QNetworkAccessManager *manager;
    Team *team;
    bool checkData();
    void connectToNetwork();
};

#endif // LOGINWINDOW_H
