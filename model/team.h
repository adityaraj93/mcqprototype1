#ifndef TEAM_H
#define TEAM_H
#include<QString>

/*
 * Class Team is used to store the general information of the participating team.
*/
#define ONESTUDENT 1
#define TWOSTUDENT 2

class Team
{
public:
    Team();
    QString server_ip_address;
    QString getTeamName() const;
    void setTeamName(const QString &value);

    QString getCollegeName() const;
    void setCollegeName(const QString &value);

    float getScore() const;
    void setScore(const float &value);

    QString getName1() const;
    void setName1(const QString &value);

    QString getUsn1() const;
    void setUsn1(const QString &value);

    QString getEmail1() const;
    void setEmail1(const QString &value);

    QString getPhone1() const;
    void setPhone1(const QString &value);

    QString getName2() const;
    void setName2(const QString &value);

    QString getUsn2() const;
    void setUsn2(const QString &value);

    QString getEmail2() const;
    void setEmail2(const QString &value);

    QString getPhone2() const;
    void setPhone2(const QString &value);

    ~Team();

    qint8 getNs() const;
    void setNs(const qint8 &value);

private:
    QString teamName;
    QString collegeName;
    qint8 ns;           // number of students in the team, can be either 1 or 2
    float score;        // final score of the team

    QString name1;      // the name of the first student
    QString usn1;       // the usn of first student
    QString email1;     // the email of the first student
    QString phone1;     // the phone number of the first student

    QString name2;      // the name of the second student
    QString usn2;       // the usn of second student
    QString email2;     // the email of the second student
    QString phone2;     // the phone number of the second student

};

#endif // TEAM_H
