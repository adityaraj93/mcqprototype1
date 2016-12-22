#ifndef LOGINVALIDATOR_H
#define LOGINVALIDATOR_H

#include <QValidator>



class LoginValidator
{
public:
    LoginValidator(){}

    // QValidator interfac

    QValidator::State validateTeamName(QString &value) const;
    QValidator::State validateCollegeName(QString &value) const;
    QValidator::State validateName(QString &value) const;
    QValidator::State validateUSN(QString &value) const;
    QValidator::State validateMobile(QString &value) const;
    QValidator::State validateEmail(QString &value) const;

};

#endif // LOGINVALIDATOR_H
