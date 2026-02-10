#ifndef DEVICE_DM3_68_H
#define DEVICE_DM3_68_H

#include <QDialog>
#include <QTime>
namespace Ui {
class device_dm3068;
}

class device_dm3068 : public QDialog
{
    Q_OBJECT

public:
    explicit device_dm3068(QWidget *parent = nullptr);
    ~device_dm3068();
signals:
    void detectionObj(QString obj);
    void times(int t);
    void internalSeconds(QTime internalS);
private slots:
    void on_pushButton_confirm_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::device_dm3068 *ui;
};

#endif // DEVICE_DM3_68_H
