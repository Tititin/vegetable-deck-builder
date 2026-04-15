#pragma once

#include <SFML/Graphics.hpp>
#include <functional>
#include "lib/Params.hpp"
#include "lib/Enums.hpp"

class Clickable {
public:
    //Callbacks
    using ClickCallback = std::function<void(Clickable&)>;
    using ClickReleaseCallback = std::function<void(Clickable&)>;

    enum class ClickState {
        NONE,
        PRESSED
    };

    Clickable() {};

    virtual ~Clickable() = default;
    virtual void handleEvent(const sf::Event& event, const sf::RenderWindow& window) = 0;
    virtual void init() = 0;

    virtual ClickState getClickState() const { return _clickState; }
    virtual void setClickState(ClickState state) { _clickState = state; }

    virtual ClickCallback getOnClick() const { return _onClick; }
    virtual ClickCallback getOnClickRelease() const { return _onClickRelease; }
    virtual ClickCallback getOnDoubleClick() const { return _onDoubleClick; }
    virtual bool isClicked() const { return _isClicked; }
    virtual bool contains(const sf::Vector2f& point) = 0;

    virtual void click(MouseClickState clickState) = 0;

protected:
    ClickCallback _onClick;
    ClickCallback _onClickRelease;
    ClickCallback _onDoubleClick;

    bool            _isClicked = false;

    ClickState      _clickState = ClickState::NONE;
};