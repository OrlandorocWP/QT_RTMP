#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QFrame>
#include <vlc/vlc.h>
#include <QMouseEvent>
#include<QDebug>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void startStreaming2();
    void startStreaming3();
    void startStreaming4();

private:
    Ui::Widget *ui;
    QLineEdit* lineEdit_2;
    QLineEdit* lineEdit_3;
    QLineEdit* lineEdit_4;
    QPushButton* pushButton_2;
    QPushButton* pushButton_3;
    QPushButton* pushButton_4;
    QFrame* videoFrame1;
    QFrame* videoFrame2;
    QFrame* videoFrame3;
    QFrame* videoFrame4;
    libvlc_instance_t* vlcInstance;
    libvlc_media_player_t* mediaPlayer1;  // 添加第1个mediaPlayer
    libvlc_media_player_t* mediaPlayer2;  // 添加第2个mediaPlayer
    libvlc_media_player_t* mediaPlayer3;  // 添加第3个mediaPlayer
    libvlc_media_player_t* mediaPlayer4;  // 添加第4个mediaPlayer
    libvlc_media_t* media;
protected:
    void mousePressEvent(QMouseEvent *event) override;
private:
    QFrame* enlargedFrame;
    bool isFrame1Enlarged;
    bool isFrame2Enlarged;
    bool isFrame3Enlarged;
    bool isFrame4Enlarged;
    QRect originalGeometry1;
    QRect originalGeometry2;
    QRect originalGeometry3;
    QRect originalGeometry4;



};

#endif // WIDGET_H
