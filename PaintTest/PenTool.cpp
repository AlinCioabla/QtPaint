#include "PenTool.h"

PenTool::PenTool(QObject *parent, PaintScene * scene)
  : Tool(parent, scene)
{
}

QGraphicsItem* PenTool::drawShape(QPointF start, QPointF end)
{
  return nullptr;
}

PenTool::~PenTool()
{
}


