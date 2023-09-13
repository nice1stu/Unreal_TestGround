// MyMultiplayerPlayer.cpp

#include "MyMultiplayerPlayer.h"
#include "Kismet/KismetMathLibrary.h"
#include "Net/UnrealNetwork.h" // Include this for replication

AMyMultiplayerPlayer::AMyMultiplayerPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	// Set up replication for PlayerColor
	bReplicates = true;
	bReplicateMovement = false; // Depending on your needs
}

// Replication logic for PlayerColor
void AMyMultiplayerPlayer::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(AMyMultiplayerPlayer, PlayerColor, COND_SimulatedOnly);
}

void AMyMultiplayerPlayer::Move(FVector2D AxisInput)
{
	auto MoveVector = FVector(AxisInput.Y, -AxisInput.X, 0.f);

	auto TransformedVector = UKismetMathLibrary::TransformDirection(
		GetActorTransform(),
		MoveVector
	);

	auto DeltaTime = GetWorld()->GetDeltaSeconds();

	MoveVector *= MoveSpeed;

	SetActorLocation(
		GetActorLocation() +
		MoveVector * DeltaTime
	);
}

void AMyMultiplayerPlayer::OnRep_PlayerColor()
{
	// This function is called when PlayerColor is replicated
	// You can update your material color or perform other actions here
}
