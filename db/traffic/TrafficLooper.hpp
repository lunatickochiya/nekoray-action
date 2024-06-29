#pragma once

#include <QString>
#include <QList>
#include <QMutex>

#include "TrafficData.hpp"

namespace NekoGui_traffic {
    class TrafficLooper {
    public:
        bool loop_enabled = false;
        bool looping = false;
        QMutex loop_mutex;

        QList<std::shared_ptr<TrafficData>> items;
        TrafficData *proxy = nullptr;

        void UpdateAll();

        void Loop();

    private:
        TrafficData *direct = new TrafficData("direct");

        [[nodiscard]] static TrafficData *update_stats(TrafficData *item);
    };

    extern TrafficLooper *trafficLooper;
} // namespace NekoGui_traffic
