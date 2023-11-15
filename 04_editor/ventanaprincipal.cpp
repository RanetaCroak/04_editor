#include "ventanaprincipal.h"
#include <QIcon>
#include <QToolBar>
#include <QMenuBar>
#include <QLabel>
#include <QComboBox>
#include <QStatusBar>


VentanaPrincipal::VentanaPrincipal (QWidget * parent) :
		 QMainWindow(parent) {
		 
		 editorCentral = new QTextEdit();
		 setCentralWidget(editorCentral);
		 
		 setWindowIcon(QIcon("./images/icono.png"));
		 resize (800,600);
			
		createActions();
		createMenus(); 
		
		documentoModificado = false;
 }
		 
		 
void VentanaPrincipal::createActions(){
				 accionSalir = new QAction("Salir");
				 accionSalir->setIcon(QIcon("./images/icono.png"));
				 accionSalir->setShortcut(QKeySequence("Ctrl+q"));
				 accionSalir->setStatusTip("Sal y vete a tomar por c..");
				 accionSalir->setToolTip("Sal y vete a tomar por c..");	
				 	 
				 connect(accionSalir,SIGNAL(triggered()),
				 				this,SLOT(close()));
				 				
				 accionAbrir = new QAction("Abrir");
				 accionAbrir->setIcon(QIcon("./images/iconoAbrir.png"));
				 accionAbrir->setShortcut(QKeySequence("Ctrln"));
				 accionAbrir->setStatusTip("Abre cosas");
				 accionAbrir->setToolTip("Esto sirve para abrir cosas");	
				 	 
				 connect(accionAbrir,SIGNAL(triggered()),
				 				this,SLOT(abrir()));
				 				
				 accionGuardar = new QAction("Guardar");
				 accionGuardar->setIcon(QIcon("./images/iconoGuardar.png"));
				 accionGuardar->setShortcut(QKeySequence("Ctrln"));
				 accionGuardar->setStatusTip("Guarda cosas");
				 accionGuardar->setToolTip("Esto sirve para guardar cosas");	
				 	 
				 connect(accionGuardar,SIGNAL(triggered()),
				 				this,SLOT(guardar()));
}

void VentanaPrincipal::createMenus(){
		menuArchivo = new QMenu("Archivo");
		menuArchivo->addAction(accionGuardar); 
		menuArchivo->addSeparator();
		menuArchivo->addAction(accionAbrir); 
		menuArchivo->addAction(accionSalir); 
		
	  menuBar()->addMenu(menuArchivo);
		

	QToolBar *barraPrincipal;
	barraPrincipal = addToolBar("Principal");
	barraPrincipal->addAction(accionAbrir); 
	barraPrincipal->addAction(accionGuardar); 
	barraPrincipal->addAction(accionSalir); 
}

void VentanaPrincipal::createContextMenu(){
	editorCentral->addAction(accionSalir);
	editorCentral->addAction(accionAbrir);
	editorCentral->addAction(accionGuardar);
	editorCentral->setContextMenuPolicy(Qt::ActionsContextMenu);
	}
	
void VentanaPrincipal::createStatusBar(){
		QLabel *etiqueta = new QLabel ("Editor listo");
		QComboBox *combo = new QComboBox();
		combo->addItem("1");
		combo->addItem("2");
		
		statusBar()->addWidget(etiqueta);
		statusBar()->addWidget(combo);
}

	// 
	QString ruta = QFileDialog::getOpenFileName(this, QString("Abrir archivo para editar"),
									QString("Ficheros de texto (*.txt)")
									);

	if(ruta.isEmpty())
		return;
		
	QFile fichero(ruta);
	
	if (! fichero.open(QIODevice::ReadOnly) )
		return;
	
	// Requerix un puntero	
	QTextStream stream(&fichero);
	
	QString linea;
	
	while( !stream.atEnd() ){
		linea = stream.readLine();
	}

	qDebug() << "El dialogo revulve " << ruta;

void VentanaPrincipal::slotAbrir(){
	etiquetaEstado->setText("Fichero Abierto")
	} 
void VentanaPrincipal::slotGuardar(){
	etiquetaEstado->setText("Fichero Guardado")
	} 

void VentanaPrincipal::slotNuevo(){
	if (!documentoModificado)
	editorCentral->clear();
}	

	respuesta = QMessageBox::warning(this,"Fichero Modificado", "¿Desea guardar?", QMessageBox::Ok | QMessageBox::Cancel );
	
	if (documentoModificado){
		
		respuesta = QMessageBox::warning(this, "Fichero Modificado", "Quieres continuar?", QMessageBox::Ok | QMessageBox::Cancel
		
		if (respuesta == QMessageBox::Ok){
			etiquetaEstado->setText("Fichero Abierto")
	}
	
	void VentanaPrincipal::closeEvent(QCLoseEvent * evento){
		int respuesta;
		
		QMessageBox::warning(this, "Me están cerrando!", "AAAAAaaaaaaa Seguro????", QMessageBox::Ok | QMessageBox::Cancel
		
		if (respuesta == QMessageBox::Ok){
			etiquetaEstado->setText("Cerrando...")
		
		if (respuesta == QMessageBox::Cancel){
			etiquetaEstado->setText("Nos quedamos pues...")
		
		// Ignorar el evento
			event->ignore()
		}
	}
	
	void VentanaPrincipal::ShowEvent(QShowEvent * evento){
		editorCentral->selectAll()
	} 
	
		 
		 
