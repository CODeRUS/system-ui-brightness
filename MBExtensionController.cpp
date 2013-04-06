#include "MBExtensionController.h"
#include <MLocale>
#include <QGraphicsLinearLayout>

MBExtensionsController::MBExtensionsController(MBExtensionsPlugin *extensionsPlugin,
                                               QGraphicsItem *parent) :
    MWidget(parent),
    m_extensionsPlugin(extensionsPlugin)
{
    setObjectName("StatusIndicatorMenuExtensionContentItem");

    setMinimumHeight(72);
    setMaximumHeight(72);

    grabGesture(Qt::TapAndHoldGesture);

    MLocale locale;
    locale.installTrCatalog("settings");
    MLocale::setDefault(locale);

    QGraphicsLinearLayout *layout = new QGraphicsLinearLayout(Qt::Vertical, this);
    layout->setContentsMargins(0,0,0,8);
    layout->setSpacing(8);
    a_label = new MBrightnessLabel(this);
    layout->addItem(a_label);
    a_brightness = new MBrightnessBar(this);
    layout->addItem(a_brightness);
}

MBExtensionsController::~MBExtensionsController()
{
}

bool MBExtensionsController::event(QEvent *event)
{
    if (event->type() == QEvent::Gesture)
    {
        if (static_cast<QGestureEvent*>(event)->gesture(Qt::TapAndHoldGesture)->state() == Qt::GestureFinished)
        {
            MFeedback("priority2_grab", this).play();
            a_brightness->switchHacky();
        }
    }
    else
        return MWidget::event(event);
}

void MBExtensionsController::mousePressEvent(QGraphicsSceneMouseEvent *ev)
{
    a_brightness->setBarWidth(ev->pos().x(), false);
}

void MBExtensionsController::mouseMoveEvent(QGraphicsSceneMouseEvent *ev)
{
    a_brightness->setBarWidth(ev->pos().x(), true);
}
