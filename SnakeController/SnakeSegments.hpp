#pragma once
#include "SnakeInterface.hpp"
#include "SnakeController.hpp"


    namespace Snake{
        namespace{
bool isHorizontal(Direction direction)
{
    return Direction_LEFT == direction or Direction_RIGHT == direction;
}

bool isVertical(Direction direction)
{
    return Direction_UP == direction or Direction_DOWN == direction;
}

bool isPositive(Direction direction)
{
    return (isVertical(direction) and Direction_DOWN == direction)
        or (isHorizontal(direction) and Direction_RIGHT == direction);
}

bool perpendicular(Direction dir1, Direction dir2)
{
    return isHorizontal(dir1) == isVertical(dir2);
}
        }

class SnakeSegments{

    
    public:

    SnakeSegments():length(0){} 

    int getLength(){return length;}

    void setDirection(Snake::Direction d){
        m_currentDirection = d;
    }
    struct Segment
    {
        int x;
        int y;
    };
    Segment calculateNewHead() const{
        
        Segment const& currentHead = m_segments.front();

        Segment newHead;
        newHead.x = currentHead.x + (isHorizontal(m_currentDirection) ? isPositive(m_currentDirection) ? 1 : -1 : 0);
        newHead.y = currentHead.y + (isVertical(m_currentDirection) ? isPositive(m_currentDirection) ? 1 : -1 : 0);

        return newHead;
    }
    void setSegment(int newX, int newY){
        Segment seg{newX,newY};
        m_segments.push_back(seg);
    }
    std::list<Segment> m_segments;
    Direction m_currentDirection;
    int length;

};
    }
//namespace Snake