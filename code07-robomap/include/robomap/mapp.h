#ifndef MAPP_H
#define MAPP_H

#include <QWidget>
#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include<rviz/tool_manager.h>
#include "ui_mapp.h"

//add
#include <ros/ros.h>
#include <signal.h>
#include <geometry_msgs/Twist.h>

#include<QAbstractButton>
#include <QtCore>

namespace Ui {
class MAPP;
}

class MAPP : public QWidget
{
  Q_OBJECT

public:
  explicit MAPP(QWidget *parent = 0);
  ~MAPP();

void ros_init(int argc,char **argv);
void shutdown(int sig);

void setAutoRepeat(bool);


private slots:
  void on_btn_map_clicked();

  void on_btn_quit_clicked();

  void on_btn_back_pressed();

  void on_btn_back_released();

  void on_btn_left_pressed();

  void on_btn_right_pressed();

  void on_btn_forward_pressed();

  void on_btn_stop_clicked();

private:
  Ui::MAPP *ui;
  rviz::VisualizationManager *manager_;
  rviz::RenderPanel *render_panel_;
  rviz::Display *map_;
  QTimer *m_timer;

};

#endif // MAPP_H
