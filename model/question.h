#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>
#include<QString>

class Question
{
public:
    Question(){}
    Question(qint8 no, QString _ques, QString _code, QString _a, QString _b, QString _c, QString _d, qint8 _ans);

    qint8 getQno() const;
    void setQno(const qint8 &value);

    QString getQues() const;
    void setQues(const QString &value);

    QString getCode() const;
    void setCode(const QString &value);

    QString getOpta() const;
    void setOpta(const QString &value);

    QString getOptb() const;
    void setOptb(const QString &value);

    QString getOptc() const;
    void setOptc(const QString &value);

    QString getOptd() const;
    void setOptd(const QString &value);

    qint8 getAns() const;
    void setAns(const qint8 &value);

private:
    qint8 qno;
    QString ques;
    QString code;
    QString opta;
    QString optb;
    QString optc;
    QString optd;
    qint8 ans;
};

#endif // QUESTION_H
