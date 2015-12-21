#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

/*!
 \brief

*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     \brief

     \param parent
    */
    explicit MainWindow(QWidget *parent = 0);
    /*!
     \brief

    */
    ~MainWindow();

private:
    int fd; /*!< TODO */
    char matrix_row_0; /*!< TODO */
    char matrix_row_1; /*!< TODO */
    char matrix_row_2; /*!< TODO */
    char matrix_row_3; /*!< TODO */
    char matrix_row_4; /*!< TODO */
    char matrix_row_5; /*!< TODO */
    char matrix_row_6; /*!< TODO */
    char matrix_row_7; /*!< TODO */
    bool isInverted; /*!< TODO */

    char display_setting; /*!< TODO */
    Ui::MainWindow *ui; /*!< TODO */
private slots:
    /*!
     \brief String an Matrix senden

    */
    void on_pushButton_2_clicked();
    /*!
     \brief Helligkeit einstellen

     \param value Stufe der Helligkeit 1-16
    */
    void on_horizontalSlider_valueChanged(int value);
    /*!
     \brief Muster an Matrix senden

    */
    void on_pushButton_clicked();

    /*!
     \brief

     \param checked
    */
    void on_checkBox_0_7_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_0_6_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_0_5_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_0_4_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_0_3_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_0_2_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_0_1_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_0_0_clicked(bool checked);
    /*!
     \brief

     \param index
    */
    void on_comboBox_2_activated(int index);
    /*!
     \brief

     \param index
    */
    void on_comboBox_activated(int index);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_1_7_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_1_6_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_1_5_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_1_4_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_1_3_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_1_2_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_1_1_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_1_0_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_2_0_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_2_1_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_2_7_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_2_2_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_2_3_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_2_4_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_2_5_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_2_6_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_3_7_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_3_6_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_3_5_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_3_4_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_3_3_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_3_2_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_3_1_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_3_0_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_4_7_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_4_6_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_4_5_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_4_4_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_4_3_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_4_2_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_4_1_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_4_0_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_5_7_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_5_6_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_5_5_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_5_4_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_5_3_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_5_2_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_5_1_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_5_0_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_6_7_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_6_6_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_6_5_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_6_4_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_6_3_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_6_2_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_6_1_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_6_0_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_7_7_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_7_6_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_7_5_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_7_4_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_7_3_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_7_2_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_7_1_clicked(bool checked);
    /*!
     \brief

     \param checked
    */
    void on_checkBox_7_0_clicked(bool checked);
    /*!
     \brief Jedes Feld leeren

    */
    void on_pushButton_4_clicked();
    /*!
     \brief Jedes Feld füllen

    */
    void on_pushButton_3_clicked();
    /*!
     \brief Gespeichertes Muster wieder löschen

    */
    void on_pushButton_6_clicked();
    /*!
     \brief Gesetztes Muster speichern

    */
    void on_pushButton_5_clicked();
    /*!
     \brief Gewähltes Muster aus Datei lesen und Muster setzen

    */
    void on_pushButton_7_clicked();
    /*!
     \brief Gepsierte Muster aus Datei aktualisieren

    */
    void on_pushButton_8_clicked();
    /*!
     \brief Aktiviere "Speichern"-Button wenn Textfeld nicht leer, sonst deaktivieren

     \param arg1
    */
    void on_lineEdit_textChanged(const QString &arg1);
    /*!
     \brief Aktiviere "String Senden"-Button wenn Textfeld nicht leer, sonst deativieren

     \param arg1
    */
    void on_lineEdit_2_textEdited(const QString &arg1);
    /*!
     \brief Invertieren umschalten

     \param index Auswahl
    */
    void on_comboBox_4_activated(int index);
};

#endif // MAINWINDOW_H
