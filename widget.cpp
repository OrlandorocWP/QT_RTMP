#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
        ui(new Ui::Widget),
        lineEdit_2(NULL),
        lineEdit_3(NULL),
        lineEdit_4(NULL),
        pushButton_2(NULL),
        pushButton_3(NULL),
        pushButton_4(NULL),
        videoFrame1(NULL),
        videoFrame2(NULL),
        videoFrame3(NULL),
        videoFrame4(NULL),
        vlcInstance(NULL),
        mediaPlayer1(NULL),
        mediaPlayer2(NULL),
        mediaPlayer3(NULL),
        mediaPlayer4(NULL),
        media(NULL),
        enlargedFrame(NULL),
        isFrame1Enlarged(false),
        isFrame2Enlarged(false),
        isFrame3Enlarged(false),
        isFrame4Enlarged(false),
        originalGeometry1(),
        originalGeometry2(),
        originalGeometry3(),
        originalGeometry4()

{
    ui->setupUi(this);

    // 初始化成员变量
    lineEdit_2 = ui->lineEdit_2;
    lineEdit_3 = ui->lineEdit_3;
    lineEdit_4 = ui->lineEdit_4;
    pushButton_2 = ui->pushButton_2;
    pushButton_3 = ui->pushButton_3;
    pushButton_4 = ui->pushButton_4;
    videoFrame1 = ui->videoFrame_1;
    videoFrame2 = ui->videoFrame_2;
    videoFrame3 = ui->videoFrame_3;
    videoFrame4 = ui->videoFrame_4;
    enlargedFrame = NULL;
    //isEnlarged = false;


    this->setStyleSheet("background-color: black;");

    // 设置LineEdit和PushButton的文字颜色为白色

        lineEdit_2->setStyleSheet("color: white;");
        lineEdit_3->setStyleSheet("color: white;");
        lineEdit_4->setStyleSheet("color: white;");

        pushButton_2->setStyleSheet("color: white;");
        pushButton_3->setStyleSheet("color: white;");
        pushButton_4->setStyleSheet("color: white;");


    // 确保 lineEdit、pushButton 和 videoFrame1、videoFrame2 成员变量被正确初始化
    if (lineEdit_2 && pushButton_2 && videoFrame1 && videoFrame2 && lineEdit_3 && pushButton_3 && videoFrame3 && videoFrame4 && lineEdit_4 && pushButton_4) {
        // 创建libvlc实例和媒体播放器实例
        vlcInstance = libvlc_new(0, NULL);
        mediaPlayer1 = libvlc_media_player_new(vlcInstance);
        mediaPlayer2 = libvlc_media_player_new(vlcInstance);
        mediaPlayer3 = libvlc_media_player_new(vlcInstance);
        mediaPlayer4 = libvlc_media_player_new(vlcInstance);


        // 设置视频输出为 videoFrame1 和 videoFrame2
        libvlc_media_player_set_xwindow(mediaPlayer1, videoFrame1->winId());
        libvlc_media_player_set_xwindow(mediaPlayer2, videoFrame2->winId());
        libvlc_media_player_set_xwindow(mediaPlayer3, videoFrame3->winId());
        libvlc_media_player_set_xwindow(mediaPlayer4, videoFrame4->winId());


        // 播放默认的RTMP流
        QString defaultStreamAddress = "rtmp://10.7.178.110:9090/live";
        lineEdit_2->setText(defaultStreamAddress);
        lineEdit_3->setText(defaultStreamAddress);
        lineEdit_4->setText(defaultStreamAddress);

        // 创建媒体对象并设置地址，播放媒体流
        if (!defaultStreamAddress.isEmpty()) {
            media = libvlc_media_new_location(vlcInstance, defaultStreamAddress.toUtf8().constData());
            libvlc_media_player_set_media(mediaPlayer1, media);
            libvlc_media_player_set_media(mediaPlayer2, media);
            libvlc_media_player_set_media(mediaPlayer3, media);
            libvlc_media_player_set_media(mediaPlayer4, media);
            libvlc_media_player_play(mediaPlayer1);
            libvlc_media_player_play(mediaPlayer2);
            libvlc_media_player_play(mediaPlayer3);
            libvlc_media_player_play(mediaPlayer4);
        }

        // 连接按钮点击事件到槽函数
        connect(pushButton_2, SIGNAL(clicked()), this, SLOT(startStreaming2()));
        connect(pushButton_3, SIGNAL(clicked()), this, SLOT(startStreaming3()));
        connect(pushButton_4, SIGNAL(clicked()), this, SLOT(startStreaming4()));
    }
}

Widget::~Widget()
{
    // 停止并释放资源
    libvlc_media_player_stop(mediaPlayer1);
    libvlc_media_player_release(mediaPlayer1);
    libvlc_media_player_stop(mediaPlayer2);
    libvlc_media_player_release(mediaPlayer2);
    libvlc_release(vlcInstance);

    delete ui;
}

