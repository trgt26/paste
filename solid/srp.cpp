// No SRP

#include <iostream>
#include <string>

// Problematic design: Violates SRP
class Rectangle {
public:
    double width;
    double height;

    Rectangle(double w, double h) : width(w), height(h) {}

    // Responsibility 1: Calculate Area
    double calculateArea() const {
        return width * height;
    }

    // Responsibility 2: Draw the rectangle (e.g., to console)
    void draw() const {
        std::cout << "Drawing a Rectangle with width " << width << " and height " << height << ":" << std::endl;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                std::cout << "* ";
            }
            std::cout << std::endl;
        }
    }

    // Responsibility 3: Save to a simple text format (hypothetical)
    void saveToFile(const std::string& filename) const {
        std::cout << "Saving Rectangle to " << filename << std::endl;
        // In a real scenario, this would write to a file
        // For simplicity, just printing to console
        std::cout << "Width: " << width << ", Height: " << height << std::endl;
    }
};

int main() {
    Rectangle rect(5, 3);

    std::cout << "Area: " << rect.calculateArea() << std::endl;
    rect.draw();
    rect.saveToFile("rectangle_data.txt");

    return 0;
}

// SRP Compatible

#include <iostream>
#include <string>
#include <fstream> // For file operations

// Responsibility 1: Geometric properties and calculations
class Rectangle {
public:
    double width;
    double height;

    Rectangle(double w, double h) : width(w), height(h) {}

    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

// Responsibility 2: Area Calculation (could be a free function or a dedicated calculator class)
class ShapeCalculator {
public:
    static double calculateArea(const Rectangle& rect) {
        return rect.getWidth() * rect.getHeight();
    }

    // You could add other shape calculations here later
    // static double calculatePerimeter(const Rectangle& rect) { ... }
};

// Responsibility 3: Drawing/Rendering
class RectangleConsoleDrawer {
public:
    static void draw(const Rectangle& rect) {
        std::cout << "Drawing a Rectangle with width " << rect.getWidth() << " and height " << rect.getHeight() << ":" << std::endl;
        for (int i = 0; i < rect.getHeight(); ++i) {
            for (int j = 0; j < rect.getWidth(); ++j) {
                std::cout << "* ";
            }
            std::cout << std::endl;
        }
    }
};

// Responsibility 4: Persistence/Saving
class RectangleFileSaver {
public:
    static void saveToFile(const Rectangle& rect, const std::string& filename) {
        std::cout << "Saving Rectangle to " << filename << std::endl;
        std::ofstream outFile(filename);
        if (outFile.is_open()) {
            outFile << "Width: " << rect.getWidth() << std::endl;
            outFile << "Height: " << rect.getHeight() << std::endl;
            outFile.close();
            std::cout << "Successfully saved." << std::endl;
        } else {
            std::cerr << "Error: Could not open file " << filename << std::endl;
        }
    }
};

int main() {
    Rectangle rect(5, 3);

    // Calculate Area
    std::cout << "Area: " << ShapeCalculator::calculateArea(rect) << std::endl;

    // Draw
    RectangleConsoleDrawer::draw(rect);

    // Save
    RectangleFileSaver::saveToFile(rect, "rectangle_data.txt");

    // Example with a square (which is a type of rectangle)
    // You could have a Square class that inherits from Rectangle,
    // or just use Rectangle with equal sides.
    Rectangle square(4, 4);
    std::cout << "\n--- Square Example ---" << std::endl;
    std::cout << "Area of square: " << ShapeCalculator::calculateArea(square) << std::endl;
    RectangleConsoleDrawer::draw(square);
    RectangleFileSaver::saveToFile(square, "square_data.txt");


    return 0;
}




    
