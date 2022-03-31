#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	init_canvas();
	init_entries();
	set_validate_settings();

}

MainWindow::~MainWindow()
{
	err_t rc = prepare_to_quit();

	if (!rc)
		delete ui;
}

void MainWindow::init_canvas()
{
	scene.canvas = new QGraphicsScene(this);
	scene.height = HEIGHT;
	scene.width = WIDTH;

	ui->graphicsView->setScene(scene.canvas);
}

void MainWindow::init_entries()
{
	ui->x_move_entry->setText(ZERO);
	ui->y_move_entry->setText(ZERO);
	ui->z_move_entry->setText(ZERO);

	ui->x_rot_angle_entry->setText(ZERO);
	ui->y_rot_angle_entry->setText(ZERO);
	ui->z_rot_angle_entry->setText(ZERO);

	ui->x_scale_entry->setText(ONE);
	ui->y_scale_entry->setText(ONE);
	ui->z_scale_entry->setText(ONE);
}

void MainWindow::set_validate_settings()
{
	QValidator *validator = new QDoubleValidator();
	validator->setLocale(QLocale(QLocale::English));

    ui->x_move_entry->setMaxLength(3);
    ui->y_move_entry->setMaxLength(3);
    ui->z_move_entry->setMaxLength(3);

	ui->x_move_entry->setValidator(validator);
	ui->y_move_entry->setValidator(validator);
	ui->z_move_entry->setValidator(validator);

    ui->x_rot_angle_entry->setMaxLength(3);
    ui->y_rot_angle_entry->setMaxLength(3);
    ui->z_rot_angle_entry->setMaxLength(3);

    ui->x_rot_angle_entry->setValidator(validator);
	ui->y_rot_angle_entry->setValidator(validator);
	ui->z_rot_angle_entry->setValidator(validator);

    ui->x_scale_entry->setMaxLength(3);
    ui->y_scale_entry->setMaxLength(3);
    ui->z_scale_entry->setMaxLength(3);

	ui->x_scale_entry->setValidator(validator);
	ui->y_scale_entry->setValidator(validator);
	ui->z_scale_entry->setValidator(validator);
}

void MainWindow::on_Exit_triggered()
{
	prepare_to_quit();

	QApplication::quit();
}

void MainWindow::on_MenuAuthorInfo_triggered()
{
	QMessageBox::information(this, "Об Авторе:", "Вязовцев Максим ИУ7-45Б");
}

void MainWindow::on_MenuProgInfo_triggered()
{
	QMessageBox::information(this, "О программе:", "Простейший 3D визуализатор.");
}

void MainWindow::on_menuSaveModel_triggered()
{
	err_t rc = OK;
	event_t event;
	char filename[MAX_LEN];

	QString qpath = QFileDialog::getOpenFileName();

	if (qpath.isEmpty())
		rc = EMPTY_FILE_PATH;

	if (!rc)
	{
		std::strcpy(filename, qpath.toStdString().c_str());
		rc = fixing_save_to_file_event(event, filename);

		if (!rc)
			rc = action_manager(event);
	}

	if (rc)
		printErrorMessage(rc);

}

void MainWindow::on_menuOpenModel_triggered()
{
	err_t rc = OK;
    event_t event;
    char filename[MAX_LEN];

	QString qpath = QFileDialog::getOpenFileName();

	if (qpath.isEmpty())
		rc = EMPTY_FILE_PATH;

	if (!rc)
	{
		std::strcpy(filename, qpath.toStdString().c_str());
		rc = fixing_open_file_event(event, filename);

		if (!rc)
			rc = action_manager(event);
	}

	if (rc)
		printErrorMessage(rc);

}

void MainWindow::printErrorMessage(err_t rc)
{
	switch(rc)
	{
	case ERROR_FILE_OPEN:
        QMessageBox::critical(this, "Ошибка","Выбранный файл не существует");
		break;
	case ERROR_FILE_EMPTY:
        QMessageBox::critical(this, "Ошибка","Выбранный файл пуст или содержит некорректные значения в peaks");
		break;
	case ERROR_FILE_DATA:
        QMessageBox::critical(this, "Ошибка","Выбранный файл содержит некорректные данные");
		break;
	case ERROR_FILE_FEW_DATA:
        QMessageBox::critical(this, "Ошибка","Выбранный файл содержит недостаточно данных");
		break;
	case ERROR_MOVE_X_EMPTY:
        QMessageBox::critical(this, "Ошибка","Не заполнено поле перемещения по X");
		break;
	case ERROR_MOVE_Y_EMPTY:
        QMessageBox::critical(this, "Ошибка","Не заполнено поле перемещения по Y");
		break;
	case ERROR_MOVE_Z_EMPTY:
        QMessageBox::critical(this, "Ошибка","Не заполнено поле перемещения по Z");
		break;
	case ERROR_ROT_X_EMPTY:
        QMessageBox::critical(this, "Ошибка","Не заполнено поле вращения по оси X");
		break;
	case ERROR_ROT_Y_EMPTY:
        QMessageBox::critical(this, "Ошибка","Не заполнено поле вращения по оси Y");
		break;
	case ERROR_ROT_Z_EMPTY:
        QMessageBox::critical(this, "Ошибка","Не заполнено поле вращения по оси Z");
		break;
	case ERROR_SCALE_X_EMPTY:
        QMessageBox::critical(this, "Ошибка","Не заполнено поле масштабирования по оси X");
		break;
	case ERROR_SCALE_Y_EMPTY:
		QMessageBox::warning(this, "Ошибка","Не заполнено поле масштабирования по оси Y");
		break;
	case ERROR_SCALE_Z_EMPTY:
        QMessageBox::critical(this, "Ошибка","Не заполнено поле масштабирования по оси Z");
		break;
	case MODEL_EMPTY:
        QMessageBox::critical(this, "Ошибка","Считывание фигуры не выполнено");
		break;
	default:
		break;
	}
}

