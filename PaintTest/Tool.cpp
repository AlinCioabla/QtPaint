#include "Tool.h"

Tool::Tool(QObject *parent, PaintScene * scene)
  : QObject(parent)
{
  mScene = scene;
}

Tool::~Tool()
{
}
