#include "carofeplugin.h"
#include "modelsviewplugin.h"
CarofePlugin::CarofePlugin(){
 _keys<<"ASC";
}
QStringList  CarofePlugin::keys (){
	return _keys;
}
MVGLWidget*  CarofePlugin::create (QString key,QWidget * parent){
 if(key.find("ASC")!=-1){
  return new AscView(parent);
 }else{
  return NULL;
 }
}

CarofePlugin::~CarofePlugin(){}

MODELSVIEWPLUGIN_EXPORT(CarofePlugin)

