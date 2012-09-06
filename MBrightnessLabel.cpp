#include "MBrightnessLabel.h"

MBrightnessLabel::MBrightnessLabel(QGraphicsItem *parent):
    MLabel(qtTrId("qtn_sett_main_brightness"), parent)
{
    setMaximumHeight(22);
    setColor(QColor(255,255,255));
    QFont myfont = font();
    myfont.setPixelSize(22);
    setFont(myfont);
}
