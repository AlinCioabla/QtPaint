#include "PaintTest.h"


MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags)
  : QMainWindow(parent, flags)
{

  ui.setupUi(this);
  mView = new PaintView(this);
  mScene = new PaintScene(this);
  mColorDialog = new QColorDialog(this);


  mScene->setSceneRect(QRectF(0, 0, 2000, 2000));

  mView->setScene(mScene);
  setCentralWidget(mView);

  mTool = SelectedTool::ePen;
  ui.selectionPen->setChecked(true);

  currentTool = new EllipseTool(this, mScene);

  mToolSelectionBarButtons = new QActionGroup(this);
  mToolSelectionBarButtons->addAction(ui.selectionPen);
  mToolSelectionBarButtons->addAction(ui.selectionLine);
  mToolSelectionBarButtons->addAction(ui.selectionRectangle);
  mToolSelectionBarButtons->addAction(ui.selectionEllipse);
  mToolSelectionBarButtons->setExclusive(true);

  connect(mView, SIGNAL(UpdateMousePos(QPointF)), this, SLOT(UpdateMousePos(QPointF)));

  connect(ui.selectionLine, &QAction::triggered, this, &MainWindow::onLineSelect);
  connect(ui.selectionPen, &QAction::triggered, this, &MainWindow::onPenSelect);
  connect(ui.selectionEllipse, &QAction::triggered, this, &MainWindow::onEllipseSelect);
  connect(ui.selectionRectangle, &QAction::triggered, this, &MainWindow::onRectangleSelect);
  connect(ui.selectionColor, &QAction::triggered, this, &MainWindow::onColorSelection);

  connect(mView, SIGNAL(drawShape(QPointF, QPointF)), this, SLOT(drawShape(QPointF, QPointF)));
  connect(mView, SIGNAL(freeDraw(QPointF)), this, SLOT(freeDraw(QPointF)));
  connect(mView, SIGNAL(previewShape(QPointF, QPointF)), this, SLOT(previewShape(QPointF, QPointF)));


  mView->show();

}


MainWindow::~MainWindow()
{
  delete mScene;
  delete mView;
}

void MainWindow::onActionExitTriggered()
{
  close();
}

void MainWindow::drawShape(QPointF start, QPointF end)
{
  switch (mTool)
  {
  case SelectedTool::ePen:
    break;
  case SelectedTool::eEllipse:
    previewedShape = mScene->addEllipse(QRectF(start, end), QPen(mColor));
    break;
  case SelectedTool::eLine:
    previewedShape = mScene->addLine(start.x(), start.y(), end.x(), end.y(), QPen(mColor));
    break;
  case SelectedTool::eRectangle:
    previewedShape = mScene->addRect(QRectF(start, end), QPen(mColor));
  }
}

void MainWindow::freeDraw(QPointF currentPos)
{
  if (mTool == SelectedTool::ePen)
  {

    mScene->addLine(_initialPoint.x(), _initialPoint.y(), currentPos.x(), currentPos.y(), QPen(mColor));
  }
  _initialPoint = currentPos;
}

void MainWindow::previewShape(QPointF start, QPointF end)
{
  switch (mTool)
  {
  case SelectedTool::ePen:
    break;
  case SelectedTool::eEllipse:
    if (previewedShape)
      delete previewedShape;
    previewedShape = currentTool->drawShape(start, end);//mScene->addEllipse(QRectF(start, end), QPen(mColor));
    break;
  case SelectedTool::eLine:
    delete previewedShape;
    previewedShape = mScene->addLine(start.x(), start.y(), end.x(), end.y(), QPen(mColor));
    break;
  case SelectedTool::eRectangle:
    delete previewedShape;
    previewedShape = mScene->addRect(QRectF(start, end), QPen(mColor));
  }
}

void MainWindow::onPenSelect()
{
  mTool = SelectedTool::ePen;
}

void MainWindow::onRectangleSelect()
{
  mTool = SelectedTool::eRectangle;
}

void MainWindow::onEllipseSelect()
{
  mTool = SelectedTool::eEllipse;
}

void MainWindow::onLineSelect()
{
  mTool = SelectedTool::eLine;
}

void MainWindow::onColorSelection()
{
  int r = mColorDialog->exec();
  if (r == QDialog::Accepted)
  {
    mColor = mColorDialog->selectedColor();
  }

}


void MainWindow::UpdateMousePos(QPointF point)
{
  QString msg;
  msg.sprintf("%2.0fx%2.0f", point.x(), point.y());
  statusBar()->showMessage(msg);
}