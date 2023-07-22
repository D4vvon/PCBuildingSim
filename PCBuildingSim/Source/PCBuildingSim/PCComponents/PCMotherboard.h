// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PCComponents/BasePCComponent.h"
#include "PCMotherboard.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PCBUILDINGSIM_API APCMotherboard : public ABasePCComponent
{
	GENERATED_BODY()
	
public:

protected:

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


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability")
	EMotherboardType MotherboardType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | CPU")
	ECPUSocketType CPUSocket;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | CPU", meta = (EditCondition = "CPUSocket == ECPUSocketType::Intel"))
	EIntelSocketTypes IntelSocket;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | CPU", meta = (EditCondition = "CPUSocket == ECPUSocketType::AMD"))
	EAMDSocketTypes AMDSocket;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | CPU", meta = (EditCondition = "CPUSocket == ECPUSocketType::Intel"))
	EIntelChipsetTypes IntelChipset;														  
																							  
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | CPU", meta = (EditCondition = "CPUSocket == ECPUSocketType::AMD"))
	EAMDChipsetTypes AMDChipset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | CPU", meta = (EditCondition = "CPUSocket == ECPUSocketType::Intel"))
	EIntelCore IntelCore;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | CPU", meta = (EditCondition = "CPUSocket == ECPUSocketType::AMD"))
	EAMDCore AMDCore;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | RAM")
	float RAM_SlotsCount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | RAM")
	ERAMTypes RAMType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | RAM")
	float MaxRAMCount; //in Gb


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | ROM")
	float ROM_SlotsPCIECount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | ROM")
	float ROM_SATACount;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | ROM")
	bool bIsSupportNVMe;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | ROM")
	float ROM_SlotsM2Count;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | PCI_Slots", meta = (ClampMin = 0, ClampMax = 4, UIMin = 0, UIMax = 4))
	float PCI_E_Version;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | PCI_Slots")
	float PCIE_x16_Count;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | PCI_Slots")
	bool bIsSupportSLI_CrossFire;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | PCI_Slots")
	ESLICrossFireTypes SLI_CrossfireType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | PCI_Slots")
	float PCIE_x1_Count;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | BackPanel")
	TArray<EFrontPanelSlots> PanelSlots;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | BackPanel")
	TArray<EVideoPorts> VideoPorts;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | InnerConnectors")
	TArray<EInnerConnectorTypes> InnerConnectors;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | InnerConnectors")
	uint8 CPUpin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | InnerConnectors")
	float PWM_4pin_ConnectorsForFan;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | InnerConnectors")
	float SWC_4pin_Connector;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | InnerConnectors")
	float Fan_3pin_Connectors;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | InnerConnectors")
	float LED_3pin_Connectors;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Characteristic | Compability | InnerConnectors")
	float LED_4pin_Connectors;
};
