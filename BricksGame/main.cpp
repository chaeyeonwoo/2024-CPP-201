#include <SFML/Graphics.hpp>
#include <vector>

// 공 클래스
class Ball {
public:
    sf::CircleShape shape;
    sf::Vector2f velocity;

    Ball(float radius = 10.0f) {
        shape.setRadius(radius);
        shape.setFillColor(sf::Color::White);
        shape.setOrigin(radius, radius);
        velocity = { -200.0f, -200.0f };
    }

    void update(float dt) {
        shape.move(velocity * dt);
    }
};

// 패들 클래스
class Paddle {
public:
    sf::RectangleShape shape;
    float speed;

    Paddle(float width = 100.0f, float height = 20.0f) {
        shape.setSize({ width, height });
        shape.setFillColor(sf::Color::White);
        shape.setOrigin(width / 2.0f, height / 2.0f);
        speed = 400.0f;
    }

    void update(float dt) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && shape.getPosition().x - shape.getSize().x / 2 > 0)
            shape.move(-speed * dt, 0.0f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && shape.getPosition().x + shape.getSize().x / 2 < 800)
            shape.move(speed * dt, 0.0f);
    }
};

// 벽돌 클래스
class Brick {
public:
    sf::RectangleShape shape;
    bool destroyed{ false };

    Brick(float x, float y, float width = 60.0f, float height = 20.0f) {
        shape.setSize({ width, height });
        shape.setFillColor(sf::Color::Red);
        shape.setOrigin(width / 2.0f, height / 2.0f);
        shape.setPosition(x, y);
    }
};

// 충돌 감지 함수
bool isIntersecting(const sf::RectangleShape& rect, const sf::CircleShape& circle) {
    float deltaX = circle.getPosition().x - std::max(rect.getPosition().x - rect.getSize().x / 2, std::min(circle.getPosition().x, rect.getPosition().x + rect.getSize().x / 2));
    float deltaY = circle.getPosition().y - std::max(rect.getPosition().y - rect.getSize().y / 2, std::min(circle.getPosition().y, rect.getPosition().y + rect.getSize().y / 2));
    return (deltaX * deltaX + deltaY * deltaY) < (circle.getRadius() * circle.getRadius());
}

// 게임 상태 업데이트 함수
void updateGame(Ball& ball, Paddle& paddle, std::vector<Brick>& bricks, float dt) {
    ball.update(dt);
    paddle.update(dt);

    // 벽에 충돌
    if (ball.shape.getPosition().x < ball.shape.getRadius() || ball.shape.getPosition().x > 800 - ball.shape.getRadius())
        ball.velocity.x = -ball.velocity.x;
    if (ball.shape.getPosition().y < ball.shape.getRadius())
        ball.velocity.y = -ball.velocity.y;

    // 바닥에 충돌 (게임 오버)
    if (ball.shape.getPosition().y > 600) {
        ball.shape.setPosition(400, 300);
        ball.velocity = { -200.0f, -200.0f };
    }

    // 패들에 충돌
    if (isIntersecting(paddle.shape, ball.shape))
        ball.velocity.y = -ball.velocity.y;

    // 벽돌에 충돌
    for (auto& brick : bricks) {
        if (!brick.destroyed && isIntersecting(brick.shape, ball.shape)) {
            brick.destroyed = true;
            ball.velocity.y = -ball.velocity.y;
        }
    }
}

// 게임 그리기 함수
void renderGame(sf::RenderWindow& window, Ball& ball, Paddle& paddle, std::vector<Brick>& bricks) {
    window.clear(sf::Color::Black);
    window.draw(ball.shape);
    window.draw(paddle.shape);
    for (auto& brick : bricks)
        if (!brick.destroyed)
            window.draw(brick.shape);
    window.display();
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Brick Breaker");
    window.setFramerateLimit(60);

    Ball ball;
    ball.shape.setPosition(400, 300);

    Paddle paddle;
    paddle.shape.setPosition(400, 550);

    std::vector<Brick> bricks;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 10; ++j)
            bricks.emplace_back((j + 1) * 70, (i + 1) * 30);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float dt = clock.restart().asSeconds();

        updateGame(ball, paddle, bricks, dt);
        renderGame(window, ball, paddle, bricks);
    }

    return 0;
}