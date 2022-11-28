#include "game/scenes/PickPlayLevel.h"

#include <game/components/SystemPlayComponent.h>
#include <game/editor/components/FilePathComponent.h>

#include <filesystem>
#include <vector>

PickPlayLevel::PickPlayLevel(Context *ctx, const Controls &controls, const Engine &engine)
        : IScene(ctx), controls_(controls), engine_(engine) {}

void PickPlayLevel::OnCreate() {}

void PickPlayLevel::OnRender() {
    terminal_clear();
    terminal_printf(59, 1, "Выберите уровень и нажмите (O).");

    std::vector<std::filesystem::directory_entry> loadFiles;
    for (auto &fileName : std::filesystem::directory_iterator("./src/room texts")) {
        loadFiles.emplace_back(fileName);
    }

    if (controls_.IsPressed(TK_S)) {
        if (menuPos_ > 0) {
            menuPos_ -= 1;
        }
    } else if (controls_.IsPressed(TK_W)) {
        if (menuPos_ < loadFiles.size()-1) {
            menuPos_ += 1;
        }
    }

    terminal_put(60, 24, '>');

    int i = 0;
    for (auto &file : loadFiles) {
        terminal_printf(61, 24 - i + menuPos_, file.path().filename().c_str());
        i++;
    }
    if (controls_.IsPressed(TK_O)) {
        {
            auto filepath = engine_.GetEntityManager()->CreateEntity();
            filepath->Add<FilePathComponent>(loadFiles[menuPos_].path().c_str());
        }

        ctx_->scene_ = "FirstFloor";
    }

    terminal_printf(0, 49, "(W S) CHOICE | (O) OPEN");
    terminal_refresh();
}

void PickPlayLevel::OnExit() {}
