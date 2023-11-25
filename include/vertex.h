#pragma once

#include <iostream>

class Vertex
{
public:
    Vertex();
    Vertex(float x, float y);

    friend std::ostream& operator<<(std::ostream& os, const Vertex& vert);

private:
    float _x;
    float _y;
};
