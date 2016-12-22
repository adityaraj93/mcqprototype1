#include "quizdetail.h"

QuizDetail::QuizDetail()
{

}
QString QuizDetail::getStartTime() const
{
    return startTime;
}

void QuizDetail::setStartTime(const QString &value)
{
    startTime = value;
}
QString QuizDetail::getEndTime() const
{
    return endTime;
}

void QuizDetail::setEndTime(const QString &value)
{
    endTime = value;
}



