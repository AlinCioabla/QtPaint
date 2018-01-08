#ifndef PAINTTEST_H
#define PAINTTEST_H

#include <QtGui/QtGui>
#include "ui_painttest.h"
#include "PaintView.h"
#include "PaintScene.h"
#include "SelectedTool.h"
#include <QtGui/qcolor.h>
#include <QtWidgets/QColorDialog>


class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow( QWidget *parent = 0, Qt::WindowFlags flags = 0 );



	~MainWindow();

public slots:
	void UpdateMousePos( QPointF );
	void onActionExitTriggered();
  
  void drawShape(QPointF, QPointF);
  void freeDraw(QPointF);

  void onPenSelect();
  void onRectangleSelect();
  void onEllipseSelect();
  void onLineSelect();

  void onColorSelection();

private:
  PaintView*			mView;
	PaintScene*			mScene;
  SelectedTool mTool;
  QColor mColor;
	Ui::PaintTestClass	ui;
  QActionGroup *mToolSelectionBarButtons;
  QColorDialog *mColorDialog;
  QPointF _initialPoint;
};

#endif // PAINTTEST_H
