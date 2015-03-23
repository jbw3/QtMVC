#include <QDebug>

#include "personmodel.h"

PersonModel::PersonModel(QObject* parent) :
    QAbstractTableModel(parent)
{
}

PersonModel::~PersonModel()
{
}

void PersonModel::setPersonList(const QList<Person>& personList)
{
    persons = personList;
}

int PersonModel::rowCount(const QModelIndex& /* parent */) const
{
    return persons.length();
}

int PersonModel::columnCount(const QModelIndex& /* parent */) const
{
    return Person::NUM_COLUMNS;
}

QVariant PersonModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole)
    {
        return static_cast<int>(Qt::AlignRight | Qt::AlignVCenter);
    }
    else if (role == Qt::DisplayRole)
    {
        const Person& person = persons.at(index.row());

        switch (index.column())
        {
        case 0:
            return person.firstname;
            break;
        case 1:
            return person.lastname;
            break;
        case 2:
            return person.age;
            break;
        default:
            return "???";
            break;
        }
    }

    return QVariant();
}

QVariant PersonModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal)
        {
            switch (section)
            {
            case 0:
                return "Firstname";
                break;
            case 1:
                return "Lastname";
                break;
            case 2:
                return "Age";
                break;
            default:
                return "???";
                break;
            }
        }
        else if (orientation == Qt::Vertical)
        {
            return section + 1;
        }
    }

    return QVariant();
}
