#include "SmartCode.h"
#include <QtWidgets/QApplication>
#include <QSplashScreen>
#include <QIcon>
#include <QPropertyAnimation>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//QPixmap pixmap(":/SmartCode/Resources/imgs/icon11.png");
	//QSplashScreen splash(pixmap);
	//splash.show();
	//a.processEvents();
	////QString strpath = QApplication::applicationDirPath();
	////strpath += ":/SmartCode/Resources/imgs/icon11.png";
	//a.setWindowIcon(QIcon(":/SmartCode/Resources/imgs/icon11.png"));
	//SmartCode w;
	//QPropertyAnimation* animation = new QPropertyAnimation(&w, "windowOpacity");
	//animation->setDuration(200);
	//animation->setStartValue(0);
	//animation->setEndValue(1);
	//animation->start();
	//w.show();
	//splash.finish(&w);

	QSplashScreen* splash = new QSplashScreen;
	splash->setPixmap(QPixmap(":/SmartCode/Resources/imgs/icon11.png"));
	splash->show();
	SmartCode w;
	QPropertyAnimation* animation = new QPropertyAnimation(&w, "windowOpacity");
	animation->setDuration(500);
	animation->setStartValue(0);
	animation->setEndValue(1);
	animation->start();
	w.show();
	splash->finish(&w);
	delete splash;



	return a.exec();
}
