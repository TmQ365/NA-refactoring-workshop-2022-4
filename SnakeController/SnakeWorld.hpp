#pragma once
#include "SnakeController.hpp"
#include "IPort.hpp"
namespace Snake{
class SnakeWorld{

public:
    SnakeWorld(IPort& displayPort, IPort& foodPort, IPort& scorePort): 
    m_displayPort(displayPort), m_foodPort(foodPort), m_scorePort(scorePort){}
    
    int getScore;
    IPort& m_displayPort;
    IPort& m_foodPort;
    IPort& m_scorePort;

    std::pair<int, int> m_mapDimension;
    std::pair<int, int> m_foodPosition;
    

};
}