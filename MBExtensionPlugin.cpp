#include "MBExtensionPlugin.h"
#include "MBExtensionController.h"

Q_EXPORT_PLUGIN2(brightnessapplet, MBExtensionsPlugin)

MBExtensionsPlugin::MBExtensionsPlugin(QObject *parent) :
    statusIndicatorMenu(0),
    m_extensionsController(0)
{
    Q_UNUSED(parent)
}

void MBExtensionsPlugin::setStatusIndicatorMenuInterface(MStatusIndicatorMenuInterface &menuInterface)
{
    statusIndicatorMenu = &menuInterface;
}

MStatusIndicatorMenuInterface *MBExtensionsPlugin::statusIndicatorMenuInterface() const
{
    return statusIndicatorMenu;
}

bool MBExtensionsPlugin::initialize(const QString &)
{
    m_extensionsController = new MBExtensionsController(this);

    return true;
}

QGraphicsWidget *MBExtensionsPlugin::widget()
{
    return m_extensionsController;
}
