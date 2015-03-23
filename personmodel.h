#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QAbstractTableModel>

struct Person
{
    static const int NUM_COLUMNS = 3;

    QString firstname;
    QString lastname;
    uint age;

    Person() :
        firstname(""),
        lastname(""),
        age(0)
    {}

    Person(const QString& fname, const QString& lname, uint a) :
        firstname(fname),
        lastname(lname),
        age(a)
    {}
};

class PersonModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit PersonModel(QObject* parent = 0);

    virtual ~PersonModel();

    void setPersonList(const QList<Person>& personList);

    virtual int rowCount(const QModelIndex& parent) const;

    virtual int columnCount(const QModelIndex& parent) const;

    virtual QVariant data(const QModelIndex& index, int role) const;

    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;

protected:
    QList<Person> persons;
};

#endif // PERSONMODEL_H