void Widget::startStreaming2()
{
    if (lineEdit_2) {
        QString streamAddress = lineEdit_2->text();
        if (!streamAddress.isEmpty()) {
            // 创建新的媒体对象并设置地址
            if (media) {
                libvlc_media_release(media);
            }
            media = libvlc_media_new_location(vlcInstance, streamAddress.toUtf8().constData());

            // 设置videoFrame2的mediaPlayer的媒体
            libvlc_media_player_set_media(mediaPlayer2, media);

            // 播放videoFrame2的mediaPlayer的媒体
            libvlc_media_player_play(mediaPlayer2);
        }
    }
}
void Widget::startStreaming3()
{
    if (lineEdit_3) {
        QString streamAddress = lineEdit_3->text();
        if (!streamAddress.isEmpty()) {
            // 创建新的媒体对象并设置地址
            if (media) {
                libvlc_media_release(media);
            }
            media = libvlc_media_new_location(vlcInstance, streamAddress.toUtf8().constData());

            // 设置videoFrame3的mediaPlayer的媒体
            libvlc_media_player_set_media(mediaPlayer3, media);

            // 播放videoFrame3的mediaPlayer的媒体
            libvlc_media_player_play(mediaPlayer3);
        }
    }
}
void Widget::startStreaming4()
{
    if (lineEdit_4) {
        QString streamAddress = lineEdit_4->text();
        if (!streamAddress.isEmpty()) {
            // 创建新的媒体对象并设置地址
            if (media) {
                libvlc_media_release(media);
            }
            media = libvlc_media_new_location(vlcInstance, streamAddress.toUtf8().constData());

            // 设置videoFrame4的mediaPlayer的媒体
            libvlc_media_player_set_media(mediaPlayer4, media);

            // 播放videoFrame4的mediaPlayer的媒体
            libvlc_media_player_play(mediaPlayer4);
        }
    }
}
void Widget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QFrame* clickedFrame = NULL;

        if (videoFrame1->geometry().contains(event->pos()))
        {
            clickedFrame = videoFrame1;
        }
        else if (videoFrame2->geometry().contains(event->pos()))
        {
            clickedFrame = videoFrame2;
        }
        else if (videoFrame3->geometry().contains(event->pos()))
        {
            clickedFrame = videoFrame3;
        }
        else if (videoFrame4->geometry().contains(event->pos()))
        {
            clickedFrame = videoFrame4;
        }

        if (clickedFrame)
        {
            if (clickedFrame == enlargedFrame)
            {
                // 点击的是当前放大的 frame，缩小并恢复原始大小和位置
                if (clickedFrame == videoFrame1)
                {
                    clickedFrame->setGeometry(originalGeometry1);
                    libvlc_media_player_set_xwindow(mediaPlayer1, videoFrame1->winId()); // 重新设置媒体播放器的视窗
                }
                else if (clickedFrame == videoFrame2)
                {
                    clickedFrame->setGeometry(originalGeometry2);
                    libvlc_media_player_set_xwindow(mediaPlayer2, videoFrame2->winId()); // 重新设置媒体播放器的视窗
                }
                else if (clickedFrame == videoFrame3)
                {
                    clickedFrame->setGeometry(originalGeometry3);
                    libvlc_media_player_set_xwindow(mediaPlayer3, videoFrame3->winId()); // 重新设置媒体播放器的视窗
                }
                else if (clickedFrame == videoFrame4)
                {
                    clickedFrame->setGeometry(originalGeometry4);
                    libvlc_media_player_set_xwindow(mediaPlayer4, videoFrame4->winId()); // 重新设置媒体播放器的视窗
                }

                clickedFrame->raise();
                enlargedFrame = NULL;
            }
            else
            {
                // 点击的是未放大的 frame，放大并覆盖其他 frame
                if (enlargedFrame)
                {
                    if (enlargedFrame == videoFrame1)
                    {
                        enlargedFrame->setGeometry(originalGeometry1);
                        libvlc_media_player_set_xwindow(mediaPlayer1, videoFrame1->winId()); // 重新设置媒体播放器的视窗
                    }
                    else if (enlargedFrame == videoFrame2)
                    {
                        enlargedFrame->setGeometry(originalGeometry2);
                        libvlc_media_player_set_xwindow(mediaPlayer2, videoFrame2->winId()); // 重新设置媒体播放器的视窗
                    }
                    else if (enlargedFrame == videoFrame3)
                    {
                        enlargedFrame->setGeometry(originalGeometry3);
                        libvlc_media_player_set_xwindow(mediaPlayer3, videoFrame3->winId()); // 重新设置媒体播放器的视窗
                    }
                    else if (enlargedFrame == videoFrame4)
                    {
                        enlargedFrame->setGeometry(originalGeometry4);
                        libvlc_media_player_set_xwindow(mediaPlayer4, videoFrame4->winId()); // 重新设置媒体播放器的视窗
                    }
                }

                if (clickedFrame == videoFrame1)
                {
                    originalGeometry1 = clickedFrame->geometry();
                    clickedFrame->setGeometry(rect());
                    libvlc_media_player_set_xwindow(mediaPlayer1, NULL); // 设置媒体播放器的视窗为空
                }
                else if (clickedFrame == videoFrame2)
                {
                    originalGeometry2 = clickedFrame->geometry();
                    clickedFrame->setGeometry(rect());
                    libvlc_media_player_set_xwindow(mediaPlayer2, NULL); // 设置媒体播放器的视窗为空
                }
                else if (clickedFrame == videoFrame3)
                {
                    originalGeometry3 = clickedFrame->geometry();
                    clickedFrame->setGeometry(rect());
                    libvlc_media_player_set_xwindow(mediaPlayer3, NULL); // 设置媒体播放器的视窗为空
                }
                else if (clickedFrame == videoFrame4)
                {
                    originalGeometry4 = clickedFrame->geometry();
                    clickedFrame->setGeometry(rect());
                    libvlc_media_player_set_xwindow(mediaPlayer4, NULL); // 设置媒体播放器的视窗为空
                }

                clickedFrame->raise();
                enlargedFrame = clickedFrame;
            }
        }
    }

    // 调用父类的事件处理函数
    QWidget::mousePressEvent(event);
}
