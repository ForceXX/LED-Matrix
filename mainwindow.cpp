#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HT16K33.h"
#include <unistd.h>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QString>
#include <QTextStream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fd = ht16k33_init_i2c();

    //Matrix leeren
    ht16k33_clear(fd);

    //Alle einzelnen Zeilen leeren
    matrix_row_0 = 0x00;
    matrix_row_1 = 0x00;
    matrix_row_2 = 0x00;
    matrix_row_3 = 0x00;
    matrix_row_4 = 0x00;
    matrix_row_5 = 0x00;
    matrix_row_6 = 0x00;
    matrix_row_7 = 0x00;

    //standardmäßig nicht invertieren
    isInverted=false;

    //Display anschalten
    display_setting = 0x81;

    MainWindow::on_pushButton_8_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QString eingabe = ui->lineEdit_2->text();
    //Laufschrift von links nach rechts
    if(ui->radioButton->isChecked()){
        ht16k33_print_right(fd, eingabe.toUtf8().data());
    }
    //Laufschrift von rechts nach links
    else if(ui->radioButton_2->isChecked()){
        ht16k33_print_left(fd, eingabe.toUtf8().data());
    }
    //Jedes Zeichen einzeln zeichnen
    else if(ui->radioButton_5->isChecked()){
        ht16k33_print_string(fd, eingabe.toUtf8().data());
    }
    //Sonst
    else{
        //TODO
    }
    ui->lineEdit_2->clear();//Textfeld leeren
    ui->pushButton_2->setEnabled(false);//Senden-Button nicht anklickbar
}

//Enable String-"Senden" Button wenn Textfeld nicht leer, sonst disable:

void MainWindow::on_lineEdit_2_textEdited(const QString &arg1)
{
    if(arg1 != ""){
        ui->pushButton_2->setEnabled(true);
    }
    else{
        ui->pushButton_2->setEnabled(false);
    }
}

//Helligkeit über horizontalen Slider einstellen (16 Stufen, default ganz hell(16)):

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    switch(value){
        case 1: ht16k33_set_brigthness(fd,brigthness_1_16);
                break;
        case 2: ht16k33_set_brigthness(fd,brigthness_2_16);
                break;
        case 3: ht16k33_set_brigthness(fd,brigthness_3_16);
                break;
        case 4: ht16k33_set_brigthness(fd,brigthness_4_16);
                break;
        case 5: ht16k33_set_brigthness(fd,brigthness_5_16);
                break;
        case 6: ht16k33_set_brigthness(fd,brigthness_6_16);
                break;
        case 7: ht16k33_set_brigthness(fd,brigthness_7_16);
                break;
        case 8: ht16k33_set_brigthness(fd,brigthness_8_16);
                break;
        case 9: ht16k33_set_brigthness(fd,brigthness_9_16);
                break;
        case 10: ht16k33_set_brigthness(fd,brigthness_10_16);
                break;
        case 11: ht16k33_set_brigthness(fd,brigthness_11_16);
                break;
        case 12: ht16k33_set_brigthness(fd,brigthness_12_16);
                break;
        case 13: ht16k33_set_brigthness(fd,brigthness_13_16);
                break;
        case 14: ht16k33_set_brigthness(fd,brigthness_14_16);
                break;
        case 15: ht16k33_set_brigthness(fd,brigthness_15_16);
                break;
        case 16: ht16k33_set_brigthness(fd,brigthness_16_16);
                break;
        default: ht16k33_set_brigthness(fd,brigthness_16_16);
    }
}

//Gesetztes Muster an Matrix senden:

