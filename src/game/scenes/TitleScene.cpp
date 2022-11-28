#include "game/scenes/TitleScene.h"

#include <BearLibTerminal.h>

void TitleScene::OnCreate() {
    engine_.GetEntityManager()->DeleteAll();
    engine_.GetSystemManager()->DeleteAll();
}

void TitleScene::OnRender() {
  terminal_clear();

  terminal_print(60, 22, "Rogue-like game by D. V. Likhachev");


  if (controls_.IsPressed(TK_S)) {
      if (menuPos < 2) {
          menuPos += 1;
      }
  } else if (controls_.IsPressed(TK_W)) {
      if (menuPos > 1) {
          menuPos -= 1;
      }
  }

  terminal_print(65, 24 + 2 * menuPos, "-->");

  terminal_printf(70, 26, "Начать игру");
  terminal_printf(70, 28, "Редактор");

  if (controls_.IsPressed(TK_ENTER)) {
    if (menuPos == 1) {
        ctx_->scene_ = "FirstFloor";
    } else if (menuPos == 2) {
        ctx_->scene_ = "FloorEditor";
    }
  }

  terminal_refresh();
}

void TitleScene::OnExit() {}

TitleScene::TitleScene(Context *ctx, const Controls &controls, const Engine &engine)
: IScene(ctx), controls_(controls), engine_(engine) {}
