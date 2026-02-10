#ifndef BRIGETESTSETTING_EXPECT_R_H
#define BRIGETESTSETTING_EXPECT_R_H

#include "datastruct.h"

#include <qdialog.h>


namespace Ui {
class brigetestsetting_expect_R;
}

class brigetestsetting_expect_R : public QDialog
{
    Q_OBJECT
public:
    explicit brigetestsetting_expect_R(QString mod, QWidget *parent = nullptr);
    ~brigetestsetting_expect_R();

signals:
    void settingData(brigetestData settings);

private slots:
    void on_pushButton_confirm_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::brigetestsetting_expect_R *ui;
};

#endif // BRIGETESTSETTING_EXPECT_R_H
