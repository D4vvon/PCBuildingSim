#pragma once

UENUM(BlueprintType)
enum class EComponentsTypes : uint8
{
	None,
	Frame,
	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EFrameType : uint8
{
	None,
	UltraTower,
	FullTower,
	MidiTower,
	MiniTower,
	SFF,
	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EMotherboardType : uint8
{
	None,
	WTX,
	EE_ATX,
	E_ATX,
	XL_ATX,
	ATX,
	Mini_ATX,
	Micro_ATX,
	Flex_ATX,
	Mini_ITX,
	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EPowerType : uint8
{
	None,
	ATX,
	SFX,
	EPS,
	TFX,
	CFX,
	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EFanSize : uint8
{
	None,
	mm_120,
	mm_140,
	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EFrontPanelSlots : uint8
{
	None,
	JackAudio_35,
	JackMic_35,
	USB_32_Gen1TypeA,
	USB_32_Gen2TypeC,
	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class ECPUSocketType : uint8
{
	None,
	Intel,
	AMD,
	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EIntelSocketTypes : uint8
{
	None,
	Socket_423,
	Socket_603_604,
	LGA771,
	LGA775,
	LGA1567,
	LGA1366,
	LGA1156,
	LGA1155,
	LGA2011,
	LGA1356,
	LGA1150,
	LGA2011_3,
	LGA1151,
	LGA2066,
	LGA1200,
	LGA1700,
	LGA1851,
	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EAMDSocketTypes : uint8
{
	None,
	Socket_462,
	Socket_754,
	Socket_939,
	AM2,
	AM2_PLUS,
	AM3,
	AM3_PLUS,
	FM1,
	FM2,
	FM2_PLUS,
	AM1,
	AM4,
	sTRX4,
	sWRX8,
	AM5,
	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EIntelChipsetTypes : uint8
{
	None,
	H110,
	B150,
	Q150,
	H170,
	Z170,
	B250,
	Q250,
	H270,
	Q270,
	Z270,
	X299,
	H310,
	B360,
	B365,
	H370,
	Q370,
	Z370,
	Z390,
	H410,
	B460,
	H470,
	Q470,
	Z490,
	H510,
	B560,
	H570,
	Z590,
	W580,
	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EAMDChipsetTypes : uint8
{
	None,
	A300,
	X300,
	PRO500,
	A320,
	B350,
	X370,
	B450,
	X470,
	A520,
	B550,
	X570,
	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EIntelCore : uint8
{
	None,
	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EAMDCore : uint8
{
	None,
	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class ERAMTypes : uint8
{
	None,
	DDR2,
	DDR3,
	DDR4,
	DDR5,
	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class ESLICrossFireTypes : uint8
{
	None,
	CrossFireX,
	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EVideoPorts : uint8
{
	None,
	HDMI,
	DisplayPort,
	MAX UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EInnerConnectorTypes : uint8
{
	None,
	USB20_9pin,
	USB32_Gen1_19pin,
	MAX UMETA(Hidden)
};