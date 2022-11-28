#include "game/scenes/FirstFloor.h"

#include <game/components/PlayerControlComponent.h>
#include <game/components/TurnsComponent.h>
#include <game/editor/components/FilePathComponent.h>
#include <game/entities/player.h>
#include <game/systems/AISystem.h>
#include <game/systems/BattleSystem.h>
#include <game/systems/CollisionSystem.h>
#include <game/systems/DoorSystem.h>
#include <game/systems/InventorySystem.h>
#include <game/systems/MovementSystem.h>
#include <game/systems/PlayerControlSystem.h>
#include <game/systems/RenderingSystem.h>
#include <game/systems/TurnsSystem.h>
#include <game/utils/HUDRenderer.h>
#include <game/utils/RoomReader.h>
#include <game/utils/SceneRenderer.h>

#include <string>
#include <vector>

FirstFloor::FirstFloor(Context *ctx, const Controls &controls, const Engine &engine)
    : IScene(ctx), controls_(controls), engine_(engine) {}

void FirstFloor::OnCreate() {
  bool filePathExist = false;
  for (auto &filePathCheck : *engine_.GetEntityManager()) {
    if (filePathCheck.Contains<FilePathComponent>()) {
      filePathExist = true;
    }
  }

  if (!filePathExist) {
    ctx_->scene_ = "PickPlayLevel";
  }

  for (auto &filePathEnt : *engine_.GetEntityManager()) {
    if (filePathEnt.Contains<FilePathComponent>()) {
      if (!filePathEnt.Get<FilePathComponent>()->path_.empty()) {
        std::string path = filePathEnt.Get<FilePathComponent>()->path_;

        engine_.GetEntityManager()->DeleteAll();
        {
          auto systemStats = engine_.GetEntityManager()->CreateEntity();
          systemStats->Add<TurnsComponent>(0, 1000);

          engine_.GetEntityManager()->AddToTag("system", systemStats);
        }

        RoomReader err = RoomReader(engine_.GetEntityManager(), path);
        err.ReadFile();

        bool isPlayerExist = false;
        for (auto &ent : *engine_.GetEntityManager()) {
          if (ent.Contains<PlayerControlComponent>()) {
            isPlayerExist = true;
          }
        }

        if (!isPlayerExist) {
            {
                auto player = CreatePlayerAt(engine_.GetEntityManager(), Vec2{0, 0});
                engine_.GetEntityManager()->AddToTag("player", player);
                engine_.GetEntityManager()->AddToTag("MovementSystem", player);
                engine_.GetEntityManager()->AddToTag("Collider", player);
            }
        }

        break;
      }
    }
  }

  std::vector<IRender *> renders;
  renders.push_back(new SceneRenderer);
  renders.push_back(new HUDRenderer);

  auto sys = engine_.GetSystemManager();
  sys->AddSystem<RenderingSystem>(renders);
  sys->AddSystem<PlayerControlSystem>(controls_);
  sys->AddSystem<AISystem>();
  sys->AddSystem<MovementSystem>();
  sys->AddSystem<CollisionSystem>();
  sys->AddSystem<InventorySystem>();
  sys->AddSystem<TurnsSystem>(ctx_);
  sys->AddSystem<DoorSystem>(ctx_);
  sys->AddSystem<BattleSystem>(ctx_);
}

void FirstFloor::OnRender() {
  if (controls_.IsPressed(TK_BACKSPACE)) {
    ctx_->scene_ = "title";
  }

  if (controls_.IsPressed(TK_R)) {
    ctx_->scene_ = "GameOver";
  }

  engine_.OnUpdate();
}

void FirstFloor::OnExit() {}
