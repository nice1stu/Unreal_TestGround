// MyMultiplayerPlayer.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyMultiplayerPlayer.generated.h"

UCLASS()
class UNREAL_TESTGROUND_API AMyMultiplayerPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyMultiplayerPlayer();

	UPROPERTY(Replicated, BlueprintReadOnly)
		FLinearColor PlayerColor; // Replicated color for the player

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float MoveSpeed = 1000.f;

	UFUNCTION(BlueprintCallable)
		void Move(FVector2D AxisInput);

	// Function to handle replicated PlayerColor
	UFUNCTION()
		void OnRep_PlayerColor();
};

