#ifndef MBrightnessBar_H
#define MBrightnessBar_H

#include <MWidget>
#include <MImageWidget>

#include <MLabel>
#include <QGraphicsSceneMouseEvent>

#include <gq/GConfItem>
#include <QTime>

class MBrightnessBar : public MWidget
{
    Q_OBJECT

public:
    explicit MBrightnessBar(QGraphicsItem *parent = 0);
    virtual ~MBrightnessBar();

    void setBarWidth(int width, bool isMove);

private:
    MImageWidget *backgroundbar;
    MImageWidget *brightnessbar;
    MImageWidget *value_round_corner;
    GConfItem *m_gconf_brightness;

    GConfItem *m_bar_red;
    GConfItem *m_bar_green;
    GConfItem *m_bar_blue;

    QTime interval;
    QPixmap pix_brightnessbar;

private slots:
    void onValueChanged();
    void onRGBChanged();

};

#endif // MBrightnessBar_H
