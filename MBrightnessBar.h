#ifndef MBrightnessBar_H
#define MBrightnessBar_H

#include <MWidget>
#include <MImageWidget>

#include <MLabel>
#include <QGraphicsSceneMouseEvent>

#include <gq/GConfItem>
#include <QTime>

#include <QFile>
#include <QFileSystemWatcher>
#include <QTextStream>

class MBrightnessBar : public MWidget
{
    Q_OBJECT

protected:
    void enterDisplayEvent();

public:
    explicit MBrightnessBar(QGraphicsItem *parent = 0);
    virtual ~MBrightnessBar();

    void setBarWidth(int width, bool isMove);
    void switchHacky();

private:
    int getHackyBrightness();

    MImageWidget *backgroundbar;
    MImageWidget *brightnessbar;
    MImageWidget *value_round_corner;
    GConfItem *m_gconf_brightness;

    GConfItem *m_bar_red;
    GConfItem *m_bar_green;
    GConfItem *m_bar_blue;

    GConfItem *m_hacky_red;
    GConfItem *m_hacky_green;
    GConfItem *m_hacky_blue;

    QTime interval;
    QPixmap pix_brightnessbar;

    GConfItem *als_enabled;
    GConfItem *sys_brightness;

    QFileSystemWatcher *fs;

    bool hacky_enabled;

private slots:
    void onValueChanged();
    void onRGBChanged();
    void onAlsChanged();
    void sysBrightnessChanged(QString);

};

#endif // MBrightnessBar_H
