#include "modelsviewplugin.h"
#include "ascview.h"
#include "dsview.h"

class CarofePlugin: public ModelsViewPlugin {
public:
  CarofePlugin();
  QStringList  keys ();
  MVGLWidget*  create (QString key,QWidget * parent);
  virtual ~CarofePlugin();
private:
  QStringList _keys;
  
}; 
