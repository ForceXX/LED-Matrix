#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    int fd;
    char matrix_row_0;
    char matrix_row_1;
    char matrix_row_2;
    char matrix_row_3;
    char matrix_row_4;
    char matrix_row_5;
    char matrix_row_6;
    char matrix_row_7;

    char display_setting;
    Ui::MainWindow *ui;
private slots:
    void on_pushButton_2_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_pushButton_clicked();

    void on_checkBox_0_7_clicked(bool checked);
    void on_checkBox_0_6_clicked(bool checked);
    void on_checkBox_0_5_clicked(bool checked);
    void on_checkBox_0_4_clicked(bool checked);
    void on_checkBox_0_3_clicked(bool checked);
    void on_checkBox_0_2_clicked(bool checked);
    void on_checkBox_0_1_clicked(bool checked);
    void on_checkBox_0_0_clicked(bool checked);
    void on_comboBox_2_activated(int index);
    void on_comboBox_activated(int index);
    void on_checkBox_1_7_clicked(bool checked);
    void on_checkBox_1_6_clicked(bool checked);
    void on_checkBox_1_5_clicked(bool checked);
    void on_checkBox_1_4_clicked(bool checked);
    void on_checkBox_1_3_clicked(bool checked);
    void on_checkBox_1_2_clicked(bool checked);
    void on_checkBox_1_1_clicked(bool checked);
    void on_checkBox_1_0_pressed();
    void on_checkBox_1_0_clicked(bool checked);
    void on_checkBox_2_0_clicked(bool checked);
    void on_checkBox_2_1_clicked(bool checked);
    void on_checkBox_2_7_clicked(bool checked);
    void on_checkBox_2_2_clicked(bool checked);
    void on_checkBox_2_3_clicked(bool checked);
    void on_checkBox_2_4_clicked(bool checked);
    void on_checkBox_2_5_clicked(bool checked);
    void on_checkBox_2_6_clicked(bool checked);
    void on_checkBox_3_7_clicked(bool checked);
    void on_checkBox_3_6_clicked(bool checked);
    void on_checkBox_3_5_clicked(bool checked);
    void on_checkBox_3_4_clicked(bool checked);
    void on_checkBox_3_3_clicked(bool checked);
    void on_checkBox_3_2_clicked(bool checked);
    void on_checkBox_3_1_clicked(bool checked);
    void on_checkBox_3_0_pressed();
    void on_checkBox_3_0_clicked(bool checked);
    void on_checkBox_4_7_clicked(bool checked);
    void on_checkBox_4_6_clicked(bool checked);
    void on_checkBox_4_5_clicked(bool checked);
    void on_checkBox_4_4_clicked(bool checked);
    void on_checkBox_4_3_clicked(bool checked);
    void on_checkBox_4_2_clicked(bool checked);
    void on_checkBox_4_1_clicked(bool checked);
    void on_checkBox_4_0_clicked(bool checked);
    void on_checkBox_5_7_clicked(bool checked);
    void on_checkBox_5_6_clicked(bool checked);
    void on_checkBox_5_5_clicked(bool checked);
    void on_checkBox_5_4_clicked(bool checked);
    void on_checkBox_5_3_clicked(bool checked);
    void on_checkBox_5_2_clicked(bool checked);
    void on_checkBox_5_1_clicked(bool checked);
    void on_checkBox_5_0_clicked(bool checked);
    void on_checkBox_6_7_clicked(bool checked);
    void on_checkBox_6_6_clicked(bool checked);
    void on_checkBox_6_5_clicked(bool checked);
    void on_checkBox_6_4_clicked(bool checked);
    void on_checkBox_6_3_clicked(bool checked);
    void on_checkBox_6_2_clicked(bool checked);
    void on_checkBox_6_1_clicked(bool checked);
    void on_checkBox_6_0_clicked(bool checked);
    void on_checkBox_7_7_clicked(bool checked);
    void on_checkBox_7_6_clicked(bool checked);
    void on_checkBox_7_5_clicked(bool checked);
    void on_checkBox_7_4_clicked(bool checked);
    void on_checkBox_7_3_clicked(bool checked);
    void on_checkBox_7_2_clicked(bool checked);
    void on_checkBox_7_1_clicked(bool checked);
    void on_checkBox_7_0_clicked(bool checked);
    void on_pushButton_4_clicked();
    void on_pushButton_3_clicked();
    void on_lineEdit_textChanged(const QString &arg1);
    void on_lineEdit_2_textEdited(const QString &arg1);
};

#endif // MAINWINDOW_H
