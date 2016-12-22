#ifndef QUIZDETAIL_H
#define QUIZDETAIL_H

#include <QString>
class QuizDetail
{
public:
    QuizDetail();
    QString getStartTime() const;
    void setStartTime(const QString &value);

    QString getEndTime() const;
    void setEndTime(const QString &value);

private:
    QString startTime;
    QString endTime;
};

#endif // QUIZDETAIL_H
