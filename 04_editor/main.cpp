#include <QApplication>
#include "ventanaprincipal.h"

int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
  	  VentanaPrincipal * editor = new VentanaPrincipal();
  	  editor->show();
  	     
/*     QWidget *window = new QWidget;
     window->show();*/
     
     return app.exec();
 }
