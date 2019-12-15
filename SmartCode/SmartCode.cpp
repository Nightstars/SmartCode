#include "SmartCode.h"

SmartCode::SmartCode(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//�ȴ�300����
	//Sleep(300);
	setWindowFlags(Qt::FramelessWindowHint | windowFlags());
	//����TitleBarָ��
	//����TitleBarָ��
	TitleBar* pTitleBar = new TitleBar(this);
	//���ÿ��
	pTitleBar->resize(1200,30);
	//�����¼�
	installEventFilter(pTitleBar);
	//���ô����С
	resize(1200, 780);
	//���ô������
	setWindowTitle(" <h1><font color=white>SmartCode</font></h1>");
	//���ô���ͼ��
	setWindowIcon(QIcon(":/SmartCode/Resources/imgs/icon1.png"));
	//����Բ�Ǵ���
	#pragma region ����Բ�Ǵ���
	QBitmap bmp(this->size());
	bmp.fill();
	QPainter p(&bmp);
	p.setRenderHint(QPainter::Antialiasing);
	p.setPen(Qt::NoPen);
	p.setBrush(Qt::black);
	p.drawRoundedRect(bmp.rect(), 7, 7);
	setMask(bmp);
	#pragma endregion
	//���ô��屳��
	#pragma region ���ô��屳��
	this->setAutoFillBackground(true); // ���Ҫ����, ���������ʾ��������ͼ.
	QPalette palette = this->palette();
	palette.setBrush(QPalette::Window,
		QBrush(QPixmap(":/SmartCode/Resources/skins/skin7.png").scaled(// ���ű���ͼ.
			this->size(),
			Qt::IgnoreAspectRatio,
			Qt::SmoothTransformation)));             // ʹ��ƽ�������ŷ�ʽ
	this->setPalette(palette);
	#pragma endregion
	//����Զ��������
	#pragma region ����Զ��������
	QVBoxLayout* pLayout = new QVBoxLayout();
	pLayout->addWidget(pTitleBar);
	pLayout->addStretch();
	pLayout->setSpacing(0);
	pLayout->setContentsMargins(0, 0, 0, 0);
	setLayout(pLayout);
	#pragma endregion	
	#pragma region ��ఴť
	ui.account_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}");
	ui.codegen_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/codegen_h.png);}"
														"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/codegen_n.png);}"
														"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/codegen_h.png);}");
	ui.codeprev_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/preview_h.png);}"
														"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/preview_n.png);}"
														"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/preview_h.png);}");
	ui.templete_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/templete_h.png);}"
														"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/templete_n.png);}"
														"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/templete_h.png);}");
	ui.setting_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/seeting_h.png);}"
														"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/seeting_n.png);}"
														"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/seeting_h.png);}");
	ui.about_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/about_h.png);}"
														"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/about_n.png);}"
														"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/about_h.png);}");
	ui.extendtion_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/extendtion_h.png);}"
														"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/extendtion_n.png);}"
														"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/extendtion_h.png);}");
	#pragma endregion
	#pragma region ��ҳ��
	ui.widget->setStyleSheet("background-color:	#0540F2;border-radius:5;");
	ui.main_page->setStyleSheet("background-color:rgba(255, 255, 255, 1);border-radius:5;");
	//ui.account_page->setStyleSheet("background-color:white;border-radius:5;");
	//ui.codegen_page->setStyleSheet("background-color:white;border-radius:5;");
	//Ĭ��������
	ui.main_page->setCurrentIndex(0);
	#pragma endregion

	#pragma region ��ҳ���
	connect(ui.account_btn, SIGNAL(clicked(bool)), this, SLOT(turnAccountPage()));
	connect(ui.codegen_btn, SIGNAL(clicked(bool)), this, SLOT(turnCodegenPage()));
	connect(ui.codeprev_btn, SIGNAL(clicked(bool)), this, SLOT(turnPreviewPage()));
	connect(ui.templete_btn, SIGNAL(clicked(bool)), this, SLOT(turnTempletePage()));
	connect(ui.setting_btn, SIGNAL(clicked(bool)), this, SLOT(turnSeetingPage()));
	connect(ui.about_btn, SIGNAL(clicked(bool)), this, SLOT(turnAboutPage()));
	connect(ui.extendtion_btn, SIGNAL(clicked(bool)), this, SLOT(turnExtendPage()));
	#pragma endregion


}
void SmartCode::turnAccountPage()
{
	/*QPropertyAnimation* animation = new QPropertyAnimation(ui.main_page, "windowOpacity");
	animation->setDuration(500);
	animation->setStartValue(0);
	animation->setEndValue(1);
	animation->start();
	connect(animation, SIGNAL(finished()), this, SLOT(turnAccountPage_t()));*/

	ui.account_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/mine_h.png);}");
	ui.codegen_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/codegen_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/codegen_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/codegen_n.png);}");
	ui.codeprev_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/preview_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/preview_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/preview_n.png);}");
	ui.templete_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/templete_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/templete_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/templete_n.png);}");
	ui.setting_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/seeting_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/seeting_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/seeting_n.png);}");
	ui.about_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/about_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/about_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/about_n.png);}");
	ui.extendtion_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/extendtion_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/extendtion_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/extendtion_n.png);}");
	ui.main_page->setCurrentIndex(0);
}
void SmartCode::turnAccountPage_t()
{
	ui.main_page->setCurrentIndex(0);
}
void SmartCode::turnCodegenPage()
{
	//QPropertyAnimation* animation = new QPropertyAnimation(ui.main_page, "windowOpacity");
	//animation->setDuration(500);
	//animation->setStartValue(0);
	//animation->setEndValue(1);
	//animation->start();
	//connect(animation, SIGNAL(finished()), this, SLOT(turnCodegenPage_t()));

	ui.codegen_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/codegen_h.png);}");
	ui.account_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/mine_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}");
	ui.codeprev_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/preview_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/preview_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/preview_n.png);}");
	ui.templete_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/templete_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/templete_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/templete_n.png);}");
	ui.setting_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/seeting_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/seeting_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/seeting_n.png);}");
	ui.about_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/about_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/about_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/about_n.png);}");
	ui.extendtion_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/extendtion_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/extendtion_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/extendtion_n.png);}");
	ui.main_page->setCurrentIndex(1);
}
void SmartCode::turnCodegenPage_t()
{
	ui.codegen_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/codegen_h.png);}");
	ui.main_page->setCurrentIndex(1);
}
void SmartCode::turnPreviewPage()
{
	ui.codeprev_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/preview_h.png);}");
	ui.account_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/mine_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}");
	ui.codegen_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/codegen_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/codegen_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/codegen_n.png);}");
	ui.templete_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/templete_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/templete_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/templete_n.png);}");
	ui.setting_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/seeting_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/seeting_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/seeting_n.png);}");
	ui.about_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/about_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/about_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/about_n.png);}");
	ui.extendtion_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/extendtion_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/extendtion_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/extendtion_n.png);}");
	ui.main_page->setCurrentIndex(2);
}
void SmartCode::turnTempletePage()
{
	ui.templete_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/templete_h.png);}");
	ui.account_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/mine_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}");
	ui.codegen_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/codegen_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/codegen_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/codegen_n.png);}");
	ui.codeprev_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/preview_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/preview_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/preview_n.png);}");
	ui.setting_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/seeting_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/seeting_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/seeting_n.png);}");
	ui.about_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/about_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/about_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/about_n.png);}");
	ui.extendtion_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/extendtion_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/extendtion_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/extendtion_n.png);}");
	ui.main_page->setCurrentIndex(3);
}
void SmartCode::turnSeetingPage()
{
	ui.setting_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/seeting_h.png);}");
	ui.account_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/mine_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}");
	ui.codegen_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/codegen_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/codegen_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/codegen_n.png);}");
	ui.codeprev_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/preview_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/preview_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/preview_n.png);}");
	ui.templete_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/templete_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/templete_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/templete_n.png);}");
	ui.about_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/about_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/about_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/about_n.png);}");
	ui.extendtion_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/extendtion_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/extendtion_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/extendtion_n.png);}");
	ui.main_page->setCurrentIndex(4);
}
void SmartCode::turnAboutPage()
{
	ui.about_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/about_h.png);}");
	ui.account_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/mine_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}");
	ui.codegen_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/codegen_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/codegen_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/codegen_n.png);}");
	ui.codeprev_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/preview_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/preview_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/preview_n.png);}");
	ui.templete_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/templete_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/templete_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/templete_n.png);}");
	ui.setting_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/seeting_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/seeting_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/seeting_n.png);}");
	ui.extendtion_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/extendtion_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/extendtion_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/extendtion_n.png);}");
	ui.main_page->setCurrentIndex(5);
}
void SmartCode::turnExtendPage()
{
	ui.extendtion_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/extendtion_h.png);}");
	ui.account_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/mine_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/mine_n.png);}");
	ui.codegen_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/codegen_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/codegen_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/codegen_n.png);}");
	ui.codeprev_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/preview_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/preview_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/preview_n.png);}");
	ui.templete_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/templete_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/templete_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/templete_n.png);}");
	ui.setting_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/seeting_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/seeting_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/seeting_n.png);}");
	ui.about_btn->setStyleSheet("QPushButton{border-image: url(:/SmartCode/Resources/imgs/about_n.png);}"
		"QPushButton:hover{border-image: url(:/SmartCode/Resources/imgs/about_h.png);}"
		"QPushButton:pressed{border-image: url(:/SmartCode/Resources/imgs/about_n.png);}");
	ui.main_page->setCurrentIndex(6);
}