void MainWindow::on_DrawPicButton_clicked()
{
	err_t rc = OK;
	event_t event;

	scene.canvas->clear();
	fixing_draw_event(event, scene);

	rc = action_manager(event);

	if (rc)
	{
		printErrorMessage(rc);
	}
}

void MainWindow::on_ScaleButton_clicked()
{
	err_t rc = OK;
	event_t event;
	points_t scale_coefs;

	rc = check_scale_coefs();

	if (!rc)
	{
		get_scale_coefs(scale_coefs);
		rc = fixing_scale_event(event, scale_coefs);

		if (!rc)
			rc = action_manager(event);

		if (!rc)
			on_DrawPicButton_clicked();
	}

	if(rc)
		printErrorMessage(rc);
}

err_t MainWindow::check_scale_coefs()
{
	err_t rc = OK;

	if (ui->x_scale_entry->text().isEmpty())
		rc = ERROR_SCALE_X_EMPTY;
	if (ui->y_scale_entry->text().isEmpty())
		rc = ERROR_SCALE_Y_EMPTY;
	if (ui->z_scale_entry->text().isEmpty())
		rc = ERROR_SCALE_Z_EMPTY;

	return rc;
}

void MainWindow::get_scale_coefs(points_t &scale_coefs)
{
	scale_coefs.x = ui->x_scale_entry->text().toFloat();
	scale_coefs.y = ui->y_scale_entry->text().toFloat();
	scale_coefs.z = ui->z_scale_entry->text().toFloat();
}

void MainWindow::on_MoveButton_clicked()
{
	err_t rc = OK;
	event_t event;
	points_t move_coefs;

	rc = check_move_coefs();

	if (!rc)
	{
		get_move_coefs(move_coefs);
		rc = fixing_move_event(event, move_coefs);

		if (!rc)
			rc = action_manager(event);

		if (!rc)
			on_DrawPicButton_clicked();
	}

	if (rc)
		printErrorMessage(rc);
}

err_t MainWindow::check_move_coefs()
{
	err_t rc = OK;

	if (ui->x_move_entry->text().isEmpty())
		rc = ERROR_MOVE_X_EMPTY;
	if (ui->y_move_entry->text().isEmpty())
		rc = ERROR_MOVE_Y_EMPTY;
	if (ui->z_move_entry->text().isEmpty())
		rc = ERROR_MOVE_Z_EMPTY;

	return rc;
}

void MainWindow::get_move_coefs(points_t &move_coefs)
{
	move_coefs.x = ui->x_move_entry->text().toFloat();
	move_coefs.y = ui->y_move_entry->text().toFloat();
	move_coefs.z = ui->z_move_entry->text().toFloat();
}

void MainWindow::on_RotateButton_clicked()
{
	err_t rc = OK;
	event_t event;
	points_t rot_angles;

	rc = check_rotation_angles();

	if (!rc)
	{
		get_rotation_angles(rot_angles);
		rc = fixing_rotation_event(event, rot_angles);

		if (!rc)
			rc = action_manager(event);

		if (!rc)
			on_DrawPicButton_clicked();
	}

	if(rc)
		printErrorMessage(rc);
}

err_t MainWindow::check_rotation_angles()
{
	err_t rc = OK;

	if (ui->x_rot_angle_entry->text().isEmpty())
		rc = ERROR_ROT_X_EMPTY;
	if (ui->y_rot_angle_entry->text().isEmpty())
		rc = ERROR_ROT_Y_EMPTY;
	if (ui->z_rot_angle_entry->text().isEmpty())
		rc = ERROR_ROT_Z_EMPTY;

	return rc;
}

void MainWindow::get_rotation_angles(points_t &rot_angles)
{
	rot_angles.x = ui->x_rot_angle_entry->text().toFloat();
	rot_angles.y = ui->y_rot_angle_entry->text().toFloat();
	rot_angles.z = ui->z_rot_angle_entry->text().toFloat();
}
