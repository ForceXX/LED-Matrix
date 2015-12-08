#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
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
    ht16k33_clear(fd);

    matrix_row_0 = 0x00;
    matrix_row_1 = 0x00;
    matrix_row_2 = 0x00;
    matrix_row_3 = 0x00;
    matrix_row_4 = 0x00;
    matrix_row_5 = 0x00;
    matrix_row_6 = 0x00;
    matrix_row_7 = 0x00;

    isInverted=false;

    display_setting = 0x81;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//String-"Senden" Button
void MainWindow::on_pushButton_2_clicked()
{
    QString eingabe = ui->lineEdit_2->text();
    ht16k33_print_left(fd, eingabe.toUtf8().data());
    ui->lineEdit_2->clear();
    ui->pushButton_2->setEnabled(false);
}

//Enable String-"Senden" Button wenn Textfeld nicht leer, sonst disable
void MainWindow::on_lineEdit_2_textEdited(const QString &arg1)
{
    if(arg1 != ""){
        ui->pushButton_2->setEnabled(true);
    }
    else{
        ui->pushButton_2->setEnabled(false);
    }
}

//Helligkeit über horizontalen Slider einstellen (16 Stufen, default 16)
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

//Muster an Matrix senden
void MainWindow::on_pushButton_clicked()
{

    if(isInverted){
        unsigned char arr[8] = {~matrix_row_0,~matrix_row_1,~matrix_row_2,~matrix_row_3,~matrix_row_4,~matrix_row_5,~matrix_row_6,~matrix_row_7};
        ht16k33_print_array(fd, arr);

    }else{
        unsigned char arr[8] = {matrix_row_0,matrix_row_1,matrix_row_2,matrix_row_3,matrix_row_4,matrix_row_5,matrix_row_6,matrix_row_7};
        ht16k33_print_array(fd, arr);
    }

    printf("%x\n",matrix_row_0);
    printf("%x\n",matrix_row_1);
    printf("%x\n",matrix_row_2);
    printf("%x\n",matrix_row_3);
    printf("%x\n",matrix_row_4);
    printf("%x\n",matrix_row_5);
    printf("%x\n",matrix_row_6);
    printf("%x\n",matrix_row_7);

}

//Combobox Display An<->Aus
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

//Combobox Blinken Kein<->0.5Hz<->1Hz<->2Hz
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

void MainWindow::on_checkBox_0_5_clicked(bool checked)
{
    if(checked){
        matrix_row_0 |= (1<<5);
    }
    else{
        matrix_row_0 &= ~(1<<5);
    }
}


void MainWindow::on_checkBox_0_4_clicked(bool checked)
{
    if(checked){
        matrix_row_0 |= (1<<4);
    }
    else{
        matrix_row_0 &= ~(1<<4);
    }
}

void MainWindow::on_checkBox_0_3_clicked(bool checked)
{
    if(checked){
        matrix_row_0 |= (1<<3);
    }
    else{
        matrix_row_0 &= ~(1<<3);
    }
}

void MainWindow::on_checkBox_0_2_clicked(bool checked)
{
    if(checked){
        matrix_row_0 |= (1<<2);
    }
    else{
        matrix_row_0 &= ~(1<<2);
    }
}

void MainWindow::on_checkBox_0_1_clicked(bool checked)
{
    if(checked){
        matrix_row_0 |= (1<<1);
    }
    else{
        matrix_row_0 &= ~(1<<1);
    }
}

void MainWindow::on_checkBox_0_0_clicked(bool checked)
{
    if(checked){
        matrix_row_0 |= (1<<0);
    }
    else{
        matrix_row_0 &= ~(1<<0);
    }
}

void MainWindow::on_checkBox_1_7_clicked(bool checked)
{
    if(checked){
        matrix_row_1 |= (1<<7);
    }
    else{
        matrix_row_1 &= ~(1<<7);
    }
}

void MainWindow::on_checkBox_1_6_clicked(bool checked)
{
    if(checked){
        matrix_row_1 |= (1<<6);
    }
    else{
        matrix_row_1 &= ~(1<<6);
    }
}

