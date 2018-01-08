#pragma once
#include <QtGui>

class PainterView :
	public QGraphicsView
{
	Q_OBJECT

protected:
	virtual	void		mouseMoveEvent( QMouseEvent* );

private:
Q_SIGNALS:
	void updateMousePos(QPointF);

public:
	PainterView(QWidget*);
	virtual	~PainterView();
};

