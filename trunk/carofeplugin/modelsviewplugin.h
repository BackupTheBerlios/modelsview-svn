#ifndef MODELSVIEWPLUGIN_H
#define MODELSVIEWPLUGIN_H
#include <qstringlist.h>
#include <qstring.h>
#include "mvglwidget.h"
#include <qwidget.h>
#define MODELSVIEWPLUGIN_EXPORT(ARG)  ModelsViewPlugin * getMVPlugin(){ return new ARG();}

// Interface 3DModelsViewPlugin
 
class ModelsViewPlugin {
public:
 ModelsViewPlugin(){}
  virtual QStringList  keys () = 0;
  virtual  MVGLWidget*  create (QString key,QWidget * parent) = 0;
  virtual  ~ModelsViewPlugin(){}
};
extern "C"{
 ModelsViewPlugin * getMVPlugin();
}
#endif //MODELSVIEWPLUGIN_H

