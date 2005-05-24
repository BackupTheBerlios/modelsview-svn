#include <qdir.h>
#include <qapplication.h>
#include <qstringlist.h>
#include <qstring.h>
#include "pluginloader.h"

bool PluginLoader::loadAll(QString from){
 QDir dir(from);
 QStringList listfile;
  listfile = dir.entryList("*.*");
#ifdef MYDEBUG
 qDebug(from.latin1());
#endif 
 for(int i = 2; i<listfile.size();i++){
#ifdef MYDEBUG
  qDebug("Pillo ficheros");
  qDebug(listfile[i].latin1());
#endif
  QLibrary * lib = new QLibrary(dir.path()+QString("/")+listfile[i]);
  if(lib->load()){ 
    _pluginlist.push_back(lib);
   #ifdef MYDEBUG
    qDebug("Se añadio a la lista de plugins");
   #endif
  }
 }
 
 
 for(int i=0;i<_pluginlist.size();i++){
  getPluginType getP = (getPluginType)_pluginlist[i]->resolve("getMVPlugin");
  if(getP){
   ModelsViewPlugin * modv = NULL;
   modv = getP();
   if(modv){
    _viewerlist.push_back(modv);
    QStringList l = modv->keys();
    for(int j = 0 ; j<l.size();j++)
     if(_keys.findIndex(l[j])==-1) _keys<<l[j];
   }
   #ifdef MYDEBUG
    else    qDebug("En Plugin no se cargo nada");
   #endif
   
  }
 }
 return true;
 
}
 MVGLWidget * PluginLoader::create(QString key,QWidget* parent){
    if(_keys.findIndex(key)!=-1){
       int i=0;
       while(_viewerlist[i]->keys().findIndex(key)==-1)i++;
       return _viewerlist[i]->create(key,parent);
       
    }else return NULL;
 }
 QStringList PluginLoader::keys(){
  return _keys;
 }
 
 PluginLoader::PluginLoader(){
 }
PluginLoader::~PluginLoader(){
 if(!_viewerlist.empty())
  for(int i = 0; i< _viewerlist.size();i++) delete _viewerlist[i];
 if(!_pluginlist.empty())
  for(int i = 0; i< _pluginlist.size();i++) delete _pluginlist[i];
}
