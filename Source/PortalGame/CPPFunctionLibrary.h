// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CPPFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PORTALGAME_API UCPPFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject"))
	static bool IsInFrustum(AActor* Actor, const UObject* WorldContextObject);
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject"))
	static bool IsInFrustumComp(USceneComponent* Component, const UObject* WorldContextObject);
	
};
