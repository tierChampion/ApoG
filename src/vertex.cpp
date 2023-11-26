#include "vertex.h"

Vertex::Vertex()
    : _x(0), _y(0)
{
}

Vertex::Vertex(float x, float y)
    : _x(x), _y(y)
{
}

std::ostream &operator<<(std::ostream &os, const Vertex &vert)
{
    return os << "Vertex (" << vert._x  << ", " << vert._y << ")";
}
