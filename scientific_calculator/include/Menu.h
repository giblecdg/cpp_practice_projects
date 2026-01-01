#ifndef MENU_H
#define MENU_H

class Menu {
public:
    void run();

private:
    bool useDegrees = true;

    void arithmetic();
    void power();
    void root();
    void trigonometry();
    void settings();
};

#endif
