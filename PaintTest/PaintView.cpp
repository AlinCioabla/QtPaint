#include "PaintView.h";
#include <QtCore/qdebug.h>
#include <QtGui/QMouseEvent>

PaintView::PaintView(QWidget* parent) :QGraphicsView(parent)
{
  setMouseTracking(true);
}


PaintView::~PaintView()
{
}

bool PaintView::mousePressed()
{
  return isMousePressed;
}


void	PaintView::mouseMoveEvent(QMouseEvent* event)
{
  QPointF currentMousePos = mapToScene(event->pos());
  emit UpdateMousePos(currentMousePos);

  if (mousePressed())
  {
    emit previewShape(mousePressedPos, currentMousePos);
  }

}
void PaintView::mousePressEvent(QMouseEvent * event)
{
  mousePressedPos = mapToScene(event->pos());
  isMousePressed = true;

}

void PaintView::mouseReleaseEvent(QMouseEvent * event)
{
  mouseReleasedPos = mapToScene(event->pos());
  isMousePressed = false;
  emit drawShape();
  //signal draw previewed paiting
}

// view only updates mouse current pos