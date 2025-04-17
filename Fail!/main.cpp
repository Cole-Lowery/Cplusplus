#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    Shape() {}
    virtual ~Shape() {}  // Made destructor virtual for proper cleanup
    virtual float Area() const = 0;  // Made pure virtual to enforce implementation
    virtual bool IsCircle() const { return false; }  // Added type check method
};

class Circle : public Shape {
public:
    Circle(float r) { m_radius = r; }
    ~Circle() override {}
    float Area() const override {
        return 3.14f * m_radius * m_radius;
    }
    void SetRadius(float radius) { m_radius = radius; }
    float GetRadius() const { return m_radius; }
    bool IsCircle() const override { return true; }
private:
    float m_radius;
};

class Rectangle : public Shape {
public:
    Rectangle(float w, float h) {
        m_width = w;
        m_height = h;
    }
    float Area() const override {  // Fixed method name from Areas to Area
        return m_width * m_height;
    }
private:
    float m_width;
    float m_height;
};

int main() {
    vector<Shape*> shapes;
    Circle c(1.0f);
    c.SetRadius(3.0f);
    Rectangle* r = new Rectangle(4.0f, 5.0f);
    shapes.push_back(&c);
    shapes.push_back(r);

    for (size_t i = 0; i < shapes.size(); i++) {
        cout << "Area: " << shapes[i]->Area() << endl;
        

        if (shapes[i]->IsCircle()) {
            const Circle* circle = static_cast<const Circle*>(shapes[i]);
            cout << "Radius: " << circle->GetRadius() << endl;
        }
    }

    delete r;
    shapes.clear();
    
    return 0;
}