/**
 * @file /include/robomap/main_window.hpp
 *
 * @brief Qt based gui for robomap.
 *
 * @date November 2010
 **/
#ifndef robomap_MAIN_WINDOW_H
#define robomap_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"
#include "romap.h"
#include <rviz/render_panel.h>
#include <rviz/visualization_manager.h>
#include <rviz/tool_manager.h>
#include "ui_romap.h"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace robomap {

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

private slots:
    void on_pushButton_clicked();

    void on_btn_mapping_clicked();

private:
	Ui::MainWindowDesign ui;
	QNode qnode;
};

}  // namespace robomap

#endif // robomap_MAIN_WINDOW_H
