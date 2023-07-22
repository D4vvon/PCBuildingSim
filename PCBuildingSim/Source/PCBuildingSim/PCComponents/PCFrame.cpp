// Fill out your copyright notice in the Description page of Project Settings.


#include "PCComponents/PCFrame.h"

APCFrame::APCFrame()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FrameMesh"));
	Mesh->SetupAttachment(RootComponent);

	PowerPlace = CreateDefaultSubobject<UBoxComponent>(TEXT("PowerPlace"));
	PowerPlace->SetupAttachment(Mesh);
	PowerPlace->OnComponentBeginOverlap.AddDynamic(this, &APCFrame::OnOverlapBegin);
	PowerPlace->OnComponentEndOverlap.AddDynamic(this, &APCFrame::OnOverlapEnd);

	MotherboardPlace = CreateDefaultSubobject<UBoxComponent>(TEXT("MotherboardPlace"));
	MotherboardPlace->SetupAttachment(Mesh);
	MotherboardPlace->OnComponentBeginOverlap.AddDynamic(this, &APCFrame::OnOverlapBegin);
	MotherboardPlace->OnComponentEndOverlap.AddDynamic(this, &APCFrame::OnOverlapEnd);
}

void APCFrame::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, FString::Printf(TEXT("TriggerActor %s"), *OtherActor->GetName()));
	if (OtherComponent != Mesh)
	{
		OtherActor->SetActorLocation(OverlappedComponent->GetComponentLocation());
		OtherActor->DisableComponentsSimulatePhysics();		
	}
}

void APCFrame::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Blue, TEXT("EndOverlap"));
}