void MainWindow::on_checkBox_1_5_clicked(bool checked)
{
    if(checked){
        matrix_row_1 |= (1<<5);
    }
    else{
        matrix_row_1 &= ~(1<<5);
    }
}

void MainWindow::on_checkBox_1_4_clicked(bool checked)
{
    if(checked){
        matrix_row_1 |= (1<<4);
    }
    else{
        matrix_row_1 &= ~(1<<4);
    }
}

void MainWindow::on_checkBox_1_3_clicked(bool checked)
{
    if(checked){
        matrix_row_1 |= (1<<3);
    }
    else{
        matrix_row_1 &= ~(1<<3);
    }
}

void MainWindow::on_checkBox_1_2_clicked(bool checked)
{
    if(checked){
        matrix_row_1 |= (1<<2);
    }
    else{
        matrix_row_1 &= ~(1<<2);
    }
}

void MainWindow::on_checkBox_1_1_clicked(bool checked)
{
    if(checked){
        matrix_row_1 |= (1<<1);
    }
    else{
        matrix_row_1 &= ~(1<<1);
    }
}

void MainWindow::on_checkBox_1_0_clicked(bool checked)
{
    if(checked){
        matrix_row_1 |= (1<<0);
    }
    else{
        matrix_row_1 &= ~(1<<0);
    }
}

void MainWindow::on_checkBox_2_7_clicked(bool checked)
{
    if(checked){
        matrix_row_2 |= (1<<7);
    }
    else{
        matrix_row_2 &= ~(1<<7);
    }
}

void MainWindow::on_checkBox_2_6_clicked(bool checked)
{
    if(checked){
        matrix_row_2 |= (1<<6);
    }
    else{
        matrix_row_2 &= ~(1<<6);
    }
}

void MainWindow::on_checkBox_2_5_clicked(bool checked)
{
    if(checked){
        matrix_row_2 |= (1<<5);
    }
    else{
        matrix_row_2 &= ~(1<<5);
    }
}

void MainWindow::on_checkBox_2_4_clicked(bool checked)
{
    if(checked){
        matrix_row_2 |= (1<<4);
    }
    else{
        matrix_row_2 &= ~(1<<4);
    }
}

void MainWindow::on_checkBox_2_3_clicked(bool checked)
{
    if(checked){
        matrix_row_2 |= (1<<3);
    }
    else{
        matrix_row_2 &= ~(1<<3);
    }
}

void MainWindow::on_checkBox_2_2_clicked(bool checked)
{
    if(checked){
        matrix_row_2 |= (1<<2);
    }
    else{
        matrix_row_2 &= ~(1<<2);
    }
}

void MainWindow::on_checkBox_2_1_clicked(bool checked)
{
    if(checked){
        matrix_row_2 |= (1<<1);
    }
    else{
        matrix_row_2 &= ~(1<<1);
    }
}


void MainWindow::on_checkBox_2_0_clicked(bool checked)
{
    if(checked){
        matrix_row_2 |= (1<<0);
    }
    else{
        matrix_row_2 &= ~(1<<0);
    }
}


void MainWindow::on_checkBox_3_7_clicked(bool checked)
{
    if(checked){
        matrix_row_3 |= (1<<7);
    }
    else{
        matrix_row_3 &= ~(1<<7);
    }
}

void MainWindow::on_checkBox_3_6_clicked(bool checked)
{
    if(checked){
        matrix_row_3 |= (1<<6);
    }
    else{
        matrix_row_3 &= ~(1<<6);
    }
}

void MainWindow::on_checkBox_3_5_clicked(bool checked)
{
    if(checked){
        matrix_row_3 |= (1<<5);
    }
    else{
        matrix_row_3 &= ~(1<<5);
    }
}

void MainWindow::on_checkBox_3_4_clicked(bool checked)
{
    if(checked){
        matrix_row_3 |= (1<<4);
    }
    else{
        matrix_row_3 &= ~(1<<4);
    }
}

void MainWindow::on_checkBox_3_3_clicked(bool checked)
{
    if(checked){
        matrix_row_3 |= (1<<3);
    }
    else{
        matrix_row_3 &= ~(1<<3);
    }
}

