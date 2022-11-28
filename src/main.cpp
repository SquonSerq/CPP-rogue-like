#include <game/editor/scenes/PickLevelLoad.h>
#include <game/editor/scenes/SaveLevel.h>
#include <game/scenes/FloorEditor.h>
#include <game/scenes/GameOverScene.h>
#include <game/scenes/LevelStats.h>
#include <game/scenes/PickPlayLevel.h>

#include <vector>

#include "game/scenes/FirstFloor.h"
#include "game/scenes/TitleScene.h"
#include "lib/scenes/context.h"
#include "lib/scenes/scene_manager.h"

int main() {
  terminal_open();
  terminal_refresh();

  terminal_set("window.size=160x50; window.title='Rogue-like'");

  Controls controls;

  Context ctx{};
  SceneManager sm(ctx);
  Engine engine{};

  sm.Put("title", new TitleScene(&ctx, controls, engine));
  sm.Put("FirstFloor", new FirstFloor(&ctx, controls, engine));
  sm.Put("levelStats", new LevelStats(&ctx, controls, engine));
  sm.Put("GameOver", new GameOverScene(&ctx, controls, engine));
  sm.Put("FloorEditor", new FloorEditor(&ctx, controls, engine));
  sm.Put("PickLevelLoad", new PickLevelLoad(&ctx, controls, engine));
  sm.Put("SaveLevel", new SaveLevel(&ctx, controls, engine));
  sm.Put("PickPlayLevel", new PickPlayLevel(&ctx, controls, engine));

  ctx.scene_ = "title";

  while (true) {
    controls.OnUpdate();
    if (controls.IsPressed(TK_ESCAPE) || controls.IsPressed(TK_CLOSE)) {
      break;
    }

    sm.OnRender();

    controls.Reset();
  }

  sm.OnExit();

  terminal_close();
}
