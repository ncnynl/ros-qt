/**
 * @file /include/btn/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef btn_QNODE_HPP_
#define btn_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include <QThread>
#include <QStringListModel>
#include <std_msgs/String.h>  //add

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace btn {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
	bool init(const std::string &master_url, const std::string &host_url);
	void run();

	/*********************
	** Logging
	**********************/
	enum LogLevel {
	         Debug,
	         Info,
	         Warn,
	         Error,
	         Fatal
	 };

	QStringListModel* loggingModel() { return &logging_model; }
	void log( const LogLevel &level, const std::string &msg);
  QStringListModel* loggingModel_sub() { return &logging_model_sub; } //add
  void log_sub( const LogLevel &level, const std::string &msg); //add
  void Callback(const std_msgs::StringConstPtr &submsg);  //add
  void sent_cmd();  //add

Q_SIGNALS:
	void loggingUpdated();
    void rosShutdown();
  void loggingUpdated_sub();  //add

private:
	int init_argc;
	char** init_argv;
	ros::Publisher chatter_publisher;
    QStringListModel logging_model;
    ros::Subscriber chatter_subscriber; //add
      QStringListModel logging_model_sub; //add
};

}  // namespace btn

#endif /* btn_QNODE_HPP_ */
