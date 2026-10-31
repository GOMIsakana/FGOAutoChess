# game-player-framework Specification

## Purpose

Provides shared Unreal base classes for game mode, game state, player controller, and player state, giving runtime code and designers consistent framework types to extend.

## Requirements

### Requirement: Project game framework classes
The project SHALL provide `AACGameMode` and `AACGameState` in the `FGOAutoChess` runtime module as subclasses of `AGameModeBase` and `AGameStateBase`, respectively.

#### Scenario: Game framework classes are available
- **WHEN** the `FGOAutoChess` runtime module is compiled
- **THEN** it exposes their headers under `Source/FGOAutoChess/Public/Game/` and implementations under `Source/FGOAutoChess/Private/Game/`, with the corresponding Unreal base classes

### Requirement: Project player framework classes
The project SHALL provide `AACPlayerController` and `AACPlayerState` in the `FGOAutoChess` runtime module as subclasses of `APlayerController` and `APlayerState`, respectively.

#### Scenario: Player framework classes are available
- **WHEN** the `FGOAutoChess` runtime module is compiled
- **THEN** it exposes their headers under `Source/FGOAutoChess/Public/Player/` and implementations under `Source/FGOAutoChess/Private/Player/`, with the corresponding Unreal base classes

### Requirement: Project framework classes support Blueprint extension
The four project framework classes SHALL be Blueprint-extendable extension points without imposing additional gameplay behavior.

#### Scenario: Framework classes remain extension points
- **WHEN** a designer creates a Blueprint subclass from any of the four C++ classes
- **THEN** each class can be used as the Blueprint parent and imposes no additional gameplay behavior
