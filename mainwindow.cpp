#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include "HT16K33.h"

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
    unsigned char arr[8] = {matrix_row_0,matrix_row_1,matrix_row_2,matrix_row_3,matrix_row_4,matrix_row_5,matrix_row_6,matrix_row_7};
    ht16k33_print_array(fd, arr);
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
            display_setting &= ~(0x3<<2);
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
    QListIterator<QObject *> list = ui->gridGroupBox->children();
    while(list.hasNext()){
        QCheckBox *b = qobject_cast<QCheckBox*>(list.next());
        //b.setChecked(false);
    }

}

//Alle setzen
void MainWindow::on_pushButton_3_clicked()
{

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


