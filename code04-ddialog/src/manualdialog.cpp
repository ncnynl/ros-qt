#include "../include/ddialog/manualdialog.h"
#include "ui_manualdialog.h"

manualdialog::manualdialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::manualdialog)
{
  ui->setupUi(this);
}

manualdialog::~manualdialog()
{
  delete ui;
}

//add
void manualdialog::on_up_clicked()
{

}

//add
void manualdialog::on_down_clicked()
{

}

//add
void manualdialog::on_left_clicked()
{

}

//add
void manualdialog::on_right_clicked()
{

}

//add
void manualdialog::on_back_clicked()
{
  this->close();
}
