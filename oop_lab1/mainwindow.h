#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cstring>
#include <iostream>
#include <QMessageBox>
#include <QWidget>
#include <QDoubleValidator>
#include <QFileDialog>
#include "defines.h"
#include "rc.h"
#include "model_events.h"
#include "manager.h"
#include "model_structs.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
	Ui::MainWindow *ui;

private slots:

	void on_Exit_triggered();

	void on_MenuAuthorInfo_triggered();

	void on_MenuProgInfo_triggered();

	void on_menuOpenModel_triggered();

	void printErrorMessage(err_t rc);

	void on_menuSaveModel_triggered();

	void on_DrawPicButton_clicked();

	void on_ScaleButton_clicked();
	void get_scale_coefs(points_t &scale_coefs);
	err_t check_scale_coefs();

	void on_MoveButton_clicked();
	void get_move_coefs(points_t &move_coefs);
	err_t check_move_coefs();

	void get_rotation_angles(points_t &rot_angles);
	err_t check_rotation_angles();
	void on_RotateButton_clicked();

private:
	graphic_scene_t scene;
	void init_canvas();
	void init_entries();
	void set_validate_settings();


};

#endif // MAINWINDOW_H
