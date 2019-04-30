#include "../include/robomap/romap.h"
#include "ui_romap.h"
#include <QHBoxLayout>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QProcess>

RoMap::RoMap(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::RoMap)
{
  ui->setupUi(this);
  int argc;
  char **argv;

 ros_init(argc,argv);

  render_panel_=new rviz::RenderPanel;
   ui->verticalLayout->addWidget(render_panel_);
   manager_=new rviz::VisualizationManager(render_panel_);
  render_panel_->initialize(manager_->getSceneManager(),manager_);
   manager_->initialize();
   manager_->startUpdate();



   //rviz::Display *grid_=manager_->createDisplay("rviz/Grid","adjustable grid",true);
  // ROS_ASSERT(grid_!=NULL);
   //grid_->subProp("Line Style")->setValue("Billboards");





}

RoMap::~RoMap()
{
  delete ui;
}

void RoMap::ros_init(int argc,char **argv)
{
  ros::init(argc,argv,"rosmap",ros::init_options::AnonymousName);
}
void RoMap::on_btn_display_clicked()
{
   // QProcess process;
    //process.execute("source devel/setup.bash");
   // process.execute("roslaunch rbx1_bringup fake_turtlebot.launch");
    //process.execute("roslaunch rbx1_nav fake_amcl.launch");

    manager_->removeAllDisplays();

    rviz::Display *map_=manager_->createDisplay("rviz/Map","adjustable map",true);
    ROS_ASSERT(map_!=NULL);
    map_->subProp("Topic")->setValue("/map");

    rviz::Display *robot_=manager_->createDisplay("rviz/RobotModel","adjustable robot",true);
     ROS_ASSERT(robot_!=NULL);
    robot_->subProp("Robot Description")->setValue("robot_description");


    rviz::Display *laser_=manager_->createDisplay("rviz/LaserScan","adjustable scan",true);
    ROS_ASSERT(laser_!=NULL);
    laser_->subProp("Topic")->setValue("/scan");
    laser_->subProp("Size (m)")->setValue("0.1");

    //manager_->startUpdate();


   //manager_->stopUpdate();

  }


void RoMap::on_btn_quit_clicked()
{
this->close();
}
