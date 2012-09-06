#include "MBExtensionController.h"
#include <MLocale>
#include <QGraphicsLinearLayout>

MBExtensionsController::MBExtensionsController(MBExtensionsPlugin *extensionsPlugin,
                                               QGraphicsItem *parent) :
    MWidget(parent),
    m_extensionsPlugin(extensionsPlugin)
{
    setObjectName("StatusIndicatorMenuExtensionContentItem");

    MLocale locale;
    locale.installTrCatalog("settings");
    MLocale::setDefault(locale);

    QGraphicsLinearLayout *layout = new QGraphicsLinearLayout(Qt::Vertical, this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(8);
    a_label = new MBrightnessLabel(this);
    layout->addItem(a_label);
    a_brightness = new MBrightnessBar(this);
    layout->addItem(a_brightness);
}

MBExtensionsController::~MBExtensionsController()
{
}

void MBExtensionsController::mousePressEvent(QGraphicsSceneMouseEvent *ev)
{
    a_brightness->setBarWidth(ev->pos().x(), false);
}

void MBExtensionsController::mouseMoveEvent(QGraphicsSceneMouseEvent *ev)
{
    a_brightness->setBarWidth(ev->pos().x(), true);
}