void MainWindow::on_checkBox_3_2_clicked(bool checked)
{
    if(checked){
        matrix_row_3 |= (1<<2);
    }
    else{
        matrix_row_3 &= ~(1<<2);
    }
}

void MainWindow::on_checkBox_3_1_clicked(bool checked)
{
    if(checked){
        matrix_row_3 |= (1<<1);
    }
    else{
        matrix_row_3 &= ~(1<<1);
    }
}

void MainWindow::on_checkBox_3_0_clicked(bool checked)
{
    if(checked){
        matrix_row_3 |= (1<<0);
    }
    else{
        matrix_row_3 &= ~(1<<0);
    }
}

void MainWindow::on_checkBox_4_7_clicked(bool checked)
{
    if(checked){
        matrix_row_4 |= (1<<7);
    }
    else{
        matrix_row_4 &= ~(1<<7);
    }
}

void MainWindow::on_checkBox_4_6_clicked(bool checked)
{
    if(checked){
        matrix_row_4 |= (1<<6);
    }
    else{
        matrix_row_4 &= ~(1<<6);
    }
}

void MainWindow::on_checkBox_4_5_clicked(bool checked)
{
    if(checked){
        matrix_row_4 |= (1<<5);
    }
    else{
        matrix_row_4 &= ~(1<<5);
    }
}

void MainWindow::on_checkBox_4_4_clicked(bool checked)
{
    if(checked){
        matrix_row_4 |= (1<<4);
    }
    else{
        matrix_row_4 &= ~(1<<4);
    }
}

void MainWindow::on_checkBox_4_3_clicked(bool checked)
{
    if(checked){
        matrix_row_4 |= (1<<3);
    }
    else{
        matrix_row_4 &= ~(1<<3);
    }
}

void MainWindow::on_checkBox_4_2_clicked(bool checked)
{
    if(checked){
        matrix_row_4 |= (1<<2);
    }
    else{
        matrix_row_4 &= ~(1<<2);
    }
}

void MainWindow::on_checkBox_4_1_clicked(bool checked)
{
    if(checked){
        matrix_row_4 |= (1<<1);
    }
    else{
        matrix_row_4 &= ~(1<<1);
    }
}

void MainWindow::on_checkBox_4_0_clicked(bool checked)
{
    if(checked){
        matrix_row_4 |= (1<<0);
    }
    else{
        matrix_row_4 &= ~(1<<0);
    }
}

void MainWindow::on_checkBox_5_7_clicked(bool checked)
{
    if(checked){
        matrix_row_5 |= (1<<7);
    }
    else{
        matrix_row_5 &= ~(1<<7);
    }
}

void MainWindow::on_checkBox_5_6_clicked(bool checked)
{
    if(checked){
        matrix_row_5 |= (1<<6);
    }
    else{
        matrix_row_5 &= ~(1<<6);
    }
}

void MainWindow::on_checkBox_5_5_clicked(bool checked)
{
    if(checked){
        matrix_row_5 |= (1<<5);
    }
    else{
        matrix_row_5 &= ~(1<<5);
    }
}

void MainWindow::on_checkBox_5_4_clicked(bool checked)
{
    if(checked){
        matrix_row_5 |= (1<<4);
    }
    else{
        matrix_row_5 &= ~(1<<4);
    }
}

void MainWindow::on_checkBox_5_3_clicked(bool checked)
{
    if(checked){
        matrix_row_5 |= (1<<3);
    }
    else{
        matrix_row_5 &= ~(1<<3);
    }
}

void MainWindow::on_checkBox_5_2_clicked(bool checked)
{
    if(checked){
        matrix_row_5 |= (1<<2);
    }
    else{
        matrix_row_5 &= ~(1<<2);
    }
}

void MainWindow::on_checkBox_5_1_clicked(bool checked)
{
    if(checked){
        matrix_row_5 |= (1<<1);
    }
    else{
        matrix_row_5 &= ~(1<<1);
    }
}

void MainWindow::on_checkBox_5_0_clicked(bool checked)
{
    if(checked){
        matrix_row_5 |= (1<<0);
    }
    else{
        matrix_row_5 &= ~(1<<0);
    }
}

