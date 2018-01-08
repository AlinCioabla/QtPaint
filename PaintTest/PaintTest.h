#ifndef PAINTTEST_H
#define PAINTTEST_H

#include "EllipseTool.h"
#include "PaintScene.h"
#include "PaintView.h"
#include "SelectedTool.h"
#include "Tool.h"
#include "ui_painttest.h"
#include <QtGui/QtGui>
#include <QtGui/qcolor.h>
#include <QtWidgets/QColorDialog>
#include <QtWidgets/QGraphicsItem>

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = 0, Qt::WindowFlags flags = 0);



  ~MainWindow();

  public slots:
  void UpdateMousePos(QPointF);
  void onActionExitTriggered();

  void drawShape(QPointF, QPointF);
  void freeDraw(QPointF);
  void previewShape(QPointF, QPointF);

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
  QGraphicsItem *previewedShape = nullptr;
  Tool * currentTool;

};

#endif // PAINTTEST_H
