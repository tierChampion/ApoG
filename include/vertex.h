#pragma once

#include <iostream>
#include <cstdint>

class Vertex
{
public:
    Vertex();
    Vertex(float x, float y);
    Vertex(const int &i);
    ~Vertex();

    float getX() const { return _x; }
    float getY() const { return _y; }
    uint64_t getId() const { return _id; }

    bool operator<(const Vertex &vert) const;

    bool operator==(const Vertex &vert) const;
    bool operator!=(const Vertex &vert) const;

    friend std::ostream &operator<<(std::ostream &os, const Vertex &vert);

private:
    const uint64_t _id;
    float _x;
    float _y;

    static uint64_t _vertexCount;
};

namespace std
{
    template <>
    struct hash<Vertex>
    {
        size_t operator()(const Vertex &vert) const
        {
            return std::hash<uint64_t>()(vert.getId());
        }
    };
}
