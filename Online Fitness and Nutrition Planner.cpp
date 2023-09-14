#include <bits/stdc++.h>
#include <string>
using namespace std;

class Exercise {
protected:  // Encapsulation: Attributes are protected, accessible to derived classes.
    string name;
    string category;

public:
    Exercise(const string& name, const string& category) : name(name), category(category) {}

    virtual double calculateCaloriesBurned() = 0; // Abstraction: Pure virtual function makes Exercise an abstract class.
};

class StrengthExercise : public Exercise { // Inheritance: StrengthExercise is a derived class of Exercise.
public:
    StrengthExercise(const string& name) : Exercise(name, "Strength") {}

    double calculateCaloriesBurned() override { // Polymorphism: Overriding the pure virtual function from the base class.
        return 150.0;
    }
};

class CardioExercise : public Exercise { // Inheritance: CardioExercise is a derived class of Exercise.
public:
    CardioExercise(const string& name) : Exercise(name, "Cardio") {}

    double calculateCaloriesBurned() override { // Polymorphism: Overriding the pure virtual function from the base class.
        return 200.0;
    }
};

class PlanInterface {
public:
    virtual void createPlan() = 0; // Abstraction: Pure virtual function makes PlanInterface an abstract class.
    virtual void trackProgress() = 0; // Abstraction: Pure virtual function makes PlanInterface an abstract class.
};


int main() {
    Exercise* pushUp = new StrengthExercise("Push-up");
    Exercise* jogging = new CardioExercise("Jogging");

    cout << "Calories burned doing push-ups: " << pushUp->calculateCaloriesBurned() << " kcal" << endl;
    cout << "Calories burned while jogging: " << jogging->calculateCaloriesBurned() << " kcal" << endl;

    delete pushUp;
    delete jogging;

    return 0;
}
