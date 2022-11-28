#include "game/scenes/FloorEditor.h"

#include <game/components/ColorComponent.h>
#include <game/components/MovementComponent.h>
#include <game/components/PlayerControlComponent.h>
#include <game/components/SystemPlayComponent.h>
#include <game/components/TextureComponent.h>
#include <game/components/TransformComponent.h>
#include <game/editor/components/FilePathComponent.h>
#include <game/editor/systems/EditorController.h>
#include <game/editor/systems/EditorEntityCreator.h>
#include <game/editor/utils/EditorRenderer.h>
#include <game/editor/utils/EditorRoomReader.h>
#include <game/editor/utils/RoomSaver.h>
#include <game/systems/RenderingSystem.h>
#include <game/utils/IRender.h>

#include <string>
#include <vector>

void FloorEditor::OnCreate() {
  engine_.GetSystemManager()->DeleteAll();
  bool playerControllerExist = false;
  for (auto &playerController : *engine_.GetEntityManager()) {
    if (playerController.Contains<PlayerControlComponent>()) {
      playerControllerExist = true;
    }
  }

  if (!playerControllerExist) {
    {
      auto controlEntity = engine_.GetEntityManager()->CreateEntity();

      controlEntity->Add<TransformComponent>(Vec2{0, 0});
      controlEntity->Add<TextureComponent>('X');
      controlEntity->Add<MovementComponent>();
      controlEntity->Add<PlayerControlComponent>(TK_W, TK_S, TK_A, TK_D);
      controlEntity->Add<ColorComponent>(255, 255, 0, 0);
    }
  }

  for (auto &filePathEnt : *engine_.GetEntityManager()) {
    if (filePathEnt.Contains<FilePathComponent>()) {
      if (!filePathEnt.Get<FilePathComponent>()->path_.empty()) {
        std::string path = filePathEnt.Get<FilePathComponent>()->path_;

        engine_.GetEntityManager()->DeleteAll();

        {
          auto controlEntity = engine_.GetEntityManager()->CreateEntity();

          controlEntity->Add<TransformComponent>(Vec2{0, 0});
          controlEntity->Add<TextureComponent>('X');
          controlEntity->Add<MovementComponent>();
          controlEntity->Add<PlayerControlComponent>(TK_W, TK_S, TK_A, TK_D);
          controlEntity->Add<ColorComponent>(255, 255, 0, 0);
        }
        EditorRoomReader err = EditorRoomReader(engine_.GetEntityManager(), path);
        err.ReadFile();
        break;
      }
    }
  }
    std::vector<IRender *> renders;
  renders.push_back(new EditorRenderer);

  auto sys = engine_.GetSystemManager();
  sys->AddSystem<RenderingSystem>(renders);
  sys->AddSystem<EditorController>(controls_);
  sys->AddSystem<EditorEntityCreator>(controls_);
}

void FloorEditor::OnRender() {
  if (controls_.IsPressed(TK_O)) {
    ctx_->scene_ = "PickLevelLoad";
  }

  if (controls_.IsPressed(TK_BACKSPACE)) {
    ctx_->scene_ = "title";
  }

  if (controls_.IsPressed(TK_P)) {
    for (auto &ent : *engine_.GetEntityManager()) {
      if (ent.Contains<PlayerControlComponent>()) {
        engine_.GetEntityManager()->DeleteEntity(ent.GetId());
      }
    }
    ctx_->scene_ = "SaveLevel";
  }
  engine_.OnUpdate();
}

void FloorEditor::OnExit() {}

FloorEditor::FloorEditor(Context *ctx, const Controls &controls, const Engine &engine)
    : IScene(ctx), controls_(controls), engine_(engine) {}
