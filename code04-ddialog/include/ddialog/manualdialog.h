#ifndef MANUALDIALOG_H
#define MANUALDIALOG_H
#include <QDialog>
#include "qnode.hpp"  //add

namespace Ui {
class manualdialog;
}

//add,前置声明
namespace ddialog {
  class QNode;
}

class manualdialog : public QDialog
{
  Q_OBJECT

public:
  explicit manualdialog(QWidget *parent = 0);
  ~manualdialog();

public Q_SLOTS:
  void on_up_clicked(); //add
  void on_down_clicked(); //add
  void on_left_clicked(); //add
  void on_right_clicked();  //add
  void on_back_clicked();   //add

private:
  Ui::manualdialog *ui;
  ddialog::QNode *qnode;  //add
};

#endif // MANUALDIALOG_H
