#include <bits/stdc++.h>
#include <string>
using namespace std;

class Exercise {
protected:
    string name;
    string category;

public:
    Exercise(const string& name, const string& category) : name(name), category(category) {}

    virtual double calculateCaloriesBurned() = 0;
};

class StrengthExercise : public Exercise {
public:
    StrengthExercise(const string& name) : Exercise(name, "Strength") {}

    double calculateCaloriesBurned() override {
        return 150.0;
    }
};

class CardioExercise : public Exercise {
public:
    CardioExercise(const string& name) : Exercise(name, "Cardio") {}

    double calculateCaloriesBurned() override {
        return 200.0;
    }
};

class PlanInterface {
public:
    virtual void createPlan() = 0;
    virtual void trackProgress() = 0;
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

