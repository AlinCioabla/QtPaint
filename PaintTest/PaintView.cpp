#include "PaintView.h";
#include <QtGui/QMouseEvent>
#include <QtCore/qdebug.h>

PaintView::PaintView( QWidget* parent ):QGraphicsView( parent )
{
	setMouseTracking( true );
}


PaintView::~PaintView()
{
}

bool PaintView::mousePressed()
{
  return isMousePressed;
}


void	PaintView::mouseMoveEvent( QMouseEvent* event) 
{
  if(mousePressed())
    emit freeDraw(mapToScene(event->pos()));
	emit UpdateMousePos( mapToScene( event->pos() ) );
  //if (mousePressed())
  // signal preview painting

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
  emit drawShape(mousePressedPos, mouseReleasedPos);
  //signal draw previewed paiting
}
