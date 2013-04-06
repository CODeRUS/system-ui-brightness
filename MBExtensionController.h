#ifndef APPLICATIONEXTENSIONCONTROLLER_H
#define APPLICATIONEXTENSIONCONTROLLER_H

#include <MWidget>
#include <MLayout>
#include <MLinearLayoutPolicy>

#include <QObject>

#include <MFeedback>
#include <QGesture>
#include <QTapAndHoldGesture>

#include "MBExtensionPlugin.h"
#include "MBrightnessBar.h"
#include "MBrightnessLabel.h"

class MStatusIndicatorMenuInterface;

class MBExtensionsController : public MWidget
{
    Q_OBJECT

public:
    explicit MBExtensionsController(MBExtensionsPlugin *extensionsPlugin, QGraphicsItem *parent = NULL);
    virtual ~MBExtensionsController(); 

protected:
    bool event(QEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *ev);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *ev);

private:
    MLayout *m_layout;
    MLinearLayoutPolicy *m_mainLayout;

    MBExtensionsPlugin *m_extensionsPlugin;
    MBrightnessBar *a_brightness;
    MBrightnessLabel *a_label;
};

#endif // APPLICATIONEXTENSIONCONTROLLER_H
