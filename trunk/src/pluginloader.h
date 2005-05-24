#ifndef PLUGINLOADER_H
#define PLUGINLOADER_H 
#include "modelsviewplugin.h"
#include "mvglwidget.h"
#include <qstring.h>
#include <qstringlist.h>
#include <qlibrary.h>
#include <qvaluevector.h>
typedef ModelsViewPlugin * (*getPluginType)();
class PluginLoader{
public:
PluginLoader();
~PluginLoader();
 bool loadAll(QString);
 MVGLWidget * create(QString,QWidget*);
 QStringList keys();
private:
 QValueVector<QLibrary*> _pluginlist;
 QValueVector<ModelsViewPlugin*> _viewerlist;
 QStringList _keys;
 
};
#endif
