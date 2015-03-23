#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

// forward declarations
namespace Ui
{
class Dialog;
}
class QSortFilterProxyModel;

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

protected:
    Ui::Dialog *ui;
    QSortFilterProxyModel* proxyModel;

protected slots:
    void updateSearch(QString searchText);
};

#endif // DIALOG_H
