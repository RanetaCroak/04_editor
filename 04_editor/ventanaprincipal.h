#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QAction>
#include <QCloseEvent>
#include <QFileDialog>

class VentanaPrincipal : public QMainWindow {
Q_OBJECT

public:
	VentanaPrincipal(QWidget * parent = NULL);

	QTextEdit * editorCentral;
	QMenu *menuArchivo;
	QAction *accionSalir;
	QAction *accionGuardar;
	QAction *accionAbrir;
	
	void createActions();
	void createMenus();
	void createContextMenu();
	void createStatusBar();
	void ShowEvent(QShowEvent*);
	
	bool documentoModificado;
	

public slots:
	void slotAbrir();
	void slotGuardar();
	void slotNuevo();
	void slotEliminar();

};


#endif