void MainWindow::on_checkBox_6_7_clicked(bool checked)
{
    if(checked){
        matrix_row_6 |= (1<<7);
    }
    else{
        matrix_row_6 &= ~(1<<7);
    }
}

void MainWindow::on_checkBox_6_6_clicked(bool checked)
{
    if(checked){
        matrix_row_6 |= (1<<6);
    }
    else{
        matrix_row_6 &= ~(1<<6);
    }
}

void MainWindow::on_checkBox_6_5_clicked(bool checked)
{
    if(checked){
        matrix_row_6 |= (1<<5);
    }
    else{
        matrix_row_6 &= ~(1<<5);
    }
}

void MainWindow::on_checkBox_6_4_clicked(bool checked)
{
    if(checked){
        matrix_row_6 |= (1<<4);
    }
    else{
        matrix_row_6 &= ~(1<<4);
    }
}

void MainWindow::on_checkBox_6_3_clicked(bool checked)
{
    if(checked){
        matrix_row_6 |= (1<<3);
    }
    else{
        matrix_row_6 &= ~(1<<3);
    }
}

void MainWindow::on_checkBox_6_2_clicked(bool checked)
{
    if(checked){
        matrix_row_6 |= (1<<2);
    }
    else{
        matrix_row_6 &= ~(1<<2);
    }
}

void MainWindow::on_checkBox_6_1_clicked(bool checked)
{
    if(checked){
        matrix_row_6 |= (1<<1);
    }
    else{
        matrix_row_6 &= ~(1<<1);
    }
}

void MainWindow::on_checkBox_6_0_clicked(bool checked)
{
    if(checked){
        matrix_row_6 |= (1<<0);
    }
    else{
        matrix_row_6 &= ~(1<<0);
    }
}

void MainWindow::on_checkBox_7_7_clicked(bool checked)
{
    if(checked){
        matrix_row_7 |= (1<<7);
    }
    else{
        matrix_row_7 &= ~(1<<7);
    }
}

void MainWindow::on_checkBox_7_6_clicked(bool checked)
{
    if(checked){
        matrix_row_7 |= (1<<6);
    }
    else{
        matrix_row_7 &= ~(1<<6);
    }
}

void MainWindow::on_checkBox_7_5_clicked(bool checked)
{
    if(checked){
        matrix_row_7 |= (1<<5);
    }
    else{
        matrix_row_7 &= ~(1<<5);
    }
}

void MainWindow::on_checkBox_7_4_clicked(bool checked)
{
    if(checked){
        matrix_row_7 |= (1<<4);
    }
    else{
        matrix_row_7 &= ~(1<<4);
    }
}

void MainWindow::on_checkBox_7_3_clicked(bool checked)
{
    if(checked){
        matrix_row_7 |= (1<<3);
    }
    else{
        matrix_row_7 &= ~(1<<3);
    }
}

void MainWindow::on_checkBox_7_2_clicked(bool checked)
{
    if(checked){
        matrix_row_7 |= (1<<2);
    }
    else{
        matrix_row_7 &= ~(1<<2);
    }
}

void MainWindow::on_checkBox_7_1_clicked(bool checked)
{
    if(checked){
        matrix_row_7 |= (1<<1);
    }
    else{
        matrix_row_7 &= ~(1<<1);
    }
}

void MainWindow::on_checkBox_7_0_clicked(bool checked)
{
    if(checked){
        matrix_row_7 |= (1<<0);
    }
    else{
        matrix_row_7 &= ~(1<<0);
    }
}

//Alle löschen
void MainWindow::on_pushButton_4_clicked()
{

    QList<QCheckBox *> allButtons = ui->gridGroupBox->findChildren<QCheckBox *>();
    for (int i=0; i<allButtons.size();i++){
        allButtons.at(i)->setChecked(true);
        allButtons.at(i)->click();
    }


}

//Alle setzen
void MainWindow::on_pushButton_3_clicked()
{

    QList<QCheckBox *> allButtons = ui->gridGroupBox->findChildren<QCheckBox *>();
    for (int i=0; i<allButtons.size();i++){
        allButtons.at(i)->setChecked(false);
        allButtons.at(i)->click();
    }
}

