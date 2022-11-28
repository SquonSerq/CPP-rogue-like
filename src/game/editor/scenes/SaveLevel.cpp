#include <game/editor/utils/RoomSaver.h>
#include "game/editor/scenes/SaveLevel.h"

SaveLevel::SaveLevel(Context *ctx, const Controls &controls, const Engine &engine)
        : IScene(ctx), controls_(controls), engine_(engine) {}

void SaveLevel::OnCreate() {
    for (auto &ch : levelName_) {
        ch = '\0';
    }
}

void SaveLevel::OnRender() {
    terminal_clear();

    terminal_print(5, 5, "название:");
    auto res = terminal_read_str(15, 5, levelName_, 25);

    if (res) {
        if (res == TK_INPUT_CANCELLED) {
            ctx_->scene_ = "FloorEditor";
        } else {
            std::stringstream ss;
            ss << "./src/room texts/" << levelName_ << ".txt";
            auto rs = RoomSaver(&engine_, ss.str());
            rs.Save();
            ctx_->scene_ = "title";
        }
    }


    terminal_refresh();
}

void SaveLevel::OnExit() {}
