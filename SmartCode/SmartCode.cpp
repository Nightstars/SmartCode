#include "SmartCode.h"

SmartCode::SmartCode(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//等待300毫秒
	//Sleep(300);
	setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//创建TitleBar指针
	//创建TitleBar指针
	TitleBar* pTitleBar = new TitleBar(this);
	//设置宽度
	pTitleBar->resize(1200,30);
	//设置事件
	installEventFilter(pTitleBar);
	//设置窗体大小
	resize(1200, 780);
	//设置窗体标题
	setWindowTitle(" <h1><font color=white>SmartCode</font></h1>");
	//设置窗体图标
	setWindowIcon(QIcon(":/SmartCode/Resources/imgs/icon1.png"));
	//设置圆角窗体
	#pragma region 设置圆角窗体
	QBitmap bmp(this->size());
	bmp.fill();
	QPainter p(&bmp);
	p.setRenderHint(QPainter::Antialiasing);
	p.setPen(Qt::NoPen);
	p.setBrush(Qt::black);
	p.drawRoundedRect(bmp.rect(), 7, 7);
	setMask(bmp);
	#pragma endregion
	//设置窗体背景
	#pragma region 设置窗体背景
	this->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
	QPalette palette = this->palette();
	palette.setBrush(QPalette::Window,
		QBrush(QPixmap(":/SmartCode/Resources/skins/skin7.png").scaled(// 缩放背景图.
			this->size(),
			Qt::IgnoreAspectRatio,
			Qt::SmoothTransformation)));             // 使用平滑的缩放方式
	this->setPalette(palette);
	#pragma endregion
	//添加自定义标题栏
	#pragma region 添加自定义标题栏
	QVBoxLayout* pLayout = new QVBoxLayout();
	pLayout->addWidget(pTitleBar);
	pLayout->addStretch();
	pLayout->setSpacing(0);
	pLayout->setContentsMargins(0, 0, 0, 0);
	setLayout(pLayout);
	#pragma endregion	
	#pragma region 左侧按钮
	ui.account_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}"
														"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/mine_h.png);}"
														"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}");
	ui.codegen_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}"
														"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/mine_h.png);}"
														"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}");
	ui.codeprev_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}"
														"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/mine_h.png);}"
														"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}");
	ui.templete_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}"
														"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/mine_h.png);}"
														"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}");
	ui.setting_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}"
														"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/mine_h.png);}"
														"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}");
	ui.about_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}"
														"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/mine_h.png);}"
														"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}");
	ui.extendtion_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}"
														"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/mine_h.png);}"
														"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}");
	#pragma endregion
	#pragma region 主页面
	ui.widget->setStyleSheet("background-color:	#0540F2;border-radius:5;");
	ui.stackedWidget->setStyleSheet("background-color:white;border-radius:5;");
	#pragma endregion


}
