# game-player-framework Specification

## Purpose

TBD: Update Purpose after archive.

## Requirements

### Requirement: Project gameplay framework classes
The project SHALL provide Blueprint-extendable C++ classes `AACGameMode`, `AACGameState`, `AACPlayerController`, and `AACPlayerState` in the `FGOAutoChess` runtime module. They SHALL derive from `AGameModeBase`, `AGameStateBase`, `APlayerController`, and `APlayerState`, respectively. Their headers SHALL reside in `Source/FGOAutoChess/Public/Game/` or `Source/FGOAutoChess/Public/Player/`, and their `.cpp` files SHALL reside in the matching `Source/FGOAutoChess/Private/Game/` or `Source/FGOAutoChess/Private/Player/` directory.

#### Scenario: Game framework classes are available
- **WHEN** the `FGOAutoChess` runtime module is compiled
- **THEN** the module exposes `AACGameMode` and `AACGameState` headers under `Source/FGOAutoChess/Public/Game/` and implementations under `Source/FGOAutoChess/Private/Game/`, with their corresponding Unreal base classes

#### Scenario: Player framework classes are available
- **WHEN** the `FGOAutoChess` runtime module is compiled
- **THEN** the module exposes `AACPlayerController` and `AACPlayerState` headers under `Source/FGOAutoChess/Public/Player/` and implementations under `Source/FGOAutoChess/Private/Player/`, with their corresponding Unreal base classes

#### Scenario: Classes remain extension points
- **WHEN** a designer creates a Blueprint subclass from any of the four C++ classes
- **THEN** the class is Blueprint-extendable and has no additional gameplay behavior imposed by this change
