#include "PainterView.h";


PainterView::PainterView(QWidget* parent):QGraphicsView(parent)
{
	setMouseTracking(true);
}


PainterView::~PainterView()
{
}


void	PainterView::mouseMoveEvent( QMouseEvent* event) 
{
	
	emit updateMousePos(mapToScene(event->pos()));
}