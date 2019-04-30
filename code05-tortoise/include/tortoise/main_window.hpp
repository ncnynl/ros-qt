/**
 * @file /include/tortoise/main_window.hpp
 *
 * @brief Qt based gui for tortoise.
 *
 * @date November 2010
 **/
#ifndef tortoise_MAIN_WINDOW_H
#define tortoise_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace tortoise {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
/**
 * @brief Qt central, all operations relating to the view part here.
 */
class MainWindow : public QMainWindow {
Q_OBJECT

public:
	MainWindow(int argc, char** argv, QWidget *parent = 0);
	~MainWindow();

	void ReadSettings(); // Load up qt program settings at startup
	void WriteSettings(); // Save qt program settings when closing

	void closeEvent(QCloseEvent *event); // Overloaded function
	void showNoMasterMessage();

public Q_SLOTS:
	/******************************************
	** Auto-connections (connectSlotsByName())
	*******************************************/
	void on_actionAbout_triggered();
	void on_button_connect_clicked(bool check );
	void on_checkbox_use_environment_stateChanged(int state);

    /******************************************
    ** Manual connections
    *******************************************/
    void updateLoggingView(); // no idea why this can't connect automatically

    void on_up_clicked(); //add
    void on_down_clicked(); //add
    void on_left_clicked(); //add
    void on_right_clicked();  //add


private:
	Ui::MainWindowDesign ui;
	QNode qnode;
};

}  // namespace tortoise

#endif // tortoise_MAIN_WINDOW_H
