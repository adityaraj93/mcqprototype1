#include "question.h"


Question::Question(qint8 no, QString _ques, QString _code, QString _a, QString _b, QString _c, QString _d, qint8 _ans): qno(no),
    ques(_ques),opta(_a),optb(_b),optc(_c),optd(_d),ans(_ans)
{

}

qint8 Question::getQno() const
{
    return qno;
}

void Question::setQno(const qint8 &value)
{
    qno = value;
}
QString Question::getQues() const
{
    return ques;
}

void Question::setQues(const QString &value)
{
    ques = value;
}
QString Question::getCode() const
{
    return code;
}

void Question::setCode(const QString &value)
{
    code = value;
}
QString Question::getOpta() const
{
    return opta;
}

void Question::setOpta(const QString &value)
{
    opta = value;
}
QString Question::getOptb() const
{
    return optb;
}

void Question::setOptb(const QString &value)
{
    optb = value;
}
QString Question::getOptc() const
{
    return optc;
}

void Question::setOptc(const QString &value)
{
    optc = value;
}
QString Question::getOptd() const
{
    return optd;
}

void Question::setOptd(const QString &value)
{
    optd = value;
}
qint8 Question::getAns() const
{
    return ans;
}

void Question::setAns(const qint8 &value)
{
    ans = value;
}









