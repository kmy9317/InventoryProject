#pragma once

#include "Inv_GridTypes.generated.h"

class UInv_InventoryItem;

UENUM(BlueprintType)
enum class EInv_ItemCategory : uint8
{
	Equippable,
	Consumable,
	Craftable,
	None
};

USTRUCT()
struct FInv_SlotAvailability
{
	GENERATED_BODY()

	FInv_SlotAvailability() {}
	FInv_SlotAvailability(int32 ItemIndex, int32 Room, bool bHasItem) : Index(ItemIndex), AmountToFill(Room), bItemAtIndex(bHasItem) {}

	// 슬롯의 인덱스 (위치)
	int32 Index{INDEX_NONE};
	// 이 슬롯이 받을 수 있는 수량
	int32 AmountToFill{0};
	// 이미 아이템이 있는지 여부
	bool bItemAtIndex{false};
};

USTRUCT()
struct FInv_SlotAvailabilityResult
{
	GENERATED_BODY()

	FInv_SlotAvailabilityResult() {}

	// 추가하려는 아이템
	TWeakObjectPtr<UInv_InventoryItem> Item;
	// 총 수용 가능 수량
	int32 TotalRoomToFill{0};
	// 못 들어가는 나머지
	int32 Remainder{0};
	// 스택 가능 여부
	bool bStackable{false};
	// 가능한 모든 슬롯들
	TArray<FInv_SlotAvailability> SlotAvailabilities;
};