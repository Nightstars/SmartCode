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
	#pragma region ��ҳ��
	ui.widget->setStyleSheet("background-color:	#0540F2;border-radius:5;");
	ui.stackedWidget->setStyleSheet("background-color:white;border-radius:5;");
	#pragma endregion


}
