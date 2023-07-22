#include "Character/MainPlayerController.h"
#include "Character/PlayerCharacter.h"

void AMainPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	PlayerCharacter = Cast<APlayerCharacter>(InPawn);
}

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("MoveForward", this, &AMainPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMainPlayerController::MoveRight);
	InputComponent->BindAxis("Turn", this, &AMainPlayerController::Turn);
	InputComponent->BindAxis("LookUp", this, &AMainPlayerController::LookUp);

	InputComponent->BindAction("TakeObj", EInputEvent::IE_Pressed, this, &AMainPlayerController::GrabObj);
	InputComponent->BindAction("DropObj", EInputEvent::IE_Released, this, &AMainPlayerController::DropObj);
}

void AMainPlayerController::MoveForward(float Value)
{
	if (PlayerCharacter.IsValid())
	{
		PlayerCharacter->MoveForward(Value);
	}
}

void AMainPlayerController::MoveRight(float Value)
{
	if (PlayerCharacter.IsValid())
	{
		PlayerCharacter->MoveRight(Value);
	}
}

void AMainPlayerController::Turn(float Value)
{
	if (PlayerCharacter.IsValid())
	{
		PlayerCharacter->Turn(Value);
	}
}

void AMainPlayerController::LookUp(float Value)
{
	if (PlayerCharacter.IsValid())
	{
		PlayerCharacter->LookUp(Value);
	}
}

void AMainPlayerController::GrabObj()
{
	if (PlayerCharacter.IsValid())
	{
		PlayerCharacter->TraceLineForMovingPCComponents();
	}
}

void AMainPlayerController::DropObj()
{
	if (PlayerCharacter.IsValid())
	{
		PlayerCharacter->DropObject();
	}
}
