#include "team.h"

Team::Team()
{

}
QString Team::getTeamName() const
{
    return teamName;
}

void Team::setTeamName(const QString &value)
{
    teamName = value;
}
QString Team::getCollegeName() const
{
    return collegeName;
}

void Team::setCollegeName(const QString &value)
{
    collegeName = value;
}
float Team::getScore() const
{
    return score;
}

void Team::setScore(const float &value)
{
    score = value;
}
QString Team::getName1() const
{
    return name1;
}

void Team::setName1(const QString &value)
{
    name1 = value;
}
QString Team::getUsn1() const
{
    return usn1;
}

void Team::setUsn1(const QString &value)
{
    usn1 = value;
}
QString Team::getEmail1() const
{
    return email1;
}

void Team::setEmail1(const QString &value)
{
    email1 = value;
}
QString Team::getPhone1() const
{
    return phone1;
}

void Team::setPhone1(const QString &value)
{
    phone1 = value;
}
QString Team::getName2() const
{
    return name2;
}

void Team::setName2(const QString &value)
{
    name2 = value;
}
QString Team::getUsn2() const
{
    return usn2;
}

void Team::setUsn2(const QString &value)
{
    usn2 = value;
}
QString Team::getEmail2() const
{
    return email2;
}

void Team::setEmail2(const QString &value)
{
    email2 = value;
}
QString Team::getPhone2() const
{
    return phone2;
}

void Team::setPhone2(const QString &value)
{
    phone2 = value;
}

Team::~Team()
{

}
qint8 Team::getNs() const
{
    return ns;
}

void Team::setNs(const qint8 &value)
{
    ns = value;
}

