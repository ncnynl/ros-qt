#include "../include/robomap/mapp.h"
#include "ui_mapp.h"

//add
#include <ros/ros.h>
#include <signal.h>
#include <geometry_msgs/Twist.h>

ros::Publisher cmdVelPub;


MAPP::MAPP(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::MAPP)
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

   ui->btn_forward->setAutoRepeat(true);
   ui->btn_forward->setAutoRepeatDelay(1000);
   ui->btn_forward->setAutoRepeatInterval(100);

   ui->btn_back->setAutoRepeat(true);
   ui->btn_back->setAutoRepeatDelay(1000);
   ui->btn_back->setAutoRepeatInterval(100);

   ui->btn_left->setAutoRepeat(true);
   ui->btn_left->setAutoRepeatDelay(1000);
   ui->btn_left->setAutoRepeatInterval(100);

   ui->btn_right->setAutoRepeat(true);
   ui->btn_right->setAutoRepeatDelay(1000);
   ui->btn_right->setAutoRepeatInterval(100);
}

MAPP::~MAPP()
{
  delete ui;
}

void MAPP::ros_init(int argc,char **argv)
{
  ros::init(argc,argv,"rosmap",ros::init_options::AnonymousName);
}


void MAPP::on_btn_map_clicked()
{
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
}

void MAPP::on_btn_quit_clicked()
{
    this->close();
}


void MAPP::on_btn_back_pressed()
{
  ros::NodeHandle node;//为这个进程的节点创建一个句柄
  cmdVelPub = node.advertise<geometry_msgs::Twist>("/cmd_vel", 1);//在/mobile_base/commands/velocity topic上发布一个geometry_msgs/Twist的消息
 // ros::Rate loopRate(100);//ros::Rate对象可以允许你指定自循环的频率
  ROS_INFO("move_turtle_goforward cpp start...");
  geometry_msgs::Twist speed; // 控制信号载体 Twist message
// while(ros::ok())
//  {
    speed.linear.x = -0.05; // 设置线速度为0.1m/s，正为前进，负为后退(0)
    speed.angular.z = 0; // 设置角速度为0rad/s，正为左转，负为右转 (0.5)
    cmdVelPub.publish(speed); // 将刚才设置的指令发送给机器人
 //  loopRate.sleep();
 // }

}

void MAPP::on_btn_back_released()
{
  //QTimer *m_timer = new QTimer;
  //m_timer->stop();
}

void MAPP::on_btn_left_pressed()
{
  ros::NodeHandle node;//为这个进程的节点创建一个句柄
  cmdVelPub = node.advertise<geometry_msgs::Twist>("/cmd_vel", 1);//在/mobile_base/commands/velocity topic上发布一个geometry_msgs/Twist的消息
 // ros::Rate loopRate(100);//ros::Rate对象可以允许你指定自循环的频率
  ROS_INFO("move_turtle_goforward cpp start...");
  geometry_msgs::Twist speed; // 控制信号载体 Twist message
// while(ros::ok())
//  {
    speed.linear.x = 0; // 设置线速度为0.1m/s，正为前进，负为后退(0)
    speed.angular.z = 0.05; // 设置角速度为0rad/s，正为左转，负为右转 (0.5)
    cmdVelPub.publish(speed); // 将刚才设置的指令发送给机器人
 //  loopRate.sleep();
 // }

}

void MAPP::on_btn_right_pressed()
{
 ros::NodeHandle node;//为这个进程的节点创建一个句柄
cmdVelPub = node.advertise<geometry_msgs::Twist>("/cmd_vel", 1);//在/mobile_base/commands/velocity topic上发布一个geometry_msgs/Twist的消息
// ros::Rate loopRate(100);//ros::Rate对象可以允许你指定自循环的频率
ROS_INFO("move_turtle_goforward cpp start...");
geometry_msgs::Twist speed; // 控制信号载体 Twist message
// while(ros::ok())
//  {
  speed.linear.x = 0; // 设置线速度为0.1m/s，正为前进，负为后退(0)
  speed.angular.z = -0.05; // 设置角速度为0rad/s，正为左转，负为右转 (0.5)
  cmdVelPub.publish(speed); // 将刚才设置的指令发送给机器人
//  loopRate.sleep();
// }
}

void MAPP::on_btn_forward_pressed()
{
  ros::NodeHandle node;//为这个进程的节点创建一个句柄
 cmdVelPub = node.advertise<geometry_msgs::Twist>("/cmd_vel", 1);//在/mobile_base/commands/velocity topic上发布一个geometry_msgs/Twist的消息
 // ros::Rate loopRate(100);//ros::Rate对象可以允许你指定自循环的频率
 ROS_INFO("move_turtle_goforward cpp start...");
 geometry_msgs::Twist speed; // 控制信号载体 Twist message
 // while(ros::ok())
 //  {
   speed.linear.x = 0.05; // 设置线速度为0.1m/s，正为前进，负为后退(0)
   speed.angular.z = 0; // 设置角速度为0rad/s，正为左转，负为右转 (0.5)
   cmdVelPub.publish(speed); // 将刚才设置的指令发送给机器人
 //  loopRate.sleep();
 // }
}

void MAPP::on_btn_stop_clicked()
{
  ros::NodeHandle node;//为这个进程的节点创建一个句柄
 cmdVelPub = node.advertise<geometry_msgs::Twist>("/cmd_vel", 1);//在/mobile_base/commands/velocity topic上发布一个geometry_msgs/Twist的消息
 // ros::Rate loopRate(100);//ros::Rate对象可以允许你指定自循环的频率
 ROS_INFO("move_turtle_goforward cpp start...");
 geometry_msgs::Twist speed; // 控制信号载体 Twist message
 // while(ros::ok())
 //  {
   speed.linear.x = 0; // 设置线速度为0.1m/s，正为前进，负为后退(0)
   speed.angular.z = 0; // 设置角速度为0rad/s，正为左转，负为右转 (0.5)
   cmdVelPub.publish(speed); // 将刚才设置的指令发送给机器人
 //  loopRate.sleep();
 // }
}
