#ifndef MBRIGHTNESSLABEL_H
#define MBRIGHTNESSLABEL_H

#include <MLabel>
#include <QFont>

class MBrightnessLabel: public MLabel
{
    Q_OBJECT

public:
    explicit MBrightnessLabel(QGraphicsItem *parent = 0);
};

#endif // MBRIGHTNESSLABEL_H
