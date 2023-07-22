// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PCTypes.h"
#include "BasePCComponent.generated.h"

UCLASS(Abstract, NotBlueprintable)
class PCBUILDINGSIM_API ABasePCComponent : public AActor
{
	GENERATED_BODY()
	
public:
	virtual void ConnectToComponent() {};

protected:	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component | Type")
	EComponentsTypes ComponentType;

};
