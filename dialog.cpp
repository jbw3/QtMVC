#include <QDebug>
#include <QSortFilterProxyModel>

#include "dialog.h"
#include "personmodel.h"
#include "ui_dialog.h"

bool isRegExSpecialChar(const QChar& ch)
{
    return (ch == '.' || ch == '*' || ch == '(' || ch == ')' ||
            ch == '^' || ch == '$' || ch == '|' || ch == '|' ||
            ch == '[' || ch == ']' || ch == '{' || ch == '}' ||
            ch == '+' || ch == '\\');
}

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    qsrand(time(NULL));

    ui->setupUi(this);

    QList<Person> persons;
    QStringList firstnames = QStringList() << "Al" << "Arthur" << "Bill" << "Carl" << "Carol" << "Don" << "Edward" << "Emma"
                                           << "Fred" << "George" << "Hank" << "Ike" << "Jeff" << "Jerry" << "John" << "Mary"
                                           << "Sandy" << "Ted" << "Tim" << "Tom" << "Virginia" << "Will" << "Yolanda" << "Zach";
    QStringList lastnames = QStringList() << "Anderson" << "Baker" << "Burns" << "Carter" << "Cooper" << "Jackson" << "Jefferson"
                                          << "Johnson" << "McDonald" << "Smith";

    for (auto fIter = firstnames.begin(); fIter != firstnames.end(); ++fIter)
    {
        for (auto lIter = lastnames.begin(); lIter != lastnames.end(); ++lIter)
        {
            int age = (qrand() % 65) + 15;
            persons.push_back(Person(*fIter, *lIter, age));
        }
    }
    persons.push_back(Person("John", "Wilkes", 23));

    PersonModel* sourceModel = new PersonModel(this);
    sourceModel->setPersonList(persons);

    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(sourceModel);
    proxyModel->setFilterKeyColumn(-1);

    ui->tableView->setModel(proxyModel);

    connect(ui->searchBar, SIGNAL(textEdited(QString)), this, SLOT(updateSearch(QString)));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::updateSearch(QString searchText)
{
    QString regExStr;
    foreach (QChar ch, searchText)
    {
        regExStr.append(".*");
        if (isRegExSpecialChar(ch))
            regExStr.append('\\');
        regExStr.append(ch);
    }
    regExStr.append(".*");

    qDebug() << regExStr;

    QRegExp regEx(regExStr, Qt::CaseInsensitive);
    proxyModel->setFilterRegExp(regEx);
}
