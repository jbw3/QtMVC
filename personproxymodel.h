#ifndef PERSONPROXYMODEL_H
#define PERSONPROXYMODEL_H

#include <QAbstractProxyModel>

class PersonProxyModel : public QAbstractProxyModel
{
    Q_OBJECT

public:
    explicit PersonProxyModel(QObject* parent = 0);
};

#endif // PERSONPROXYMODEL_H
