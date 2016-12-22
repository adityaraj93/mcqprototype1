#include "loginvalidator.h"
#include <QDebug>

QValidator::State LoginValidator::validateTeamName(QString &value) const
{
    int x;
    QRegExp reg("[Tt][Ee][Aa][Mm][0-9]{1,3}");
    QRegExpValidator *validator = new QRegExpValidator(reg);
    return validator->validate(value,x);
}

QValidator::State LoginValidator::validateCollegeName(QString &value) const
{
    int x;
    QRegExp reg("[A-Za-z .-]*");
    QRegExpValidator *validator = new QRegExpValidator(reg);
    return validator->validate(value,x);
}

QValidator::State LoginValidator::validateName(QString &value) const
{
    int x;
    QRegExp reg("[A-Za-z .]*");
    QRegExpValidator *validator = new QRegExpValidator(reg);
    return validator->validate(value,x);
}

QValidator::State LoginValidator::validateUSN(QString &value) const
{
    int x;
    QRegExp reg("[1-9][A-Za-z]{2}[012][0-9](([A-Za-z]{2}[0-9]{3})|([A-Za-z]{3}[0-9]{2}))");
    QRegExpValidator *validator = new QRegExpValidator(reg);
    return validator->validate(value,x);
}

QValidator::State LoginValidator::validateMobile(QString &value) const
{
    int x;
    QRegExp reg("[0-9]{10}");
    QRegExpValidator *validator = new QRegExpValidator(reg);
    return validator->validate(value,x);
}

QValidator::State LoginValidator::validateEmail(QString &value) const
{
    int x;
    QRegExp reg("[a-zA-Z0-9._]+@[a-z0-9.]*\.[a-zA-Z]{2,3}");
    QRegExpValidator *validator = new QRegExpValidator(reg);
    return validator->validate(value,x);
}
