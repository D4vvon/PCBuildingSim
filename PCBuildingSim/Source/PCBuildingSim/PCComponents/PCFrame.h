
#pragma once

#include "CoreMinimal.h"
#include "PCComponents/BasePCComponent.h"
#include "Components/BoxComponent.h"
#include "PCFrame.generated.h"


UCLASS(Blueprintable)
class PCBUILDINGSIM_API APCFrame : public ABasePCComponent
{
	GENERATED_BODY()

public:
	APCFrame();

protected:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UBoxComponent* PowerPlace;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UBoxComponent* MotherboardPlace;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Profile")
	FString ModelName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Profile")
	FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Profile")
	EFrameType FrameType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Profile")
	float Length;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Profile")
	float Width;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Profile")
	float Heigth;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability")
	EMotherboardType MotherboardType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability")
	EPowerType PowerType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability")
	float MaxPowerLength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability")
	float MaxGraphiccardLength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability")
	float MaxCPUCoolerHeight;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability")
	uint8 ROMCount_25;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability")
	uint8 ROMCount_35;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Cooling")
	bool bIsFanIncluded;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Cooling", meta = (EditCondition = "bIsFanIncluded == true"))
	EFanSize IncludedFanSize;	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Cooling")
	float TopFanMaxSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Cooling")
	float SideFanMaxSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Cooling")
	float BottomFanMaxSize;
	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | FronPanel")
	TArray<EFrontPanelSlots> FrontSlots;

private:
	UFUNCTION(BlueprintCallable)
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION(BlueprintCallable)
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);
};
