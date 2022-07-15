#pragma once

#include <list>
#include <memory>
#include <stdexcept>
#include <functional>

#include "IEventHandler.hpp"
#include "SnakeInterface.hpp"
#include "SnakeWorld.hpp"
#include "SnakeSegments.hpp"

class Event;
class IPort;
class SnakeWorld;
class SnakeSegments;

namespace Snake
{
struct ConfigurationError : std::logic_error
{
    ConfigurationError();
};

struct UnexpectedEventException : std::runtime_error
{
    UnexpectedEventException();
};

class Controller : public IEventHandler
{
    friend class SnakeSegments;
public:
    Controller(IPort& p_displayPort, IPort& p_foodPort, IPort& p_scorePort, std::string const& p_config);

    Controller(Controller const& p_rhs) = delete;
    Controller& operator=(Controller const& p_rhs) = delete;

    void receive(std::unique_ptr<Event> e) override;

    
private:
    SnakeWorld m_snakeWorld;
    SnakeSegments m_snakeSegments;
    
    

    void handleTimeoutInd();
    void handleDirectionInd(std::unique_ptr<Event>);
    void handleFoodInd(std::unique_ptr<Event>);
    void handleFoodResp(std::unique_ptr<Event>);
    void handlePauseInd(std::unique_ptr<Event>);

    bool isSegmentAtPosition(int x, int y) const;
    SnakeSegments::Segment calculateNewHead() const;
    void updateSegmentsIfSuccessfullMove(SnakeSegments::Segment const& newHead);
    void addHeadSegment(SnakeSegments::Segment const& newHead);
    void removeTailSegmentIfNotScored(SnakeSegments::Segment const& newHead);
    void removeTailSegment();

    bool isPositionOutsideMap(int x, int y) const;

    void updateFoodPosition(int x, int y, std::function<void()> clearPolicy);
    void sendClearOldFood();
    void sendPlaceNewFood(int x, int y);

    bool m_paused;
};

} // namespace Snake