void MainWindow::on_pushButton_clicked()
{
    //Wenn invertiert gewählt wurde
    if(isInverted){
        unsigned char arr[8] = {(unsigned char)~matrix_row_0,(unsigned char)~matrix_row_1,(unsigned char)~matrix_row_2,
                                (unsigned char)~matrix_row_3,(unsigned char)~matrix_row_4,(unsigned char)~matrix_row_5,
                                (unsigned char)~matrix_row_6,(unsigned char)~matrix_row_7};
        ht16k33_print_array(fd, arr);

    //Normale Ausgabe
    }else{
        unsigned char arr[8] = {(unsigned char)matrix_row_0,(unsigned char)matrix_row_1,(unsigned char)matrix_row_2,
                                (unsigned char)matrix_row_3,(unsigned char)matrix_row_4,(unsigned char)matrix_row_5,
                                (unsigned char)matrix_row_6,(unsigned char)matrix_row_7};
        ht16k33_print_array(fd, arr);
    }

    //Werte der Zeilen zu debugging-Zwecken auf der4 Standardkonsole ausgeben
    printf("%x\n",matrix_row_0);
    printf("%x\n",matrix_row_1);
    printf("%x\n",matrix_row_2);
    printf("%x\n",matrix_row_3);
    printf("%x\n",matrix_row_4);
    printf("%x\n",matrix_row_5);
    printf("%x\n",matrix_row_6);
    printf("%x\n",matrix_row_7);

}

//Combobox Display An<->Aus:

void MainWindow::on_comboBox_2_activated(int index)
{
    switch(index){
        case 0://Display an
            display_setting |= 1;
            ht16k33_write_command(fd, display_setting);
            break;
        case 1://Display aus
            display_setting &= ~(1);
            ht16k33_write_command(fd, display_setting);
            break;
        default://Display an
            display_setting = 0x80;
            ht16k33_write_command(fd, display_setting);
            break;
    }
}

//Combobox Blinken Kein<->0.5Hz<->1Hz<->2Hz:

void MainWindow::on_comboBox_activated(int index)
{
    switch(index){
        case 0://Kein Blinken
            display_setting &= ~(0x3<<1);
            printf("0 %x\n",display_setting);
            ht16k33_write_command(fd, display_setting);
            break;
        case 1://0.5Hz Blinken
            display_setting |= (3<<1);
            printf("1 %x\n",display_setting);
            ht16k33_write_command(fd, display_setting);
            break;
        case 2://1Hz Blinken
            display_setting &= ~(1<<1);
            display_setting |= (1<<2);
            printf("2 %x\n",display_setting);
            ht16k33_write_command(fd, display_setting);
            break;
        case 3://2Hz Blinken
            display_setting &= ~(1<<2);
            display_setting |= (1<<1);
            printf("3 %x\n",display_setting);
            ht16k33_write_command(fd, display_setting);
            break;
        default://Kein Blinken
            display_setting &= ~(0x3<<2);
            ht16k33_write_command(fd, display_setting);
            break;
    }
}

/*
 * Checkboxen für die 64 einzelnen LEDs
 * Wenn Checkbox gesetzt wird die Zeile mit einer 1 an der Stelle verodert.
 * Wenn Checkbox nicht gesetzt wird die Zeile mit einer 0 an der Stelle verundet.
 */

void MainWindow::on_checkBox_0_7_clicked(bool checked)
{
    if(checked){
        matrix_row_0 |= (1<<7);
    }
    else{
        matrix_row_0 &= ~(1<<7);
    }
}


