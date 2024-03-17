// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UDuplicationData.generated.h"
/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class PORTALS_API UDuplicationData : public UObject
{
	GENERATED_BODY()
public:

	~UDuplicationData();
	UDuplicationData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* Portal;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* Object;
	UDuplicationData(AActor* Portal, AActor* Object);
	UFUNCTION(BlueprintPure,BlueprintCallable)
	static UDuplicationData* MakeDuplicationData(AActor* newPortal, AActor* newObject);
};
