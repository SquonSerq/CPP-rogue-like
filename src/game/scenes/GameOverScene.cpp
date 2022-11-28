#include "game/scenes/GameOverScene.h"

void GameOverScene::OnCreate() {
    engine_.GetSystemManager()->DeleteAll();
}

void GameOverScene::OnRender() {
    terminal_clear();

    terminal_print(70, 22, "Game over!");
    terminal_print(64, 24, "Press SPACE to retry!");

    if (controls_.IsPressed(TK_SPACE)) {
        ctx_->scene_ = "FirstFloor";
    }

    terminal_refresh();
    engine_.OnUpdate();
}

void GameOverScene::OnExit() {
    engine_.GetSystemManager()->DeleteAll();
    engine_.GetEntityManager()->DeleteAll();
}

GameOverScene::GameOverScene(Context *ctx, const Controls &controls, const Engine &engine)
        : IScene(ctx), controls_(controls), engine_(engine) {}
