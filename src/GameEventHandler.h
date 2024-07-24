#pragma once
#include "SfseMessagingListener.h"

namespace plugin {
    class GameEventHandler : public SfseMessagingListener<GameEventHandler> {
        private:
            GameEventHandler() {
                registerListener();
            };
            GameEventHandler(GameEventHandler&) = delete;
            GameEventHandler& operator=(GameEventHandler&&) = delete;
            void operator=(GameEventHandler&) = delete;

        public:
            [[nodiscard]] static GameEventHandler& getInstance() {
                static GameEventHandler instance;
                return instance;
            }

            void onLoad() override;
            void onPostLoad() override;
            void onPostPostLoad() override;
            void onPostDataLoaded() override;
            void onPostPostDataLoaded() override;
    };
}  // namespace plugin
