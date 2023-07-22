#include "PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

APlayerCharacter::APlayerCharacter()
{
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring arm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	CameraComponent->bUsePawnControlRotation = false;

	VirtualHandSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("VirtualHand"));
	VirtualHandSceneComponent->SetupAttachment(CameraComponent);

	PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("PhysHandle"));
	//PhysicsHandle->Attach

	GetCharacterMovement()->bOrientRotationToMovement = 1;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
}

void APlayerCharacter::Tick(float DeltaTime)
{
	PhysicsHandle->SetTargetLocation(VirtualHandSceneComponent->GetComponentLocation());
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerCharacter::MoveForward(float Value)
{
	if (!FMath::IsNearlyZero(Value, 1e-6f))
	{
		FRotator YawRotator(0.0f, GetControlRotation().Yaw, 0.0f);
		FVector ForwardVector = YawRotator.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardVector, Value);
	}
}

void APlayerCharacter::MoveRight(float Value)
{
	if (!FMath::IsNearlyZero(Value, 1e-6f))
	{
		FRotator YawRotator(0.0f, GetControlRotation().Yaw, 0.0f);
		FVector RightVector = YawRotator.RotateVector(FVector::RightVector);
		AddMovementInput(RightVector, Value);
	}
}

void APlayerCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void APlayerCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void APlayerCharacter::TraceLineForMovingPCComponents()
{
	if (!IsPlayerControlled())
	{
		return;
	}

	FVector ViewLocation;
	FRotator ViewRotation;

	APlayerController* PlayerController = GetController<APlayerController>();
	PlayerController->GetPlayerViewPoint(ViewLocation, ViewRotation);

	FVector ViewDirection = ViewRotation.Vector();
	FVector TraceEnd = ViewLocation + ViewDirection * TraceDistance;

	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult, ViewLocation, TraceEnd, ECC_Visibility);

	if (TraceLineObject != HitResult.GetActor())
	{
		TraceLineObject = HitResult.GetActor();
		TraceLineComponent = HitResult.GetComponent();
		if (TraceLineComponent->IsSimulatingPhysics())
		{
			GrabObject(TraceLineComponent);
		}
		else
		{
			TraceLineObject = nullptr;
			TraceLineComponent = nullptr;
		}
	}
}

void APlayerCharacter::GrabObject(UPrimitiveComponent * ObjectGrab)
{
	PhysicsHandle->GrabComponentAtLocationWithRotation(ObjectGrab, NAME_None, ObjectGrab->GetComponentLocation(), ObjectGrab->GetComponentRotation());
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Black, TEXT("Grab"));
}

void APlayerCharacter::DropObject()
{
	if (TraceLineComponent != nullptr)
	{
		PhysicsHandle->ReleaseComponent();
		TraceLineComponent = nullptr;
		TraceLineObject = nullptr;
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Black, TEXT("Drop"));
	}
}

