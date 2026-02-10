#ifndef BRIGETESTERSETTING_H
#define BRIGETESTERSETTING_H

#include <QDialog>
#include <datastruct.h>


namespace Ui {
class brigetestersetting;
}

class brigetestersetting : public QDialog
{
    Q_OBJECT

public:
    explicit brigetestersetting(QWidget *parent = nullptr);
    ~brigetestersetting();

signals:
    void settingData(brigetestData settings);

private slots:
    void on_pushButton_confirm_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::brigetestersetting *ui;
};

#endif // BRIGETESTERSETTING_H
