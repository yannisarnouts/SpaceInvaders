//
// Created by Gebruiker on 6/04/2020.
//

#ifndef PROJECT_TIMER_H
#define PROJECT_TIMER_H

namespace Game {
    class Timer {
    public:
        Timer();
        virtual ~Timer();
        virtual double getDeltaTime() = 0;
        virtual void update() = 0;
        const float getTargetDeltatime() const;
        virtual void reset() = 0;

    private:
        const float TARGET_DELTATIME = 1.5f;
    };
}

#endif //PROJECT_TIMER_H
