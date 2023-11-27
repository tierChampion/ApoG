#include "vertex.h"

uint64_t Vertex::_vertexCount = 0;

Vertex::Vertex()
    : _x(0), _y(0), _id(Vertex::_vertexCount)
{
    ++_vertexCount;
}

Vertex::Vertex(float x, float y)
    : _x(x), _y(y), _id(Vertex::_vertexCount)
{
    ++_vertexCount;
}

Vertex::~Vertex()
{
    --_vertexCount;
}

bool Vertex::operator<(const Vertex &vert) const
{
    return _id < vert._id;
}

bool Vertex::operator==(const Vertex &vert) const
{
    return _id == vert._id;
}

bool Vertex::operator!=(const Vertex &vert) const
{
    return _id != vert._id;
}

std::ostream &operator<<(std::ostream &os, const Vertex &vert)
{
    return os << "Vertex {" << vert._id << "} (" << vert._x << ", " << vert._y << ")";
}
