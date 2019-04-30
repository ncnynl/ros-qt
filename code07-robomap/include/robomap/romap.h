#ifndef ROMAP_H
#define ROMAP_H

#include <QWidget>
#include <rviz/visualization_manager.h>
#include <rviz/render_panel.h>
#include <rviz/display.h>
#include<rviz/tool_manager.h>
#include "ui_romap.h"

namespace Ui {
class RoMap;
}

class RoMap : public QWidget
{
  Q_OBJECT

public:
  explicit RoMap(QWidget *parent = 0);
  ~RoMap();

  void ros_init(int argc,char **argv);

private slots:
  void on_btn_display_clicked();

  void on_btn_quit_clicked();

private:
  Ui::RoMap *ui;
  rviz::VisualizationManager *manager_;
  rviz::RenderPanel *render_panel_;
  rviz::Display *map_;



};

#endif // ROMAP_H
