#include "EllipseTool.h"

EllipseTool::EllipseTool(QObject *parent, PaintScene * scene)
  : Tool(parent, scene)
{
}

QGraphicsItem* EllipseTool::drawShape(QPointF start, QPointF end)
{
  return mScene->addEllipse(QRectF(start, end));
}

EllipseTool::~EllipseTool()
{
}
