#include "MBrightnessBar.h"

const int BAR_WIDTH = 468;
const int BAR_HEIGHT = 24;
const int LEFT_MARGIN = 6;
const int TOP_MARGIN = 0;

const int ZONE1 = BAR_WIDTH / 4;
const int ZONE2 = ZONE1 + ZONE1; //(BAR_WIDTH / 4) * 2
const int ZONE3 = ZONE1 + ZONE2; //(BAR_WIDTH / 4) * 3

MBrightnessBar::MBrightnessBar(QGraphicsItem *parent):
    MWidget(parent)
{
    setMaximumWidth(BAR_WIDTH);
    setMinimumWidth(BAR_WIDTH);
    setMaximumHeight(BAR_HEIGHT);
    setMinimumHeight(BAR_HEIGHT);

    //bar background
    QPixmap *pix_background = new QPixmap(1,1);
    pix_background->fill(QColor(50,50,50));
    backgroundbar = new MImageWidget(pix_background, this);
    backgroundbar->setAspectRatioMode(Qt::IgnoreAspectRatio);
    backgroundbar->setGeometry(QRectF(LEFT_MARGIN,TOP_MARGIN,BAR_WIDTH,BAR_HEIGHT));

    //bar main
    pix_brightnessbar = QPixmap(1,1);
    brightnessbar = new MImageWidget(&pix_brightnessbar, this);
    brightnessbar->setAspectRatioMode(Qt::IgnoreAspectRatio);
    brightnessbar->setMaximumHeight(BAR_HEIGHT);
    brightnessbar->setMinimumHeight(BAR_HEIGHT);
    brightnessbar->setMinimumWidth(0);
    brightnessbar->setMaximumWidth(0);
    brightnessbar->setPos(LEFT_MARGIN,TOP_MARGIN);

    //color gconf
    m_bar_red =   new GConfItem("/desktop/meego/status_menu/brightness_slider/red", this);
    m_bar_green = new GConfItem("/desktop/meego/status_menu/brightness_slider/green", this);
    m_bar_blue =  new GConfItem("/desktop/meego/status_menu/brightness_slider/blue", this);
    if (m_bar_red->value().isNull())
        m_bar_red->set(255);
    if (m_bar_green->value().isNull())
        m_bar_green->set(127);
    if (m_bar_blue->value().isNull())
        m_bar_blue->set(0);
    connect(m_bar_red, SIGNAL(valueChanged()), this, SLOT(onRGBChanged()));
    connect(m_bar_green, SIGNAL(valueChanged()), this, SLOT(onRGBChanged()));
    connect(m_bar_blue, SIGNAL(valueChanged()), this, SLOT(onRGBChanged()));
    onRGBChanged();

    //round corners mask
    QImage *icon_background = new QImage("/usr/share/themes/blanco/meegotouch/icons/icon-brightness-alpha.png");
    MImageWidget *begin_round_corner = new MImageWidget(icon_background, this);
    begin_round_corner->setPos(LEFT_MARGIN,TOP_MARGIN);
    MImageWidget *end_round_corner = new MImageWidget(icon_background, this);
    end_round_corner->setPos(LEFT_MARGIN + BAR_WIDTH - 1,TOP_MARGIN);
    value_round_corner = new MImageWidget(icon_background, this);
    value_round_corner->setPos(-1,TOP_MARGIN);

    //system brightness gconf
    m_gconf_brightness = new GConfItem("/system/osso/dsm/display/display_brightness", this);
    connect(m_gconf_brightness, SIGNAL(valueChanged()), this, SLOT(onValueChanged()));
    onValueChanged();
}

MBrightnessBar::~MBrightnessBar()
{
}

void MBrightnessBar::setBarWidth(int width, bool isMove)
{
    //little hack to prevent bar blinking when moving finger at edges
    if (isMove && interval.elapsed() < 100)
        return;
    interval.restart();

    if (width > ZONE3)
        m_gconf_brightness->set(5);
    else if (width > ZONE2)
        m_gconf_brightness->set(4);
    else if (width > ZONE1)
        m_gconf_brightness->set(3);
    else if (isMove && width > 58)
        m_gconf_brightness->set(2);
    else if (isMove)
        m_gconf_brightness->set(1);
    else if (!isMove && m_gconf_brightness->value().toInt() == 1)
        m_gconf_brightness->set(2);
    else if (!isMove)
        m_gconf_brightness->set(1);
}

void MBrightnessBar::onValueChanged()
{
    int width = BAR_WIDTH * (m_gconf_brightness->value().toInt()-1) / 4;
    brightnessbar->setMinimumWidth(width);
    brightnessbar->setMaximumWidth(width);
    value_round_corner->setPos(LEFT_MARGIN + width - 1,TOP_MARGIN);
}

void MBrightnessBar::onRGBChanged()
{
    int red = m_bar_red->value().toInt();
    int green = m_bar_green->value().toInt();
    int blue = m_bar_blue->value().toInt();
    pix_brightnessbar.fill(QColor(red, green, blue));
    brightnessbar->setPixmap(pix_brightnessbar);
}
