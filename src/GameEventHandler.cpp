#include "GameEventHandler.h"

namespace plugin {
    void GameEventHandler::onLoad() {
        logger::info("onLoad()");
    }

    void GameEventHandler::onPostLoad() {
        logger::info("onPostLoad()");
    }

    void GameEventHandler::onPostPostLoad() {
        logger::info("onPostPostLoad()");
    }

    void GameEventHandler::onPostDataLoaded() {
        logger::info("onPostDataLoaded()");
    }

    void GameEventHandler::onPostPostDataLoaded() {
        logger::info("onPostPostDataLoaded()");
    }
}  // namespace plugin