void MainWindow::on_checkBox_0_6_clicked(bool checked)
{
    if(checked){
        matrix_row_0 |= (1<<6);
    }
    else{
        matrix_row_0 &= ~(1<<6);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_0_5_clicked(bool checked)
{
    if(checked){
        matrix_row_0 |= (1<<5);
    }
    else{
        matrix_row_0 &= ~(1<<5);
    }
}


/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_0_4_clicked(bool checked)
{
    if(checked){
        matrix_row_0 |= (1<<4);
    }
    else{
        matrix_row_0 &= ~(1<<4);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_0_3_clicked(bool checked)
{
    if(checked){
        matrix_row_0 |= (1<<3);
    }
    else{
        matrix_row_0 &= ~(1<<3);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_0_2_clicked(bool checked)
{
    if(checked){
        matrix_row_0 |= (1<<2);
    }
    else{
        matrix_row_0 &= ~(1<<2);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_0_1_clicked(bool checked)
{
    if(checked){
        matrix_row_0 |= (1<<1);
    }
    else{
        matrix_row_0 &= ~(1<<1);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_0_0_clicked(bool checked)
{
    if(checked){
        matrix_row_0 |= (1<<0);
    }
    else{
        matrix_row_0 &= ~(1<<0);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_1_7_clicked(bool checked)
{
    if(checked){
        matrix_row_1 |= (1<<7);
    }
    else{
        matrix_row_1 &= ~(1<<7);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_1_6_clicked(bool checked)
{
    if(checked){
        matrix_row_1 |= (1<<6);
    }
    else{
        matrix_row_1 &= ~(1<<6);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_1_5_clicked(bool checked)
{
    if(checked){
        matrix_row_1 |= (1<<5);
    }
    else{
        matrix_row_1 &= ~(1<<5);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_1_4_clicked(bool checked)
{
    if(checked){
        matrix_row_1 |= (1<<4);
    }
    else{
        matrix_row_1 &= ~(1<<4);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_1_3_clicked(bool checked)
{
    if(checked){
        matrix_row_1 |= (1<<3);
    }
    else{
        matrix_row_1 &= ~(1<<3);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_1_2_clicked(bool checked)
{
    if(checked){
        matrix_row_1 |= (1<<2);
    }
    else{
        matrix_row_1 &= ~(1<<2);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_1_1_clicked(bool checked)
{
    if(checked){
        matrix_row_1 |= (1<<1);
    }
    else{
        matrix_row_1 &= ~(1<<1);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_1_0_clicked(bool checked)
{
    if(checked){
        matrix_row_1 |= (1<<0);
    }
    else{
        matrix_row_1 &= ~(1<<0);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_2_7_clicked(bool checked)
{
    if(checked){
        matrix_row_2 |= (1<<7);
    }
    else{
        matrix_row_2 &= ~(1<<7);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_2_6_clicked(bool checked)
{
    if(checked){
        matrix_row_2 |= (1<<6);
    }
    else{
        matrix_row_2 &= ~(1<<6);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_2_5_clicked(bool checked)
{
    if(checked){
        matrix_row_2 |= (1<<5);
    }
    else{
        matrix_row_2 &= ~(1<<5);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_2_4_clicked(bool checked)
{
    if(checked){
        matrix_row_2 |= (1<<4);
    }
    else{
        matrix_row_2 &= ~(1<<4);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_2_3_clicked(bool checked)
{
    if(checked){
        matrix_row_2 |= (1<<3);
    }
    else{
        matrix_row_2 &= ~(1<<3);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_2_2_clicked(bool checked)
{
    if(checked){
        matrix_row_2 |= (1<<2);
    }
    else{
        matrix_row_2 &= ~(1<<2);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_2_1_clicked(bool checked)
{
    if(checked){
        matrix_row_2 |= (1<<1);
    }
    else{
        matrix_row_2 &= ~(1<<1);
    }
}


/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_2_0_clicked(bool checked)
{
    if(checked){
        matrix_row_2 |= (1<<0);
    }
    else{
        matrix_row_2 &= ~(1<<0);
    }
}


/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_3_7_clicked(bool checked)
{
    if(checked){
        matrix_row_3 |= (1<<7);
    }
    else{
        matrix_row_3 &= ~(1<<7);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_3_6_clicked(bool checked)
{
    if(checked){
        matrix_row_3 |= (1<<6);
    }
    else{
        matrix_row_3 &= ~(1<<6);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_3_5_clicked(bool checked)
{
    if(checked){
        matrix_row_3 |= (1<<5);
    }
    else{
        matrix_row_3 &= ~(1<<5);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_3_4_clicked(bool checked)
{
    if(checked){
        matrix_row_3 |= (1<<4);
    }
    else{
        matrix_row_3 &= ~(1<<4);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_3_3_clicked(bool checked)
{
    if(checked){
        matrix_row_3 |= (1<<3);
    }
    else{
        matrix_row_3 &= ~(1<<3);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_3_2_clicked(bool checked)
{
    if(checked){
        matrix_row_3 |= (1<<2);
    }
    else{
        matrix_row_3 &= ~(1<<2);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_3_1_clicked(bool checked)
{
    if(checked){
        matrix_row_3 |= (1<<1);
    }
    else{
        matrix_row_3 &= ~(1<<1);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_3_0_clicked(bool checked)
{
    if(checked){
        matrix_row_3 |= (1<<0);
    }
    else{
        matrix_row_3 &= ~(1<<0);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_4_7_clicked(bool checked)
{
    if(checked){
        matrix_row_4 |= (1<<7);
    }
    else{
        matrix_row_4 &= ~(1<<7);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_4_6_clicked(bool checked)
{
    if(checked){
        matrix_row_4 |= (1<<6);
    }
    else{
        matrix_row_4 &= ~(1<<6);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_4_5_clicked(bool checked)
{
    if(checked){
        matrix_row_4 |= (1<<5);
    }
    else{
        matrix_row_4 &= ~(1<<5);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_4_4_clicked(bool checked)
{
    if(checked){
        matrix_row_4 |= (1<<4);
    }
    else{
        matrix_row_4 &= ~(1<<4);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_4_3_clicked(bool checked)
{
    if(checked){
        matrix_row_4 |= (1<<3);
    }
    else{
        matrix_row_4 &= ~(1<<3);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_4_2_clicked(bool checked)
{
    if(checked){
        matrix_row_4 |= (1<<2);
    }
    else{
        matrix_row_4 &= ~(1<<2);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_4_1_clicked(bool checked)
{
    if(checked){
        matrix_row_4 |= (1<<1);
    }
    else{
        matrix_row_4 &= ~(1<<1);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_4_0_clicked(bool checked)
{
    if(checked){
        matrix_row_4 |= (1<<0);
    }
    else{
        matrix_row_4 &= ~(1<<0);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_5_7_clicked(bool checked)
{
    if(checked){
        matrix_row_5 |= (1<<7);
    }
    else{
        matrix_row_5 &= ~(1<<7);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_5_6_clicked(bool checked)
{
    if(checked){
        matrix_row_5 |= (1<<6);
    }
    else{
        matrix_row_5 &= ~(1<<6);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_5_5_clicked(bool checked)
{
    if(checked){
        matrix_row_5 |= (1<<5);
    }
    else{
        matrix_row_5 &= ~(1<<5);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_5_4_clicked(bool checked)
{
    if(checked){
        matrix_row_5 |= (1<<4);
    }
    else{
        matrix_row_5 &= ~(1<<4);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_5_3_clicked(bool checked)
{
    if(checked){
        matrix_row_5 |= (1<<3);
    }
    else{
        matrix_row_5 &= ~(1<<3);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_5_2_clicked(bool checked)
{
    if(checked){
        matrix_row_5 |= (1<<2);
    }
    else{
        matrix_row_5 &= ~(1<<2);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_5_1_clicked(bool checked)
{
    if(checked){
        matrix_row_5 |= (1<<1);
    }
    else{
        matrix_row_5 &= ~(1<<1);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_5_0_clicked(bool checked)
{
    if(checked){
        matrix_row_5 |= (1<<0);
    }
    else{
        matrix_row_5 &= ~(1<<0);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_6_7_clicked(bool checked)
{
    if(checked){
        matrix_row_6 |= (1<<7);
    }
    else{
        matrix_row_6 &= ~(1<<7);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_6_6_clicked(bool checked)
{
    if(checked){
        matrix_row_6 |= (1<<6);
    }
    else{
        matrix_row_6 &= ~(1<<6);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_6_5_clicked(bool checked)
{
    if(checked){
        matrix_row_6 |= (1<<5);
    }
    else{
        matrix_row_6 &= ~(1<<5);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_6_4_clicked(bool checked)
{
    if(checked){
        matrix_row_6 |= (1<<4);
    }
    else{
        matrix_row_6 &= ~(1<<4);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_6_3_clicked(bool checked)
{
    if(checked){
        matrix_row_6 |= (1<<3);
    }
    else{
        matrix_row_6 &= ~(1<<3);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_6_2_clicked(bool checked)
{
    if(checked){
        matrix_row_6 |= (1<<2);
    }
    else{
        matrix_row_6 &= ~(1<<2);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_6_1_clicked(bool checked)
{
    if(checked){
        matrix_row_6 |= (1<<1);
    }
    else{
        matrix_row_6 &= ~(1<<1);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_6_0_clicked(bool checked)
{
    if(checked){
        matrix_row_6 |= (1<<0);
    }
    else{
        matrix_row_6 &= ~(1<<0);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_7_7_clicked(bool checked)
{
    if(checked){
        matrix_row_7 |= (1<<7);
    }
    else{
        matrix_row_7 &= ~(1<<7);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_7_6_clicked(bool checked)
{
    if(checked){
        matrix_row_7 |= (1<<6);
    }
    else{
        matrix_row_7 &= ~(1<<6);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_7_5_clicked(bool checked)
{
    if(checked){
        matrix_row_7 |= (1<<5);
    }
    else{
        matrix_row_7 &= ~(1<<5);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_7_4_clicked(bool checked)
{
    if(checked){
        matrix_row_7 |= (1<<4);
    }
    else{
        matrix_row_7 &= ~(1<<4);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_7_3_clicked(bool checked)
{
    if(checked){
        matrix_row_7 |= (1<<3);
    }
    else{
        matrix_row_7 &= ~(1<<3);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_7_2_clicked(bool checked)
{
    if(checked){
        matrix_row_7 |= (1<<2);
    }
    else{
        matrix_row_7 &= ~(1<<2);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_7_1_clicked(bool checked)
{
    if(checked){
        matrix_row_7 |= (1<<1);
    }
    else{
        matrix_row_7 &= ~(1<<1);
    }
}

/*!
 \brief

 \param checked
*/
void MainWindow::on_checkBox_7_0_clicked(bool checked)
{
    if(checked){
        matrix_row_7 |= (1<<0);
    }
    else{
        matrix_row_7 &= ~(1<<0);
    }
}

//Muster komplett löschen:

void MainWindow::on_pushButton_4_clicked()
{

    QList<QCheckBox *> allButtons = ui->gridGroupBox->findChildren<QCheckBox *>();
    for (int i=0; i<allButtons.size();i++){
        allButtons.at(i)->setChecked(true);
        allButtons.at(i)->click();
    }
}

//Muster komplett setzen:

void MainWindow::on_pushButton_3_clicked()
{

    QList<QCheckBox *> allButtons = ui->gridGroupBox->findChildren<QCheckBox *>();
    for (int i=0; i<allButtons.size();i++){
        allButtons.at(i)->setChecked(false);
        allButtons.at(i)->click();
    }
}

//Enable "Speichern"-Button wenn Textfeld nicht leer, sonst disable:

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1 != ""){
        ui->pushButton_5->setEnabled(true);
    }
    else{
        ui->pushButton_5->setEnabled(false);
    }
}


//Gesetztes Muster in Datei speichern:

void MainWindow::on_pushButton_5_clicked(){

    char* filename="./Muster";


    FILE *file;
    file = fopen(filename,"a");
    if(!file){
        QMessageBox::warning(this, "Fehler", "Datei konnte nicht geöffnet werden", QMessageBox::Ok);
    }else{
        QString toWrite;
        toWrite=ui->lineEdit->text();

        //Debug
        printf("Speichern von %s ",toWrite.toUtf8().data());
        printf("%x %x %x %x %x %x %x %x\n",matrix_row_0,matrix_row_1,matrix_row_2,matrix_row_3,
               matrix_row_4,matrix_row_5,matrix_row_6,matrix_row_7);

        //Nur bis zum ersten Leerzeichen speichern
        toWrite = toWrite.split(" ")[0];

        fputs(toWrite.toUtf8().data(),file);
        fputc(' ',file);
        fputc(matrix_row_0,file);
        fputc(' ',file);
        fputc(matrix_row_1,file);
        fputc(' ',file);
        fputc(matrix_row_2,file);
        fputc(' ',file);
        fputc(matrix_row_3,file);
        fputc(' ',file);
        fputc(matrix_row_4,file);
        fputc(' ',file);
        fputc(matrix_row_5,file);
        fputc(' ',file);
        fputc(matrix_row_6,file);
        fputc(' ',file);
        fputc(matrix_row_7,file);
        fputc(' ',file);
        fputc('\n',file);

        fflush(file);
        fclose(file);

        ui->lineEdit->clear();//Textfeld leeren
        ui->pushButton_5->setEnabled(false);//"Speichern-Button" nicht anklickbar
        on_pushButton_4_clicked();//Zeilenvariablen zurücksetzen
        on_pushButton_8_clicked();//Musterauswahl in Combobox aktualisieren

    }

}


//Musterauswahl aus Datei aktualisieren und in Combobox Speichern

void MainWindow::on_pushButton_8_clicked(){
    ui->comboBox_3->clear();
    QString filename="Muster";
    QFile *file = new QFile(filename);

    if(!file->open(QIODevice::ReadOnly|QIODevice::Text)){
        fprintf(stderr, "Fehler Datei konnte nicht geöffnet werden");
        return;
    }else{
        QTextStream input(file);
        while(!input.atEnd()){
            QString line = input.readLine();
            QStringList list = line.split(" ");
            ui->comboBox_3->addItem(list[0]);
        }
        file->close();
    }
}


//Gewähltes Muster aus Datei lesen und setzen:

void MainWindow::on_pushButton_7_clicked(){
    char *item = ui->comboBox_3->currentText().toUtf8().data();
    char * filename="Muster";

    printf("Name Item: %s, Laenge: %d\n",item,ui->comboBox_3->currentText().length());

    FILE *file;
    file = fopen(filename,"r");
    if(!file){
        QMessageBox::critical(NULL,"Datei konnte nicht geöffnet werden", "OK");
    }
    else{
        char zeile[256];
        char tmp[256];
        while(fgets(zeile, sizeof(zeile),file)){
           printf("Zeile: %s\n",zeile);
           strcpy(tmp,zeile);
           char *p = strchr(tmp,' ');
           if(p){
               *p = 0;
               printf("Abgeschnitten: %s\n",tmp);
               printf("Vergleich: %d\n",strcmp(tmp,item));
               if(strcmp(tmp,item) == 0){
                   printf("Gleich\n");
                   char *f = strchr(zeile, ' ');
                   char *c = ++f;
                   matrix_row_0 = *c;
                   c+=2;
                   matrix_row_1 = *c;
                   c+=2;
                   matrix_row_2 = *c;
                   c+=2;
                   matrix_row_3 = *c;
                   c+=2;
                   matrix_row_4 = *c;
                   c+=2;
                   matrix_row_5 = *c;
                   c+=2;
                   matrix_row_6 = *c;
                   c+=2;
                   matrix_row_7 = *c;
                   MainWindow::on_pushButton_clicked();
                   fclose(file);
                   break;
               }
           }
        }
    }

}

//Invertieren an/aus:

void MainWindow::on_comboBox_4_activated(int index){

    switch(index){
        case 0://Display normal
            isInverted=false;//Variable auf "false" "setzen
            on_pushButton_clicked();//Muster nochmals senden
            break;
        case 1://Display invertiert
            isInverted=true;//Variable auf "true" setzen
            on_pushButton_clicked();
            break;
        default://Display auch auf normal
            isInverted=false;//Variable auf "false" "setzen
            on_pushButton_clicked();
            break;
    }
}


//Muster aus Datei und ComboBox löschen

void MainWindow::on_pushButton_6_clicked(){
    QString filename = "./Muster";

    QFile *file = new QFile(filename);

    QString item = ui->comboBox_3->currentText();

    if(!file->open(QFile::ReadWrite)){
        QMessageBox::critical(NULL,"Fehler","Datei konnte nicht geöffnet werden");
    }
    else{
        QString newFile;
        QTextStream t(file);
        while(!t.atEnd()){
            QString line = t.readLine();
            printf("Line: %s\n", line.toUtf8().data());
            if(!(line.split(' ')[0] == item)){
                newFile.append(line + "\n");
            }
        }
        file->resize(0);
        t << newFile;
        file->close();
        MainWindow::on_pushButton_8_clicked();
    }
}
