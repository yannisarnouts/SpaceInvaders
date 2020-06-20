//
// Created by Gebruiker on 6/04/2020.
//

#ifndef PROJECT_SDLTIMER_H
#define PROJECT_SDLTIMER_H

#include "../model/Timer.h"

namespace SDL {
    class SDLTimer : public Game::Timer {
    public:
        SDLTimer();
        ~SDLTimer();
        double getDeltaTime() override;
        void update() override;
        void reset() override;

    private:
        // time current - previous frame
        double deltaTime;
        int startTicks;
        int elapsedTicks;
    };
}

#endif //PROJECT_SDLTIMER_H
