#pragma once

#include <QtWidgets/QWidget>
#include "ui_SmartCode.h"
#include "title_bar.h"
#include <QVBoxLayout>
#include <QBitmap>
#include <QPainter>
#include <QIcon>

class SmartCode : public QWidget
{
	Q_OBJECT

public:
	SmartCode(QWidget *parent = Q_NULLPTR);
private:
	Ui::SmartCodeClass ui;
private slots:
	// “≥√Ê«–ªª
	void turnAccountPage();
	void turnAccountPage_t();
	void turnCodegenPage();
	void turnCodegenPage_t();
	void turnPreviewPage();
	void turnTempletePage();
	void turnSeetingPage();
	void turnAboutPage();
	void turnExtendPage();
};
