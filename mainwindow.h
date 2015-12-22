#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

/*!
 \brief Klasse des Hauptfensters der Anwendung

*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     \brief Konstruktor des Hauptfensters der Anwendung

     \param parent Elterwidget
    */
    explicit MainWindow(QWidget *parent = 0);
    /*!
     \brief Destruktor des Hauptfensters der Anwendung

    */
    ~MainWindow();

private:
    int fd; /*!< I2C-Gerätevariable */
    char matrix_row_0; /*!< Zeilenvariable 0 */
    char matrix_row_1; /*!< Zeilenvariable 0 */
    char matrix_row_2; /*!< Zeilenvariable 0 */
    char matrix_row_3; /*!< Zeilenvariable 0 */
    char matrix_row_4; /*!< Zeilenvariable 0 */
    char matrix_row_5; /*!< Zeilenvariable 0 */
    char matrix_row_6; /*!< Zeilenvariable 0 */
    char matrix_row_7; /*!< Zeilenvariable 0 */
    bool isInverted; /*!< Invertierungs-Flag */

    char display_setting; /*!< Initiale Matrix-Einstellung */
    Ui::MainWindow *ui; /*!< User Interface */
private slots:
    /*!
     \brief String aus der TextBox in Abhängigkeit der gewählten Darstellungsmethode an die LED-Matrix senden

    */
    void on_pushButton_2_clicked();
    /*!
     \brief Einstellen der Helligkeit der LED-Matrix durch einen horizontalen Slider

     \param value Stufe der Helligkeit 1-16
    */
    void on_horizontalSlider_valueChanged(int value);
    /*!
     \brief Erstelltes Muster an Matrix senden

    */
    void on_pushButton_clicked();

    /*!
    @defgroup SINGLE_LEDS_MATRIX Methoden der einzelnen Checkboxen die die LEDs der Matrix darstellen
    @{
    */
    /*!
     \brief LED Zeile 0 Spalte 0

     \param bool true->An, false->Aus
    */
    void on_checkBox_0_7_clicked(bool checked);
    /*!
     \brief LED Zeile 0 Spalte 1

     \param bool true->An, false->Aus
    */
    void on_checkBox_0_6_clicked(bool checked);
    /*!
     \brief LED Zeile 0 Spalte 2

     \param bool true->An, false->Aus
    */
    void on_checkBox_0_5_clicked(bool checked);
    /*!
     \brief LED Zeile 0 Spalte 3

     \param bool true->An, false->Aus
    */
    void on_checkBox_0_4_clicked(bool checked);
    /*!
     \brief LED Zeile 0 Spalte 4

     \param bool true->An, false->Aus
    */
    void on_checkBox_0_3_clicked(bool checked);
    /*!
     \brief LED Zeile 0 Spalte 5

     \param bool true->An, false->Aus
    */
    void on_checkBox_0_2_clicked(bool checked);
    /*!
     \brief LED Zeile 0 Spalte 6

     \param bool true->An, false->Aus
    */
    void on_checkBox_0_1_clicked(bool checked);
    /*!
     \brief LED Zeile 0 Spalte 7

     \param bool true->An, false->Aus
    */
    void on_checkBox_0_0_clicked(bool checked);

    /*!
     \brief LED Zeile 1 Spalte 0

     \param bool true->An, false->Aus
    */
    void on_checkBox_1_7_clicked(bool checked);
    /*!
     \brief LED Zeile 1 Spalte 1

     \param bool true->An, false->Aus
    */
    void on_checkBox_1_6_clicked(bool checked);
    /*!
     \brief LED Zeile 1 Spalte 2

     \param bool true->An, false->Aus
    */
    void on_checkBox_1_5_clicked(bool checked);
    /*!
     \brief LED Zeile 1 Spalte 3

     \param bool true->An, false->Aus
    */
    void on_checkBox_1_4_clicked(bool checked);
    /*!
     \brief LED Zeile 1 Spalte 4

     \param bool true->An, false->Aus
    */
    void on_checkBox_1_3_clicked(bool checked);
    /*!
     \brief LED Zeile 1 Spalte 5

     \param bool true->An, false->Aus
    */
    void on_checkBox_1_2_clicked(bool checked);
    /*!
     \brief LED Zeile 1 Spalte 6

     \param bool true->An, false->Aus
    */
    void on_checkBox_1_1_clicked(bool checked);
    /*!
     \brief LED Zeile 1 Spalte 7

     \param bool true->An, false->Aus
    */
    void on_checkBox_1_0_clicked(bool checked);
    /*!
     \brief LED Zeile 1 Spalte 7

     \param bool true->An, false->Aus
    */
    void on_checkBox_2_0_clicked(bool checked);
    /*!
     \brief LED Zeile 2 Spalte 6

     \param bool true->An, false->Aus
    */
    void on_checkBox_2_1_clicked(bool checked);
    /*!
     \brief LED Zeile 2 Spalte 0

     \param bool true->An, false->Aus
    */
    void on_checkBox_2_7_clicked(bool checked);
    /*!
     \brief LED Zeile 2 Spalte 5

     \param bool true->An, false->Aus
    */
    void on_checkBox_2_2_clicked(bool checked);
    /*!
     \brief LED Zeile 2 Spalte 4

     \param bool true->An, false->Aus
    */
    void on_checkBox_2_3_clicked(bool checked);
    /*!
     \brief LED Zeile 2 Spalte 3

     \param bool true->An, false->Aus
    */
    void on_checkBox_2_4_clicked(bool checked);
    /*!
     \brief LED Zeile 2 Spalte 2

     \param bool true->An, false->Aus
    */
    void on_checkBox_2_5_clicked(bool checked);
    /*!
     \brief LED Zeile 2 Spalte 1

     \param bool true->An, false->Aus
    */
    void on_checkBox_2_6_clicked(bool checked);
    /*!
     \brief LED Zeile 3 Spalte 0

     \param bool true->An, false->Aus
    */
    void on_checkBox_3_7_clicked(bool checked);
    /*!
     \brief LED Zeile 3 Spalte 1

     \param bool true->An, false->Aus
    */
    void on_checkBox_3_6_clicked(bool checked);
    /*!
     \brief LED Zeile 3 Spalte 2

     \param bool true->An, false->Aus
    */
    void on_checkBox_3_5_clicked(bool checked);
    /*!
     \brief LED Zeile 3 Spalte 3

     \param bool true->An, false->Aus
    */
    void on_checkBox_3_4_clicked(bool checked);
    /*!
     \brief LED Zeile 3 Spalte 4

     \param bool true->An, false->Aus
    */
    void on_checkBox_3_3_clicked(bool checked);
    /*!
     \brief LED Zeile 3 Spalte 5

     \param bool true->An, false->Aus
    */
    void on_checkBox_3_2_clicked(bool checked);
    /*!
     \brief LED Zeile 3 Spalte 6

     \param bool true->An, false->Aus
    */
    void on_checkBox_3_1_clicked(bool checked);
    /*!
     \brief LED Zeile 3 Spalte 7

     \param bool true->An, false->Aus
    */
    void on_checkBox_3_0_clicked(bool checked);
    /*!
     \brief LED Zeile 3 Spalte 0

     \param bool true->An, false->Aus
    */
    void on_checkBox_4_7_clicked(bool checked);
    /*!
     \brief LED Zeile 4 Spalte 1

     \param bool true->An, false->Aus
    */
    void on_checkBox_4_6_clicked(bool checked);
    /*!
     \brief LED Zeile 4 Spalte 2

     \param bool true->An, false->Aus
    */
    void on_checkBox_4_5_clicked(bool checked);
    /*!
     \brief LED Zeile 4 Spalte 3

     \param bool true->An, false->Aus
    */
    void on_checkBox_4_4_clicked(bool checked);
    /*!
     \brief LED Zeile 4 Spalte 4

     \param bool true->An, false->Aus
    */
    void on_checkBox_4_3_clicked(bool checked);
    /*!
     \brief LED Zeile 4 Spalte 5

     \param bool true->An, false->Aus
    */
    void on_checkBox_4_2_clicked(bool checked);
    /*!
     \brief LED Zeile 4 Spalte 6

     \param bool true->An, false->Aus
    */
    void on_checkBox_4_1_clicked(bool checked);
    /*!
     \brief LED Zeile 4 Spalte 7

     \param bool true->An, false->Aus
    */
    void on_checkBox_4_0_clicked(bool checked);
    /*!
     \brief LED Zeile 4 Spalte 0

     \param bool true->An, false->Aus
    */
    void on_checkBox_5_7_clicked(bool checked);
    /*!
     \brief LED Zeile 5 Spalte 1

     \param bool true->An, false->Aus
    */
    void on_checkBox_5_6_clicked(bool checked);
    /*!
     \brief LED Zeile 5 Spalte 2

     \param bool true->An, false->Aus
    */
    void on_checkBox_5_5_clicked(bool checked);
    /*!
     \brief LED Zeile 5 Spalte 3

     \param bool true->An, false->Aus
    */
    void on_checkBox_5_4_clicked(bool checked);
    /*!
     \brief LED Zeile 5 Spalte 4

     \param bool true->An, false->Aus
    */
    void on_checkBox_5_3_clicked(bool checked);
    /*!
     \brief LED Zeile 5 Spalte 5

     \param bool true->An, false->Aus
    */
    void on_checkBox_5_2_clicked(bool checked);
    /*!
     \brief LED Zeile 5 Spalte 6

     \param bool true->An, false->Aus
    */
    void on_checkBox_5_1_clicked(bool checked);
    /*!
     \brief LED Zeile 5 Spalte 7

     \param bool true->An, false->Aus
    */
    void on_checkBox_5_0_clicked(bool checked);
    /*!
     \brief LED Zeile 5 Spalte 0

     \param bool true->An, false->Aus
    */
    void on_checkBox_6_7_clicked(bool checked);
    /*!
     \brief LED Zeile 6 Spalte 1

     \param bool true->An, false->Aus
    */
    void on_checkBox_6_6_clicked(bool checked);
    /*!
     \brief LED Zeile 6 Spalte 2

     \param bool true->An, false->Aus
    */
    void on_checkBox_6_5_clicked(bool checked);
    /*!
     \brief LED Zeile 6 Spalte 3

     \param bool true->An, false->Aus
    */
    void on_checkBox_6_4_clicked(bool checked);
    /*!
     \brief LED Zeile 6 Spalte 4

     \param bool true->An, false->Aus
    */
    void on_checkBox_6_3_clicked(bool checked);
    /*!
     \brief LED Zeile 6 Spalte 5

     \param bool true->An, false->Aus
    */
    void on_checkBox_6_2_clicked(bool checked);
    /*!
     \brief LED Zeile 6 Spalte 6

     \param bool true->An, false->Aus
    */
    void on_checkBox_6_1_clicked(bool checked);
    /*!
     \brief LED Zeile 6 Spalte 7

     \param bool true->An, false->Aus
    */
    void on_checkBox_6_0_clicked(bool checked);
    /*!
     \brief LED Zeile 6 Spalte 0

     \param bool true->An, false->Aus
    */
    void on_checkBox_7_7_clicked(bool checked);
    /*!
     \brief LED Zeile 7 Spalte 1

     \param bool true->An, false->Aus
    */
    void on_checkBox_7_6_clicked(bool checked);
    /*!
     \brief LED Zeile 7 Spalte 2

     \param bool true->An, false->Aus
    */
    void on_checkBox_7_5_clicked(bool checked);
    /*!
     \brief LED Zeile 7 Spalte 3

     \param bool true->An, false->Aus
    */
    void on_checkBox_7_4_clicked(bool checked);
    /*!
     \brief LED Zeile 7 Spalte 4

     \param bool true->An, false->Aus
    */
    void on_checkBox_7_3_clicked(bool checked);
    /*!
     \brief LED Zeile 7 Spalte 5

     \param bool true->An, false->Aus
    */
    void on_checkBox_7_2_clicked(bool checked);
    /*!
     \brief LED Zeile 7 Spalte 6

     \param bool true->An, false->Aus
    */
    void on_checkBox_7_1_clicked(bool checked);
    /*!
     \brief LED Zeile 7 Spalte 7

     \param bool true->An, false->Aus
    */
    void on_checkBox_7_0_clicked(bool checked);
    /*!
    @}
    */
    /*!
     \brief Jede Checkbox der Matrix leeren und die Zeilenvariablen zurücksetzen

    */
    void on_pushButton_4_clicked();
    /*!
     \brief Jede Checkbox der Matrix füllen und die Zeilenvariablen auf 0xFF stellen

    */
    void on_pushButton_3_clicked();
    /*!
     \brief Gespeichertes Muster aus Datei und ComboBox löschen

     Sucht nach der Datei 'Muster' in der die gespeicherten Muster enthalten sind.
     Wird diese Datei gefunden wird sie im ReadWrite-Modus geöffnet.
     Falls nicht erscheint eine Warnung.
     Anschließend wird ein TextStream geöffnet und die Datei zeilenweise ausgelesen und einem QString angehängt.
     Wird ein Eintrag gefunden, der mit den gleichen Zeichen beginnt wie das aktuell ausgewählte
     Item der comboBox_3 wird diese Zeile nicht an den QString angehängt und die nächste Zeile gelesen.
     Danach wird der Inhalt Datei mit resize(0) gelöscht und der neue QString geschrieben und die Datei geschlossen.
     Nun werden die Items der comboBox_3 aktualisiert.

    */
    void on_pushButton_6_clicked();
    /*!
     \brief Erstelltes Muster in Datei und ComboBox speichern

     Sucht nach der Datei 'Muster'. Wenn Sie nicht gefunden wird wird sie erstellt.
     Anschließend wird sie im Append-Modus geöffnet.
     Falls sie nicht geöffnet werden kann wird eine Warnung ausgegeben.
     Aschließend wird der Name des Musters bis zum ersten Leerzeichen aus der TextBox gelesen
     und in die Datei geschrieben.
     Anschließend werden mit Leerzeichen getrennt nacheinander die Zeilenvariablen in die Datei geschrieben.
     Abschließend wird ein "\n" Zeilenumbruch angefügt und der Puffer mit fflush() endgültig in die Datei geschrieben
     und diese geschlossen.
     Nun wird das Textfeld und die Checkboxen geleert, die Zeilenvariablen zurückgesetzt und die comboBox_3 aktualisiert.
    */
    void on_pushButton_5_clicked();
    /*!
    \brief Gewähltes Muster aus Datei lesen und Muster setzen

    Es wird im aktuellen Verzeichnis nach der Datei 'Muster' gesucht. Wird diese nicht gefunden wird eine
    Warnung ausgegeben.
    Sonst wird diese Datei im Read-Only-Modus geöffnet und zeilenweise gelesen.
    Wird eine Zeile gefunden die mit den gleichen Zeichen beginnt wie das aktuell ausgewählte Item der comboBox_3
    werden die darauf folgenden Zeilenvariablen gelesen und in die Klassenvariablen geschrieben.
    Anschließend wird das Muster an die Matrix gesendet.
    Zuletzt wird die Datei geschlossen und die Methode verlassen.

    */
    void on_pushButton_7_clicked();
    /*!
     \brief Gespeicherte Muster aus Datei lesen und in der ComboBox aktualisieren

     Die Items der comboBox_3 werden gelöscht.
     Es wird im aktuellen Verzeichnis nach der Datei 'Muster' gesucht.
     Wird diese nicht gefunden wird eine Warnung ausgegeben.
     Sonst wird diese im Read-Only-Modus geöffnet und zeilenweise gelesen.
     Die Zeichen bis zum ersten Leerzeichen werden gelesen und ein neues Item in der comboBox_3
     mit diesem Namen erzeugt.
     Wenn das Dateiende erreicht wird wir die Datei geschlossen.

    */
    void on_pushButton_8_clicked();
    /*!
     \brief Aktiviere "Speichern"-Button wenn Textfeld nicht leer, sonst deaktivieren

     \param QString Inhalt der TextBox
    */
    void on_lineEdit_textChanged(const QString &arg1);
    /*!
     \brief Aktiviere "String Senden"-Button wenn Textfeld nicht leer, sonst deativieren

     \param QString Inhalt der TextBox
    */
    void on_lineEdit_2_textEdited(const QString &arg1);
    /*!
     \brief Invertieren umschalten

     \param int Index des ausgewählten Items der ComboBox
    */
    void on_comboBox_4_activated(int index);
    /*!
     \brief Einstellung die Matrix aus- oder einzuschalten

     \param int Index des ausgewählten Items der ComboBox
    */
    void on_comboBox_2_activated(int index);
    /*!
     \brief Einstellung ob die Matrix blinkt

     \param int Index des ausgewählten Items der ComboBox
    */
    void on_comboBox_activated(int index);
};

#endif // MAINWINDOW_H