//Enable "Speichern"-Button wenn Textfeld nicht leer, sonst disable
void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    if(arg1 != ""){
        ui->pushButton_5->setEnabled(true);
    }
    else{
        ui->pushButton_5->setEnabled(false);
    }
}


//Muster speichern
void MainWindow::on_pushButton_5_clicked(){
    QString filename="Muster.txt";

    QFile file(filename);
    fprintf(stderr, "Hier");
    if(!file.open(QIODevice::Append | QIODevice::Text)){
        fprintf(stderr, "Da");
        QMessageBox::warning(this, "Fehler", "Datei konnte nicht geöffnet werden", QMessageBox::Ok);

    }else{
        QString toWrite;
        toWrite=ui->lineEdit->text();

        //Falls Leerzeichen vorhanden, also mehr als ein Wort, wird der Rest gelöscht
       for (int i=0;i<toWrite.length();i++){
           fprintf(stderr, "In for-Schleife: %s", toWrite.at(i));
           if(toWrite.at(i)==' '){
                QChar eingabe[i];
                for(int j=0;j<i;j++){
                    eingabe[j]=toWrite.at(j);
                }
                QString lokal(eingabe);
                toWrite=lokal;
                break;
           }
        }

        QString qrow_0(matrix_row_0);
        if (matrix_row_0==0x00)
            qrow_0='9';

        QString qrow_1(matrix_row_1);
        if (matrix_row_1==0x00)
            qrow_1='9';

        QString qrow_2(matrix_row_2);
        if (matrix_row_2==0x00)
            qrow_2='9';

        QString qrow_3(matrix_row_3);
        if (matrix_row_3==0x00)
            qrow_3='9';

        QString qrow_4(matrix_row_4);
        if (matrix_row_3==0x00)
            qrow_3='9';

        QString qrow_5(matrix_row_5);
        if (matrix_row_5==0x00)
            qrow_5='9';

        QString qrow_6(matrix_row_6);
        if (matrix_row_6==0x00)
            qrow_6='9';

        QString qrow_7(matrix_row_7);
        if (matrix_row_7==0x00)
            qrow_7='9';

        toWrite += " " + qrow_0+ " "+qrow_1+" " + qrow_2 + " " + qrow_3 + " " + qrow_4 + " " + qrow_5 + " " + qrow_6 + " " + qrow_7 + "\n";

        QTextStream out(&file);
        out << toWrite;

        ui->lineEdit->clear();
        ui->pushButton_5->setEnabled(false);
        on_pushButton_8_clicked();

    }


}


//Musterauswahl aktualisieren
void MainWindow::on_pushButton_8_clicked(){
    ui->comboBox_3->clear();

    const char* const filename="Muster.txt";
    FILE *fp;

    char puffer[100];
    if((fp=fopen(filename, "r"))==NULL){
        fprintf(stderr, "Kann %s nicht oeffnen\n", filename);
        return;
    }
    //int size=0;
    fprintf(stderr, "Vor while\n");
    while(fgets(puffer, 100, fp)){
        //size=sizeof(puffer)/sizeof(char);
        for (int i=0;i<100;i++){
            if(puffer[i]==' '){
                //fprintf(stderr, "Char: %i", puffer[i-1]);
                char puffer2[i];
                for(int j=0;j<i;j++){
                    puffer2[i]=puffer[i];

                }
                ui->comboBox_3->addItem(puffer2);
                break;
            }
        }

    }
}

//Muster laden

void MainWindow::on_pushButton_7_clicked(){
    QString filename="Muster.txt";

    QFile file(filename);

    QStringList lines;

    while(!file.atEnd())
        lines.append(file.readLine());

    for (int i=0;i<lines.size();i++){

    }
    //TODO

}

//Invertieren an/aus
void MainWindow::on_comboBox_4_activated(int index){

    switch(index){
        case 0://Display normal
            isInverted=false;
            on_pushButton_clicked();
            break;
        case 1://Display invertiert
            isInverted=true;
            on_pushButton_clicked();
            break;
        default://Display normal
            isInverted=false;
            on_pushButton_clicked();
            break;
    }
}


//Muster aus Datei löschen
void MainWindow::on_pushButton_6_clicked(){
    //TODO
}



